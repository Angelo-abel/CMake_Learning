#define ll long long 
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 3e4 + 10;
ll sum[maxn << 2];
ll n;
int arr[maxn];

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        copy(nums.begin(), nums.end(), arr + 1);
        build(1, n, 1);
    }
    
    void update(int index, int val) {
        update(index + 1, val, 1, n, 1);
    }
    
    int sumRange(int left, int right) {
        return query(left + 1, right + 1, 1, n, 1);
    }

    inline void pushup(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void build(int l, int r, int rt) {
        if (l == r) {
            sum[rt] = arr[l];
            return;
        }

        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int idx, int val, int l, int r, int rt) {
        if (l == r) {
            sum[rt] = val;
            return;
        }

        int m = (l + r) >> 1;
        if (idx <= m)
            update(idx, val, lson);

        if (idx > m)
            update(idx, val, rson);

        pushup(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R)
            return sum[rt];

        int m = (l + r) >> 1;
        int ans = 0;
        if (L <= m)
            ans += query(L, R, lson);
        if (m < R)
            ans += query(L, R, rson);

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
