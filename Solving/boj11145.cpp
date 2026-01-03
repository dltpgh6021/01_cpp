#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    string s;
    for (int i = 0; i < t; i++) {
        getline(cin, s);
        cout << s;


    }

    return 0;
}