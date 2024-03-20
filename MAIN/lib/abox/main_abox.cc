/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_abox.hh"
#include "sim_abox.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- Android virtual BOX --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)installs Genymotion (android-emulator).""\n"
  "nc-mate abox" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate abox --inst""\n"
  "installs Genymotion (android-emulator) which deponds on VirtualBox.""\n" +
  v3 + "nc-mate abox --rem""\n"
  "un-installs Genymotion.""\n" +
  v3 + "nc-mate abox --add <.APK>""\n"
  "installs application in <.APK> package on virtual android-os. those <.APK> "
  "packages could be obtained from:""\n"
  R"(https://apps.evozi.com/apk-downloader/)""\n"
  R"(https://apkdl.in)""\n"
  R"(https://apkdl.net)""\n"
  R"(https://apkpure.com)""\n" +
  v3 + "nc-mate abox --del <apk-id>""\n"
  "un-installs android application by APK-ID.""\n" +
  v4 + "nc-mate abox --del " + quote("com.karmangames.spades")
  << endl;
  // the last two sections could be relocated to maunal.
  exit(0);
 }
 if(str(argv[1]) == "--sim") {
  sim_abox(argv[2], argv[3]);
  exit(0);
 }
 proc_abox(argv[1], argv[2]);
}
