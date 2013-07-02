#ifndef ICIPHER_H
#define ICIPHER_H

namespace ccns
{
    namespace crypto
    {
        class ICipher
        {
        public:
            enum ICipherType{AES};

            virtual ~ICipher(){}

            virtual ICipherType getType() = 0;

            virtual void encrypt();
            virtual void decrypt();

        };
    }
}
#endif // ICIPHER_H
