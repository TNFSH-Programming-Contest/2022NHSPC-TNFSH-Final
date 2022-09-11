#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=1e9+7;
LL dp[2][1000005];
int main(){ 
	ios::sync_with_stdio(0);cin.tie(0);
	LL m,s,e,k;
	cin>>m>>s>>e>>k;
	k--;
	dp[0][s]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=m;j++){
			dp[i%2][j]=0;
			if(j+1<=m){
				dp[i%2][j]+=dp[(i+1)%2][j+1];
				dp[i%2][j]%=mod;
			}
			if(j-1>=0){
				dp[i%2][j]+=dp[(i+1)%2][j-1];
				dp[i%2][j]%=mod;
			}
		}
	}
	cout<<dp[k%2][e]<<'\n';
	return 0;
}

