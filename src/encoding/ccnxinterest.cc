#include "ccnxinterest.h"

using namespace ccns::encoding;

CCNxInterest::CCNxInterest(std::string name) : AbstractPacket(0, name)
{
   minSuffixComponents = 0;
   maxSuffixComponents = UINT_MAX;
   childselector = 1;
   answerOriginKind = 3;
}
