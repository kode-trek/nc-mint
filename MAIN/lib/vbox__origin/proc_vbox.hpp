void proc_vbox(string arg1, string arg2) {
 //var(s)
 int c = 0;
 string op = arg1;
 string vm = ts();
 string here = pwd();
 string v_nam = (string) "virtualbox-6.1_6.1.18-142142~Ubuntu~eoan_amd64.deb";
 string v_lnk = (string) "https://download.virtualbox.org/virtualbox/6.1.18/" +
 v_nam;
 //msg(s)
 string msg1 = (string) "[] retrieving <virtualbox*.deb> from ""\n" +
 squote(v_lnk) + "...";
 string msg2 = (string) "[] installing virtualbox (might take long)...";
 //cmd(s)
 string cmd1 = (string) "wget " +
 "-q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v_lnk);
 string cmd2 = (string) "sudo gdebi -n " + quote(v_nam);
 string cmd3 = (string) "virtualbox --help";
 string cmd4 = (string)
 "cd /; sudo apt-get autoremove --purge virtualbox* -y; cd " + here;
 //op(s)
 if (op == "--inst") {
  ctrl_c();
  sys("sudo apt-get clean -y 1>/dev/null 2>/dev/null"); //traps sudo-pass
  disp(msg1);
  c = cd("~");
  if (not c) {
   cout << "HALTED.""\n""[FAILED] to switch path:""\t" << quote("~") << endl;
   exit(1);
  }
  c = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd1 << endl; exit(1);}
  cout << "DONE." << endl;
  apt();
  disp(msg2);
  c = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd2 << endl; exit(1);}
  c = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (c) {
   cout << "HALTED.""\n""[FAILED] to install virtualbox." << endl;
   exit(1);
  }
  cout << "DONE." << endl;
 }
 if (op == "--rem") {
  c = sys("vboxmanage --version 1>/dev/null 2>/dev/null");
  if (c) {cout << "[OK] virtualbox is un-installed." << endl; exit(0);}
  sys("echo -n `vboxmanage list runningvms` > " + vm);
  if (fsize(vm) != 0) {
   rm(vm);
   cout << "[FAILED] running VM(s) found:" << endl;
   sys("vboxmanage list runningvms");
   exit(1);
  }
  rm(vm);
  cout << "[] needs to administer manually:""\n""> " << cmd4 << endl;
 }
}
