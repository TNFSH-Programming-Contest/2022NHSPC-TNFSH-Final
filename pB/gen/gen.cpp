#include <bits/stdc++.h>
#include "testlib.h"
#define LL long long 
using namespace std;

void gen_norm(LL MIN_V, LL MAX_V) {
	int N = rnd.next(MIN_V, MAX_V);
	cout<<N<<'\n';
	
	for(int i=0;i<N;i++){
		int ai = rnd.next(1, 1000000000);
		cout<<ai<<" ";
	}
	cout<<'\n';
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1); 

	string MODE = argv[1];

	if (MODE == "norm") {
		LL MIN_V = atoll(argv[2]);
		LL MAX_V = atoll(argv[3]);
		
		gen_norm(MIN_V, MAX_V);
	} else {
		return -1;  
	}
}

