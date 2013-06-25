### Install-Script for third-party libraries

echo "Installing third party libraries"

## Installing Boost Library

echo "Installing Boost.."

BOOTSTRAP_DIR="./boost_1_53_0"
if [ ! -d "$BOOTSTRAP_DIR" ]; then
	echo "Fetching Boost C++ Library"
    wget http://sourceforge.net/projects/boost/files/boost/1.53.0/boost_1_53_0.tar.gz
    tar xzvf boost_1_53_0.tar.gz
    rm boost_1_53_0.tar.gz
else
	echo "Boost already downloaded."
	echo "To download Boost again please delete the ccns/boost_* folder."
	read -p "Press [Enter] key to continue"
fi

echo "Boost installation finished."

## End Boost

echo "Install-Script finished."
