#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int n, k;
double a[100005];

int check(int x)
{
    double doa = 0, recebe = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > x)
        {
            doa += a[i] - x;
        }
        else
        {
            recebe += x - a[i];
        }
    }
    return doa - (doa * k / 100.) >= recebe;
}
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    double mid, l = 0, r = 1000;
    while (r - l > EPS)
    {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.3lf\n", l);

    return 0;
}