/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void proc_hi(void) {
 /* variable(s) */
 string cmd = mark("[] ", "blue");
 string err = mark("[FAILED] ", "red");
 // command(s)
 int e = 0;
 string cmd1 = R"(dig @resolver4.opendns.com myip.opendns.com +short)";
 string cmd2 = R"(hostname -I | awk '{print $1}')";
 string cmd3 = "date";
 // op(s)
 note("This is [public] ");
 e = sys(cmd1 + " 2>/dev/null");
 if (e) {
  note("[local] ");
  sys(cmd2 + " 2>/dev/null");
 }
 e = sys(cmd3 + " 2>/dev/null");
 if (e) cout << err + cmd3 << endl;
 cout <<
 "\n""yet more details could be discovered manually.""\n" +
 mark("[os] ", "blue") + "lsb_release -a""\n" +
 mark("[kernel] ", "blue") + "uname -a""\n" +
 mark("[disk] ", "blue") + "df -h""\n" +
 mark("[usb] ", "blue") + "lsusb""\n" +
 mark("[cpu] ", "blue") + "cat /proc/cpuinfo""\n" +
 mark("[mem] ", "blue") + "cat /proc/meminfo""\n" +
 mark("[ram] ", "blue") + "free -m""\n" +
 mark("[net] ", "blue") + "ifconfig""\n" +
 mark("[hware] ", "blue") + "lshw""\n" +
 mark("[sound] ", "blue") + "aplay -l""\n" +
 mark("[pci] ", "blue") + "lspci"
 << endl;
}
