#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    bool possible = true;
    int *matrix = new int[10001];
    queue<int> q;
    int input;

    cin >> n >> m;

    for (int i = 0; i < n * m; i++) {
        scanf("%d", &input);
        getchar();

        if(!matrix[input]) {
            q.push(input);
        }
        matrix[input]++;
    }

    int tmp;
    if (m % 2 == 0) {
        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            if(matrix[tmp] % 2 == 1) {
                possible = false;
                break;
            }
        }
    }
    else {
        int middle = 0;
        while(!q.empty()) {
            tmp = q.front();
            q.pop();

            if(matrix[tmp] % 2 == 1 && middle == n) {
                possible = false;
                break;
            }
            else if(matrix[tmp] % 2 == 1) {
                middle++;
            }
        }
    }

    if(possible) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}