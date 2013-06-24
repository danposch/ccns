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

    IPacket* p = pman.createInterest(name);

    cout << "Packet Name = " << p->getName() << std::endl;

    //IPacketBuilder *builder = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);
    //IPacketBuilder *builder2 = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);

    cout << "Hello World!" << endl;
    return 0;
}
