/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void sim_zpr(string arg1, string arg2, string arg3, string arg4) {
 /* variable(s)
 [v1] operation
 [v2] input
 [v3] password
 [v4] number-of-chunk(s)
 [v5] output-zip-file
 [v6] output-directory-of-chunked-file(s)
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 string v3 = arg3;
 string v4 = arg4;
 string v5 = uri(v2, "file-name") + "_PACKED_" + ts();
 string v6 = uri(v2, "file-name") + "_UNPACKED_" + ts();
 // command(s)
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
 // op(s)
 if ((v1 == "--pack") && (v3 == "") && (v4 == "")) cout << cmd + cmd1 << endl;
 if ((v1 == "--pack") && (v3 != "") && (v4 == "")) cout << cmd + cmd2 << endl;
 if ((v1 == "--pack") && (v3 == "") && (v4 != "")) cout << cmd + cmd3 << endl;
 if ((v1 == "--pack") && (v3 != "") && (v4 != "")) cout << cmd + cmd4 << endl;
 if ((v1 == "--unpack") && (uri(uri(v2, "file-name"), "extension") != ".tar"))
  cout << cmd + cmd5 << endl;
 if ((v1 == "--unpack") && (uri(uri(v2, "file-name"), "extension") == ".tar")) {
  cout <<
  cmd + cmd6 + "\n" +
  cmd + cmd7 + "\n" +
  cmd + "rm " + v6 + ".tar"
  << endl;
 }
 if (v1 == "--peek") cout << cmd + cmd8 << endl;
}
