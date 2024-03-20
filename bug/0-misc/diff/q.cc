int main (int argc, char* argv[]) {
 if (argc < 3) {
  cout << "needs 2 argument(s)." << endl;
  exit(0);
 }
 string v1 = cat(argv[1]);
 string v2 = argv[2];
 vector<string> v3 = split(cat(v2), "\n");
 string v4 = "";
 string v5 = ts();
 // op(s)
 for (int i = 0; i < v3.size(); i++) {
  if (has(v1, v3[i])) v4 += "\n";
  if (not has(v1, v3[i])) v4 += v3[i] + "\n";
 }
 drop(v5, v4);
 cout << "[OUT] " + v5 << endl;
}
