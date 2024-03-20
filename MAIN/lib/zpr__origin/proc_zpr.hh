/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_zpr(string arg1, string arg2, string arg3, string arg4) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] password
 [v4] number-of-chunk(s)
 [v5] output-zip-file
 [v6] output-directory-of-chunked-file(s)
 */
 string cmd = mark("[] ", "blue");
 string inp = mark("[INP] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 string err2 = mark("\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 string v3 = arg3;
 string v4 = arg4;
 string v5 = uri(v2, "file-name") + "_PACKED_" + ts();
 string v6 = uri(v2, "file-name") + "_UNPACKED_" + ts();
 // message(s)
 string msg1 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into archive...";
 string msg2 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into password-protected archive...";
 string msg3 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into splitted archive...";
 string msg4 =
 inp + quote(v2) + "\n" +
 out1 + quote(v5 + ".zip") + "\n" +
 cmd + "packing file(s) into password-protected and splitted archive...";
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
 string cmd1 = "7z a " + quote(v5 + ".zip") + " " + quote(v2);
// string cmd1 = "zip -y -q -r " + quote(v5 + ".zip") + " " + quote(v2);
 string cmd2 = "7z -p" + quote(v3) + " a " + quote(v5 + ".zip") + " " +
 quote(v2);
// string cmd2 = "zip -y -q -r -P" + quote(v3) + " " + quote(v5 + ".zip") + " " +
// quote(v2);
 string cmd3 = "7z -v" + v4 + "m a " + quote(v5 + ".zip") + " " + quote(v2);
// string cmd3 = "zip -y -q -r -s" + quote(v4) + "M " + quote(v5 + ".zip") + " " +
// quote(v2);
 string cmd4 = "7z -p" + quote(v3) + " -v" + v4 + "m a " + quote(v5 + ".zip") +
 " " + quote(v2);
// string cmd4 = "zip -y -q -r -s" + quote(v4) + "M -P" + quote(v3) + " " +
// quote(v5 + ".zip") + " " + quote(v2);
 string cmd5 = "7z -y -p" + quote(v3) + " -o" + quote(v6) + " x " + quote(v2);
 string cmd6 = "7z -y -o" + quote(v6 + ".tar") + " x " + quote(v2);
 string cmd7 = "7z -y -o" + quote(v6) + " x " + quote(v6 + ".tar");
 string cmd8 = "7z l " + quote(v2);
 // use unzip instead of 7z to extract .zup
 // use 7z to extract non-*.zip
 // -force would use unzip after 7z
 // op(s)
 if ((v1 == "--pack") && (v3 == "") && (v4 == "")) {
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--pack") && (v3 != "") && (v4 == "")) {
  note(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--pack") && (v3 == "") && (v4 != "")) {
  note(msg3);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd3 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--pack") && (v3 != "") && (v4 != "")) {
  note(msg4);
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd4 << endl;
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--unpack") && (uri(uri(v2, "file-name"), "extension") != ".tar")) {
  note(msg5);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
 }
 if ((v1 == "--unpack") && (uri(uri(v2, "file-name"), "extension") == ".tar")) {
  note(msg6);
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
 if (v1 == "--peek") sys(cmd8);
}
