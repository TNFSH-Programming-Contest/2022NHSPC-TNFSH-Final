#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() { 
	registerValidation();

	int m = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int s = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int e = inf.readInt(-1000000000, 1000000000);
	inf.readSpace();
	int k = inf.readInt(-1000000000, 1000000000);
	inf.readEoln();  

	inf.readEof();

	ensure(2<=k&&k<=1000000);
	ensure(0<m&&m<=1000000);
	ensure(0<=s&&s<=m);
	ensure(0<=e&&e<=m);
	
	return 0;
}
