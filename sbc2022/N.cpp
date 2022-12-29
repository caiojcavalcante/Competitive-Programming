#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

vector<pair<int, int>> v;
multiset <int> not_selected, selected;

signed main()
{
    int n, k, l, a, ans, s1 = 0, s2 = 0;

    cin >> n;

    rep(i, 0, n)
    {
        cin >> a;
        v.push_back({a, 0});
    }
    rep(i, 0, n)
    {
        cin >> a;
        v[i].second = a;
    }

    cin >> k >> l;

    rep(i, 0, k)
    {
        s1 += v[i].first;

        if(i < l)
        {
            s2 += v[i].second;
            selected.insert(v[i].second);
        }
        else if(v[i].second > *selected.begin())
        {
            s2 -= *selected.begin();
            not_selected.insert(*selected.begin());
            selected.erase(selected.begin());
            selected.insert(v[i].second);
            s2 += v[i].second;
        }
        else
            not_selected.insert(v[i].second);
    }
    
    ans = s1 + s2;

    for(int i = k - 1; i >= 0; i--)
    {
        //remove da frente

        s1 -= v[i].first;

        if(selected.find(v[i].second) != selected.end())
        {
            s2 -= v[i].second;
            selected.erase(selected.find(v[i].second));

            if(not_selected.size() > 0)
            {
                int aux = *not_selected.rbegin();
                selected.insert(aux);
                not_selected.erase(not_selected.find(aux));
                s2 += aux;
            }
        }
        else
            not_selected.erase(not_selected.find(v[i].second));

        //adiciona de tras
        s1 += v.back().first;

        if(v.back().second > *selected.begin())
        {
            int aux = *selected.begin();
            selected.erase(selected.find(aux));
            s2 -= aux;
            not_selected.insert(aux);
            selected.insert(v.back().second);
            s2 += v.back().second;
        }
        else
            not_selected.insert(v.back().second);

        v.pop_back();
        ans = max(ans, s1 + s2);
    }

    cout << ans << endl;
}