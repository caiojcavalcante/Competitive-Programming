#include <bits/stdc++.h>
#include <time.h>

// #define int unsigned long
using namespace std;

vector<int> primos;

bool isPrime(int n)
{
    if (n < primos[primos.size() - 1])
        // return binary_search(primos.begin(), primos.end(), n);
        return true;

    if(n < 10e12)
        for (int i = 0; i < primos.size(); i++)
        {
            if (n % primos[i] == 0)
                return false;
            if(primos[i] * primos[i] > n)
            {
                primos.push_back(n);
                return true;
            }
        }
    cout << "limites excedidos" << endl;
    return false;
}

signed main()
{
    //BRUTA PRIMOS
    int n = 3;
    primos.push_back(2);
    primos.push_back(3);
    primos.push_back(5);
    while(n < 10000000)
    {
        isPrime(n);
        n += 2;
    }
    //COSPE PRIMOS  
    time_t startTime;
    time_t now;
    time(&startTime);

    int i = primos[primos.size() - 1] + 2;

    while(difftime(now, startTime) <= 60)
    {
        for(int j = 0; j < 100000; j++)
        {
            isPrime(i);
            i+=2;
        }
        time(&now);
    }
    cout << "NUMEROS CHECADOS: " << i << endl;
    cout << "PRIMOS ENCONTRADOS: " << primos.size() << endl;
    for(int k = 0; k < primos.size(); k++)
    {
        cout << primos[k] << endl;
    }
    return 0;
}