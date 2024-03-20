#include "proc_zpr.hpp"
#include "sim_zpr.hpp"
int main(int argc, char* argv[]) {
 if ((string) argv[1] == "") {
  cout <<
  "-- Z i P pe R --""\n"
  "(un-)pack file(s)/archives.""\n"
  "\n"
  "nc-mate zpr --help"
  << endl;
  exit(0);
 }
 if ((string) argv[1] == "--help") {
  cout <<
  "-- Z i P pe R --""\n"
  "(un-)pack file(s)/archives.""\n"
  "\n"
  "[PATTERN] nc-mate zpr -z <file | dir> [pass] [chunk-size(MB)]""\n"
  "packs <file | dir> into <*.ZIP> archive.""\n"
  "if [pass] sets password on <*.ZIP> archive.""\n"
  "if [chunk-size] splits <*.ZIP> archive in nMB chunks.""\n"
  "\n"
  "[PATTERN] nc-mate zpr -u <*.ZIP|TAR-BALL|*.RAR|*.7Z|*.JAR| .. > [pass]""\n"
  "exctracts archive.""\n"
  "if [pass] exctracts password-protected archive.""\n"
  "\n"
  "[EXAMPLE] nc-mate zpr -z 'my-dir' clock""\n"
  "packs 'my-dir' into <*.zip> archive.""\n"
  "sets password 'clock' on archive.""\n"
  "\n"
  "[EXAMPLE] nc-mate zpr -z 'my-dir' \"\" 2""\n"
  "packs 'my-dir' into <*.zip> archive.""\n"
  "won't set password on archive.""\n"
  "splits <*.zip> archive in 2MB chunks."
  << endl;
  exit(0);
 }
 if ((string) argv[1] == "--sim") {
  sim_zpr(argv[2], argv[3], argv[4], argv[5]);
  exit(0);
 }
 proc_zpr(argv[1], argv[2], argv[3], argv[4]);
}
