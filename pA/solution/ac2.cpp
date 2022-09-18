#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int n,q;
long long a[N];
long long ans[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for(int k=1;k<=n;k++){
		long long mn = 1e18+10;
		for(int i=1;i<=n;i+=k)
			mn = min(mn, a[min(n,i+k-1)]-a[i-1]);
		ans[k] = mn;
	}
	while(q--){
		int k;
		cin >> k;
		cout << ans[min(n,k)] << '\n';
	}
}
