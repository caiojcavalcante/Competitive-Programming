#include <bits/stdc++.h>

#define WALL '#'
#define PATH '.'
#define END 'E'

char map[100][100];

using namespace std;
int main() {
    int i, j;
    cin >> i >>j;
    for(int n = 0; n < i; n++) {
        cin >> map[n];
    }
    for(int n = 0; n < i; n++) {
        for(int m = 0; m < j; m++) {
            cout << map[n][m];
        }
        cout << endl;
    }
	return 0;
}