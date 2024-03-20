void sim_deb(string arg1, string arg2) {
	//var(s)
	string op = arg1;
	string inp = arg2;
	int l = strlen(inp.c_str());
	if (inp[l - 1] == '/') inp = inp.substr(0, l - 1);
	string source = (string) "/usr/lib/nc-mate/0_asset/helloworld_1.0-1";
	string target = (string) "~/Documents/";
	//op(s)
	if (op == "--sample") {
		cout <<
		"[] removes '~/Documents/helloworld_1.0-1/'.""\n"
		"[...] provides sample 'helloworld_1.0-1' <pkg-dir> in '~/Documents/'.""\n"
		"[] copies '/usr/lib/nc-mate/asset/helloworld_1.0-1' into '~/Documents/'."
		<< endl;
		exit(0);
	}
	if (op == "--what") {
		cout <<
		"[...] displays properties for " << quote(inp) << " <deb-pkg>.""\n"
		"[] dpkg -f " << quote(inp)
		<< endl;
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
		cout <<
		"[...] packs " << quote(uri(inp)[1]) << " <pkg-dir> into " <<
		quote(uri(inp)[1] + ".deb") << ".""\n"
		"[] dpkg-deb --build " << quote(inp)
		<< endl;
		exit(0);
	}
	if (op == "--inst") {
		cout <<
		"[...] captures sudo-pass.""\n"
		"[] sudo apt-get clean -y""\n"
		"[...] installs application in " << quote(uri(inp)[1]) << ".""\n"
		"[] sudo dpkg --install " << quote(inp)
		<< endl;
		exit(0);
	}
	if (op == "--rem") {
		cout <<
		"[...] captures sudo-pass.""\n"
		"[] sudo apt-get clean -y"
		<< endl;
		if (uri(inp)[3] == ".deb") {
			cout <<
			"[...] un-installs application in " << quote(uri(inp)[1]) << ".""\n"
			"[] sudo dpkg --remove `dpkg -f " << quote(inp)
			<< endl;
		}
		if (uri(inp)[3] != ".deb") {
			cout <<
			"[...] un-installs " << quote(uri(inp)[1]) << " application.""\n"
			"[] sudo dpkg --remove " << quote(inp)
			<< endl;
		}
	}
}
