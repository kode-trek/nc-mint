void proc_wifi(string arg1, string arg2, string arg3) {
 /*  variable(s)
 [v1] operation
 [v2] hotspot-ID
 [v3] hotspot-password
 [inp] color-input
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string err1 = color("red", "[FAILED] ");
 string err2 = color("red", "HALTED.""\n""[FAILED] ");
 string out = color("green", "DONE.");
 string v1 = arg1;
 string v2 = arg2;
 string v3 = arg3;
 // message(s)
 string msg1 = "establishing connection (GUI might show up)...";
 string msg2 = "removing " + quote(v2) + " connection...";
 // command(s)
 int e = 0;
 string cmd1 = "nmcli d wifi list";
 string cmd2 = "nmcli -t -f ssid dev wifi";
 string cmd3 = "nmcli d disconnect "
 R"(`iw dev | awk '$1=="Interface"{print $2}'`)";
 string cmd4 = "nmcli d wifi connect " + quote(v2) + " ifname " +
 R"(`iw dev | awk '$1=="Interface"{print $2}'` password )" + quote(v3);
 string cmd5 = "nmcli con delete " + quote(v2);
 // op(s)
 if (v1 == "--disp") {
  if (v2 == "--all") {
   e = sys(cmd1 + " 2>/dev/null");
   if (e) {
    cout << err1 + cmd1 << endl;
    exit(1);
   }
  }
  e = sys(cmd2 + " 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
 }
 if (v1 == "--connect") {
  disp(cmd + msg1);
  e = sys(cmd3 + "1>/dev/null 2>/dev/null");
  e = sys(cmd4 + "1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd4 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (v1 == "--forget") {
  disp(cmd + msg2);
  e = sys(cmd5 + "1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd5 << endl;
   exit(1);
  }
  cout << out << endl;
 }
}
