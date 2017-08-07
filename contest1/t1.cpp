#include <iostream>
#include <vector>  
using namespace std;  
  
const int MAXN = 1000;  
int p[MAXN];  
vector<int> G[MAXN];  
  
void dfs(int u, int fa) {   //递归转化为以u为根的子树，u的父亲为fa  
    int d = G[u].size();        //节点u的相邻点的个数  
    for(int i = 0; i < d; ++i) {    //循环遍历跟这个节点相连接的d个节点。  
        int v = G[u][i];       //节点u的第i个相邻点v  
        if(fa != v) dfs(v, p[v] = u);  //把v的父亲节点设为u，然后递归转化为以v为根的子树  
        //一定要判断v是否和其父亲节点相等！  
    }  
}  
  
int main() {  
    int root, n;
    cin >> n >> root;    //指定根节点。  
    for(int i = 0; i < n-1; i++) {   //输入n-1条边  
        int u, v;  
        cin >> u >> v;  
        G[u-1].push_back(v-1);  
        G[v-1].push_back(u-1);  
    }  
    p[root-1] = -1;   //设定根节点的父亲节点为-1，代表根节点没有父亲节点。  
    dfs(root-1, -1);  
    for(int i = 0; i < n; ++i) {  
        cout << p[i] + 1 << " ";  
    }  
    return 0;  
}