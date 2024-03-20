#include "heads-up.h"

int main(int argc, char* argv[]) {
	if ((string) argv[1] == "") {
		cout << "no argument(s) supplied." << endl;
		cout << "nc-mate wifi --help" << endl;
		exit(1);
	}
	//
	if ((string) argv[1] == "--help") {
		cout << "stablishes connections to available WiFi hotspots." << endl;
		cout << endl;
		cout << "[PATTERN] nc-mate wifi --connect" << endl;
		cout << "connects to WiFi hotspot." << endl;
		cout << endl;
		cout << "[PATTERN] nc-mate wifi --forget" << endl;
		cout << "removes WiFi connection." << endl;
		exit(1);
	}
	//
	string fname = "";
	string w_if = "";
	string id = "";
	string pass = "";
	//
	if ((string) argv[2] == "--connect") {
		// displays available wifi hotspot(s)
		sys("nmcli d wifi list");
		// elicits wifi interface(s)
		fname = "." + ts();
		sys(R"(iw dev | awk '$1=="Interface"{print $2}' > )" + fname);
		w_if = readln_txt(fname).txt;
		rm(fname);
		// makes a list of all SSID(s)
		cout << endl << "----------------------" << endl;
		cout << "available hotspot(s): " << endl;
		cout << "----------------------" << endl;
		sys("nmcli -t -f ssid dev wifi");
		cout << endl << "SSID: "; cin >> id;
		// requires password
		SetStdinEcho(false);
		cout << "PASS: "; cin >> pass;
		SetStdinEcho(true);
		// tryin to connect
		disp("\nconnecting to WiFi...");
		sys("nmcli d disconnect " + id + " 1>/dev/null 2>/dev/null");
		sys("nmcli d wifi connect " + id + " ifname " + w_if + " password " + pass);
		// in case of wrong password, GUI interface would show up.
		exit(1);
	}
	//
	if ((string) argv[2] == "--forget") {
		cout << "list of connection(s):" << endl;
		cout << "----------------------" << endl;
		sys("nmcli -t -f Name con show");
		cout << endl << "pick an item to remove. NAME: "; cin >> id;
		sys("nmcli con delete " + id);
	}
}
