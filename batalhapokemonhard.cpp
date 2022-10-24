#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

int ceil_division(int a, int b)
{
    return (a + b - 1) / b;
}

signed main()
{
    int vidaA, vidaB, ataqueA, ataqueB;
    short ganhou;
    cin >> vidaA;
    while(scanf("%lld%lld%lld%lld", &vidaA, &vidaB, &ataqueA, &ataqueB) != EOF)
    {
        // printf("%d %d %d %d\n", vidaA, ataqueA, vidaB, ataqueB);
        while(1)
        {
            if(vidaA <= 0)
            {
                ganhou = 1;
                break;
            }
            if(ceil_division(vidaB, ataqueA) <= ceil_division(vidaA, ataqueB))
            {
                ganhou = 0;
                break;
            }
            cout << endl;
            vidaA -= ataqueB;
            ataqueA += 50;
        }
        cout << endl;
        cout << (ganhou ? "Bezaliel":"Clodes") << endl;
    }
}