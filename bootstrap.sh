#! /bin/sh
### Install-Script for third-party libraries

ROOT_UID="0"

#Check if run as root
if [ `whoami` != root ]; then
    echo "Please run this script as root or using sudo"
    exit
fi

echo "Installing third party libraries"

## Installing Boost Library

echo "Installing Boost.."

BOOST_DIR="./boost_1_53_0"
if [ ! -d "$BOOST_DIR" ]; then
	echo "Fetching Boost C++ Library"
    wget http://sourceforge.net/projects/boost/files/boost/1.53.0/boost_1_53_0.tar.gz
    tar xzvf boost_1_53_0.tar.gz
    rm boost_1_53_0.tar.gz
	cd ./boost_1_53_0
	./bootstrap.sh
	./b2 install --prefix=/usr/local
	cd ..
else
	echo "Boost already downloaded."
	echo "To download Boost again please delete the ccns/boost_* folder."
	read -p "Press [Enter] key to continue"
fi

echo "Boost installation finished."

## End Boost

## Installing Crypto++

echo "Installing Crypto++"

CRYPTO_DIR="./crypto++"
if [ ! -d "$CRYPTO_DIR" ]; then
	wget http://prdownloads.sourceforge.net/cryptopp/cryptopp562.zip
	unzip cryptopp562.zip  -d ./crypto++
	rm cryptopp562.zip
	cd ./crypto++

	# edit config to build static and dynmaic lib
	line="# CXXFLAGS += -fPIC"
	rep="CXXFLAGS += -fPIC"
	sed -i "s/${line}/${rep}/g" ~/ccns/crypto++/GNUmakefile

	# edit config to build without debug symbols	
	line="CXXFLAGS = -DNDEBUG -g -O2"
	rep="CXXFLAGS = -DNDEBUG -O2"
	sed -i "s/${line}/${rep}/g" ~/ccns/crypto++/GNUmakefile

	make libcryptopp.a libcryptopp.so cryptest.exe

	make install PREFIX=/usr/local
	cd ..
else
	echo "Crypto++ already downloaded."
	echo "To download Crypto++ again please delete the ccns/boost_* folder."
	read -p "Press [Enter] key to continue"
fi

echo "Crypto++ installation finished."

## End Crypto ++

##finally calling ldconfig

ldconfig

echo "Install-Script finished."
