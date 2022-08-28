#include<bits/stdc++.h>
#define LL long long 
using namespace std;
LL N,a;
multiset<LL,greater<LL>> st;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a;
		if(st.upper_bound(a)!=st.end()){
			st.erase(st.upper_bound(a));
		}
		st.insert(a);
	}
	cout<<st.size()<<'\n';  
	return 0;
}

