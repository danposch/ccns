#include "dsa.h"

using namespace ccns::crypto;

DSA::DSA(ISignatureType type) : AbstractDigitalSignature(type)
{
}

bool DSA::generateKeyPair(util::BinaryBuffer *pub_buffer, util::BinaryBuffer *priv_buffer)
{
    CryptoPP::AutoSeededRandomPool seed;
    CryptoPP::DSA::PrivateKey priv_key;
    CryptoPP::DSA::PublicKey pub_key;

    priv_key.GenerateRandomWithKeySize(seed, DSA_KEY_SIZE);
    pub_key.AssignFrom(priv_key);

    if( !priv_key.Validate(seed,3) || !pub_key.Validate(seed, 3))
    {
        return false; //keys are invalid or weak
    }

    pub_buffer->clear();
    priv_buffer->clear();

    *pub_buffer = saveKey(&pub_key);
    *priv_buffer = saveKey(&priv_key);

    return true;
}

ccns::util::BinaryBuffer DSA::saveKey(CryptoPP::CryptoMaterial *key)
{
    std::string enc_key;
    key->Save( CryptoPP::StringSink(enc_key).Ref());

    return util::BinaryBuffer(enc_key);
}

bool DSA::loadKey(const util::BinaryBuffer &data, CryptoPP::CryptoMaterial *key)
{
    key->Load(CryptoPP::StringStore(data.getString()).Ref());

    return true;
}

ccns::util::BinaryBuffer DSA::sign(const util::BinaryBuffer &data, const util::BinaryBuffer &priv_key, util::BinaryBuffer *signature_buf)
{
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::DSA::PrivateKey k;
    loadKey(priv_key, &k);

    std::string m = data.getString();
    std::string signature;

    CryptoPP::DSA::Signer signer(k);

    CryptoPP::StringSource(m, true,
        new CryptoPP::SignerFilter(rng, signer,
            new CryptoPP::StringSink(signature),
            false // putMessage for recovery
       )
    );

    if(signature_buf != NULL)
    {
        signature_buf->clear();
        signature_buf->append(signature);
        return *signature_buf;
    }

    return  util::BinaryBuffer(signature);
}

bool DSA::verify(const util::BinaryBuffer &data, const util::BinaryBuffer &pub_key, const util::BinaryBuffer signature_buf)
{
    CryptoPP::DSA::PublicKey k;
    loadKey(pub_key, &k);

    CryptoPP::DSA::Verifier verifier( k );

    bool result = false;

    CryptoPP::StringSource( data.getString() + signature_buf.getString(), true,
        new CryptoPP::SignatureVerificationFilter(
            verifier,
            new CryptoPP::ArraySink(
                (byte*)&result, sizeof(result)),
            CryptoPP::SignatureVerificationFilter::PUT_RESULT |
            CryptoPP::SignatureVerificationFilter::SIGNATURE_AT_END
        )
    );

    return result;
}
