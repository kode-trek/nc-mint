void sim_vbox(string arg1, string arg2) {
 //var(s)
 string op = arg1;
 string v_nam = (string) "virtualbox-6.1_6.1.18-142142~Ubuntu~eoan_amd64.deb";
 string v_lnk = (string) "https://download.virtualbox.org/virtualbox/6.1.18/" +
 v_nam;
 //op(s)
 if (op == "--inst") {
  cout <<
  "[...] captures sudo-password.""\n"
  "[] sudo apt-get clean -y""\n"
  "[...] retrieves <virtualbox*.deb>.""\n"
  "[] switches path to '~'.""\n"
  "[] wget -q -c --no-check-certificate --tries=0 --read-timeout=32 " <<
  quote(v_lnk) << "\n"
  "[...] updates APT.""\n"
  "[] sudo dpkg --configure -a""\n"
  "[] sudo apt-get clean -y""\n"
  "[] sudo apt-get install --reinstall -f -y""\n"
  "[] sudo apt-get update -y""\n"
  "[] sudo apt-get install --reinstall apt -y""\n"
  "[] sudo apt-get install --reinstall software-properties-common -y""\n"
  "[] sudo apt-get clean -y""\n"
  "[] sudo apt-get autoclean -y""\n"
  "[] sudo apt-get update -y""\n"
  "[...] installs virtualbox.""\n"
  "[] sudo gdebi -n " << quote(v_nam) << "\n"
  "[...] verifys virtualbox-setup.""\n"
  "[] virtualbox --help"
  << endl;
 }
 if (op == "--rem") {
  cout <<
  "[...] captures sudo-password.""\n"
  "[] sudo apt-get clean -y""\n"
  "[...] un-installs virtualbox.""\n"
  "[] switches path to '/'.""\n"
  "[] sudo apt-get autoremove --purge -y virtualbox*""\n"
  "[...] verifys virtualbox-removal.""\n"
  "[] virtualbox --help"
  << endl;
 }
}
