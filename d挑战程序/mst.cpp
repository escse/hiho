#include <iostream>
#include <algorithm>
using namespace std;
//minimium spanning tree

//prim
struct edge                       /*构建小顶堆*/
{
    int to;
    int dis;
    bool operator < (const edge& t) const{
        return dis>t.dis;
    }
};

int priority_queue_prim()
{
    vector<edge> G[maxn];
    priority_queue<edge> q; 
    bool vis[maxn]; 
    memset(vis,false,sizeof(vis));
    
    /*维护一个与1号节点相连的边的集合，然后每次在其中找出最小的边*/
    for(int i=0; i<G[1].size(); ++i){
        q.push(G[1][i]);
    }

    vis[1]=true;              /*第一个点标记访问*/
    int ret=0;                /*统计权值*/
    int cnt=N-1;              /*所有点是否访问*/
    while(!q.empty() &&cnt)
    {
        edge p=q.top(); q.pop();
        if(vis[p.to]) continue;
        ret+=p.dis;
        cnt--;
        vis[p.to]=true;       /*将这条边连接的点加入到1号节点中，然后用新加入节点连接出的几条边去更新优先队列*/
        for(int i=0; i<G[p.to].size(); ++i){
            edge pp=G[p.to][i];
            if(!vis[pp.to]) q.push(pp);
        }
    }
   printf("%d\n",ret);
}

//kruskal ??
class DisjointSet {
public:
    DisjointSet(): rank(nullptr), par(nullptr), size(0){}
    DisjointSet(int n) {
        size = n;
        rank = new int[2 * n];
        par  = rank + n;
        for (int i = 0; i < n; ++i) {
            rank[i] = 0;
            par[i] = i;
        }
    }

    ~DisjointSet() {
        delete rank;
    }

    int set_size(int n) {
        size = n;
        if (rank != nullptr) delete rank;
        rank = new int[2 * n];
        par  = rank + n;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    

private:
    int *rank;
    int *par;
    int size;
};


struct edge {int u, v, cost;};
edge es[MAX_E];
int V, E;
int kruskal() {
    sort(es, es+E, comp);
    init_union_find(V);
    int res = 0;
    for (int i = 0; i < E; ++i) {
        edge& e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}


int main(int argc, const char *argv[]) {
    
    return 0;
}