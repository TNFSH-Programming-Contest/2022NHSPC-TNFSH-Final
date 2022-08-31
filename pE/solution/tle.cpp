#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
 
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))
 
using namespace std;
//using namespace __gnu_pbds;
using pii = pair<long long,long long>;
using ld = long double;
using ll = long long;
 
mt19937 mtrd(chrono::steady_clock::now().time_since_epoch().count());
 
const int mod = 1000000007;
const int mod2 = 998244353;
const ld PI = acos(-1);
 
#define Bint __int128
#define int long long
/* ----------------------------------------  */
 
int n,q;

void solve(){
	cin >> n >> q;
	deque<int>a;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.pb(x);
	}
	while(q--){
		int type;
		cin >> type;
		if(type==1){
			int x;
			cin >> x;
			a.pb(x);
		}
		else if(type==2){
			int x;
			cin >> x;
			a.pf(x);
		}
		else if(type==3){
			int t,x;
			cin >> x >> t;
			deque<int>tmp;
			int cnt = 0;
			for(int i=0;i<a.size();i++){
				if(a[i]==x)
					cnt++;
				if(cnt!=t || a[i]!=x)
					tmp.pb(a[i]);
			}
			a = tmp;
		}
		else{
			int l,r;
			cin >> l >> r;
			l--,r--;
			int sum = 0;
			for(int i=l;i<=r;i++)
				sum += a[i];
			cout << sum << '\n';
		}
	}
	for(auto i:a)
		cout << i << ' ';
	cout << '\n';
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

