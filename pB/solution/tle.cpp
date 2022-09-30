#include<bits/stdc++.h>
#define LL long long 
using namespace std;
LL N,a[2000005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	LL ans=0,now;
	for(int i=0;i<N;i++){
		if(a[i]!=-1){
			ans++;
			now=a[i];
			a[i]=-1;
			for(int j=i+1;j<N;j++){
				if(a[j]>now){
					now=a[j];
					a[j]=-1;
				}
			}
		}
	}
	cout<<ans<<'\n';  
	return 0;
}

