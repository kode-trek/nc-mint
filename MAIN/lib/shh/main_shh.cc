/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

#include "proc_shh.hh"
#include "sim_shh.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- SHush History --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "turns off terminal command-history.""\n"
  "nc-mint shh" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint shh --clear""\n"
  "clears command-history when terminal-session ends."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_shh(argv[2]);
  exit(0);
 }
 proc_shh(argv[1]);
}
