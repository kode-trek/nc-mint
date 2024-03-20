void f1(string &str, const string& from, const string& to) {
 size_t start_pos = 0;
 while((start_pos = str.find(from, start_pos)) != std::string::npos) {
  str.replace(start_pos, from.length(), to);
  // Handles case where 'to' is a substring of 'from'
  start_pos += to.length();
 }
}

void f(string arg1, string arg2) {
 string task = "~/Documents/task_" + ts();
 drop("~/Documents/Job-List", arg1 + "\t" + arg2 + "\n");
 f1(arg1, "/", "\\/");
 f1(arg2, "/", "\\/");
 sys("sed 's/clock/" + arg1 + "/g' job-1.sh > job-2.sh");
 sys("sed 's/task/" + arg2 + "/g' job-2.sh > " + task);
 rm("job-2.sh");
 sys("chmod 755 " + task);
 sys(task + " &");
}

int main(int argc, char* argv[1]) {
 f(argv[1], argv[2]);
}

//ls /etc/xdg/autostart/
