#include <bits/stdc++.h>
#define endl '\n'
#define YELLOW 1
#define RED 2

using namespace std;

int dict[2] = {0, 0};

signed main()
{
    int casos, length, acc, max_acc, dict_page;
    char c;
    string s;
    cin >> casos;
    for(int i = 0; i < casos; i++)
    {
        cin >> length >> c;

        if(c == 'y')
            dict_page = YELLOW;
        else if(c == 'r')
            dict_page = RED;
        else
        {
            cout << 0 << endl;
            continue;
        }

        acc = 0;
        max_acc = 0;

        for(int i = 0;i < length; i++)
        {
            cin >> s[i];

            if(s[i] == 'r')
                dict[RED]= i;
            else if(s[i] == 'y')
                dict[YELLOW] = i;
            
            else
                acc = i - dict[dict_page];

            max_acc = max(acc, max_acc);
        } 
        
        cout << acc << endl;
    }
    return 0;
}