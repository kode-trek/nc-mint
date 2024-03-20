#include "proc_vbox.hpp"
#include "sim_vbox.hpp"
int main(int argc, char* argv[]) {
 if ((string) argv[1] == "") {
  cout <<
  "-- V irtual B O X --""\n"
  "(un-)installs virtualbox (virtual-machine).""\n"
  "\n"
  "nc-mate vbox --help"
  << endl;
  exit(0);
 }
 if ((string) argv[1] == "--help") {
  cout <<
  "-- V irtual B O X --""\n"
  "(un-)installs virtualbox (virtual-machine).""\n"
  "\n"
  "[PATTERN] nc-mate vbox --inst""\n"
  "installs latest stable version of virtualbox.""\n"
  "\n"
  "[PATTERN] nc-mate vbox --rem""\n"
  "un-installs virtualbox."
  << endl;
  exit(0);
 }
 if ((string) argv[1] == "--sim") {sim_vbox(argv[2], argv[3]); exit(0);}
 proc_vbox(argv[1], argv[2]);
}
