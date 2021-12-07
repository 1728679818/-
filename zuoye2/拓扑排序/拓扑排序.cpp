#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 100010;

int h[N],e[N],ne[N],in_cnt[N],idx = 0;
int n,m,from,to;
int res[N];
void add(int from,int to)
{
    e[idx] = to;
    ne[idx] = h[from];
    h[from] = idx ++;
    in_cnt[to] ++;
}
int main()
{
    scanf("%d %d",&n,&m);
    memset(h,-1,sizeof(h));
    for(int i = 0 ; i < m ; i ++)
    {
        scanf("%d %d",&from,&to);
        add(from,to);
    }
    queue<int> q;
    for(int i = 1 ; i <= n ; i ++)
        if(in_cnt[i] == 0)
            q.push(i);
    int u = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        res[u ++] = p;
        for(int i = h[p] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            in_cnt[j] --;
            if(in_cnt[j] == 0)
                q.push(j);
        }
    }
    if(u != n) printf("-1");
    else
    {
        for(int i = 0 ; i < n ; i ++)
            printf("%d ",res[i]);
    }
    return 0;
}
