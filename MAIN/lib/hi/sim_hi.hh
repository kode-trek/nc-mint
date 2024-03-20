/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mint/main/LICENSE
*/

void sim_hi(void) {
 /* variable(s) */
 string cmd = mark("[] ", "blue");
 // op(s)
 cout <<
 cmd + "dig @resolver4.opendns.com myip.opendns.com +short""\n" +
 cmd + "date""\n"
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
