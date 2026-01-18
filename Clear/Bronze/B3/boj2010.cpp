#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, total = 0, tmp;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        total = total + tmp;
    }

    printf("%d", total - n + 1);

    return 0;
}