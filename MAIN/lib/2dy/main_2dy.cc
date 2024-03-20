#include "proc_2dy.hh"
#include "sim_2dy.hh"

int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] color-title
 [v2] color-help
 [v3] color-pattern
 */
 string v1 = color("blue", "-- 2dy T O D A Y --");
 string v2 = color("blue", " --help");
 string v3 = color("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "displays/sets clock (date and time).""\n"
  "nc-mate 2dy" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mate 2dy --show""\n"
  "displays clock.""\n" +
  v3 + "nc-mate 2dy --list""\n"
  "displays list of time-zone(s).""\n"
  "[UP | DOWN] traverse.""\n"
  "[Q] quit.""\n" +
  v3 + "nc-mate 2dy --set <time-zone>""\n"
  "sets clock."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_2dy(argv[2], argv[3]);
  exit(0);
 }
 proc_2dy(argv[1], argv[2]);
}
