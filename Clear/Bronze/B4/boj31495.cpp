#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    bool isEmpty = true;

    if(s[0] != '\"' || s[s.length() - 1] != '\"') cout << "CE";
    else if (s.length() == 2) cout << "CE";
    else {
        for(int i = 1; i < s.length() - 1; i++) {
            if (s[i] != ' ') isEmpty = false;
        }
        if (isEmpty) cout << "CE";
        else for(int j = 1; j < s.length() - 1; j++) printf("%c", s[j]);
    }

    return 0;
}