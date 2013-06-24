#include "abstractpacket.h"

AbstractPacket::AbstractPacket()
{

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
