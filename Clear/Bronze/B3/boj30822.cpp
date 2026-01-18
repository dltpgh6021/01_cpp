#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int uospc[5] = {0, 0, 0, 0, 0};
    int n = 0;

    int min = 1000;
    int max = 0;

    cin >> n;
    char *S = new char[n + 1];

    cin >> S;

    for(int i = 0; i < n; i++) {
        switch(S[i]) {
            case 'u': 
            uospc[0]++;
            break;
            case 'o':
            uospc[1]++;
            break;
            case 's':
            uospc[2]++;
            break;
            case 'p':
            uospc[3]++;
            break;
            case 'c':
            uospc[4]++;
            break;
        }
    }

    for(int i = 0; i < 5; i++) {
        if(min > uospc[i]) min = uospc[i];
        if(max < uospc[i]) max = uospc[i];
    }

    if(min == 1000) min == 0;

    cout << min;

    delete S;

    return 0;
}