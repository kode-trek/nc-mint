int main (int argc, char* argv[]) {
 if (argc < 2) {
  cout << "needs 1 arg." << endl;
  exit(0);
 }
 string v1 = argv[1];
 vector<string> v2 = tree(v1);
 int v3 = 1;
 string v5 = "";
 int p = 0;
 int q = 0;
 //
 v3 = v2.size() / 200;
 for (int i = 0; i < v3; i++) {
  v5 = "pt-" + str(1 + i);
  md(v5);
  p = i * 200;
  q = (i + 1) * 200;
  for (p; p < q; p++) mv(v2[p], v5);
 }
}
