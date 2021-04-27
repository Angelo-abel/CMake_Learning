#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ll long long

const int N = 3e4 + 10;
ll sum[N << 2], la[N << 2];
int arr[N];
int n;

class NumArray {
public:
    int temp[N];
    NumArray(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < nums.size(); i++)
            arr[i + 1] = nums[i];

        build(1, n, 1);
    }
    
    void update(int index, int val) {
        update(index + 1, val, 1, n, 1);
    }
    
    int sumRange(int left, int right) {
        return query(left+ 1, right + 1, 1, n, 1);
    }

private:
    void pushup(int x) {
        sum[x] = sum[x << 1] + sum[x << 1 | 1];
    }

    void build(int l, int r, int rt) {
        if (l == r)
            sum[rt] = arr[l];
            return;

        int m = l + ((r - l) >> 1);
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int idx, int val, int l, int r, int rt) {
        if (l == r)
            sum[rt] = val;
            return;

        int m = l + ((r - l ) >> 1);
        // 需要更新条件
        if (idx <= m)
            update(idx, val, lson);
        if (m < idx)
            update(idx, val, rson);

        // 需要自定向上更新当前节点
        pushup(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R)
            return sum[rt];
        
        int m = l + ((r - l) >> 1);
        ll ans = 0;
        if (L <= m) {
            ans += query(L, R, lson);
        }
        if (m < R) {
            ans += query(L, R, rson);
        }
        return ans;
    }
};

