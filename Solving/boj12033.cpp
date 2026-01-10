#include <iostream>
using namespace std;

void search(int *arr, int n);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int *arr = new int[n * 2];

        for(int j = 0; j < n * 2; j++) cin >> arr[j];
        
        cout << "Case #" << i + 1 << ": ";
        search(arr, n);
        cout << "\n";

        delete arr;
    }

    return 0;
}

void search(int *arr, int n) {
    bool *clear = new bool[n * 2];
    for(int i = 0; i < n * 2; i++) clear[i] = false;

    int i = 0;
    while (i < 2 * n) {
        if(clear[i]) {i++; continue;}

        for (int j = i + 1; j < n * 2; j++) {
            if((arr[i] / 3) * 4 == arr[j]) {
                clear[i] = true;
                clear[j] = true;
                break;
            }
        }
        cout << arr[i] << ' ';

        i++;
    }
    delete clear;
}