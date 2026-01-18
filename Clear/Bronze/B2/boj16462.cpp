#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int total = 0;
    int input = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        int q = 1;
        int tmp;
        while(input != 0) {
            if (input != 100) {
            tmp = input % 10;
            if(tmp == 0 || tmp == 6) tmp = 9;
            total += tmp * q;
            input /= 10;
            q *= 10;
            }
            else { total += 100; break; }
        }
    }

    cout << round(float(total) / n) << '\n';

    return 0;
}