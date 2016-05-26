#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define sqr(x) ((x)*(x))
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (int i=0; i<(n); i++)
#define rep(i,n) for (int i=1; i<=(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for (int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<int,int> pii;
typedef set<int>::iterator setIter;

int n,m;
char st[100009];

int change(char ch) {
    int res=m,lb=1,rb=1,ret=0;
    while (lb<=n) {
        while (rb<=n && (st[rb]==ch || res>0)) {
            if (st[rb]!=ch) res--;
            rb++;
        }
        ret=max(ret,rb-lb);
        if (st[lb]!=ch) res++;
        lb++;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    scanf("%s",st+1);
    int ans1=change('a');
    int ans2=change('b');
    printf("%d\n",max(ans1,ans2));
    return 0;
}
