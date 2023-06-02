#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>  // 使用哈希表
/*
 *这个头文件是C++标准库中的<unordered_set>，它提供了一种无序容器，
 *可以存储不重复元素的集合。在<unordered_set>中，每个元素的值都必须是唯一的，
 *而且不能按特定顺序排序。
 */
using namespace std;

/*
 * 判断一个整数数组中是否存在重复元素
 */
bool containsDuplicate(vector<int>& nums){
    // decltype(nums.size()) n = nums.size();
    // 方法一，暴力法  --- 超时了
    // for(int i=0;i<n;++i){
    //     for(int j=i+1;j<n;++j){
    //         if(nums[i]==nums[j]){
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // 方法二，二分法---本质上还是相当于寻找吧
    // 二分法得进行排序吧  -- 不靠谱
    // sort(nums.begin(), nums.end());
    // for(int j=0;j<n;++j){
    //     for(int i=j+1;i<n/2;++i){  // 只是顺着寻找nums[j]有没有出现
    //         int left=i,right=n-1;
    //         if(nums[i]==nums[(right - left)/2]){
    //             return true;
    //         }else if(nums[i]>nums[(right-left)/2]){
    //             left = (right - left)/2;
    //         }else{
    //             right = (right - left)/2;
    //         }
    //     }
    //     if(j==n-1){
    //         return false;
    //     }
    // }

    // 方法三： 哈希表
    unordered_set<int> un;
    for(int x:nums){
        // 如果在哈希表中找到了这个元素，则说明有重复
        if(un.find(x)!=un.end()){
            return true;
        }
        un.insert(x);  // 将不重复的元素插入到哈希表中
    }
    return false;  // 如果程序能结束，说明没有找到相同元素
}

int main(){
    // 1. 输入
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n;++i){
        int j;
        cin>>j;
        nums.push_back(j);
    }

    // 2. 函数体
    bool ans = containsDuplicate(nums);

    // 3. 输出
    cout << ans<<endl;

    return 0;
}