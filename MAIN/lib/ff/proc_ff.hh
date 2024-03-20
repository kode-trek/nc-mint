/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void proc_ff(string arg1, string arg2) {
 /* variable(s)
 [v1] upgrade
 [v2] reset
 [v3] FireFox-download-link
 [v4] FireFox-tarball
 */
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("[WARNING] ", "yellow");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 =
 R"(https://download.mozilla.org/?)"
 R"(product=firefox-latest&os=linux64&lang=en-US)";
 string v4 = "firefox-latest.tar.bz2";
 // message(s)
 string msg1 = cmd + "retrieving latest stable version of firefox...";
 string msg2 =
 cmd + "erasing all JSON data-bases (bookmarks, settings, etc)...";
 string msg3 = cmd + "installing firefox...";
 // command(s)
 int e = 0;
 string cmd1 = "wget -qc --no-check-certificate --tries=0 --read-timeout=32 " +
 quote(v3) + " -O" + quote(v4);
 string cmd2 = "sudo rm -rf /usr/lib/firefox /usr/lib/firefox-a*"
 " /usr/bin/firefox";
 string cmd3 = "sudo tar -xf " + quote(v4) + " -C /usr/lib/";
 string cmd4 = "sudo ln -s /usr/lib/firefox/firefox /usr/bin/";
 string cmd5 = "firefox --version";
 // op(s)
 if (v1 == "--upgrade") {
  if (exist("~/firefox-latest.tar.bz2")) {
   cout <<
   out1 + "~/firefox-latest.tar.bz2""\n" +
   err1 + "file(s) exist."
   << endl;
   pausee();
  }
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(msg1);
  e = cd("~");
  if (e) {
   cout <<
   err2 + "directory inaccessible.""\n" +
   out1 + "~"
   << endl;
   exit(1);
  }
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd1 << endl;
   exit(1);
  }
  cout << out2 << endl;
  if (v2 == "--reset") {
   note(msg2);
   rm("~/.mozilla/");
   cout << out2 << endl;
  }
  note(msg3);
  sys(cmd2 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   exit(1);
  }
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd4 << endl;
   exit(1);
  }
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + "FireFox is not upgraded properly." << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
}
