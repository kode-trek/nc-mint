/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void proc_dns(string arg1) {
 /* variable(s)
 [v1] operation
 */
 string cmd = mark("[] ", "blue");
 string out = mark("DONE.", "green");
 string err = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 // message(s)
 string msg1 = cmd + "fixing nameservers in '/etc/resolv.conf'...";
 string msg2 =
 cmd + "rolling nameserver in '/etc/resolv.conf' back to '127.0.0.X'...";
 // command(s)
 int e = 0;
 string cmd1 = "sudo rm /etc/resolv.conf";
 string cmd2 =
 "sudo cp /usr/lib/nc-mint-lib/asset/dns/resolv.conf.1 /etc/resolv.conf";
 string cmd3 = ". ~/.bashrc";
 string cmd4 =
 "sudo cp /usr/lib/nc-mint-lib/asset/dns/resolv.conf.0 /etc/resolv.conf";
 // op(s)
 if (v1 == "--bypass") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd2 << endl;
   exit(1);
  }
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd3 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (v1 == "--reset") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(msg2);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd4 << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
