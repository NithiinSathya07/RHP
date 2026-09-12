//https://atcoder.jp/contests/abc103/tasks/abc103_d
//https://atcoder.jp/contests/abc103/submissions/79174780
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

void solve(){
	int N,Q;
	cin>>N>>Q;
	vector<pair<int,int>> arr(Q);
	for(int req=0;req<Q;req++){
		int lt,rt;
		cin>>lt>>rt;
		arr[req]= make_pair(rt,lt);
	}
	sort(arr.begin(),arr.end());
	int count=0;
	int rtmost=-5;
	for(auto[rt,lt]:arr){
		if(lt>=rtmost){
			count++;
			rtmost=rt;
		}
	}
	cout<<count<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	while(tc--)
	solve();
}