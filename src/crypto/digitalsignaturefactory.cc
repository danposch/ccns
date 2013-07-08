#include "digitalsignaturefactory.h"

using namespace ccns::crypto;

IDigitalSignature* IgetSignatureAlgorithm(IDigitalSignature::ISignatureType type)
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
