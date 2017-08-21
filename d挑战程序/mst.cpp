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
struct edge {int u, v, cost;};
edge es[MAX_E];
int V, E;
int kruskal() {
    sort(es, es+E, comp);

}


int main(int argc, const char *argv[]) {
    
    return 0;
}