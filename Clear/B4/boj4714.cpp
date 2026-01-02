#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    float f;
    while(1) {
        scanf("%f", &f);
        if(f < 0) break;
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", f, f * 0.167);
    }

    return 0;
}