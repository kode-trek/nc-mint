/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_deb(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] source
 [v4] target
 */
 string inp = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 string err2 = mark("[WARNING] ", "yellow");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = "/usr/lib/nc-mate-lib/asset/helloworld_1.0-1";
 string v4 = "~";
 // message(s)
 string msg1 =
 out1 + v4 + "/helloworld_1.0-1""\n" +
 cmd + "providing sample package-directory...";
 string msg2 =
 inp + uri(v2, "full-name") + "\n" +
 out1 + uri(v2, "full-name") + ".deb""\n" +
 cmd + "packing directory into debian-package...";
 string msg3 =
 inp + uri(v2, "full-name") + "\n" +
 cmd + "installing application in debian-package (might take long)...";
 string msg5 =
 inp + uri(v2, "full-name") + "\n" +
 cmd + "un-installing application in debian-package (might take long)...";
 string msg6 =
 inp + uri(v2, "full-name") + "\n" +
 cmd + "un-installing application (might take long)...";
 // command(s)
 int e = 0;
 string cmd1 = "dpkg -f " + quote(v2);
 string cmd2 = "dpkg-deb --build " + quote(v2);
 string cmd3 = "sudo dpkg --install " + quote(v2);
 string cmd4 = "sudo apt-get install -f -y";
 string cmd5 =
 "sudo dpkg --remove `dpkg -f " + quote(v2) + " Package 2>/dev/null` ";
 string cmd6 = "sudo dpkg --remove " + quote(v2);
 // op(s)
 if (v1 == "--sample") {
  note(msg1);
  rm(v4 + "/helloworld_1.0-1");
  e = cp(v3, v4);
  if (e) {
   cout <<
   err1 + "un-able to copy files.""\n"
   "[source] " + v3 + "\n"
   "[target] " + v4
   << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if (v1 == "--what") {
  sys("dpkg -f " + quote(v2));
  cout << endl <<
  err2 + "if apt can't find the archive for incomplete-installed package""\n" +
  cmd + "dpkg --remove --force-remove-reinstreq" +
  " `dpkg -f " + quote(v2) + " Package 2>/dev/null`" + "\n" +
  err2 + "if your system has broken dependencies""\n" +
  cmd + cmd4 + "\n" +
  err2 + "if could not get lock /var/lib/dpkg/lock""\n" +
  cmd + "sudo init 6"
  << endl;
  e = sys(cmd1);
  if (e) exit(1);
  exit(0);
 }
 if (v1 == "--tip") {
  cout <<
  "[permission-mode]""\n"
  "directory       775""\n"
  "regular-file    664""\n"
  "application     755""\n"
  "\n"
  "[debian-directory]""\n"
  "<pkg-dir>/DEBIAN/control""\n"
  "<pkg-dir>/DEBIAN/preinst""\n"
  "<pkg-dir>/DEBIAN/postinst""\n"
  "<pkg-dir>/usr/bin/""\n"
  "<pkg-dir>/usr/lib/""\n"
  "...""\n"
  "\n"
  "read more:""\n"
  "https://ubuntuforums.org/showthread.php?t=910717""\n"
  "https://www.debian.org/doc/manuals/maint-guide/build.en.html"
  << endl;
  exit(0);
 }
 if (v1 == "--build") {
  note(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--inst") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  apt("`dpkg -f " + quote(v2) + " Package 2>/dev/null`");
  note(msg3);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd3 << endl;
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--rem") {
  if (uri(v2, "extension") == ".deb") {
   apt("`dpkg -f " + quote(v2) + " Package 2>/dev/null`");
   note(msg5);
   e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
   if (e) {
    cout << err1 + cmd5 << endl;
    exit(1);
   }
  }
  if (uri(v2, "extension") != ".deb") {
   apt(v2);
   note(msg6);
   e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
   if (e) {
    cout << err1 + cmd6 << endl;
    exit(1);
   }
  }
  cout << out2 << endl;
 }
}

//	string inp = arg2;
//	int l = strlen(inp.c_str());
//	if (inp[l - 1] == '/') inp = inp.substr(0, l - 1);
