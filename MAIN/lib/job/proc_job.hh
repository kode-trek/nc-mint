void proc_job(string arg1, string arg2) {
  drop("~/Documents/Job-List", arg1 + "\t" + arg2 + "\n");
  sys("sed 's/clock/" + arg1 + "/g' job-1.sh > job-2.sh");
  sys("sed 's/task/" + arg2 + "/g' job-2.sh > ~/Documents/task_" + ts() + ".sh");
}
