#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

const int mxN = 1e6, mxV = 1e9;

void gen_task1(bool Max){
	int n = rnd.next(1,mxN), q = rnd.next(1,mxN);
	if(Max)
		n = mxN, q = mxN;
	cout << n << ' ' << q << '\n';
	for(int i=0;i<n;i++)
		cout << rnd.next(1,mxV) << " \n"[i==n-1];
	set<int>s;
	while(q--){
		int k;
		do{
			k = rnd.next(n+1,mxV);
		}while(s.count(k));
		s.insert(k);
		cout << k << '\n';
	}
}

void gen_task(int N, bool Max){
	int n = rnd.next(1,N), q = rnd.next(1,N);
	if(Max)
		n = N, q = N;
	cout << n << ' ' << q << '\n';
	for(int i=0;i<n;i++)
		cout << rnd.next(1,mxV) << " \n"[i==n-1];
	int q1 = min(n,9*q/10);
	int q2 = q-q1;
	set<int>s;
	vector<int>v,tmp;
	for(int i=1;i<=n;i++)
		tmp.push_back(i);
	shuffle(tmp.begin(), tmp.end());
	while(q1--){
		v.push_back(tmp.back());
		tmp.pop_back();
	}
	while(q2--){
		int k;
		do{
			k = rnd.next(n+1,mxV);
		}while(s.count(k));
		s.insert(k);
		v.push_back(k);
	}
	shuffle(v.begin(), v.end());
	for(auto i:v)
		cout << i << '\n';
}

int main(int argc,char *argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	registerGen(argc,argv,1);

	int task_num = atoi(argv[1]);
	if(task_num==1)
		gen_task1((argv[2]=="max"));
	else
		gen_task(mxN, (argv[2]=="max"));
}


