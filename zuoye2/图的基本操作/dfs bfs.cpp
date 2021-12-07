void add(int x, int y) {
    ver[++tot] = y, next[tot] = head[x], head[x] = tot;
    deg[y]++;
}


void dfs(int x)
{
    v[x] = 1; // ��¼��x�����ʹ���v��visit����д
    for (int i = h[x]; ~i; i = ne[i])
    {
        int y = e[i];
        if (v[y]) continue; // ��y�Ѿ������ʹ���
        dfs(y);
    }
}


void bfs()
{
    memset(d, 0, sizeof d);
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (q.size() > 0)
    {
        int x = q.front();
        q.pop();
        for (int i = h[x]; ~i; i = ne[i])
        {
            int y = e[i];
            if (d[y]) continue;
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
}


