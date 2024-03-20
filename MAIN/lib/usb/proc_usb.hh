/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_usb(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input/option
 [v3] attached-media
 [v4] temporary-list
 */
 string inp = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("[FAILED] ", "red");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 string v3 = arg3;
 if (v3 == "") v3 = "DISK_" + ts();
 vector<string> v4 = {};
 // message(s)
 string msg1 = "disk-space/file-system/USB-connected-device(s):""\n" +
 cmd + "lsblk""\n" +
 cmd + "lsusb""\n" +
 cmd + "df -hT""\n" +
 cmd + "sudo fdisk -l""\n"
 "MTP/PTP-storage (ex. android-device) | external-storage(s):""\n" +
 cmd + R"(ls /run/user/$UID/gvfs/)""\n" +
 cmd + R"(ls /media/$USER/)";
 string msg2 =
 inp + v2 + "\n" +
 out1 + v2 + "\n"
 "changing transferred-file(s) permission-mode(s) to fit in with EXT4 "
 "file-system...";
 string msg3 =
 inp + v2 + "\n" +
 out1 + v3 + "\n"
 "fixing NTFS-storage to fit in with <windows:namin'> style (NTFS-3G)...";
 string msg4 =
 inp + "/dev/" + v3 + "\n" +
 out1 + "/dev/" + v3 + "\n"
 "formatting USB-drive to NTFS and erasing file(s)...";
 string msg5 =
 inp + "/dev/" + v3 + "\n" +
 out1 + "/dev/" + v3 + "\n"
 "formatting USB-drive to FAT-32 and erasing file(s)...";
 string msg6 =
 inp + v2 + "\n" +
 out1 + v3 + "\n"
 "burning ISO image to portable-device...";
 string msg7 =
 inp + v2 + "\n" +
 out1 + v3 + ".iso""\n"
 "packing file(s) into ISO image...";
 // command(s)
 int e = 0;
 string cmd1 = "ls /dev/" + v2;
 string cmd2 = "sudo umount /dev/" + v2;
 string cmd3 = "sudo mkdir /media/$USER/" + v3;
 string cmd4 = "file -b --mime-type " + quote(v2);
 string cmd5 = "find " + quote(v2) + R"( -type f -exec chmod 664 {} \;)";
 string cmd6 = "find " + quote(v2) + R"( -type d -exec chmod 775 {} \;)";
 string cmd7 = "sudo mount -t ntfs-3g -o permissions /dev/" + v2 +
 " /media/$USER/" + v3;
 string cmd8 = "sudo mkfs.ext4 -F /dev/" + v2;
 string cmd9 = "sudo mkfs.ntfs -Ff /dev/" + v2;
 string cmd10 = "sudo mkfs.vfat -I /dev/" + v2;
 string cmd11 = "sudo dd bs=4M if=" + quote(v2) + " of=/dev/" + v3 +
 " conv=fdatasync";
 string cmd12 = "mkisofs -l -L -input-charset default -allow-lowercase "
 "-allow-multidot -o " + quote(v3) + ".iso " + quote(v2);
 // op(s)
 if (v1 == "--report") {
  cout << msg1 << endl;
  if (dir(v2)) {
   cout << endl;
   v4 = tree(v2, false);
   for (int i = 0; i < v4.size(); i++) {
    cmd4 = "echo -n `file -b --mime-type " + quote(v4[i]) + "`";
    note(mark("[NAME__", "blue") + shortq(uri(v4[i], "full-name")) + mark("]", "blue"));
    note(mark("[TYPE__", "blue"));
    sys(cmd4 + " 2>/dev/null");
    note(mark("]", "blue"));
    note(mark("[SIZE__", "blue") + str(fsize(v4[i])) + mark("B]\n", "blue"));
   }
  }
  if (not dir(v2) and exist(v2)) {
   cout << endl;
   cmd4 = "echo -n `file -b --mime-type " + quote(v2) + "`";
   note(mark("[NAME__", "blue") + shortq(uri(v2, "full-name")) + mark("]", "blue"));
   note(mark("[TYPE__", "blue"));
   sys(cmd4 + " 2>/dev/null");
   note(mark("]", "blue"));
   note(mark("[SIZE__", "blue") + str(fsize(v2)) + mark("B]\n", "blue"));
  }
 }
 if (v1 == "--ext4") {
  note(cmd + msg2);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd5 << endl;
   exit(1);
  }
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd6 << endl;
   exit(1);
  }
  cout <<
  out2 + "\n" +
  cmd + "chmod <MODE> <FILE>""\n"
  "directory       775""\n"
  "regular-file    664""\n"
  "application     755""\n"
  "permission-MODE(s) for some FILE(s) (ex. text/x-shellscript) need "
  "maintenance manually."
  << endl;
 }
 if (v1 == "--ntfs") {
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << mark("[WARNING] ", "yellow") + "no such file or directory." << endl;
   exit(1);
  }
  if (not isdigit(v2[v2.length() - 1])) {
   cout <<
   inp + "/dev/" + v2 + "\n" +
   mark("[WARNING] ", "yellow") +
   "provided the whole disk instead of a partition (e.g. /dev/" + v2 + "1)?"
   << endl;
   exit(1);
  }
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg3);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   exit(1);
  }
  e = sys(cmd7 + " 1>/dev/null 2>/dev/null");
  if (e) {
   e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
   if (e) {
    cout << err2 + cmd2 << endl;
    rm(v3);
    exit(1);
   }
  }
  cout << out2 << endl;
 }
 if ((v1 == "--format") and (v2 == "--ext4")) {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg4);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd8 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd8 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--format") and (v2 == "--ntfs")) {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg4);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd9 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd9 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--format") and (v2 == "--fat32")) {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg4);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd10 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd10 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if (v1 == "--burn") {
  sys("sudo '' 2>/dev/null");
  note(cmd + msg5);
  e = sys(cmd11 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd11 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if (v1 == "--iso") {
  note(cmd + msg6);
  e = sys(cmd12 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd12 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
}
