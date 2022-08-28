#include <bits/stdc++.h>
#include "testlib.h"
#define LL long long 
using namespace std;

void gen_norm(LL MIN_V, LL MAX_V) {
	int N = rnd.next(1, 100);
	int M = rnd.next(1, 100);
	int T = rnd.next(MIN_V, MAX_V);
	int x = rnd.next(0, N-1);
	int y = rnd.next(0, M-1);
	cout<<N<<" "<<M<<'\n';
	cout<<T<<'\n';
	cout<<x<<" "<<y<<'\n';
	
	for(int i=1;i<T;i++){
		int xi = rnd.next(0, N-1);
		int yi = rnd.next(0, M-1); 
		int wi = rnd.next(1, 1000000000); 
		cout<<xi<<" "<<yi<<" "<<wi<<'\n';
	} 
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

