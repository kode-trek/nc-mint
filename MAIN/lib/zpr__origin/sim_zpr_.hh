void sim_zpr(string arg1, string arg2, string arg3, string arg4) {
 //var(s)
 string op = arg1;
 string inp = arg2;
 string pass = arg3;
 string chunk = arg4;
 string zip = (string) "packed_" + ts();
 string dir = (string) "unpacked_" + ts();
 //op(s)
 //packs
 if ((op == "-z") && (pass == "") && (chunk == "")) {
  cout <<
  "[...] packs " << quote(inp) << " into " << quote(zip + ".zip") <<
  " archive.""\n"
  "[] zip -y -q -r " << quote(zip + ".zip") << " " << quote(inp)
  << endl;
 }
 if ((op == "-z") && (pass != "") && (chunk == "")) {
  cout <<
  "[...] packs " << quote(inp) << " into " << quote(zip + ".zip") << ".""\n"
  "      sets password " << quote(pass) << " on archive.""\n"
  "[] zip -y -q -r -P" << quote(pass) << " " << quote(zip + ".zip") << " " <<
  quote(inp)
  << endl;
 }
 if ((op == "-z") && (pass == "") && (chunk != "")) {
  cout <<
  "[...] packs " << quote(inp) << " into " << quote(zip + ".zip") << ".""\n"
  "      splits archive in " << quote(chunk + "MB") << " chunks.""\n"
  "[] zip -y -q -r -s" << quote(chunk) << "M " << quote(zip + ".zip") <<
  " " << quote(inp)
  << endl;
 }
 if ((op == "-z") && (pass != "") && (chunk != "")) {
  cout <<
  "[...] packs " << quote(inp) << " into " << quote(zip + ".zip") << ".""\n"
  "      splits archive in " << quote(chunk + "MB") << " chunks.""\n"
  "      sets password " << quote(pass) << " on archive.""\n"
  "[] zip -y -q -r -s" << quote(chunk) << "M -P" << quote(pass) << " " <<
  quote(zip + ".zip") << " " << quote(inp)
  << endl;
 }
 //un-packs
 if ((op == "-u") && (uri(uri(inp)[2])[3] != ".tar")) {
  if (pass != "") {
   cout <<
   "[...] extracts " << quote(inp) << " password-protected archive."
   << endl;
  } else { cout << "[...] extracts " << quote(inp) << " archive." << endl;}
  cout <<
  "[] 7z -y -p" << quote(pass) << " -o" << quote(dir) << " x " << quote(inp)
  << endl;
 }
 if ((op == "-u") && (uri(uri(inp)[2])[3] == ".tar")) {
  cout <<
  "[...] extracts " << quote(inp) << " TAR-BALL.""\n"
  "[] 7z -y -o" << quote(dir + ".tar") << " x " << quote(inp) << "\n"
  "[] 7z -y -o" << quote(dir) << " x " << quote(dir + ".tar") << "\n"
  "[] removes '" << dir << ".tar'"
  << endl;
 }
}
