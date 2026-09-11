//https://atcoder.jp/contests/abc073/tasks/abc073_c
//https://atcoder.jp/contests/abc073/submissions/79141968
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
  int N; cin>>N;
  map<int, int> m;
  for (int ctr=1; ctr<=N; ctr++) {
    int curr; cin>>curr;
    m[curr]++;
  }
  int ans = 0;
  for (auto[num, cnt] : m) {
    if (cnt&1) {
      ans++;
    }
  }
  cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) {
        solve();
    }
}