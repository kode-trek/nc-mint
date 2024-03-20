/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_2dy(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] time-zone
 */
 string cmd = mark("[] ", "blue");
 string out1 = mark("DONE.", "green");
 string err1 = mark("[FAILED] ", "red");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = arg2;
 // message(s)
 string msg1 = "setting clock...";
 // command(s)
 int e = 0;
 string cmd1 = "date";
 string cmd2 = "timedatectl list-timezones";
 string cmd3 = "sudo timedatectl set-timezone " + v2;
 // op(s)
 if (v1 == "--show") {
  e = sys(cmd1 + " 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   exit(1);
  }
 }
 if (v1 == "--list") {
  e = sys(cmd2 + " 2>/dev/null | less");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
 }
 if (v1 == "--set") {
  sys("sudo '' 2>/dev/null"); // traps sudo-password
  note(cmd + msg1);
  e = sys(cmd3 + " 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   exit(1);
  }
  cout << out1 << endl;
 }
}
