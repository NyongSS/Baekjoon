#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int k[100];
int answer = 0;

int blackJack(int n, int m, int k[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int z = j + 1; z < n; z++) {
                if ((abs(k[i] + k[j] + k[z] - m) < abs(answer - m)) && (k[i] + k[j] + k[z] <= m)) {
                    answer = k[i] + k[j] + k[z];
                }
            }
        }
    }
    return answer;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    cout << blackJack(n, m, k);
    return 0;
}
