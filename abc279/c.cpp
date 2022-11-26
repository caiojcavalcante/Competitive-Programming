#include <bits/stdc++.h>

using namespace std;

unordered_multiset<string> hash_map;

int main()
{
    int a, b, ans = 0, index;
    scanf("%d %d", &a, &b);
    char s[b + 1][a + 1], t[b + 1][a + 1];

    memset(s, '\0', sizeof(s));
    memset(t, '\0', sizeof(s));

    for(int j = 0; j < a; j++)
        for(int i = 0; i < b; i++)
            scanf(" %c", &s[i][j]);

    for(int i = 0; i < b; i++)
        hash_map.insert(s[i]);

    for(int j = 0; j < a; j++)
        for(int i = 0; i < b; i++)
            scanf(" %c", &t[i][j]);

    for(int i = 0; i < b; i++)
    {
        if (hash_map.find(t[i]) != hash_map.end())
        {
            hash_map.erase(hash_map.find(t[i]));
            ans++;
        }
    }

    printf("%s\n", ans == b ? "Yes" : "No");
    return 0;
}