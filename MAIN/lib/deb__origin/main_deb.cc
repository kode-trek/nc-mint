/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_deb.hh"
#include "sim_deb.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- DEBian package --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "builds/(un-)installs debian-package.""\n"
  "nc-mate deb" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate deb --sample""\n"
  "provides sample 'hello-world' <pkg-dir> in '~'.""\n" +
  v3 + "nc-mate deb --what <*.DEB>""\n"
  "displays properties of <*.DEB> debian-package.""\n" +
  v3 + "nc-mate deb --tip""\n" // remove this section and add a manual pdf to sample
  "helps with building <*.DEB> debian-package.""\n" +
  v3 + "nc-mate deb --build <pkg-dir>""\n"
  "packs <pkg-dir> into <*.DEB> debian-package.""\n" +
  v3 + "nc-mate deb --inst <*.DEB>""\n"
  "installs application in <*.DEB>.""\n" +
  v3 + "nc-mate deb --rem <*.DEB | app>""\n"
  "un-installs <app>lication in <*.DEB>."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_deb(argv[2], argv[3]);
  exit(0);
 }
 proc_deb(argv[1], argv[2]);
}
