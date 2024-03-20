/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

#include "proc_dns.hh"
#include "sim_dns.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- Domain Name System --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("OBSOLETED", "yellow");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n" +
  v4 + "\n"
  "nc-mate dns" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate dns --bypass""\n" +
  v3 + "nc-mate dns --reset"
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_dns(argv[2]);
  exit(0);
 }
 proc_dns(argv[1]);
}
