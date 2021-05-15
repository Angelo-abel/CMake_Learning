#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5 + 5;
int n, m;
int in[maxn];
vector<int> g[maxn];
int ans[maxn];

// 完成拓扑排序算法
int topsort()
{
    int cnt = 0;
    // queue<int> q;;
    priority_queue<int, vector<int>, greater<int>> q;
    while (q.size()) {
        q.pop();
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        int now = q.top();
        q.pop();
        ans[++cnt] = now;
        for (int i = 0; i < g[now].size(); i++) {
            if (--in[g[now][i]] == 0)
                q.push(g[now][i]);
        }
    }
    return (cnt == n) ? 1 : 0;
}

void init()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
}

const int maxn = 1e5 + 5;
int n, m;
vector<int> G[maxn];
int in[maxn];
int ans[maxn];

void init()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) G[i].clear();
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        in[y]++;
    }
}

int topsort()
{
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    while (q.size())
        q.pop();
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (q.size()) {
        int now = q.top();
        q.pop();
        ans[++cnt] = now;
        for (int i = 0; i < G[now].size(); i++) {
            if (--in[G[now][i]] == 0)
                q.push(G[now][i]);
        }
    }
    return (cnt == n) ? 1 : 0;
}
