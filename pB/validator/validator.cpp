#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(-1000000000, 1000000000);
	inf.readEoln();
	
	ensure(0<N&&N<=2000000);
	
	for(int i=0;i<N;i++){
		int ai = inf.readInt(-1000000000, 1000000000);
		inf.readSpace();
	}
	inf.readEoln();

	inf.readEof();  
	
	return 0;
}
