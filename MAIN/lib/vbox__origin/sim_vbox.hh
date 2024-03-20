/*
 The MIT License (MIT)
 Copyright (c) 2023 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/nc-mate/main/LICENSE
*/

void sim_vbox(string arg1) {
 /* variable(s)
 [v1] operation
 [v2] VirtalBox-version
 [v3] running-virtual-machine(s)
 [v4] VirtualBox-bin-file
 [v5] VirtualBox-download-link
 [v6] VirtualBox_Extension_Pack-bin-file
 [v7] VirtualBox_Extension_Pack-download-link
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = "6.1";
 string v3 = ts();
 string v4 = "virtualbox-6.1_6.1.32-149290_Ubuntu_eoan_amd64.deb";
 string v5 = "https://download.virtualbox.org/virtualbox/6.1.32/" + v4;
 string v6 = "Oracle_VM_VirtualBox_Extension_Pack-6.1.32-149290.vbox-extpack";
 string v7 = "https://download.virtualbox.org/virtualbox/6.1.32/" + v6;
 // command(s)
 string cmd1 = "wget --spider " + quote(v5);
 string cmd2 = "wget --spider " + quote(v7);
 string cmd3 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v5);
 string cmd4 =
 "wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " + quote(v7);
 string cmd5 = "sudo gdebi -n " + quote(v4);
 string cmd6 =
 "echo y | sudo vboxmanage extpack install --replace " + quote(v6);
 string cmd7 = "sudo gpasswd -a " + uname() + " vboxusers";
 string cmd8 = "echo -n `vboxmanage list runningvms` > " + v3;
 string cmd9 = "vboxmanage list runningvms";
 string cmd10 =
 "ps aux | grep -F /usr/lib/virtualbox/VirtualBox | grep -Fv grep > " + v3;
 string cmd11 =
 "ps aux | grep -F /usr/lib/virtualbox/VirtualBox | grep -Fv grep";
 string cmd12 = "sudo apt-get remove -y virtualbox-" + v2;
 string cmd13 = "vboxmanage --version";
 // op(s)
 if (v1 == "--inst") {
  cout <<
  cmd + "updates APT.""\n" +
  cmd + "cd ~""\n" +
  cmd + cmd3 + "\n" +
  cmd + cmd4 + "\n" +
  cmd + cmd5 + "\n" +
  cmd + cmd6 + "\n" +
  cmd + cmd7 + "\n" +
  cmd + cmd11 + "\n"
  "Restart system for the changes to take effect.""\n" +
  cmd + "sudo init 6"
  << endl;
 }
 if (v1 == "--rem") {
  cout <<
  cmd + cmd13 + "\n" +
  cmd + cmd9 + "\n" +
  cmd + cmd11 + "\n" +
  cmd + "updates APT.""\n" +
  cmd + cmd12
  << endl;
 }
}

//		"[...] updates APT.""\n"
//		"[] sudo dpkg --configure -a""\n"
//		"[] sudo apt-get clean -y""\n"
//		"[] sudo apt-get install --reinstall -f -y""\n"
//		"[] sudo apt-get update -y""\n"
//		"[] sudo apt-get install --reinstall apt -y""\n"
//		"[] sudo apt-get install --reinstall software-properties-common -y""\n"
//		"[] sudo apt-get clean -y""\n"
//		"[] sudo apt-get autoclean -y""\n"
//		"[] sudo apt-get update -y""\n"
