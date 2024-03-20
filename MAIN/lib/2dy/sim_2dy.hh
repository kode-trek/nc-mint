/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void sim_2dy(string arg1, string arg2) {
 /* variable(s)
 [v1] operation
 [v2] time-zone
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = arg2;
 // command(s)
 string cmd1 = "date";
 string cmd2 = "timedatectl list-timezones";
 string cmd3 = "sudo timedatectl set-timezone " + v2;
 // op(s)
 if (v1 == "--show") cout << cmd + cmd1 << endl;
 if (v1 == "--list") cout << cmd + cmd2 << endl;
 if (v1 == "--set") cout << cmd + cmd3 << endl;
}
