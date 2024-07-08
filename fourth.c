#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> P; // (weight, vertex)

void prim(vector<vector<P>>& graph, int start) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<P, vector<P>, greater<P>> pq;

    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int wt = edge.first;
            if (!inMST[v] && key[v] > wt) {
                key[v] = wt;
                pq.push({wt, v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != start) {
            cout << "Edge: " << i << " - Cost: " << key[i] << endl;
        }
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<P>> graph(n);

    graph[0].push_back({2, 1});
    graph[0].push_back({3, 3});
    graph[1].push_back({2, 0});
    graph[1].push_back({3, 2});
    graph[1].push_back({1, 3});
    graph[2].push_back({3, 1});
    graph[2].push_back({5, 4});
    graph[3].push_back({3, 0});
    graph[3].push_back({1, 1});
    graph[3].push_back({2, 4});
    graph[4].push_back({5, 2});
    graph[4].push_back({2, 3});

    prim(graph, 0);

    return 0;
}



#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> P; // (weight, vertex)

void dijkstra(vector<vector<P>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int wt = edge.first;
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Vertex: " << i << " - Distance: " << dist[i] << endl;
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<P>> graph(n);

    graph[0].push_back({10, 1});
    graph[0].push_back({5, 3});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({2, 1});
    graph[3].push_back({9, 2});
    graph[3].push_back({2, 4});
    graph[4].push_back({6, 0});
    graph[4].push_back({7, 2});

    dijkstra(graph, 0);

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};

    cout << "Max value: " << knapsack(W, wt, val) << endl;

    return 0;
}
