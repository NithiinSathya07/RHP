//https://atcoder.jp/contests/abc252/tasks/abc252_d
//https://atcoder.jp/contests/abc252/submissions/78314416 How can we use combination to solve one one three so if you are considering one leaving one fling values on the two values are from this having this remaining two values you have to choose two values it is nothing but two into one by two so what the same thing for one again you will do the same thing so one plus one but going for three you will not consider one because already combination means water you will not be like reputation a v and ba are same in combination okay so that you have to do it because you will not consider you will consider forty thousand thousand batters so that what is that so you will from three do not have two values for that right you don't have two values for the leaving house one right so you that you will stop so what swo is the assert but then again the problem is you have to keep counting and you have to keep multiplying okay and then you have to find how many when you are considering a value then also you have to find how many repeated characters are then you have to subtract everything so the code will be lengthy that is the reason I shows finally serves to solve the problem so using combination also you can solve combination means what like you are having let's say you are having what four five six seven eight like this so when you are considering what how many other unique values are there like what is that phi is there six is that seven is there eight is that so you would choose four right you just start on the mean values one two three four five values are that so py course by three so for one you can choose it in four many ways you can choose you should not consider this one because when you have one insult you have found the order base of introduce one two four stuff three by zero to six so it's six but again you want to figure out how unique values are there in C two is definitely use binary such otherwise we cannot solve it in lot the only calculation part is resident calculation part is different in the combination calculation out how many values are lawyer how many values are upper around you may consider unique values
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long int;
using namespace std;

void solve()
{
    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long int ans = 0;
    for(int i=1; i<N-1; i++)
    {
        auto ubit = upper_bound(arr.begin(), arr.end(), arr[i]);
        int high = arr.end() - ubit;
        auto lbit = lower_bound(arr.begin(), arr.end(), arr[i]);
        int low = lbit - arr.begin();
        ans += 1LL*high*low;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}