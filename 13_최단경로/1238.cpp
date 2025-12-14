#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost)
            continue;

        for (auto [next, w] : graph[now])
        {
            if (dist[next] > cost + w)
            {
                dist[next] = cost + w;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1), reverseGraph(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        reverseGraph[b].push_back({a, t}); // 간선 뒤집기
    }

    vector<int> distFromX = dijkstra(X, graph, N);
    vector<int> distToX = dijkstra(X, reverseGraph, N);

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, distFromX[i] + distToX[i]);
    }

    cout << ans;
    return 0;
}
