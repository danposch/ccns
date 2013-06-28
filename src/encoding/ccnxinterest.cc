#include "ccnxinterest.h"

#include <iostream>
#include <fstream>

using namespace ccns::encoding;

CCNxInterest::CCNxInterest(std::string name) : AbstractPacket(IPacket::CCNxInterest, name)
{
   minSuffixComponents = 0;
   maxSuffixComponents = UINT_MAX;
   childselector = 1;
   answerOriginKind = 3;
}

ccns::util::BinaryBuffer CCNxInterest::serialize()
{
    /*
    std::ofstream file("/home/dposch/archive.xml");
    boost::archive::xml_oarchive oa(file);

    oa & BOOST_SERIALIZATION_NVP(packetType);
    oa & BOOST_SERIALIZATION_NVP(packetName);

    util::BinaryBuffer b;

    return b;*/
}
