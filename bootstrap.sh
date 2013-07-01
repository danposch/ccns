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
	echo "Boost installation finished."
else
	echo "Boost already downloaded."
	echo "To download Boost again please delete the ccns/boost_* folder."
	echo "Press [Enter] key to continue.."
	read dummy < /dev/tty
fi

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
	echo "Crypto++ installation finished."
else
	echo "Crypto++ already downloaded."
	echo "To download Crypto++ again please delete the ccns/boost_* folder."
	echo "Press [Enter] key to continue.."
	read dummy < /dev/tty
fi

## End Crypto ++

## Installing libXml2

echo "Installing libXml2"

LIBXML_DIR="libxml2-2.9.1"
if [ ! -d "$LIBXML_DIR" ]; then
	wget https://git.gnome.org/browse/libxml2/snapshot/libxml2-2.9.1.tar.gz
	tar xzvf libxml2-2.9.1.tar.gz
	rm libxml2-2.9.1.tar.gz
	cd ./libxml2-2.9.1

	./autogen.sh --prefix=/usr/local
	./configure
	make
	make install
	cd ..
	echo "libXml2 installation finished."
else
	echo "libXml2 already downloaded."
	echo "To download libXml2 again please delete the ccns/libxml* folder."
	echo "Press [Enter] key to continue.."
	read dummy < /dev/tty
fi

## End libXml2

##finally calling ldconfig

echo "Calling ldconfig.."
ldconfig

echo "Install-Script finished."
