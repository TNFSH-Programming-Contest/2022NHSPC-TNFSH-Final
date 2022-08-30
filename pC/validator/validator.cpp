#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int M = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int T = inf.readInt(-1000000000, 1000000000);
	inf.readEoln();
	ensure(0<N&&N<=100);
	ensure(0<M&&M<=100);
	ensure(0<M&&M<=100000);
	
	int x = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int y = inf.readInt(-1000000000, 1000000000);
	inf.readEoln();
	ensure(0<=x&&x<N);
	ensure(0<=y&&y<M);

	for(int i=1;i<T;i++){
		int xi = inf.readInt(-1000000000, 1000000000);
		inf.readSpace();
		int yi = inf.readInt(-1000000000, 1000000000);
		inf.readSpace();
		int wi = inf.readInt(-1000000000, 1000000000);
		inf.readEoln();
		ensure(0<=xi&&xi<N);
		ensure(0<=yi&&yi<M);
	}

	inf.readEof();
	
	return 0;
}
