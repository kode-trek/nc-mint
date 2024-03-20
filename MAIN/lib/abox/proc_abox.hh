/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void proc_abox(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] android-application-name
 [v3] genymotion-bin-file
 [v4] genymotion-download-link
 */
 string cmd = mark("[] ", "blue");
 string out = mark("DONE.", "green");
 string err1 = mark("[FAILED] ", "red");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 string err3 = mark("[WARNING] ", "yellow");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = "genymotion-3.2.1-linux_x64.bin"; // check for update regulary
 string v4 = "https://dl.genymotion.com/releases/genymotion-3.2.1/" + v3;
 // message(s)
 string msg1 = "retrieving Genymotion...";
 string msg2 = "installing Genymotion...";
 string msg3 = "un-installing Genymotion...";
 // command(s)
 int e = 0;
 string cmd1 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v4); // wget same pattern for entire repos?
 string cmd2 = "chmod 755 " + quote(v3);
 string cmd3 = "./" + quote(v3) + " -y";
 string cmd4 = "sudo rm /usr/bin/adb"; // cautious?
 string cmd5 = "sudo cp genymotion/tools/adb /usr/bin/"; // /usr/bin/nc-mint*/
 string cmd6 = "adb install " + quote(v2);
 string cmd7 = "adb uninstall " + quote(v2);
 // op(s)
 if (v1 == "--inst") {
  sys("sudo '' 2>/dev/null");// traps sudo-password
  e = cd("~");
  if (e) {
   cout << err1 + "directory not found: [out]" + quote("~") << endl; // check for same format CD CP MV
   exit(1);
  }
  note(cmd + msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd1 << endl;
   exit(1);
  }
  cout << out << endl;
  apt(); // need troublesome package?
  note(cmd + msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   exit(1);
  }
  e = sys(cmd3);
  if (e) exit(1);
  sys(cmd4 + " 1>/dev/null 2>/dev/null"); // rm(file)?
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   exit(1);
  }
 }
 if (v1 == "--rem") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg3);
//  sys("~/genymotion-*.bin --uninstall");
  rm("~/genymotion");
  rm("~/.Genymobile");
  rm("~/.config/Genymobile/Genymotion.conf");
  sys(cmd4 + " 1>/dev/null 2>/dev/null");
  cout <<
  out + "\n" +
  err3 + "To remove all programs used by 'Genymotion Desktop', you may also" // virtualbox could manually be removed:
  " un-install 'VirtualBox'.""\n" +
  cmd + "nc-mate vbox --rem"
  << endl;
 }
 if (v1 == "--add") sys(cmd6);
 if (v1 == "--del") sys(cmd7);
}
