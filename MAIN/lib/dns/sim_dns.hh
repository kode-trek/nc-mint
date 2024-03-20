/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void sim_dns(string arg1) {
 /* variable(s)
 [v1] operation
 */
 string cmd = mark("[] ", "blue");
 string out = mark("DONE.", "green");
 string err = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "sudo rm /etc/resolv.conf";
 string cmd2 =
 "sudo cp /usr/lib/nc-mint-lib/asset/dns/resolv.conf.1 /etc/resolv.conf";
 string cmd3 = ". ~/.bashrc";
 string cmd4 =
 "sudo cp /usr/lib/nc-mint-lib/asset/dns/resolv.conf.0 /etc/resolv.conf";
 // op(s)
 if (v1 == "--bypass") {
  cout <<
  cmd + cmd1 + "\n" +
  cmd + cmd2
  << endl;
 }
 if (v1 == "--reset") {
  cout <<
  cmd + cmd1 + "\n" +
  cmd + cmd4
  << endl;
 }
}
