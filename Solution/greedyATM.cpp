#include <iostream>
using namespace std;
/*
줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가
주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의
최솟값을 구하는 프로그램을 작성하시오.

첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는
각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)

첫째 줄에 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다.
*/
int N;
int ppl[100];

//pi를 작은 순서로 sorting하는 알고리즘
int sort() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ppl[i] > ppl[j]) {
                int tmp = ppl[i];
                ppl[i] = ppl[j];
                ppl[j] = tmp;
            }
        }
    }
    return *ppl;
}

//sorting한 pi들을 n명 각자에게 누적하여 더하는 알고리즘
void accumulate() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i+1; j++)
            sum += ppl[j];
    }
    //함수의 리턴값 출력
    cout << sum << endl;
}

int main(void) {
    int k;
    //처음 입력 받기 
    cin >> N;
    //처음 입력 받은 숫자가 될 때까지 다음 입력 받기 & 받은 입력들을 배열에 저장해 두기 
    for (int i = 0; i < N; i++)
        cin >> ppl[i];

    //배열을 함수로 넘기기
    sort();
    accumulate();

    return 0;
}

