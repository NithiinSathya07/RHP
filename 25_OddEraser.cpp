// https://codeforces.com/contest/2258/problem/A
// https://codeforces.com/contest/2258/submission/389705899
#include<iostream>
#include<vector>
#include<queue>
#include<array>
#include<algorithm>
#define ll unsigned long long int
using namespace std;

int hcf(int a,int b){
	return b==0 ?a :hcf(b,a%b);
}

void solve(){
	int N; cin >> N;
	vector<int> arr(N);
	for(int i=0;i<N;i++)
    {
		cin>>arr[i];
	}
	cout << hcf(arr[0],arr[N-1]) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}