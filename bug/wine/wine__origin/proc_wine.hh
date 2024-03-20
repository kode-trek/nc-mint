 [v1] operation
 [v2] MESA_GL_VERSION_OVERRIDE=4.5 (gpu-intensive video-game)

 string v1 = arg1;
 string v2 = "export MESA_GL_VERSION_OVERRIDE=4.5";
 // message(s)
 string msg1 = "installing wine (might take long)...";
 string msg2 = "un-installing wine...";
 // command(s)
 int e = 0;
 string cmd1 = "sudo apt-get install wine -y";
 string cmd2 = "sudo apt-get remove wine -y";
 string cmd3 = "sudo apt-get install mono-complete -y";
 string cmd4 = "sudo apt-get remove mono-complete -y";
 string cmd5 = "sudo dpkg --add-architecture i386"; // older x32 software
 string cmd6 = "echo \"" + v2 + "\" >> ~/.bashrc";
 string cmd7 = "echo \"`sed '/" + v2 + "/d' ~/.bashrc`\" > ~/.bashrc";
 string cmd8 = "wine --version";
 // op(s)
  "extra packages (ex. gecko) in '~/.wine' and other configurations could be"
  " achieved manually via a graphical user interface.""\n"
  "> winecfg""\n"
  "> wine uninstall""\n"
  "> nc-mate wine --man"


 string msg1 = (string) "[] installing wine64 (might take long)...";
 string msg2 = (string) "[] un-installing wine (might take long)...";
 //cmd(s)
 string cmd1 = (string) "sudo apt-get install wine64 -y";
 string cmd5 = (string) "sudo apt-get autoremove --purge wine* -y";

  "packages (ex. gecko) could be added manually (via GUI) in '~/.wine'.""\n"
  "> winecfg"

  rm("~/.wine");


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



  "[...] '~/.wine' need to be created.""\n"
  "      extra packages (ex. gecko) may required (via GUI).""\n"
  "      > winecfg"

  "[...] verifies wine64-removal.""\n"
  "[] wine --version"


