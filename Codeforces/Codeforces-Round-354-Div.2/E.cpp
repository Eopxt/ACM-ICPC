#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define sqr(x) ((x)*(x))
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (lld i=0; i<(n); i++)
#define rep(i,n) for (lld i=1; i<=(n); i++)
#define For(i,s,t) for (lld i=(s); i<=(t); i++)
#define FOR(i,s,t) for (lld i=(s); i>=(t); i--)
#define foreach(j,x) for (lld j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<lld,lld> pii;
typedef set<lld>::iterator setIter;

const lld mod1=1e9+7, mod2=3e8+7, mod3=1e8+9, mod4=5e8+1;
lld n,x,a[100009],cnt;
char st[100009][9];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%lld%lld",&n,&x);
    For(i,0,n) {
        scanf("%s",&st[i]);
        if (st[i][0]=='?') cnt++;
    }
    if (x==0) {
        if (st[0][0]=='?') {
            if ((n+1-cnt)%2==1) printf("Yes\n");
                else printf("No\n");
        }
        else {
            if (st[0][0]=='0') printf("Yes\n");
                else printf("No\n");
        }
    }
    else {
        if (cnt==0) {
            For(i,0,n) {
                bool neg=(st[i][0]=='-');
                lld j=neg,len=strlen(st[i]);
                while (j<len) a[i]=a[i]*10+st[i][j++]-'0';
                if (neg) a[i]=-a[i];
            }
            lld w1=1,w2=1,w3=1,w4=1,s1=0,s2=0,s3=0,s4=0;
            For(i,0,n) {
                s1=(s1+w1*a[i])%mod1;
                s2=(s2+w2*a[i])%mod2;
                s3=(s3+w3*a[i])%mod3;
                s4=(s4+w4*a[i])%mod4;
                w1=w1*x%mod1;
                w2=w2*x%mod2;
                w3=w3*x%mod3;
                w4=w4*x%mod4;
            }
            if (s1==0 && s2==0 && s3==0 && s4==0) printf("Yes\n");
                else printf("No\n");
        }
        else printf("%s\n",(n%2==1)?"Yes":"No");
    }
    return 0;
}
