#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, m;
    cin >> n >> a >> b >> m;

    int *score = new int[n];
    int *room = new int[n];
    int *changeStack = new int[n];
    for (int i = 0; i < n; i++) { room[i] = i; changeStack[i] = 0; }

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
        else posDays = 0; 

        if (i == m - 1) break;

        // 상벌점 입력 받기
        for(int j = 0; j < n; j++) cin >> score[j]; 
        int minus;
        for(int j = 0; j < n; j++) {
            cin >> minus;
            score[j] -= minus;
            score[j] += changeStack[j];
        }

        for (int i = 0; i < n; i++) changeStack[i] = 0;

        // 상벌점 계산을 통한 방 바꾸기
        for (int j = 0; j < n - 1; j++) {
            int p, q;
            p = score[room[j]];
            q = score[room[j + 1]];

            if ( ( p > 0 && q > 0 && q - p >= 2 ) || 
            ( p < 0 && q > 0 ) || 
            ( p < 0 && q < 0 && q - p >= 4 ) ) {
                if(room[j] == hongPos) hongPos = room[j + 1];
                if(room[j + 1] == hongPos) hongPos = room[j];
                if(room[j] == joPos) joPos = room[j + 1];
                if(room[j + 1] == joPos) joPos = room[j];

                int tmp;
                tmp = room[j];
                room[j] = room[j + 1];
                room[j + 1] = tmp;

                changeStack[room[j]] -= 2;
                changeStack[room[j + 1]] += 2;
            }
        }
        
    }

    cout << posDay << ' ' << maxPosDays;

    delete score;
    delete changeStack;
    delete room;

    return 0;
}