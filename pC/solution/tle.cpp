#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL N,M,T;
LL x[100005],y[100005],w[100005];
LL dp[105][105][3][3];
LL MAX(LL a,LL b,LL t){
	LL res=-1e18;
	res=max(res,dp[a-1][b][t][0]);
	res=max(res,dp[a+1][b][t][0]);  
	res=max(res,dp[a][b-1][t][0]);
	res=max(res,dp[a][b+1][t][0]);
	res=max(res,dp[a-1][b][t][1]);
	res=max(res,dp[a+1][b][t][1]);
	res=max(res,dp[a][b-1][t][1]);
	res=max(res,dp[a][b+1][t][1]);
	return res;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>T;
	for(int i=0;i<T;i++){
		cin>>x[i]>>y[i];
		if(i>0)cin>>w[i];
		x[i]++;
		y[i]++;
	}
	for(int a=0;a<=N+1;a++){
		for(int b=0;b<=M+1;b++){
			dp[a][b][0][0]=dp[a][b][0][1]=-1;
			dp[a][b][1][0]=dp[a][b][1][1]=-1;
		}
	}
	dp[x[0]][y[0]][0][0]=dp[x[0]][y[0]][0][1]=0;
	for(int i=1;i<=T;i++){
		LL t=i%2;
		for(int a=1;a<=N;a++){
			for(int b=1;b<=M;b++){
				if(abs(a-x[0])+abs(b-y[0])>i)continue;
				if(a==x[i-1]&&b==y[i-1]){
					dp[a][b][t][0]=max(dp[a][b][t][0],max(max(dp[a][b][t^1][0]+w[i-1],dp[a][b][t^1][1]),MAX(a,b,t^1)+w[i-1]));
					dp[a][b][t][1]=max(dp[a][b][t][1],dp[a][b][t][0]);
				}
				if(a==x[i]&&b==y[i]){
					dp[a][b][t][0]=max(dp[a][b][t][0],max(max(dp[a][b][t^1][0],dp[a][b][t^1][1]),MAX(a,b,t^1)));
					dp[a][b][t][1]=max(dp[a][b][t][1],dp[a][b][t][0]+w[i]);
				}
				if((a!=x[i]||b!=y[i])&&(a!=x[i-1]||b!=y[i-1])){
					dp[a][b][t][0]=max(dp[a][b][t][0],max(max(dp[a][b][t^1][0],dp[a][b][t^1][1]),MAX(a,b,t^1)));
					dp[a][b][t][1]=max(dp[a][b][t][1],dp[a][b][t][0]);
				} 
			}
		} 
	}
	LL ans=0;
	for(int a=1;a<=N;a++){
		for(int b=1;b<=M;b++){
			ans=max(ans,dp[a][b][T%2][0]);
			ans=max(ans,dp[a][b][T%2][1]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
