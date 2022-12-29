#include <bits/stdc++.h>
#define int long long
#define CIMA 1
#define BAIXO 2
#define ESQUERDA 3
#define DIREITA 4
#define DEBUG 10
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int n, ans, laser_x, laser_y, temp_x, temp_y, max_x = 0, max_y = 0, total_pintado = 0;

bool mx[1005][1005], my[1005][1005], m[1005][1005];

int paint(int x, int y, int dir)
{
    if(x < 0 || y < 0)
        return 0;

    if(x > max_x + 1 || y > max_y + 1)
        return 0;

    if(m[x][y])
        return 0;

    if(dir == CIMA && my[x + 1][y] && my[x + 1][y + 1])
        return 0;

    if(dir == BAIXO && my[x][y] && my[x][y + 1])
        return 0;

    if(dir == DIREITA && mx[x][y] && mx[x + 1][y])
        return 0;

    if(dir == ESQUERDA && mx[x][y + 1] && mx[x + 1][y + 1])
        return 0;

    m[x][y] = true;
    total_pintado++;

    int ret = 1;

    ret += paint(x - 1, y, CIMA);
    ret += paint(x + 1, y, BAIXO);
    ret += paint(x, y - 1, ESQUERDA);
    ret += paint(x, y + 1, DIREITA);

    return ret;
}

void cut()
{
    rep(i, 0, n)
    {
        cin >> laser_y >> laser_x;

        mx[temp_x][temp_y] = true;
        my[temp_x][temp_y] = true;

        max_x = max(max_x, laser_x);
        max_y = max(max_y, laser_y);

        for(temp_x; temp_x < laser_x; temp_x++)
            mx[temp_x][laser_y] = true;

        for(temp_x; temp_x > laser_x; temp_x--)
            mx[temp_x][laser_y] = true;

        for(temp_y; temp_y < laser_y; temp_y++)
            my[laser_x][temp_y] = true;

        for(temp_y; temp_y > laser_y; temp_y--)
            my[laser_x][temp_y] = true;        
    }
}

signed main()
{
    cin >> n;

    cin >> temp_y >> temp_x;

    cut();

    //elimina a parte de fora
    paint(0, 0, -1);

    int x = 0, y = 0;

    // rep(i, 0, max_x + 1)
    // {
    //     rep(j, 0, max_y + 1)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(ans < (max_x + 2) * (max_y + 2) - total_pintado)
    {
        if(!m[x][y])
        {
            ans = max(ans, paint(x, y, -1));
        }
        x++;
        if(x > max_x + 1)
        {
            x = 0;
            y++;
        }
    }

    cout << ans << endl;
}
