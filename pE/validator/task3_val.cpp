#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const int mxN = 100000, V = 1e9;

void validate_test(int n,int q,int query_type_l,int query_type_r,int type3 = 0){
	map<int,int>cnt;
	for(int i=0;i<n;i++){
		if(i)
			inf.readSpace();
		int x = inf.readInt(-V,V,"a_i");
		cnt[x]++;
	}
	inf.readEoln();
	while(q--){
		int type = inf.readInt(1,4,"query type");
        ensuref(type!=3, "find query 3.");
		inf.readSpace();
		if(type==1){
			inf.readInt(-V, V, "query 1");
			n++;
		}
		else if(type==2){
			inf.readInt(-V, V, "query 2");
			n++;
		}
		else if(type==3){
			int x = inf.readInt(-V, V, "query 3");
			inf.readSpace();
			ensuref(cnt[x]>0, "query 3 : x is not in array now");
			inf.readInt(1, (type3 ? 1 : cnt[x]), "query 3 t");
			n--;
			cnt[x]--;
		}
		else{
			int l = inf.readInt(1, n, "query 4 l");
			inf.readSpace();
			int r = inf.readInt(l, n, "query 4 r");
		}
		inf.readEoln();
	}
}

int main(int argc,char *argv[]){
	registerValidation(argc,argv);
	
	int n = inf.readInt(1,mxN, "n");
	inf.readSpace();
	int q = inf.readInt(1,mxN, "q");
	inf.readEoln();

	validate_test(n,q,-1,-1);

	inf.readEof();
}
