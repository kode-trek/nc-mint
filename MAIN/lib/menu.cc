/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

int main() {
 /* variable(s)
 [v1] key-value
 */
 map<string, string> v1;
 v1["hi"] = "\t""displays properties of this computer (node).";
 v1["2dy"] = "\t""displays/sets clock (date and time).";
 v1["wifi"] = "\t""establishes/disbands WiFi connection.";
 v1["ff"] = "\t""upgrades FireFox.";
 v1["shh"] = "\t""turns off terminal command-history.";
 v1["deb"] = "\t""builds/(un-)installs debian-package.";
 v1["snf"] = "\t""searches for file(s) or certain phrase(s) inside file(s).";
 v1["xcb"] = "\t""displays text saved in clip-board.";
 v1["usb"] = "\t""provides access to external storage(s) connected via USB.";
 v1["vbox"] = "\t""(un-)installs VirtualBox (virtual-machine).";
 v1["abox"] = "\t""(un-)installs Genymotion (android-emulator).";
 v1["zpr"] = "\t""(un-)pack file(s)/archive(s).";
 v1["job"] = "\t""manages job scheduler.";
 // op(s)
 for (auto item : v1)
  cout << "[" + mark(item.first, "blue") + "]" + item.second << endl;
}
