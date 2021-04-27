// 线段树区间操作
#define ll long long
#define lson l, m, rt << 1;
#define rson m + 1, r, rt << 1 | 1
#define le rt << 1
#define re rt << 1 | 1
#define mid (l + ((r - l) >> 1))
const int N = 1e5 + 10;
ll sum[N << 2], la[N << 2];
int arr[N];
int n;

void pushup(int rt)
{
    sum[rt] = sum[le] + sum[re];
}

// 需要更新的都是线段树对应顶点
void pushdown(int rt, int m)
{
    if (la[rt]) {
        la[le] += la[rt];
        la[re] += la[rt];
        sum[le] += la[rt] * (m - (m >> 1));
        sum[re] += la[rt] * (m >> 1);
    }
}

void build(int l, int r, int rt) {
    arr[rt] = 0;
    if (l == r) {
        sum[rt] = arr[l];
        return;
    }

    int m = mid;
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
    int m = mid;
    if (L <= m)
        // 需要更新线段树区间和顶点
        update(L, R, c, lson);
    if (m < R)
        update(L, R, c, rson);
    
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];

    pushdown(rt, r - l + 1);
    int m = mid;
    int res = 0;
    if (L <= m)
        ans += query(L, R, lson);
    if (m < R)
        ans += query(L, R, rson);
    return ans;
}

// 区间线段树
// 单点线段线段树使用
