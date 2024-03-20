#	dep-hell
sudo apt-get install libssl-dev
sudo apt-get install liblzo2-dev
sudo apt-get install libpam0g-dev

#	create
tar xf openvpn-2.4.8.tar.gz
cd openvpn-2.4.8/
sudo ./configure && sudo make && sudo make install

#	start deamon
sudo openvpn --config "$1"
#[Ctrl + C] to STOP
