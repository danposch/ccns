#include "abstractdigitalsignature.h"

using namespace ccns::crypto;

AbstractDigitalSignature::AbstractDigitalSignature(ISignatureType sigType)
{
    this->sigType = sigType;
}

IDigitalSignature::ISignatureType AbstractDigitalSignature::getType()
{
    return this->sigType;
}
