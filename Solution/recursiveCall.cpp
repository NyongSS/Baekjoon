#include <iostream>
using namespace std;
/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
**/

//a, b, c중 하나가 음수일 때는 반드시 1이고 하나라도 20보다 크면 w(20, 20, 20)을 리턴하므로
//memo배열은 21, 21, 21을 담고 있으면 될 것이다. 
int memo[21][21][21];
int a, b, c;

int memoization(int a, int  b, int c){
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return memoization(20, 20, 20);
    if (memo[a][b][c])
        return memo[a][b][c];
    if (a < b && b < c) 
        return memo[a][b][c] = memoization(a, b, c - 1) + memoization(a, b - 1, c - 1) - memoization(a, b - 1, c);
    else 
        return memo[a][b][c] = memoization(a - 1, b, c) + memoization(a - 1, b - 1, c) + memoization(a - 1, b, c - 1) - memoization(a - 1, b - 1, c - 1);
}

int main()
{
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ")= " << memoization(a, b, c) << '\n';
    }
	return 0;
}
