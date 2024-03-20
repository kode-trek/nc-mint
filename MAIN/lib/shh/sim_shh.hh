/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void sim_shh(string arg1) {
  /* variable(s)
  [v1] operation
  [v2] conf-file-bashrc
  [v3] history-backup-file
  */
  string cmd = mark("[] ", "blue");
  //
  string v1 = arg1;
  string v2 = R"(~/.bashrc)";
  string v3 = R"(~/hist_)" + ts();
  // command(s)
  string cmd1 = R"(cat /dev/null > ~/.bash_history)";
  string cmd2 = "history -c";
  string cmd3 = "history >> " + v3;
  // op(s)
  if (v1 == "--clear") {
    cout <<
    cmd + "echo " + quote(cmd1) + " > " + v2 + "\n" +
    cmd + "echo " + quote(cmd2) + " > " + v2 + "\n" +
    cmd + "cp ~/.bash_history " + v3 + "\n" +
    cmd + cmd3
    << endl;
  }
}

// "[] . ~/.bashrc"

// "reminds to back-up:""\n" +
// cmd + cmd3

