#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/
void moveZeros(vector<int>& nums){
    // sort(nums.begin(), nums.end());排序了顺序就乱了
    decltype(nums.size()) n = nums.size();
    for(int fast=0,slow=0; fast<n;++fast){
        if(nums[fast]!=0 && nums[slow]==0){
            swap(nums[slow], nums[fast]);
        }
        if(nums[slow]!=0){
            ++slow;
        }
        
    }
}

int main(){
    // 1. 样例输入
    vector<int> num = {1};
    vector<int> &nums = num;

    // 2. 函数体
    moveZeros(nums);

    for(auto i : num){
        cout<<i<<" ";
    }
}