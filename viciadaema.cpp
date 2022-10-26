#include <bits/stdc++.h>

int main()
{
    char s[100] = {'b'};
    int ans = 0;
    cin >> s;

    for(int i = 0; i < 21; i++)
    {
        if(s[i] == 'a')
        {
            ans++;
            if((i > 0 && s[i - 1] == 'i') || i < 21 && s[i + 1] == 'i')
                ans++;
        }
    }
    cout << ans;
}