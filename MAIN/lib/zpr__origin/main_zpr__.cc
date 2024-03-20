#include "proc_zpr.hh"
#include "sim_zpr.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 [v4] color-example
 */
 string v1 = color("blue", "-- Z i P pe R --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 string v4 = color("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "(un-)pack file(s)/archive(s).""\n"
  "nc-mate zpr" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate zpr --peek <archive>""\n"
  "enlists item(s) in <archive>.""\n" +
  v3 + "nc-mate zpr --pack <file | dir> [pass] [chunk-size(MB)]""\n"
  "packs <file | dir> into <*.ZIP> archive.""\n"
  "(pass) sets password on <*.ZIP> archive.""\n"
  "(chunk-size) splits <*.ZIP> archive in nMB chunks.""\n" +
  v3 + "nc-mate zpr --unpack <TAR-BALL|*.ZIP|*.RAR|*.7Z|*.JAR|..> [pass]""\n"
  "exctracts archive.""\n"
  "(pass) exctracts password-protected archive.""\n" +
  v4 + "nc-mate zpr --pack " + quote("my-dir") + " " + quote("clock") + "\n"
  "packs 'my-dir' into <*.zip> archive. sets password 'clock' on archive.""\n" +
  v4 + "nc-mate zpr --pack " + quote("my-dir") + " \"\" " + quote("2") + "\n"
  "packs 'my-dir' into <*.zip> archive. doesn't set password on archive. "
  "splits <*.zip> archive in 2MB chunks."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_zpr(argv[2], argv[3], argv[4], argv[5]);
  exit(0);
 }
 proc_zpr(argv[1], argv[2], argv[3], argv[4]);
}
