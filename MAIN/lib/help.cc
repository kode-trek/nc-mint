/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

int main() {
 string v1 = mark("-- Net Command - MINT --", "green");
 string v2 = mark("[PATTERN] ", "blue");
 string v3 = mark("Linux Mint 21.2 (victoria)", "yellow");
 string v4 = mark("[DEVELOPMENT] ", "yellow");
 // op(s)
 cout <<
 v1 + "\n"
 "collection of tools to facilitate working with Linux Mint.""\n" +
 v2 + "nc-mint cmd""\n"
 "enlists commands.""\n" +
 v2 + "nc-mint <cmd> --help""\n"
 "displays manual for <cmd>-command.""\n" +
 v2 + "nc-mint <cmd> --sim [arg(s)...]""\n"
 "simulates process by displaying corresponding <cmd>-command associated with "
 "supplied arguments.""\n""\n"
 "this terminal-app had a test-drive on " + v3 + " platform.""\n" +
 v4 + "github.com/kode-trek"
 << endl;
}
