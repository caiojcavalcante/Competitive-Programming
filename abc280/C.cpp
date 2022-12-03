#include <bits/stdc++.h>

using namespace std;
int main()
{
    char ans = 0, buffer;

    whiel(cin >> buffer)
        ans ^= buffer;

    cout << ans << endl;
    return 0;
}