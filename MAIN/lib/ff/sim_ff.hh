/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void sim_ff(string arg1, string arg2) {
 /* variable(s)
 [v1] upgrade
 [v2] reset
 [v3] FireFox-download-link
 [v4] FireFox-tarball
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = arg2;
 string v3 =
 R"(https://download.mozilla.org/?)"
 R"(product=firefox-latest&os=linux64&lang=en-US)";
 string v4 = "firefox-latest.tar.bz2";
 // command(s)
 string cmd1 = "wget -qc --no-check-certificate --tries=0 --read-timeout=32 " +
 quote(v3) + " -O" + quote(v4);
 string cmd2 = "sudo rm -rf /usr/lib/firefox /usr/lib/firefox-a* "
 "/usr/bin/firefox";
 string cmd3 = "sudo tar -xf " + quote(v4) + " -C /usr/lib/";
 string cmd4 = "sudo ln -s /usr/lib/firefox/firefox /usr/bin/";
 string cmd5 = "firefox --version";
 // op(s)
 if (v1 == "--upgrade") {
  cout <<
  cmd + "cd ~""\n" +
  cmd + cmd1
  << endl;
  if (v2 == "--reset") cout << cmd + "rm -r ~/.mozilla/" << endl;
  cout <<
  cmd + cmd2 + "\n" +
  cmd + cmd3 + "\n" +
  cmd + cmd4 + "\n" +
  cmd + cmd5
  << endl;
 }
}
