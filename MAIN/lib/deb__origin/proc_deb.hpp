void proc_deb(string arg1, string arg2) {
	//var(s)
	int c = 0;
	string op = arg1;
	string inp = arg2;
	int l = strlen(inp.c_str());
	if (inp[l - 1] == '/') inp = inp.substr(0, l - 1);
	string source = (string) "/usr/lib/nc-mate/asset/helloworld_1.0-1";
	string target = (string) "~/Documents/";
	//msg(s)
	string msg1 = (string) "[] provideing sample 'helloworld_1.0-1' <pkg-dir> in"
	" '~/Documents/'...";
	string msg2 = (string) "[] packing " + quote(uri(inp)[1]) +
	" <pkg-dir> into " + quote(uri(inp)[1] + ".deb") + "...";
	string msg3 = (string) "[] installing application in " + quote(uri(inp)[1]) +
	"...";
	string msg4 = (string) "[] un-installing application in " +
	quote(uri(inp)[1]) + "...";
	string msg5 = (string) "[] un-installs " + quote(uri(inp)[1]) +
	" application...";
	//cmd(s)
	string cmd1 = (string) "dpkg -f " + quote(inp);
	string cmd2 = (string) "dpkg-deb --build " + quote(inp);
	string cmd3 = (string) "sudo dpkg --install " + quote(inp);
	string cmd4 = (string) "sudo dpkg --remove `dpkg -f Package 2>/dev/null`" +
	quote(inp);
	string cmd5 = (string) "sudo dpkg --remove " + quote(inp);
	//op(s)
	if (op == "--sample") {
		disp(msg1);
		rm("~/Documents/helloworld_1.0-1");
		c = cp("/usr/lib/nc-mate/asset/helloworld_1.0-1", "~/Documents/");
		if (not c) {
			cout <<
			"HALTED.""\n""[FAILED] to copy files.""\n"
			"from:""\t""/usr/lib/nc-mate/asset/helloworld_1.0-1""\n"
			"to:""\t""~/Documents"
			<< endl;
			exit(1);
		}
		cout << "DONE." << endl;
	}
	if (op == "--what") {
		c = sys(cmd1);
		if (c) exit(1);
		exit(0);
	}
	if (op == "--tip") {
		cout <<
		"[permission-mode]""\n"
		"directory       775""\n"
		"regular-file    664""\n"
		"application     755""\n"
		"\n"
		"[debian-directory]""\n"
		"<pkg-dir>/DEBIAN/control""\n"
		"<pkg-dir>/DEBIAN/preinst""\n"
		"<pkg-dir>/DEBIAN/postinst""\n"
		"<pkg-dir>/usr/bin/""\n"
		"<pkg-dir>/usr/lib/""\n"
		"...""\n"
		"\n"
		"more details:""\n"
		"https://ubuntuforums.org/showthread.php?t=910717""\n"
		"https://www.debian.org/doc/manuals/maint-guide/build.en.html"
		<< endl;
		exit(0);
	}
	if (op == "--build") {
		disp(msg2);
		c = sys(cmd2 + " 1>/dev/null 2>/dev/null");
		if (c) {cout << "HALTED.""\n""[FAILED] " << cmd2 << endl; exit(1);}
		exit(0);
	}
	if (op == "--inst") {
		disp(msg3);
		c = sys(cmd3 + " 1>/dev/null 2>/dev/null");
		if (c) {cout << "HALTED.""\n""[FAILED] " << cmd3 << endl; exit(1);}
		exit(0);
	}
	if (op == "--rem") {
		if (uri(inp)[3] == ".deb") {
			disp(msg4);
			c = sys(cmd4 + " 1>/dev/null 2>/dev/null");
			if (c) {cout << "HALTED.""\n""[FAILED] " << cmd4 << endl; exit(1);}
		}
		if (uri(inp)[3] != ".deb") {
			disp(msg5);
			c = sys(cmd5 + " 1>/dev/null 2>/dev/null");
			if (c) {cout << "HALTED.""\n""[FAILED] " << cmd5 << endl; exit(1);}
		}
	}
}
