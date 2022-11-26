#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3], n;
    cin >> a[0] >> a[1] >> n;
    
    n %= 3;

    a[2] = a[0] ^ a[1];

    cout << a[n] << endl;
    return 0;
}