#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {
        string s;
        cin >> s;

        if(s == "P=NP") cout << "skipped" << '\n';
        else {
            int a = 0;
            int b = 0;
            int i;
            for (i = 0; i < s.length(); i++) {
                if(s[i] == '+') break;
                else a = (s[i] - '0') + a * 10;
            }
            i++;
            int j = 0;
            for (i; i < s.length(); i++) {
                b = (s[i] - '0') + b * 10;
            }
            cout << a + b << '\n';
        }
    }

    return 0;
}