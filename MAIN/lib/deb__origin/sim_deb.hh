void sim_deb(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] source
 [v4] target
 [cmd] color-command
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string err = color("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = "/usr/lib/nc-mate-lib/asset/helloworld_1.0-1";
 string v4 = "~/Documents/";
 // command(s)
 string cmd1 = "dpkg -f " + quote(v2);
 string cmd2 = "dpkg-deb --build " + quote(v2);
 string cmd3 = "sudo dpkg --install " + quote(v2);
 string cmd4 = "sudo apt-get install -f -y";
 string cmd5 =
 "sudo dpkg --remove `dpkg -f " + quote(v2) + " Package 2>/dev/null` ";
 string cmd6 = "sudo dpkg --remove " + quote(v2);
 // op(s)
 if (v1 == "--sample") {
  cout <<
  cmd + "rm " + v4 + "/helloworld_1.0-1""\n" +
  cmd + "cp " + v3 + " " + v4
  << endl;
 }
 if (v1 == "--what") {
  cout <<
  err + "if apt can't find the archive for incomplete-installed package""\n" +
  cmd + "dpkg --remove --force-remove-reinstreq" +
  " `dpkg -f " + quote(v2) + " Package 2>/dev/null`" + "\n" +
  err + "if your system has broken dependencies""\n" +
  cmd + cmd4 + "\n" +
  err + "if could not get lock /var/lib/dpkg/lock""\n" +
  cmd + "sudo init 6""\n" +
  cmd + cmd1
  << endl;
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
  "more details:""\n"
  "https://ubuntuforums.org/showthread.php?t=910717""\n"
  "https://www.debian.org/doc/manuals/maint-guide/build.en.html"
  << endl;
  exit(0);
 }
 if (v1 == "--build") cout << cmd + cmd2 << endl;
 if (v1 == "--inst") {
  cout <<
  cmd + cmd3 + "\n" +
  cmd + cmd4
  << endl;
 }
 if (v1 == "--rem") {
  if (uri(v2)[3] == ".deb") cout << cmd + cmd5 << endl;
  if (uri(v2)[3] != ".deb") cout << cmd + cmd6 << endl;
 }
}
