#include <iostream>

#include "packetmanager.h"
#include "ipacketbuilder.h"
#include "../util/binarybuffer.h"

using namespace std;
using namespace ccns::encoding;
using namespace ccns::util;

/*!
  This program prints Hello world
*/

int main()
{

    PacketManager pman;

    std::string name("/aau/itec/daniel");
    unsigned char data[5] = {'d','a','t','a','\0'};

    IPacketBuilder *interestBuilder = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);
    IPacketBuilder *coBuilder = pman.getPacketBuilder(IPacketBuilder::ContentObjectBuilder);

    IPacket* interest = interestBuilder->createPacket(name);
    IPacket* content = coBuilder->createPacket(name,data);

    cout << "Packet Name = " << interest->getName() << " Packet Type = "<< interest->getType() << std::endl;
    cout << "Packet Name = " << content->getName() << " Packet Type = "<< content->getType() << std::endl;

    BinaryBuffer buf;

    cout << "Hello World!" << endl;
    return 0;
}
