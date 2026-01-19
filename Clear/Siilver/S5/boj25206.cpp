#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char *s = new char[50];
    float f;
    char *c = new char[2];
    float totalScore = 0;
    float score = 0;
    float count = 0;

    for(int i = 0; i < 20; i++) {
        score = 0;
        scanf("%s %f %s", s, &f, c);
        getchar();

        if(c[0] == 'P') continue;

        switch(c[0]){
            case 'A':
                score = 4;
                break;
            case 'B':
                score = 3;
                break;
            case 'C':
                score = 2;
                break;
            case 'D':
                score = 1;
                break;
            case 'F':
                score = 0;
                break;
        }
        if(c[1] == '+') score += 0.5;

        totalScore += f * score;
        count += f;
    }

    printf("%.6f", totalScore / count);

    return 0;
}