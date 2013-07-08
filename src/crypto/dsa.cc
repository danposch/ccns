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
    *pub_buffer = saveKey(&priv_key);

    return true;
}

ccns::util::BinaryBuffer DSA::saveKey(CryptoPP::CryptoMaterial *key)
{
    CryptoPP::ByteQueue q;
    key->Save(q);

    size_t size = q.MaxRetrievable();

    unsigned char* tmp = (unsigned char*) calloc(size, sizeof(unsigned char));
    q.Get(tmp, size);

    free(tmp);
    return util::BinaryBuffer(tmp, size);
}

bool DSA::loadKey(const util::BinaryBuffer &data, CryptoPP::CryptoMaterial *key)
{
    CryptoPP::ByteQueue q;
    q.Put2(data.data(), data.length(), 1, true);

    key->Load(q);
    return true;
}

ccns::util::BinaryBuffer DSA::sign(const util::BinaryBuffer &data, const util::BinaryBuffer &priv_key, util::BinaryBuffer *signature_buf)
{
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::DSA::PrivateKey k;
    loadKey(priv_key, &k);

    CryptoppDigest sha3(IDigest::Cryptopp_SHA3_256);
    std::string m = sha3.computeDigest(data).getString();
    std::string signature;

    CryptoPP::DSA::Signer signer(k);

    CryptoPP::StringSource(m, true,
        new CryptoPP::SignerFilter(rng, signer,
            new CryptoPP::StringSink(signature),
            true // putMessage for recovery
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

ccns::util::BinaryBuffer DSA::verify(const util::BinaryBuffer &data, const util::BinaryBuffer &pub_key, util::BinaryBuffer *signature_buf)

{
    util::BinaryBuffer dummy;
    return dummy;

}
