#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define endl '\n'

using namespace std;

void solve()
{
    bool ans = true;
    string s;
    cin >> s;
    if(s[0] < 'A' || s[0] > 'Z') ans = false;
    rep(i, 1, 7)
    {
        if(s[i] < '0' || s[i] > '9') ans = false;
    }
    if(s[7] < 'A' || s[7] > 'Z') ans = false;
    if(sz(s) != 8) ans = false;
    cout << (ans ? "Yes" : "No") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int casos = 1;
    //cin >> casos;
    while(casos--)
    {
        solve();
    }
}