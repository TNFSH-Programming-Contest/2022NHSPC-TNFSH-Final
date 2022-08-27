#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int mxN = 1e6, V = 1e9;

int main(int argc,char *argv[]){
	registerValidation(argc,argv);

	int n = inf.readInt(1,mxN,"n");
	inf.readSpace();
	int q = inf.readInt(1,mxN,"q");
	inf.readEoln();

	for(int i=0;i<n;i++){
		if(i)
			inf.readSpace();
		int x = inf.readInt(1,V,"a_i");
	}
	inf.readEoln();

	set<int>s;
	while(q--){
		int k = inf.readInt(1,V,"k");
		ensuref(!s.count(k), "k has occured more than once\n");
		ensuref(k>=n, "k is not greater or equal to n\n");
		s.insert(k);
		inf.readEoln();
	}
	inf.readEof();
}
