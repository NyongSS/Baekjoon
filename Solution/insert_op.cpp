#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

int N, k;
vector<int> v;
int oper [4];

int m = MAX;
int M = -MAX;

int calc(int count, int result) {

    //연산이 끝나면 최댓값, 최솟값 갱신
    if (N == count) {
        if (m > result) m = result;
        if (M < result) M = result;
        return;
    }
    if (oper[0] != 0) {
        oper[0]--;
        int ns = result + v[count];
        calc(count + 1, ns);
        oper[0]++;
    }
    if (oper[1] != 0) {
        oper[1]--;
        int ns = result - v[count];
        calc(count + 1, ns);
        oper[1]++;
    }
    if (oper[2] != 0) {
        oper[2]--;
        int ns = result * v[count];
        calc(count + 1, ns);
        oper[2]++;
    }
    if (oper[3] != 0) {
        oper[3]--;
        int ns = result / v[count];
        calc(count + 1, ns);
        oper[3]++;
    }
}


int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
    v.push_back(k);
    }
    cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

    calc(v[0], 1);

    cout << M << "\n" << m << "\n"<<endl;
    return 0;
}
