#include<iostream>
#include<vector>
using namespace std;
/*
输入一个按照升序排列好的数组，原地删除重复出现的元素
输出去重后元素个数，返回一个不重复的数组
*/
int removeDuplicates(vector<int>& nums){
    int slow=0, fast=0;
    decltype(nums.size()) n = nums.size();
    vector<int> ans;
    while(fast<n){
        if(nums[fast]!=nums[slow]){
            ++slow;
            nums[slow]=nums[fast];
        }
        ++fast;
    }
    return slow+1;
}

bool check_ans(vector<int>& nums){
    vector<int> expectedNums = {0, 1, 2, 3, 4};

    int k = removeDuplicates(nums);
    if(k == expectedNums.size()){
        return 1;
    }
}


int main(){
    // 用例子
    vector<int> num = {0,0,1,1,1,2,2,3,3,4};

    vector<int> &nums = num;
    // 函数体
    int ans = removeDuplicates(nums);
    // 输出
    cout<<ans;
}