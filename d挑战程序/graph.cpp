#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


//bellman-ford
struct edge {int from, to, cost;};
edge es[MAX_E];
int d[MAX_D];
int V, E;
//不存在负圈，因此不会经过同一条边2次，while最多执行v-1次
void shortestpath(int s) {
    for (int i = 0; i < V; ++i) {
        d[i] = numeric_limits<int>::max();
    }
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge& e = es[i];
            if (d[e.from] != numeric_limits<int>::max() && d[e.to] > d[e.from] + e.cost) {
                update = true;
                d[e.to] = d[e.from] + e.cost;
            }
        }
        if (!update) break;
    }
}

//
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V]
int V;
void dijkstras(int s) {
    fill(d, d+V, numeric_limits<int>::max());
    fill(used, used+V, 0);
    d[s] = 0;
    while (true) {
        int v = -1;
        //找到最小的点
        for (int u = 0; u < V; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; ++u) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}


//
#include <queue>
struct edge {int to, cost;};
using P = pair<int, int>;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstras(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, numeric_limits<int>::max());
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
            edge& e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

//floyd-warshall 算法


int main(int argc, const char *argv[]) {
    
    return 0;
}