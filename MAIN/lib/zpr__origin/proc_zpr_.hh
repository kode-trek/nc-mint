void proc_zpr(string arg1, string arg2, string arg3, string arg4) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] password
 [v4] number-of-chunk(s)
 [v5] output-zip-file
 [v6] output-directory-of-chunked-file(s)
 [inp] color-input
 [cmd] color-command
 [out] color-output
 [err] color-error/warning
 */
 string cmd = color("blue", "[] ");
 string inp = color("blue", "[inp] ");
 string out1 = color("blue", "[out] ");
 string out2 = color("green", "DONE.");
 string err1 = color("red", "HALTED.""\n""[FAILED] ");
 string err2 = color("red", "\n""[FAILED] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 abbr(v2);
 string v3 = arg3;
 string v4 = arg4;
 string v5 = "packed_" + ts();
 string v6 = "unpacked_" + ts();
 // message(s)
 string msg1 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into archive...";
 string msg2 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into archive..."
 "setting password on archive...";
 string msg3 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into archive..."
 "splitting archive...";
 string msg4 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into archive..."
 "splitting archive..."
 "setting password on archive...";
 string msg5 =
 inp + quote(v2) + "\n" +
 out1 + quote(v6) + "\n" +
 cmd + "extracting archive...";
 string msg6 =
 inp + quote(v2) + "\n" +
 out1 + quote(v6) + "\n" +
 cmd + "extracting TAR-BALL...";
 // command(s)
 int e = 0;
 string cmd1 = "zip -y -q -r " + quote(v5 + ".zip") + " " + quote(v2);
 string cmd2 =
 "zip -y -q -r -P" + quote(v3) + " " + quote(v5 + ".zip") + " " + quote(v2);
 string cmd3 =
 "zip -y -q -r -s" + quote(v4) + "M " + quote(v5 + ".zip") + " " + quote(v2);
 string cmd4 = "zip -y -q -r -s" + quote(v4) + "M -P" + quote(v3) + " " +
 quote(v5 + ".zip") + " " + quote(v2);
 string cmd5 = "7z -y -p" + quote(v3) + " -o" + quote(v6) + " x " + quote(v2);
 string cmd6 = "7z -y -o" + quote(v6 + ".tar") + " x " + quote(v2);
 string cmd7 = "7z -y -o" + quote(v6) + " x " + quote(v6 + ".tar");
 string cmd8 = "7z l " + quote(v2);
 // op(s)
 if ((v1 == "-z") && (v3 == "") && (v4 == "")) {
  disp(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "-z") && (v3 != "") && (v4 == "")) {
  disp(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "-z") && (v3 == "") && (v4 != "")) {
  disp(msg3);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd3 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "-z") && (v3 != "") && (v4 != "")) {
  disp(msg4);
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd4 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 // un-packs
 if ((v1 == "-u") && (uri(uri(v2)[2])[3] != ".tar")) {
  disp(msg5);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "-u") && (uri(uri(v2)[2])[3] == ".tar")) {
  disp(msg6);
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   rm(v6 + ".tar");
   exit(1);
  }
  e = sys(cmd7 + " 1>/dev/null 2>/dev/null");
  rm(v6 + ".tar");
  if (e) {
   cout << err1 + cmd6 + err2 + cmd7 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
 }
 if (v1 == "-peek") sys(cmd8);
}
