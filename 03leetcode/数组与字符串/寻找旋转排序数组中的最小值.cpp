#include<iostream>
#include<vector>

using namespace std;
/*
一个长度为n的数组，按照升序排列后，经由1-n次旋转后，得到输入数组
数组元素值互不相同，要求找到其中最小值
设计一个时间复杂度为O(logn)的算法解决此问题
*/
int findMin(vector<int>& nums){
    decltype(nums.size()) n = nums.size();
    int ans=nums[n-1];
    for(int i=0, j=n-1;i<=j;++i,--j){   // 时间速度度为logn
        if(nums[i]>nums[j]){
            ans = min(nums[j], ans);
        }else{
            ans = min(nums[i], ans);
        }
    }
    return ans;
}


int main(){
    // 1. 输入
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        nums.push_back(j);
    }
    cout<<"i am here"<<endl;
    // 2. 函数体
    int ans = findMin(nums);

    // 3. 输出
    cout<<ans<<endl;
}