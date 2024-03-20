/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_wifi.hh"
#include "sim_wifi.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- WIFI --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "establishes/disbands WiFi connection(s).""\n"
  "nc-mint wifi" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint wifi --list [--info]""\n"
  "enlists available WiFi hotspot(s).""\n" +
  v3 + "nc-mint wifi --connect <ssid> <pass>""\n"
  "connects to WiFi hotspot.""\n" +
  v3 + "nc-mint wifi --forget <name>""\n"
  "removes WiFi connection."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_wifi(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_wifi(argv[1], argv[2], argv[3]);
}
