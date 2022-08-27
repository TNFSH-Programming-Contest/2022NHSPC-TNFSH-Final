#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL N,M,T;
LL x[100005],y[100005],w[100005];
LL arr[100005][3],Max[100005];
LL ans=0;
LL Dis(LL a,LL b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);  
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>T;
	cin>>x[0]>>y[0];
	for(int i=1;i<T;i++){
		cin>>x[i]>>y[i]>>w[i];
		arr[i][0]=arr[i][1]=Max[i]=-1e18;
	}
	for(int i=1;i<T;i++){
		if(i-N-M>=0)arr[i][0]=arr[i][1]=Max[i-N-M]+w[i];
		for(int j=max((LL)0,i-N-M);j<i;j++){
			LL dis=Dis(i,j);
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					if(i+k-j-l>=dis&&arr[j][l]>=0){
						arr[i][k]=max(arr[i][k],arr[j][l]+w[i]);
					}
				}
			}
		}
		Max[i]=max(Max[i],Max[i-1]);
		for(int j=0;j<2;j++){
			Max[i]=max(Max[i],arr[i][j]);
		}
		ans=max(ans,Max[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
