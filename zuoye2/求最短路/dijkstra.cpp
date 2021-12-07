#include <bits/stdc++.h>
using namespace std;
int n, m, d[505], a[505][505];
bool v[505];
int main() {
    cin >> n >> m;
    memset(a, 0x3f, sizeof a);
    for (int i = 1; i <= m; i ++ ) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = min(a[x][y], z);
    }
    for (int i = 1; i <= n; i++) a[i][i] = 0;
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int cnt = 1; cnt <= n; cnt ++ ) {
        int min_val = 1 << 30, x;
        for (int i = 1; i <= n; i++) 
            if (!v[i] && d[i] < min_val)
                min_val = d[i], x = i;
        v[x] = true;
        for (int y = 1; y <= n; y ++ )
            d[y] = min(d[y], d[x] + a[x][y]);
    }
    if (d[n] == 0x3f3f3f3f) puts("-1");
    else cout << d[n] << endl;
    
}
