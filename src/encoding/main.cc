#include <iostream>

#include "packetmanager.h"
#include "ipacketbuilder.h"
#include "binarybuffer.h"

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
    BinaryBuffer b(data, 5);

    IPacketBuilder *interestBuilder = pman.getPacketBuilder(IPacketBuilder::InterestBuilder);
    IPacketBuilder *coBuilder = pman.getPacketBuilder(IPacketBuilder::ContentObjectBuilder);

    IPacket* interest = interestBuilder->createPacket(name);
    IPacket* content = coBuilder->createPacket(name,b);

    cout << "Packet Name = " << interest->getName() << " Packet Type = "<< interest->getType() << std::endl;
    cout << "Packet Name = " << content->getName() << " Packet Type = "<< content->getType() <<  std::endl;

    BinaryBuffer buf,buf2;

    unsigned char b1[3] = {'a','b','c'};
    unsigned char b2[5] = {'1','2','3','4','5'};
    unsigned char b3[3] = {'x','y','z'};

    BinaryBuffer buf3(b1, 3);
    fprintf(stderr, "Buffer = %s\n",buf3.data());

    fprintf(stderr, "Buffer = %s\n",buf.data());
    buf.append(b2,5);
    fprintf(stderr, "Buffer = %s\n",buf.data());

    buf.append(b3, 3);
    fprintf(stderr, "Buffer = %s\n",buf.data());

    buf = buf.append(b2,5).append(b3,3);
    fprintf(stderr, "Buffer = %s\n",buf.data());

    buf2 = buf3;
    fprintf(stderr, "Buffer2 = %s\n",buf2.data());

    buf2+buf;
    fprintf(stderr, "Buffer2 = %s\n",buf2.data());

    buf3 = (buf2+buf);
    fprintf(stderr, "Buffer3 = %s\n",buf3.data());

    BinaryBuffer buf4(buf2);
    fprintf(stderr, "Buffer4 = %s\n",buf4.data());

    buf4 = buf4.toBase64();
    fprintf(stderr, "Buffer4 = %s\n",buf4.data());

    buf4.toBase64();
    fprintf(stderr, "Buffer4 = %s\n",buf4.data());

    cout << "Hello World!" << endl;
    return 0;
}
