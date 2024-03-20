/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void sim_wifi(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] hotspot-ID
 [v3] hotspot-password
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 = arg3;
 // command(s)
 string cmd1 = "nmcli d wifi list";
 string cmd2 = "nmcli -t -f ssid dev wifi";
 string cmd3 = "nmcli d disconnect "
 R"(`iw dev | awk '$1=="Interface"{print $2}'`)";
 string cmd4 = "nmcli d wifi connect " + quote(v2) + " ifname " +
 R"(`iw dev | awk '$1=="Interface"{print $2}'` password )" + quote(v3);
 string cmd5 = "nmcli con delete " + quote(v2);
 // op(s)
 if (v1 == "--list") {
  if (v2 == "-info") cout << cmd + cmd1 << endl;
  cout << cmd + cmd2 << endl;
 }
 if (v1 == "--connect") {
  cout <<
  cmd + cmd3 + "\n" +
  cmd + cmd4
  << endl;
 }
 if (v1 == "--forget") cout << cmd + cmd5 << endl;
}
//		"[] nmcli -t -f ssid dev wifi""\n"
//		"[] nmcli -t -f Name con show""\n"
//		"[...] removes connection by NAME.""\n"
//		"[] nmcli con delete " << quote(id)
