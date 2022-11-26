#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char S[H + 1][W + 1], T[H + 1][W + 1];
    
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> S[i][j];
        }
    }
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> T[i][j];
        }
    }

    vector <string> colS, colT;
    /*colS.resize(W + 1); colT.resize(W + 1);

    /*for (int j = 1; j <= W; j++){
        for (int i = 1; i <= H; i++){
            colS[j] += S[i][j];
            colT[j] += T[i][j];
        }
    }

    for (int i = 1; i <= W; i++){
        for (int j = 1; j <= W; j++){
            if (colunsS[i] == colunsT[j]){
                aux[j] = colunsS[i];
            }
        }
    }

    for (int i = 1; i <= W; i++){
        if (aux[i] != colunsT[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;*/
    return 0;
}