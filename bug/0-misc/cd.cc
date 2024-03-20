 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (op == "--burn") {
  disp(cmd + msg5);
  e = sys(cmd8 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd8 << endl;
   exit(1);
  }
  cout << out << endl;
 }
 if (op == "--udf") {
  if (v1 == "open") {
   sys();
  }
  if (v1 == "close") {
   sys();
  }
 }
}

