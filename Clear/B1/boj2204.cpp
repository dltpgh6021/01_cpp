#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    while (n != 0) {
        char **s = new char*[n];
        for (int i = 0; i < n; i++) {
            s[i] = new char[20];
        }

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int smallestIndex = 0;
        for (int i = 0; i < n; i++) {
            if(strcasecmp(s[smallestIndex], s[i]) > 0) {
                smallestIndex = i;
            }
        }

        cout << s[smallestIndex] << '\n';

        delete s;
        cin >> n;
    }

    return 0;
}