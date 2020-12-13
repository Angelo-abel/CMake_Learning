// #include <iostream>
// #include<vector>
// #include<string>
// #include<ctime>
// #include<algorithm>
// #include <cstdlib>
// #include <cstdio>
#include <bits/stdc++.h>

using namespace std;


void MyPrint(int x)
{
    cout << x << " ";
}

void test_shuffle(){
	srand((unsigned int)time(NULL));
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
 
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

void find_repeat()
{
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

    auto it = adjacent_find(v.begin(),v.end());
    if(it != v.end()) {
        cout << "找到了首个相邻重复元素" << endl;
        cout << it-v.begin() << endl;
    }
}

void test_bin_search()
{

	vector<int>v;
 
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

    auto it = binary_search(v.begin(), v.end(), 5);
    if(it)
    {
        cout << "查找当前这个数组元素位置：" << endl;
    }
}

class MyPrintFunc
{
public:
    void operator()(int x) {
        cout << x << " ";
    }
};

// 将两个有序序列合并为一个
void test_merge()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10 ; i++) 
    {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
 
	vector<int> vtarget;
	//目标容器需要提前开辟空间
	vtarget.resize(v1.size() + v2.size());
    vtarget.shrink_to_fit();
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
    for_each(vtarget.begin(), vtarget.end(), MyPrintFunc());
}

// 求解两个容器之间集合元素的关系
void test_intersection()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
 
	vector<int> vTarget;
	//取两个容器的和给目标容器开辟空间
	vTarget.resize(max(v1.size(),v2.size()));
    cout << endl;
    cout << "求两个容器的交集";
    auto itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, MyPrintFunc());
    cout << endl;
}

// 求解两个容器交集、并集和差集之间存在区别
void test_union()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
 
	vector<int> vTarget;
    vTarget.resize(v1.size()+v2.size());
    cout << endl;
    cout << "求解两个容器的并集";
    auto itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, MyPrintFunc());
    cout << endl;
}

void test_difference()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
 
	vector<int> vTarget;
	//取两个里面较大的值给目标容器开辟空间
	vTarget.resize( max(v1.size() , v2.size()));

    // 求解v1与v2之间的差集
    auto itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    cout << "求解两个容器的差集";
    for_each(vTarget.begin(), itEnd, MyPrintFunc());
    cout << endl;
}

// 测试C++中给不同容器适配的迭代器
void  test_iterator()
{
    list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst2 ={10}, lst3={10},lst4={10};
    copy(lst.begin(), lst.end(), back_inserter(lst2));
    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
    copy(lst.begin(), lst.end(), front_inserter(lst4));

    cout << "求解两个容器的差集";
    for_each(lst2.begin(), lst2.end(), MyPrintFunc());
    for_each(lst3.begin(), lst3.end(), MyPrintFunc());
    for_each(lst4.begin(), lst4.end(), MyPrintFunc());
    cout << endl;
}

void test_equal()
{
    vector<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> lst1 = { 5, 4, 3, 2, 1, 6, 7, 8, 9 };
    cout << "equal" << equal(lst.begin()+5,lst.end(), lst1.begin()+5) <<endl;
}

void test_max_element()
{
    list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "最大元素：" << *max_element(lst.begin(), lst.end()) << endl; 
    cout << "最小元素：" << *min_element(lst.begin(), lst.end()) << endl; 
}

void print_arr(int (*parr)[4], int n1, int n2)
{
    for(int i=0; i< n1;i++) {
        for(int j=0; j< n2;j++) {
            printf("parr[row][col]:%d", *(*(parr+i)+j));
        }
    }
}

void test_print()
{
    int arr[][4]={{1,2,3,4},{5,6,7,8}};
    print_arr(arr, sizeof(arr)/sizeof(arr[0]), 4);
}
void demo1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demo2(int inner_a, int inner_b) // inner_a=10, inner_b=20
{
    int temp = inner_a;
    inner_a = inner_b;
    inner_b = temp;
}
void alloc_demo(int inner_a, int inner_b) // *inner_a = NULL;  *inner_b = NULL;
{
    inner_a = 0x11000;
    inner_b = 0x12000;
}

// void demo3_alloc()
// {
//     int a =100;
//     int *p1 = &a;
//     int **p2 = &p1;
//     int ***p3 = &p2;
//     printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
//     printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
//     printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
//     printf("&a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
// }

// 查找两个元素中第一个不匹配的位置
// mismatch
void demo3(int ***a, int ***b)
{
    int temp = ***a;
    ***a = ***b;
    ***b = temp;
}

typedef int(*PARR)[4];
// 测试数组指针和指针数组之间表示关系
// 数组指针表示含义指向某个数组, 获取到某个数组
void test_arr_ptr()
{
    int arr[4]={0,12,2,3};
    int (*arr_ptr)[4]=&arr;
    PARR temp_arr = &arr;
    printf("arr ele:%d",(*arr_ptr)[0]);
    printf("arr ele:%d",(*temp_arr)[1]);
}

// 测试数组指针和指针数组之间区别
int main(int argc, char**argv)
{
    int a =10;
    int b =20;
    int *tempa = &a; 
    int *tempb = &b;
    int **pla = &tempa;
    int **plb = &tempb;
    int ***p3a = &pla;
    int ***p3b = &plb;
    demo3(p3a, p3b);
    test_shuffle();
    find_repeat();
    test_bin_search();
    test_merge();
    test_intersection();
    test_union();
    test_difference();
    test_iterator();
    test_max_element();
    test_equal();
    test_print();
    test_arr_ptr();
    // alloc_demo()
    // // demo3(&tempa, &tempb);
    // printf("a:%d b:%d \n", a, b);
    // demo3_alloc();

    // alloc_demo(p1, p2);
    // printf("a:%d b:%d \n", a, b);
    return 0;
}
