/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_zpr.hh"
#include "sim_zpr.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- ZiPpeR --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)pack file(s)/archive(s).""\n"
  "nc-mate zpr" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate zpr --peek <archive>""\n"
  "enlists item(s) in <archive>.""\n" +
  v3 + "nc-mate zpr --pack <file | folder> [pass] [chunk-size(MB)]""\n"
  "packs <file | dir> into <*.ZIP> archive.""\n"
  "if [pass] sets password on <*.ZIP> archive.""\n"
  "if [chunk-size(MB)] splits <*.ZIP> archive in nMB chunks.""\n" +
  v3 + "nc-mate zpr --unpack <TAR-BALL|*.ZIP|*.RAR|*.7Z|*.JAR|..> [pass]""\n"
  "exctracts archive.""\n"
  "[pass] exctracts password-protected archive.""\n" +
  v4 + "nc-mate zpr --pack " + quote("my-dir") + " " + quote("clock") + "\n"
  "packs 'my-dir' into <my-dir_packed_*.zip> archive.""\n"
  "sets 'clock' password on archive.""\n" +
  v4 + "nc-mate zpr --pack " + quote("my-dir") + " \"\" " + quote("2") + "\n"
  "packs 'my-dir' into <my-dir_packed_*.zip> archive.""\n"
  "doesn't set password on archive.""\n"
  "splits <my-dir_packed_*.zip> archive in 2MB chunks."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_zpr(argv[2], argv[3], argv[4], argv[5]);
  exit(0);
 }
 proc_zpr(argv[1], argv[2], argv[3], argv[4]);
}

// if (v1 == "--fat") {
//  cout <<
//  "file(s) must not be larger than 4GB.""\n"
//  "split large-file (> 4GB) into smaller chunks:""\n" +
//  cmd + "nc-mate zpr -z <LARGE-FILE>""\n"
//  // split --bytes=1024m FILE
//  "integrates chunked files into one whole:""\n" +
//  cmd + "nc-mate zpr -u <ZIP>"
//  // cat DIR/* > summed_FILE
//  << endl;
// }
//  "prepares file(s) (in terms of size) for transfering to/from FAT32 "
//  "file-system.""\n"
//  "if [dir] integrates chunked file(s) within <dir> into one whole.""\n"
//  "if [file] splits large-<file> (> 4GB) into smaller chunks.""\n" +

//  [OK] file is already prepared for transfering to FAT32
