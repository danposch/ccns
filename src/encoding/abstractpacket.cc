#include "abstractpacket.h"

using namespace ccns::encoding;

AbstractPacket::AbstractPacket(IPacketType type, const util::Name &name, PropertyMap props)
{
    this->packetType = type;
    this->packetName = name;
    this->props = props;
}

ccns::encoding::IPacket::IPacketType AbstractPacket::getType(){
    return this->packetType;
}

ccns::util::Name AbstractPacket::getName(){
    return this->packetName;
}

int AbstractPacket::prefixMatch(const std::string &name){
    return 0;
}

ccns::util::BinaryBuffer AbstractPacket::xmlSerialize(){

    ccns::util::BinaryBuffer empty;
    return empty;
}
