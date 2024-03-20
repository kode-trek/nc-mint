/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void proc_xcb(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] start-of-text-in-clipboard
 [v3] end-of-text-in-clipboard
 */
 string err = mark("\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = mark("[START]", "yellow");
 string v3 = mark("[STOP]", "yellow");
 // command(s)
 int e = 0;
 string cmd1 = "xsel -ob";
 //
 if (v1 == "--disp") {
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err + cmd1 << endl;
   exit(1);
  }
  note(v2);
  sys(cmd1 + " 2>/dev/null");
  cout << v3 << endl;
 }
}
