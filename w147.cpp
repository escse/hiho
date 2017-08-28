#include<bits/stdc++.h>
#define maxn 30050
using namespace std;
int a[maxn][5],b[5][maxn];
bitset<maxn>s[5][maxn],t;    //s[i][j]:第i门课排在j-1之前的编号情况 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=4;j++){
			scanf("%d",a[i]+j);
			b[j][a[i][j]]=i;	 //第j门课排第a[i][j]名的是编号为i的人 
		}
	}
	for(int j=0;j<=4;j++){
		s[j][1]=0;
		for(int i=2;i<=n;i++){
			s[j][i]=s[j][i-1];
			s[j][i].set(b[j][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		t=s[0][a[i][0]];
		for(int j=1;j<=4;j++){
			t&=s[j][a[i][j]];
		}
		printf("%d\n",t.count());
	}
	return 0;
}