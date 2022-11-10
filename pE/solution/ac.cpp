#include<bits/stdc++.h>
using namespace std;

struct query{
	int op,id,id2;
	query(){}
	query(int x,int y,int z=0){
		op = x, id = y, id2 = z;
	}
};

const int N = 1e5+5;
int n,q;
int a[3*N];
vector<int>v;

int cnt;
int dseg[N*70], L[N*70], R[N*70], root[N<<1|1];

inline int newNode(){
	L[cnt] = -1;
	R[cnt] = -1;
	dseg[cnt] = 0;
	return cnt++;
}

struct dynamic_segtree{
	void modify(int l,int r,int p,int v,int rt){
		if(l==r){
			dseg[rt] += v;
			return;
		}
		int mid = (l+r)>>1;
		if(p<=mid){
			if(L[rt]==-1)
				L[rt] = newNode();
			modify(l,mid,p,v,L[rt]);
		}
		else{
			if(R[rt]==-1)
				R[rt] = newNode();
			modify(mid+1,r,p,v,R[rt]);
		}
		dseg[rt] += v;
	}
	int query(int l,int r,int v,int rt){
		if(l==r)
			return l;
		int mid = (l+r)>>1;
		if(L[rt]==-1 || dseg[L[rt]]<v)
			return query(mid+1,r,v-(L[rt]==-1 ? 0 : dseg[L[rt]]),R[rt]);
		return query(l,mid,v,L[rt]);
	}
}d_sgt[N<<1];

struct segtree{
	int seg[N*20+10], tag[N*20+10];
	void addTag(int idx,int v){
		seg[idx] += v;
		tag[idx] += v;
	}
	void push(int idx){
		addTag(idx<<1,tag[idx]);
		addTag(idx<<1|1,tag[idx]);
		tag[idx] = 0;
	}
	void modify(int l,int r,int ql,int qr,int v,int idx){
		if(l==ql && r==qr){
			addTag(idx,v);
			return;
		}
		if(tag[idx])
			push(idx);
		int mid = (l+r)>>1;
		if(qr<=mid)
			modify(l,mid,ql,qr,v,idx<<1);
		else if(ql>mid)
			modify(mid+1,r,ql,qr,v,idx<<1|1);
		else
			modify(l,mid,ql,mid,v,idx<<1), modify(mid+1,r,mid+1,qr,v,idx<<1|1);
		seg[idx] = min(seg[idx<<1], seg[idx<<1|1]);
	}
	int query(int l,int r,int p,int idx){
		if(l==r)
			return l;
		if(tag[idx])
			push(idx);
		int mid = (l+r)>>1;
		if(seg[idx<<1|1]<=p)
			return query(mid+1,r,p,idx<<1|1);
		return query(l,mid,p,idx<<1);
	}
}sgt;

struct zwk_segtree{
	long long seg[N*10+10];
	void modify(int p,int v){
		p += 3*N;
		for(;p;p>>=1)
			seg[p] += v;
	}
	long long query(int l,int r){
		r++;
		long long sum = 0;
		for(l+=3*N,r+=3*N;l<r;l>>=1,r>>=1){
			if(l&1)
				sum += seg[l++];
			if(r&1)
				sum += seg[--r];
		}
		return sum;
	}
}sgt2;

void init_sgt(){
	for(int i=0;i<v.size();i++)
		root[i] = newNode();
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	int l = N,r = n+N-1;
	for(int i=0;i<n;i++)
		cin >> a[i+N], v.push_back(a[i+N]);
	vector<query>Q;
	while(q--){
		int x,y,z;
		cin >> x >> y;
		if(x==3 || x==4){
			cin >> z;
			Q.push_back(query(x,y,z));
		}
		else{
			v.push_back(y);
			Q.push_back(query(x,y));
		}
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=0;i<n;i++)
		a[i+N] = lower_bound(v.begin(), v.end(), a[i+N])-v.begin();
	for(auto &i:Q)
		if(i.op!=4)
			i.id = lower_bound(v.begin(), v.end(), i.id)-v.begin();

	init_sgt();
	for(int i=0;i<=3*N;i++)
		sgt.modify(0,3*N,i,i,i-N,1);
	for(int i=N;i<n+N;i++)
		sgt2.modify(i,v[a[i]]), d_sgt[a[i]].modify(0,3*N,i,1,root[a[i]]);

	for(auto i:Q){
		auto [op,id,id2] = i;
		if(op==1){
			r++;
			a[r] = id;
			sgt2.modify(r,v[id]);
			d_sgt[id].modify(0,3*N,r,1,root[id]);
		}
		else if(op==2){
			l--;
			a[l] = id;
			sgt.modify(0,3*N,0,3*N,1,1);
			sgt2.modify(l,v[id]);
			d_sgt[id].modify(0,3*N,l,1,root[id]);
		}
		else if(op==3){
			int x = d_sgt[id].query(0,3*N,id2,root[id]);
			sgt.modify(0,3*N,x+1,3*N,-1,1);
			sgt2.modify(x,-v[id]);
			a[x] = -1;
			d_sgt[id].modify(0,3*N,x,-1,root[id]);
		}
		else{
			int x = sgt.query(0,3*N,id-1,1), y = sgt.query(0,3*N,id2-1,1);
			cout << sgt2.query(x,y) << '\n';
		}
	}
	bool space = false;
	for(int i=l;i<=r;i++)
		if(a[i]!=-1) {
			if(space)
				cout << ' ';
			space = true;
			cout << v[a[i]];
		}
	cout << '\n';
}
