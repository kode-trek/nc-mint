/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_vbox.hh"
#include "sim_vbox.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- V irtual B O X --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)installs VirtualBox (virtual-machine).""\n"
  "nc-mate vbox" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate vbox --inst""\n"
  "installs VirtualBox.""\n" +
  v3 + "nc-mate vbox --rem""\n"
  "un-installs VirtualBox."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_vbox(argv[2]);
  exit(0);
 }
 proc_vbox(argv[1]);
}
