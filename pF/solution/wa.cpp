#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=1e9+7;
LL arr[1000005];
LL Exp(LL q,LL t){
	LL res=1,x=q;
	while(t){ 
		if(t%2)res=res*x%mod;
		x=x*x%mod;
		t/=2;
	}
	return res;
}
LL C(LL p,LL q){
	LL res=arr[p];
	res=res*Exp(arr[q],mod-2)%mod;
	res=res*Exp(arr[p-q],mod-2)%mod;
	return res;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	LL m,s,e,k;
	cin>>m>>s>>e>>k;
	k--;
	if((k-e+s)%2){
		cout<<0<<'\n'; 
		return 0;
	}
	arr[0]=1;
	for(int i=1;i<=k;i++){
		arr[i]=arr[i-1]*i%mod;
	}
	LL x=(k-e+s)/2,y=x+e-s;
	LL a=m-e+1,b=e+1;
	LL ans=0;
	if(x>=0&&y>=0)ans+=C(k,x);
	if(x>=a){
		ans-=C(k,x-a);
		ans=(ans+mod)%mod;
	}
	if(y>=b){
		ans-=C(k,y-b);
		ans=(ans+mod)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}

