#include <bits/stdc++.h>
#define endl '\n'
using namespace std;	

int main()
{
    int casos, a = 1, b = 2, x, y, amigos, m, n;

    cin >> m;
    
    x = 0;
    y = 0;
    int e = 1;
    int d = 0;
    int sinal = 1;
    int xmove = 1;

    for(int p = 1; p <= m; p++)
    {

        if(e == d)
        {
            e++;
            d = e;
        }
        if(!d)
            xmove = !xmove;
            
        if(xmove)
        {
            cout << "X" << endl;
            x -= sinal;
            d++;
        }

        else
        {
            cout << "Y" << endl;
            y += sinal;
            d++;
        }

        cout << e << "valores" << d << endl;
        cout << x << ':' << y << endl;
        if(y == (a * x + b))
        {
            cout << "fronteira" << endl;
            m++;
        }
    }

    cout << (y > (a * x + b) ? "CIMA" : "BAIXO") << endl;
}
    // for(int i = 0; i < casos; i++)
    // {
    //     cout << "Caso" << i << endl;
    //     cin >> a >> b >> amigos;
        
    //     for(int j = 0; j < amigos; j++)
    //     {
    //         cin >> m >> n;

    //         x = 0;
    //         y = 0;

    //         for(int p = 1; p <= m; m++)
    //         {
    //             if(p % 2)
    //             {
    //                 x += ceil(p / 2.) * (- ((p / 2) % 2));
    //             }
    //             else
    //             {
    //                 y -= ceil(p / 2.) * (- ((p / 2) % 2));
    //             }
    //             if(y == (a*x + b))
    //                 m++;
    //         }

    //         cout << x > y ? "CIMA" : "BAIXO";
    //     }