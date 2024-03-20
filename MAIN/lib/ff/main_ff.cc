/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

#include "proc_ff.hh"
#include "sim_ff.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- FireFox --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "upgrades FireFox.""\n"
  "nc-mint ff" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint ff --upgrade [--reset]""\n"
  "upgrades Mozilla FireFox to the latest stable version.""\n"
  "[--reset] deletes all JSON databases (bookmarks, settings, ...)."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_ff(argv[2], argv[3]);
  exit(0);
 }
 proc_ff(argv[1], argv[2]);
}
