#include "proc_job.hh"
#include "sim_job.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("blue", "-- JOB --");
 string v2 = mark("blue", " --help");
 string v3 = mark("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "manages job scheduler.""\n"
  "nc-mint job" + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "nc-mint job <clock> <task> [arg(s)...]""\n"
  "runs <task> at specified <clock>-date/time."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_job(argv[2], argv[3]);
  exit(0);
 }
 proc_job(argv[1], argv[2]);
}
