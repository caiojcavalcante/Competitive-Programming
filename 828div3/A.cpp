#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
char dict[1500];
int main()
{   
    int casos, length, ans, arr[50];
    string s;
    cin >> casos;
    while(casos--)
    {
        ans = 1;
        cin >> length;
        for (int i = 0; i < length; i++)
            cin >> arr[i];
        
        cin >> s;
        for (int i = 0; i < length; i++)
        {
            if(dict[arr[i]] != s[i])
            {
                if(dict[arr[i]])
                {
                    ans = 0;
                    break;
                }
                dict[arr[i]] = s[i];
            }
        }

        memset(dict, 0, sizeof(dict));

        cout << (ans ? "YES" : "NO") << endl;
    }
}