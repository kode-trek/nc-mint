void proc_wifi(string arg1, string arg2, string arg3) {
 //var(s)
 int c = 0;
 string op = arg1;
 string id = arg2;
 string pass = arg3;
 //msg(s)
 string msg1 = (string) "[] establishing connection (GUI might show up)...";
 string msg2 = (string) "[] removing " + quote(id) + " connection...";
 //cmd(s)
 string cmd1 = (string) "nmcli d wifi list";
 string cmd2 = (string) "nmcli -t -f ssid dev wifi";
 string cmd3 = (string) "nmcli d disconnect "
 R"(`iw dev | awk '$1=="Interface"{print $2}'`)";
 string cmd4 = (string) "nmcli d wifi connect " + quote(id) + " ifname " +
 R"(`iw dev | awk '$1=="Interface"{print $2}'` password )" + quote(pass);
 string cmd5 = (string) "nmcli con delete " + quote(id);
 //op(s)
 if (op == "--disp") {
  if (id == "--full") {
   c = sys(cmd1 + " 2>/dev/null");
   if (c) {cout << "[FAILED] " << cmd1 << endl; exit(1);}
  }
  c = sys(cmd2 + " 2>/dev/null");
  if (c) {cout << "[FAILED] " << cmd2 << endl; exit(1);}
 }
 if (op == "--connect") {
  disp(msg1);
  c = sys(cmd3 + "1>/dev/null 2>/dev/null");
  c = sys(cmd4 + "1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd4 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 if (op == "--forget") {
  disp(msg2);
  c = sys(cmd5 + "1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd5 << endl; exit(1);}
  cout << "DONE." << endl;
 }
}
