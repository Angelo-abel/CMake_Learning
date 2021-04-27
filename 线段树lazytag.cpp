#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int l, r, sum, la;
}

const int maxn = 10010;
#define ll long long
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
ll sum[maxn<<2], la[maxn<<2];

void pushup(int rt)
{
    sums[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m)
{
    if (la[rt]) {
        la[rt << 1] += la[rt];
        la[rt << 1 | 1] += la[rt];
        sum[rt << 1] += la[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += la[rt] * (m >> 1); // 表示存在区间长度
        la[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    la[rt] = 0;
    if (l == t)
        sum[rt] = 0;
        return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        la[rt] += c;
        sum[rt] += (ll)c * (r - l + 1);
        return;
    }

    pushdown(rt, r - l + 1);

    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (R > m)
        update(L, R, c, rson);

    pushup(rt, r - l + 1);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];

    // 需要向下更新
    pusdown(rt, r - l + 1);

    ll res = 0;
    int m = (l + r) >> 1;
    if (L <= m)
        res += query(L, R, lson);
    if (m < R)
        res += query(L, R, rson);
    return res;
}


// 线段树实现理解
#define ll long long
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int N = 10010;
ll sum[N << 2], la[N << 1];
int arr[N];

void pushup(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m)
{
    if (la[rt]) {
        la[rt << 1] += la[rt];
        la[rt << 1 | 1] += la[rt];
        sum[rt << 1] = la[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] = la[rt] * (m >> 1);
        la[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    la[rt] = 0;
    if (l == r)
        sum[rt] = arr[l];
        return;

    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        la[rt] += c;
        sum[rt] += (ll)c * (r - l + 1);
        return;
    }

    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (m < R)
        update(L, R, c, rson);

    // 在这里需要更新线段树
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];

    // 这里需要更新
    pushdown(rt, r -l + 1);

    ll res = 0;
    int m = (l + r) >> 1;
    if (L <= m)
        res += query(L, R, lson);
    if (m < r)
        res += query(L, R, rson);
    return res;
}

// 线段树更新

#define ll long long
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 10010;
ll sum[maxn << 2], la[maxn << 2];
int arr[maxn];

void pushdown(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m)
{
    if(la[rt]) {
        la[rt << 1] += la[rt];
        la[rt << 1 | 1] += la[rt];
        sum[rt << 1] += la[rt] * (m - (m >> 1));
        sum[rt << 1] += la[rt] * (m >> 1);
        la[rt] = 0;
    }
}

void build(int l, int r, int rt)
{
    if (l == r) {
        sum[rt] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        la[rt] += c;
        sum[rt] += c * (r -l + 1);
        return;
    }

    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, lson);
    if (m < R)
        update(L, R, c, rson);
    pushup(rt);
}

void query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];

    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    ll res = 0;
    if (L <= m)
        res += query(L, R, lson);
    if (m < R)
        res += query(L, R, rson);
    return res;
}

// 区间线段树
// 单点线段线段树使用
