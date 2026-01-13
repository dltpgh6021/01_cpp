#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, m;
    cin >> n >> a >> b >> m;

    int *score = new int[n];
    int *changeStack = new int[n];
    for(int i = 0; i < n; i++) changeStack[i] = 0;
    int hongPos = 0;
    int joPos = a - 1;
    int posDay = 0;
    int posDays = 0;
    int maxPosDays = 0;

    for(int i = 0; i < m; i++) {
        // 홍군이 기분좋은 날 계산
        if(abs(joPos - hongPos) <= b) {
            posDay++;
            posDays++;
            if(maxPosDays < posDays) maxPosDays = posDays;
        }
        else {
            posDays = 0;
        }
        if (i == m - 1) break;
        // 상벌점 입력 받기
        for(int j = 0; j < n; j++) cin >> score[j]; 
        int minus;
        for(int j = 0; j < n; j++) {
            cin >> minus;
            score[j] -= minus;
            score[j] += changeStack[j];
        }
        for(int j = 0; j < n; j++) changeStack[j] = 0;

        // 상벌점 계산을 통한 방 바꾸기
        for (int j = 0; j < n - 1; j++) {
            if ((score[j] >= 0 && score[j + 1] >= 0 && score[j + 1] - score[j] >= 2) || 
            (score[j] < 0 && score[j + 1] >= 0) || 
            (score[j] < 0 && score[j + 1] < 0 && score[j + 1] - score[j] >= 4)) {
                int t;
                t = score[j + 1];
                score[j + 1] = score[j];
                score[j] = t;

                if (joPos == j) joPos++;
                if (joPos == j + 1) joPos--;
                if (hongPos == j) hongPos++;
                if (hongPos == j + 1) hongPos--;

                if(changeStack[j] > 0) {
                    changeStack[j + 1] = 2 + changeStack[j];
                    changeStack[j] = -2;
                }
                else changeStack[j] = -2;
            }

        }
        
    }

    cout << posDay << ' ' << posDays;

    delete score;

    return 0;
}