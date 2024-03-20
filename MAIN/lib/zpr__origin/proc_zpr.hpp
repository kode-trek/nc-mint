void proc_zpr(string arg1, string arg2, string arg3, string arg4) {
 //var(s)
 int c = 0;
 string op = arg1;
 string in = arg2;
 string pass = arg3;
 string chunk = arg4;
 string zip = (string) "packed_" + ts();
 string dir = (string) "unpacked_" + ts();
 //msg(s)
 string msg1 = (string)
 "[] packing file(s) into " + quote(zip + ".zip") + " archive...";
 string msg2 = (string)
 "[] packing file(s) into " + quote(zip + ".zip") + ".""\n"
 "   setting password on archive...";
 string msg3 = (string)
 "[] packing file(s) into " + quote(zip + ".zip") + ".""\n"
 "   splitting archive...";
 string msg4 = (string)
 "[] packing file(s) into " + quote(zip + ".zip") + ".""\n"
 "   splitting archive.""\n"
 "   setting password on archive...";
 string msg5 = (string) "[] extracting " + quote(in) + " archive...";
 string msg6 = (string) "[] extracting " + quote(in) + " TAR-BALL...";
 //cmd(s)
 string cmd1 = (string) "zip -y -q -r " + quote(zip + ".zip") + " " +
 quote(in);
 string cmd2 = (string) "zip -y -q -r -P" + quote(pass) + " " +
 quote(zip + ".zip") + " " + quote(in);
 string cmd3 = (string) "zip -y -q -r -s" + quote(chunk) + "M " +
 quote(zip + ".zip") + " " + quote(in);
 string cmd4 = (string) "zip -y -q -r -s" + quote(chunk) + "M -P" +
 quote(pass) + " " + quote(zip + ".zip") + " " + quote(in);
 string cmd5 = (string) "7z -y -p" + quote(pass) + " -o" + quote(dir) + " x " +
 quote(in);
 string cmd6 = (string) "7z -y -o" + quote(dir + ".tar") + " x " + quote(in);
 string cmd7 = (string) "7z -y -o" + quote(dir) + " x " + quote(dir + ".tar");
 //op(s)
 if ((op == "-z") && (pass == "") && (chunk == "")) {
  disp(msg1);
  c = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd1 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 if ((op == "-z") && (pass != "") && (chunk == "")) {
  disp(msg2);
  c = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd2 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 if ((op == "-z") && (pass == "") && (chunk != "")) {
  disp(msg3);
  c = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd3 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 if ((op == "-z") && (pass != "") && (chunk != "")) {
  disp(msg4);
  c = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd4 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 //un-packs
 if ((op == "-u") && (uri(uri(in)[2])[3] != ".tar")) {
  disp(msg5);
  c = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (c) {cout << "HALTED.""\n""[FAILED] " << cmd5 << endl; exit(1);}
  cout << "DONE." << endl;
 }
 if ((op == "-u") && (uri(uri(in)[2])[3] == ".tar")) {
  disp(msg6);
  c = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (c) {
   cout << "HALTED.""\n""[FAILED] " << cmd1 << endl;
   rm(dir + ".tar");
   exit(1);
  }
  c = sys(cmd7 + " 1>/dev/null 2>/dev/null");
  rm(dir + ".tar");
  if (c) {
   cout << "HALTED."
   "\n""[FAILED] " << cmd6 <<
   "\n""[FAILED] " << cmd7
   << endl;
   rm(dir);
   exit(1);
  }
  cout << "DONE." << endl;
 }
}
