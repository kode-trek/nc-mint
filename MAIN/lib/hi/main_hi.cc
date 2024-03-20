/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

#include "proc_hi.hh"
#include "sim_hi.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- HI --", "blue");
 string v2 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "--help") {
  cout <<
  v1 + "\n"
  "displays properties of this computer (node).""\n" +
  v2 + "nc-mint hi""\n"
  "displays IP, clock, etc."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_hi();
  exit(0);
 }
 proc_hi();
}
