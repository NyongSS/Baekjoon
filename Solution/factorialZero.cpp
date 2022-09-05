#include <iostream>
using namespace std;
/*
- 1~N까지의 숫자에서  5^1 = 5의 배수, 5^2 = 25의 배수, 5^3 = 125의 배수, 5^k이 n보다 작을 때 까지 이들의 개수를 구함.
- 이 개수는 N / 5^1 + N / 5^2 + N / 5^3 + ... 이런 방식으로 구할 수 있음.  
*/

int main() {
    int ans = 0;
    
    int n;
    cin >> n;
    
    for (int i=5; i<=n; i*=5)
        ans += n/i;
        
    cout << ans << '\n';
}


/*

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


*/
