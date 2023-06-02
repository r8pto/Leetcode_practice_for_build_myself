#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, val;
    cin>>n>>val;
    vector<int> num;
    // 1. 构造和提干相同的数组
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        num.push_back(j);
    }

    // 2. 构造数组引用
    vector<int>& nums=num;  // 引用需要将其绑定到一个已经存在的对象
    int *begin = &nums[0];
    int *slow = begin;
    int *fast = begin;
    int *end = &nums[n];
    while(fast<end){
        // cout<<*slow<<endl;
        if(*fast != val){
            *slow = *fast;
            ++slow;
        }
        ++fast;
    }
    cout<<slow-begin<<endl;
    for(auto i : nums){
        cout<<i<<" ";
    }

}   