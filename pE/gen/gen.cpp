#include<bits/stdc++.h>
#include<bits/extc++.h>
#include"testlib.h"
using namespace std;
using namespace __gnu_pbds;

const int mxN = 2e5;
const int V = 1e9;

tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>tr;

void gen_task(int N, vector<int>task_type, bool type3, bool Mx){ 
	int n = rnd.next(1,N), q = rnd.next(1,N);
	if(Mx)
		n = q = N;
	cout << n << ' ' << q << '\n';
	map<int,int>cnt;
	for(int i=0;i<n;i++){
		int x = rnd.next(-V,V);
		tr.insert(x);
		cnt[x]++;
		cout << x << " \n"[i==n-1];
	}
	while(q--){
		int type = rnd.any(task_type);
		if(type==1){
			int x = rnd.next(-V,V);
			tr.insert(x);
			cnt[x]++;
			cout << 1 << ' ' << x << '\n';
			n++;
		}
		else if(type==2){
			int x = rnd.next(-V,V);
			tr.insert(x);
			cnt[x]++;
			cout << 2 << ' ' << x << '\n'; 
			n++;
		}
		else if(type==3){
			int s = tr.size();
			int x = *tr.find_by_order(rnd.next(s));
			if(type3)
				cout << 3 << ' ' << x << ' ' << 1 << '\n';
			else	
				cout << 3 << ' ' << x << ' ' << rnd.next(1,cnt[x]) << '\n';
			cnt[x]--;
			if(!cnt[x])
				tr.erase(x);
			n--;
		}
		else{
			int l = rnd.next(1,n), r = rnd.next(1,n);
			if(l>r)
				swap(l,r);
			cout << 4 << ' ' << l << ' ' << r << '\n';
		}
	}
}

int main(int argc,char *argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	registerGen(argc,argv,1);
	
	int task_num = atoi(argv[1]);
	int n = mxN, type3 = 0, Mx = 0;
	vector<int>v{1,2,3,4};
	if(task_num==1)
		v = {1,2};
	else if(task_num==2)
		n = 1000;
	else if(task_num==3)
		type3 = 1;
	if(argv[2]=="max")
		Mx = 1;
	gen_task(n,v,type3,Mx);
}
