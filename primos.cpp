#include <bits/stdc++.h>
#include <time.h>

// #define int unsigned long
using namespace std;

vector<int> primos;

bool isPrime(int n)
{
    if (n < primos[primos.size() - 1])
        return binary_search(primos.begin(), primos.end(), n);

    for (int i = 0; i < primos.size(); i++)
    {
        if (n % primos[i] == 0)
            return false;
        if(primos[i] * primos[i] > n)
            return true;
    }
    return false;
}

signed main()
{
    //BRUTA PRIMOS
    int n = 3;
    primos.push_back(2);
    primos.push_back(3);
    primos.push_back(5);
    // while(n < 10000000)
    // {
    //     isPrime(n);
    //     n += 2;
    // }
    //COSPE PRIMOS  
    time_t startTime;
    time_t now;
    time(&startTime);
    time(&now);
    int i = primos[primos.size() - 1] + 2;

    while(difftime(now, startTime) <= 5)
    {
        for(int j = 0; j < 100000; j++)
        {
            if(isPrime(i))
                primos.push_back(i);
            i+=2;
        }
        time(&now);
    }
    cout << "NUMEROS CHECADOS: " << i << endl;
    cout << "PRIMOS ENCONTRADOS: " << primos.size() << endl;
    for(auto i : primos)
        cout << i << endl;
    return 0;
}