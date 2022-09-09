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
	while(q--)
		cout << rnd.next(n+1,mxV) << '\n';
}

void gen_task(int N, bool Max){
	int n = rnd.next(1,N), q = rnd.next(1,N), edge = rnx.next(3);
	if(Max)
		n = N, q = N;
	cout << n << ' ' << q << '\n';
	for(int i=0;i<n;i++)
		cout << rnd.next(1,mxV) << " \n"[i==n-1];
	if(edge == 0){
		for(int i=0;i<q;i++)
			cout << rnd.next(1,3) << '\n';
		return;
	}
	int q1 = min(n,9*q/10);
	int q2 = q-q1;
	vector<int>v;
	while(q1--)
		v.push_back(rnx.next(1,n));
	while(q2--)
		v.push_back(rnd.next(n+1,mxV));
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


