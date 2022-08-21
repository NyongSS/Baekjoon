#include <iostream>
using namespace std;
/*﻿N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.*/

int main(void) {
	int N, n, k = 1, result = 0;
	cin >> N;
	n = N;
	for (int i = 0; i < N; i++) {
		k *= n;
		n--;
	}
	while (k != 0) {
		if (k % 10 == 0) result++;
		k /= 10;
	}

	cout << result;
	return 0;
}
