#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


/**
 * 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.
 * 입력 : 첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
 * 출력: 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
 */

//트리 구조체 생성
struct Node{
    int index;               //노드의 값
    int dist;                //노드의 가중치
};

int v, maxDist, maxNode;
bool visit[100001];
vector<Node> graph[100001];

void dfs(int node, int dist)
{
    // 방문한 노드면 return
    if (visit[node])
        return;
    // maxDist 갱신
    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = node;
    }
    visit[node] = true; //방문 체크
    // 현재 정점에서 연결 된 정점들로 dfs 수행
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextIndex = graph[node][i].index;
        int nextDist = graph[node][i].dist;
        dfs(nextIndex, nextDist + dist);
    }
}

int main(){
    ios_base::sync_with_stdio(false);       //c와 c++의 버퍼를 분리해서 c++만의 독립적인 버퍼가 생성
    cin.tie(NULL);                          //cin을 cout으로부터 untie한다.
    cout.tie(NULL);

    cin >> v;                               //가장 처음 정점 번호를 받는다
    int fr, to, dist;
    for (int i = 1; i < v + 1; i++)         //정점의 번호가 될 때까지 입력을 받는다 
    {
        cin >> fr;
        while (true)
        {
            cin >> to;
            if (to == -1)
                break;
            cin >> dist;
            graph[fr].push_back({to, dist});
            graph[to].push_back({fr, dist});
        }
    }

    // 임의의 정점 1에서 가장 거리가 먼 정점 찾기
    dfs(1, 0);
    memset(visit, 0, sizeof(visit)); //메모리 초기화
    maxDist = 0;                     //거리를 0으로 다시 설정
    // 1과 가장 먼 정점에서 다시 dfs 수행하여 트리의 지름 찾기
    dfs(maxNode, 0);

    cout << maxDist << '\n';        //트리의 지름을 출력한다

    return 0;
}
