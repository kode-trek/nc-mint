#include "proc_deb.hpp"
#include "sim_deb.hpp"
int main(int argc, char* argv[]) {
	if ((string) argv[1] == "") {
		cout <<
		"-- D E B ian package --""\n"
		"builds | (un-)installs debian-package.""\n"
		"\n"
		"nc-mate deb --help"
		<< endl;
		exit(0);
	}
	if ((string) argv[1] == "--help") {
		cout <<
		"-- D E B ian package --""\n"
		"builds | (un-)installs debian-package.""\n"
		"\n"
		"[PATTERN] nc-mate deb --sample""\n"
		"provides sample 'hello-world' <pkg-dir> in '~/Documents'.""\n"
		"\n"
		"[PATTERN] nc-mate deb --what <*.DEB>""\n"
		"displays properties for <*.DEB> debian-package.""\n"
		"\n"
		"[PATTERN] nc-mate deb --tip""\n"
		"helps with building <*.DEB> debian-package.""\n"
		"\n"
		"[PATTERN] nc-mate deb --build <pkg-dir>""\n"
		"packs <pkg-dir> into <*.DEB> debian-package.""\n"
		"\n"
		"[PATTERN] nc-mate deb --inst <*.DEB>""\n"
		"installs application in <*.DEB>.""\n"
		"\n"
		"[PATTERN] nc-mate deb --rem <*.DEB | app>""\n"
		"un-installs <app>lication in <*.DEB>."
		<< endl;
		exit(0);
	}
	if ((string) argv[1] == "--sim") {sim_deb(argv[2], argv[3]); exit(0);}
	proc_deb(argv[1], argv[2]);
}
