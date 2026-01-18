#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int tiles = a + b;
    int maxL = 0;

    for (int i = 1; i * i <= tiles; i++) {
        if (tiles % i == 0) {
            int x = i;
            int y = tiles / i;

            int redTiles = (x + y - 1) * 2 - 2;
            int brownTiles = (x - 2) * (y - 2);

            if(a == redTiles && b == brownTiles) maxL = i;
        }
    }

    if(maxL < (tiles / maxL)) maxL = tiles / maxL;

    cout << maxL << ' ' << tiles / maxL << '\n';

    return 0;
}