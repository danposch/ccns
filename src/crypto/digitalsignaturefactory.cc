#include "digitalsignaturefactory.h"

using namespace ccns::crypto;

IDigitalSignature* DigitalSignatureFactory::getSignatureAlgorithm(IDigitalSignature::ISignatureType type)
{
    IDigitalSignature *algo = NULL;

    switch(type)
    {
        case IDigitalSignature::DSA:
        {
            algo = new DSA(IDigitalSignature::DSA);
            break;
        }
        default:
            algo = new DSA(IDigitalSignature::DSA);
    }
    return algo;
}
