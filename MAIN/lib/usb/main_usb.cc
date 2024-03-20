/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

#include "proc_usb.hh"
#include "sim_usb.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("-- Universal Serial Bus --", "blue");
 string v2 = mark(" --help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "provides access to external storage(s) connected via USB.""\n"
  "nc-mint usb" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint usb --report [<file | dir>]""\n"
  "enlists USB-connected device(s). reveals path(s) to MTP/PTP-storage "
  "(ex. android-device).""\n"
  "[file | dir] displays properties (NAME, TYPE, SIZE in Byte) of "
//  "displays properties (absolute-path, file-type, size) of "
  "<file | dir>ectory""\n" +
  v3 + "nc-mint usb --ext4 <file/dir>""\n"
  "changes transferred-file(s) permission-mode(s) to fit in with EXT4 "
  "file-system.""\n"
  "changes <file> permission-mode to <664>.""\n"
  "changes <dir>ectory permission-mode to <775>.""\n" +
  v3 + "nc-mint usb --ntfs <device>""\n"
  "fixes NTFS-storage-<device> to fit in with <windows:namin'> style.""\n" +
  v3 + "nc-mint usb --format [--fat32 | --ntfs] <device>""\n"
  "[--fat32] formats USB-drive-<device> to FAT32. erases file(s).""\n" +
  "[--ntfs] formats USB-drive-<device> to NTFS. erases file(s).""\n" +
  v3 + "nc-mint usb --burn <device>""\n"
  "burns ISO-image to portable-<device> (ex. flash-memory, CD/DVD, ...).""\n" +
  v3 + "nc-mint usb --iso <file | dir>""\n"
  "makes ISO-image of <file/dir>."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_usb(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_usb(argv[1], argv[2], argv[3]);
}
