#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int i = 1;
    while (true) {
        if (i * i + i + 1 == n) { cout << i << '\n'; break; }
        i++;
    }

    return 0;
}