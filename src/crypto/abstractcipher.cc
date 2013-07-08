#include "abstractcipher.h"

using namespace ccns::crypto;

AbstractCipher::AbstractCipher(ICipherType type)
{
    this->cipherType = type;
}
