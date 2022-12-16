#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int v[1000000];

int main()
{
    int balloon, balloons, ans;

    cin >> balloons;

    ans = balloons;

    rep(i, 0, balloons)
    {
        cin >> balloon;
        v[balloon]++;
        if(v[balloon + 1])
        {
            ans--;
            v[balloon + 1]--;
        }
    }

    cout << ans << endl;

    return 0;
}