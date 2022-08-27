#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

void gen_norm(long long MIN_V, long long MAX_V) {
	int m = rnd.next(MIN_V, MAX_V); 
	int s = rnd.next(0, m);
	int e = rnd.next(0, m);
	int k = rnd.next(MIN_V, MAX_V);
	if((k-s+e)%2)k++;
	if(k>MAX_V)k-=2;

	cout<<m<<" "<<s<<" "<<e<<" "<<k<<'\n';
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1); //

	string MODE = argv[1];

	if (MODE == "norm") {
		long long MIN_V = atoll(argv[2]);
		long long MAX_V = atoll(argv[3]);
		
		gen_norm(MIN_V, MAX_V);
	} else {
		return -1; 
	}
}
