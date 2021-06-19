#include <bits/stdc++.h>
using namespace std;

// 使用递归方式求解全排序
void Perm(vector<int> &nums, int start, int end)
{
    if (start == end)
        return; // 记录了一种满足全排序的算法
    for (int i = start; i < end; i++) {
        swap(nums[start], nums[i]);
        Perm(nums, start + 1, end);
        swap(nums[start], nums[i]);
    }
}

// 使用递归方式求解组合数
int comb(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

void Perm(vector<int> &nums, int start, int end)
{
    if (start == end)
        return; // 记录满足规则的下一个排序
    for (int i = start; i < end; i++) {
        swap(nums[start], nums[i]);
        Perm(nums, start + 1, end);
        swap(nums[start], nums[i]);
    }
}
