#include<iostream>
#include<vector>

using namespace std;

/*
 * 给定一个整数数组nums,将数组中的元素向右轮转k个位置，其中k是非负数
 */
void rotate(vector<int>& nums, int k){
    decltype(nums.size()) n = nums.size();
    k = k % n; // 取个余数，防止k>n
    vector<int> temp = nums;
    // 准备一个临时数组
    for(int i=0; i<n;++i){ 
        temp[i] = nums[i];
    }
    for(int i=0; i<n;++i){
        nums[(i+k)%n] = temp[i];  // 将临时数组往右移动k位后给原数组
    }

}

int main(){
    // 1. 输入
    int n, k;
    cin>>n>>k;
    vector<int> nums;
    for(int i=0; i<n;++i){
        int j;
        cin>>j;
        nums.push_back(j);
    }
    // 2. 执行函数体
    rotate(nums, k);

    // 3. 输出
    for(auto c:nums){
        cout<<c<<" ";
    }
}