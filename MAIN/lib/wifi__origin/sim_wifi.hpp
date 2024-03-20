void sim_wifi(string arg1, string arg2, string arg3) {
 //var(s)
 string op = arg1;
 string id = arg2;
 string pass = arg3;
 //op(s)
 if (op == "--disp") {
  cout << "[...] enlists available wifi hotspot(s)." << endl;
  if (id == "--full") cout << "[] nmcli d wifi list" << endl;
  cout << "[] nmcli -t -f ssid dev wifi" << endl;
  exit(0);
 }
 if (op == "--connect") {
  cout <<
  "[...] stops conection.""\n"
  "[] nmcli d disconnect "
  R"(`iw dev | awk '$1=="Interface"{print $2}'`)""\n"
  "[...] (re-)starts connection (GUI might show up).""\n"
  "[] nmcli d wifi connect " << quote(id) << " ifname " <<
  R"(`iw dev | awk '$1=="Interface"{print $2}'` password )" << quote(pass)
  << endl;
 }
 if (op == "--forget") {
  cout <<
//  "[...] enlists connection(s).""\n"
//  "[] nmcli -t -f ssid dev wifi""\n"
//  "[] nmcli -t -f Name con show""\n"
  "[...] removes connection by NAME.""\n"
  "[] nmcli con delete " << quote(id)
  << endl;
 }
}
