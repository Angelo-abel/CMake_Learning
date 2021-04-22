#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j)
{
    arr[i] = arr[i]^arr[j];
    arr[j] = arr[i]^arr[j];
    arr[i] = arr[i]^arr[j];
}

void QuickSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int base = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= base)
            j--;
        while (i < j && arr[i] <= base)
            i++;
        if (i < j)
            swap(arr, i, j);
    }
    // 基准数归位
    arr[left] = arr[i];
    arr[i] = base;
    QuickSort(arr, left, i - 1);
    QuickSort(arr, i + 1, right);
}

void Merge(int *arr, int len)
{
    int temp[len];
    int b = 0;
    int l = 0;
    int mid = len >> 1;
    int r = mid;
    while (l < mid && r < len) {
        if (arr[l] <= arr[r])
            temp[b++] = arr[l++];
        else
            temp[b++] = arr[r++];
    }
    while (l < mid)
        temp[b++] = arr[l++];
    while (r < len)
        temp[b++] = arr[r++];
    
    copy(temp, temp + len, arr);
}

void MergeSort(int *arr, int len)
{
    if (len <= 1)
        return;
    else
    {
        int mid = len >> 1;
        MergeSort(arr, mid);
        MergeSort(arr + mid, len - mid);
        Merge(arr, len);
    }
}
void heapify(int *arr, int idx, int len)
{
    int parent = idx;
    int child = (parent << 1) + 1;
    while (child < len) {
        if ((child + 1) < len && arr[child + 1] > arr[child])
            child++;
        if (arr[parent] > arr[child])
            break;
        swap(arr, parent, child);
        parent = child;
        child = (child << 1) + 1;
    }
}

void buildheap(int *arr, int size)
{
    for (int i = (size >> 1) - 1; i >= 0; i--) {
        heapify(arr, i, size);
    }
}

void heapsort(int *arr, int size)
{
    buildheap(arr, size);
    for (int i = size - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i);
    }
}

void test3()
{
    vector<int> nums;
    vector<int> nums1;
    vector<int> nums2;
    for (int i = 0; i< 10; i++) {
        nums.push_back(rand()%100);
        nums1.push_back(rand()%100);
        nums2.push_back(rand()%100);
    }

    // QuickSort(&nums[0], 0, nums.size() - 1);
    // for_each(nums.begin(), nums.end(), [](int a){cout << a << " ";});
    // cout << endl;

    // MergeSort(&nums1[0], nums1.size());
    // for_each(nums1.begin(), nums1.end(), [](int a){cout << a << " ";});
    // cout << endl;

    heapsort(&nums2[0], nums2.size());
    for_each(nums2.begin(), nums2.end(), [](int a){cout << a << " ";});
    cout << endl;
}

// 归并排序与快速排序算法
int main(int argc, char**argv)
{
    test3();
    return 0;
}
