/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_vbox(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] VirtalBox-version
 [v3] running-virtual-machine(s)
 [v4] VirtualBox-bin-file
 [v5] VirtualBox-download-link
 [v6] VirtualBox_Extension_Pack-bin-file
 [v7] VirtualBox_Extension_Pack-download-link
 */
 string cmd = mark("[] ", "blue");
 string out1 = mark("DONE.", "green");
 string out2 = mark("[OK] ", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 string err2 = mark("[WARNING] ", "yellow");
 //
 string v1 = arg1;
 string v2 = "6.1";
 string v3 = ts();
 string v4 = "virtualbox-6.1_6.1.32-149290_Ubuntu_eoan_amd64.deb";
 string v5 = "https://download.virtualbox.org/virtualbox/6.1.32/" + v4;
 string v6 = "Oracle_VM_VirtualBox_Extension_Pack-6.1.32-149290.vbox-extpack";
 string v7 = "https://download.virtualbox.org/virtualbox/6.1.32/" + v6;
 // message(s)
 string msg1 = "retrieving and installing VirtualBox (might take long)...";
 string msg2 = "un-installing VirtualBox...";
 // command(s)
 int e = 0;
 string cmd1 = "wget --spider " + quote(v5);
 string cmd2 = "wget --spider " + quote(v7);
 string cmd3 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v5);
 string cmd4 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v7);
 string cmd5 = "sudo gdebi -n " + quote(v4);
 string cmd6 =
 "echo y | sudo vboxmanage extpack install --replace " + quote(v6);
 string cmd7 = "sudo gpasswd -a " + uname() + " vboxusers";
 string cmd8 = "echo -n `vboxmanage list runningvms` > " + v3;
 string cmd9 = "vboxmanage list runningvms";
 string cmd10 =
 "ps aux | grep -F /usr/lib/virtualbox/VirtualBox | grep -Fv grep > " + v3;
 string cmd11 =
 "ps aux | grep -F /usr/lib/virtualbox/VirtualBox | grep -Fv grep";
 string cmd12 = "sudo apt-get remove -y virtualbox-" + v2;
 string cmd13 = "vboxmanage --version";
 // op(s)
 if (v1 == "--inst") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) cout << err2 + cmd1 << endl;
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) cout << err2 + cmd2 << endl;
  apt("virtualbox-" + v2);
  note(cmd + msg1);
  e = cd("~");
  if (e) {
   cout << err1 + "not able to switch path: " + quote("~") << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   exit(1);
  }
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd6 << endl;
   exit(1);
  }
  e = sys(cmd7 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd7 << endl;
   exit(1);
  }
  e = sys(cmd13 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + "VirtualBox is not installed properly." << endl;
   exit(1);
  }
  cout << out1 << endl;
  cout <<
  "Restart system for the changes to take effect.""\n" +
  cmd + "sudo init 6"
  << endl;
 }
 if (v1 == "--rem") {
  e = sys(cmd13 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << out2 + "virtualbox-" + v2 + " is un-installed." << endl;
   exit(0);
  }
  sys(cmd8);
  if (fsize(v3) != 0) {
   rm(v3);
   cout << err2 + "running VM(s) found:" << endl;
   sys(cmd9);
   exit(1);
  }
  sys(cmd10);
  if (fsize(v3) != 0) {
   rm(v3);
   cout << err2 + "VirtualBox is currently running:" << endl;
   sys(cmd11);
   cout << err2 + "Close it and try again in ten seconds." << endl;
   exit(1);
  }
  rm(v3);
  apt("virtualbox-" + v2);
  note(cmd + msg2);
  e = sys(cmd12 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + "virtualbox is not un-installed properly." << endl;
   exit(0);
  }
  cout << out1 << endl;
 }
}

//	string cmd4 = (string)
//	"cd /; sudo apt-get autoremove --purge virtualbox* -y; cd " + here;
//		cout << "[] needs to administer manually:""\n""> " << cmd4 << endl;
