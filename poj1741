/* ***********************************************
Author        :kuangbin
Created Time  :2013-11-17 14:30:29
File Name     :E:\2013ACM\专题学习\树的分治\POJ1741.cpp
 ************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,nxt,w;
}E[MAXN*2];
int adj[MAXN],tot;

void init() {
    tot = 0;
    memset(adj,-1,sizeof(adj));
}

void addedge(int u,int v,int w) {
    E[tot].to = v; E[tot].w = w;
    E[tot].nxt = adj[u];adj[u] = tot++;
}

bool vis[MAXN];
int size[MAXN],dep[MAXN];
int le,ri;
int dfssize(int u,int pre) {
    size[u] = 1;
    foreach(i,u) {
        int v = E[i].to;
        if(v == pre || vis[v])continue;
        size[u] += dfssize(v,u);
    }
    return size[u];
}

int minn;
//找重心
void getroot(int u,int pre,int totnum,int &root)
{
    int maxx = totnum - size[u];
    foreach(i,u) {
        int v = E[i].to;
        if(v == pre || vis[v])continue;
        getroot(v,u,totnum,root);
        maxx = max(maxx,size[v]);
    }
    if(maxx < minn){minn = maxx; root = u;}
}

void dfsdepth(int u,int pre,int d)
{
    dep[ri++] = d;
    foreach(i,u) {
        int v = E[i].to;
        if(v == pre || vis[v])continue;
        dfsdepth(v,u,d+E[i].w);
    }
}

int k;
int getdep(int a,int b)
{
    sort(dep+a,dep+b);
    int ret = 0, e = b-1;
    for(int i = a;i < b;i++)
    {
        if(dep[i] > k)break;
        while(e >= a && dep[e] + dep[i] > k)e--;
        ret += e - a + 1;
        if(e > i)ret--;
    }
    return ret>>1;
}

int solve(int u)
{
    int totnum = dfssize(u,-1);
    int ret = 0;
    minn = INF;
    int root;
    getroot(u,-1,totnum,root);
    vis[root] = true;
    foreach(i,root) {
        int v = E[i].to;
        if(vis[v])continue;
        ret += solve(v); 
    }
    le = ri = 0;
    foreach(i,root) {
        int v = E[i].to;
        if(vis[v])continue;
        dfsdepth(v,root,E[i].w);
        ret -= getdep(le,ri);
        le = ri;
    }
    ret += getdep(0,ri);
    for(int i = 0;i < ri;i++)
    {
        if(dep[i] <= k)ret++;
        else break;
    }
    vis[root] = false;
    return ret;
}

int main()
{
    int n;
    int u,v,w;
    while(scanf("%d%d",&n,&k) == 2)
    {
        if(n == 0 && k == 0)break;
        init();
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        memset(vis,false,sizeof(vis));
        printf("%d\n",solve(1));
    }
    return 0;
}
