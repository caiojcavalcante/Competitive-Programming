#include <bits/stdc++.h>
#define ll long long

using namespace std;
map<string, int> mp;

int main()
{
    int palavras, len, max = 0, count;
    string palavra;

    cin >> palavras >> len;

    for(int i = 0; i < palavras; i++)
    {
        cin >> palavra;
        for(int j = 0; j < len; j++)
        {
            if(palavra[j] == '*')
            {
                for(int i = 'a'; i <= 'z'; i++)
                {
                    palavra[j] = i;
                    mp[palavra]++;
                }
                break;
            }
        }
    }

    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        count = i->second;
        if(count > max)
        {
            max = count;
            palavra = i->first;
        }
    }

    cout << palavra << ' ' << max << endl;
    return 0;
}