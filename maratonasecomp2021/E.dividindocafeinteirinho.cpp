#include <bits/stdc++.h>
#define ll long long
#define li long
#define MAXN 10000000000
#define LARGURA      copos[i][0]
#define PROFUNDIDADE copos[i][1]
#define ALTURA       copos[i][2]

using namespace std;

int t, n;
ll check(li h, ll l, li copos[][3])
{
    for(int i = 0; i < n; i++)
    {
        if (ALTURA < h)
            return -1;
            
        l -= PROFUNDIDADE * LARGURA * h;
    }
    return l;
}

int main()
{
    ll l;
    cin >> t;
    while (t--)
    {
        cin >> n >> l;
        li copos[n][3];
        for(int i = 0; i < n; i++)
            cin >> LARGURA >> PROFUNDIDADE >> ALTURA;

        ll mid, left = 0, right = MAXN, resto;

        while (right - left > 1)
        {
            mid = (left + right) / 2;

            if (check(mid, l, copos) >= 0)
                left = mid;

            else
                right = mid;
        }
        cout << left << ' ' << check(left, l, copos) << endl;
    }
    return 0;
}