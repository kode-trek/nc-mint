/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

#include "proc_snf.hh"
#include "sim_snf.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- SNiFfer --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "searches for file(s) or certain phrase(s) inside file(s).""\n"
  "nc-mint snf" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint snf --file <file-name> [<dir>=PWD]""\n"
  "looks for file(s) or folder(s) by RegEx <file-name> within <dir>.""\n" +
  v3 + "nc-mate snf --text <phrase> [<dir>=PWD]""\n"
  "looks for <phrase> by RegEx inside all file(s) within <dir>.""\n"
  + v4 + "nc-mate snf --file '*[.]xml'""\n"
  "looks for all '.xml' file(s) within current-directory recursively."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_snf(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_snf(argv[1], argv[2], argv[3]);
}
