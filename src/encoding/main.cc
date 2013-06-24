#include <iostream>

#include "packetmanager.h"

using namespace std;

/*!
  This program prints Hello world
*/

int main()
{

    PacketManager pman;

    std::string name("/aau/itec/daniel");
    unsigned char data[5] = {'d','a','t','a','\0'};

    IPacket* interest = pman.createInterest(name);
    IPacket* content = pman.createContentObject(name,data);

    cout << "Packet Name = " << interest->getName() << "Packet Type = "<< interest->getType() << std::endl;
    cout << "Packet Name = " << content->getName() << "Packet Type = "<< content->getType() << std::endl;

    //IPacketBuilder *builder = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);
    //IPacketBuilder *builder2 = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);

    cout << "Hello World!" << endl;
    return 0;
}
