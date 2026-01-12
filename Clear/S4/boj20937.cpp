#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int *c = new int[50001];
    bool *isExist = new bool[50001];
    for(int i = 0; i < 50001; i++) { isExist[i] = false; c[i] = 0; }

    int input = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if(!isExist[input]) isExist[input] = true; 
        c[input]++;
    }

    int max = 0;
    for (int i = 0; i < 50001; i++) {
        if(isExist[i] & max < c[i]) max = c[i]; 
    }

    cout << max << '\n';

    delete c;

    return 0;
}