#include <iostream>
#include <deque>
using namespace std;

/*
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. 
(이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

*/



int main(){
    deque<int> dq;                              
    int m, n, cnt = 0;
    cin >> n >> m;                              //사용자에게 n과 m을 입력 받는다 
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);                        //사용자의 입력 값인 n이 될 때까지 뒤에 삽입한다. 
    }
    while (m--)                                 //m개의 숫자 추출. 
    {
        int idx, num;
        cin >> num;                             
        for (int i = 0; i < n; i++)
        {
            if (dq[i] == num)                   //for문을 돌면서 dq에 num이랑 같은 애가 있는지 찾아봄.
            {
                idx = i;                        //idx에 그 원소의 위치를 저장해 둠. 
                break;
            }
        }
        if (idx < dq.size() / 2 + 1)            //그 원소가 dq의 가운데를 기점으로 어디에 있는지에 따라 사용할 알고리즘이 달라진다.
        {
            for (int i = 0; i < dq.size(); i++) //원소가 상대적으로 dq의 앞쪽에 존재한다면, 
            {
                if (dq.front() == num)          //꺼내고자 하는 숫자와 dq의 가장 앞의 숫자가 일치한다면,    
                {
                    dq.pop_front();             //dq의 가장 앞의 수를 삭제한다. 
                    break;
                }
                dq.push_back(dq.front());       //dq의 앞의 수를 가장 뒤로 보낸다. 
                dq.pop_front();                 //그리고 dq의 가장 앞의 수를 삭제한다. 
                cnt++;                          //몇 번이나 회전을 하였는지 cnt에 저장한다. 
            }
        }
        else                                    //원소가 상대적으로 dq의 뒤쪽에 존재한다면, 
        {
            for (int i = 0; i < dq.size(); i++)
            {
                if (dq.front() == num)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;
}
