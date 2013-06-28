#include "abstractpacket.h"

using namespace ccns::encoding;

AbstractPacket::AbstractPacket(int type, const std::string &name)
{
    this->packetType = type;
    this->packetName = name;
}

int AbstractPacket::getType(){
    return this->packetType;
}

std::string AbstractPacket:: getName(){
    return this->packetName;
}

int AbstractPacket::prefixMatch(const std::string &name){
    return 0;
}

ccns::util::BinaryBuffer AbstractPacket::serialize(){

    ccns::util::BinaryBuffer empty;
    return empty;
}
