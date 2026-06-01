#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.length();

    //1 to 2^l-1
    for(int ctr=1; ctr<(1<<l); ctr++)
    {
        string combi = "";
        for(int sh=0; sh<l; sh++)
        {
            if((ctr&(1<<sh))>0)
            {
                //It is a set bit
                combi+=s[sh];
            }
        }
        cout << combi << endl;
    }
}