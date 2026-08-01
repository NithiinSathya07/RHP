#include <iostream>

using namespace std;
int main()
{
    int capacity;
    int litres; 
    cin >> capacity >> litres;
    int ans = 0;
    while(litres>0)
    {
        ans++;
        litres -= capacity;
    }
    cout << ans;
}