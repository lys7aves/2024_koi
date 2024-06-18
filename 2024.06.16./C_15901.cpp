#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAXN 1000000

using namespace std;

struct node1{
	long long int p, q;
};

long long int K=1, T=1;
node1 tree[4*MAXN];
queue<node1> stand;

void Push(long long int l, long long int r);
void Renew(long long int l, long long int r, long long int p);
void Print(long long int i);
void Delete(long long int t);

int main()
{
	long long int n, m, k, Q, i, x, o, l, r;
	node1 t;
	
	scanf("%lld %lld %lld %lld", &n, &m, &k, &Q);
	for(i=1;i<=n;i++){
		scanf("%lld", &x);
		t.p = x; t.q = 1;
		stand.push(t);	
	}
	
	while(K < m) K *= 2;
	tree[1].p = -1; tree[1].q = 1;
	for(i=1;i<=min(n,m);i++){
		Push(i, i);
	}
	
	while(Q--){
		scanf("%lld", &o);
		switch(o){
			case 1:
				scanf("%lld %lld", &l, &r);
				Push(l, r);
				break;
			case 2:
				scanf("%lld", &i);
				Print(i);
				break;
			case 3:
				scanf("%lld %lld", &t.p, &t.q);
				stand.push(t);
				break;
			case 4:
				scanf("%lld", &x);
				Delete(x);
				break;
			default: break;
		}
	}
	
	printf("\n");
	for(i=1;i<=m;i++) Print(i);
	
	return 0;
}

void Push(long long int l, long long int r)
{
	while(l<=r){
		if(stand.empty()){
			Renew(l, r, -1);
			l = r+1;
		}
		else if(stand.front().q <= r-l+1){
			Renew(l, l+stand.front().q-1, stand.front().p);
			l += stand.front().q;
			stand.pop();
		}
		else{
			Renew(l, r, stand.front().p);
			stand.front().q -= r-l+1;
			l = r+1;
		}
	}
}

void Renew(long long int l, long long int r, long long int p)
{
	l += K-1; r += K-1; T++;
	while(l<=r){
		if(l%2==1){
			tree[l].p = p;
			tree[l].q = T;
			l++;
		}
		if(r%2==0){
			tree[r].p = p;
			tree[r].q = T;
			r--;
		}
		l /= 2;
		r /= 2;
	}
}

void Print(long long int i)
{
	long long int t=0, p=0;
	
	i += K-1;
	while(i){
		if(t < tree[i].q){
			t = tree[i].q;
			p = tree[i].p;
		}
		i /= 2;
	}
	
	printf("%lld ", max(p,(long long int)0));
}

void Delete(long long int t)
{
	while(!stand.empty() && stand.front().q <= t){
		t -= stand.front().q;
		stand.pop();
	}
	if(!stand.empty()) stand.front().q -= t;
}
