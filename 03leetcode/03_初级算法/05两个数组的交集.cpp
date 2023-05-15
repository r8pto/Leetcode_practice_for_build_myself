#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
 * 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
 返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
 （如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2y0c2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    decltype(nums1.size()) n1=nums1.size(), n2=nums2.size();
    // 1. 不用考虑元素的顺序，只用出现即可
    // 2. 如果一个元素中某元素只出现一次，则只按一次来算
    vector<int> ans;
    // 暴力方法，不能全对
    // if(nums1.size()>=nums2.size()){
    //     for(int i=0; i<n1;++i){
    //         for(auto b:nums2){
    //             if(nums1[i]==b){ // 如何只添加一次
    //                 ans.push_back(nums1[i]);
    //                 ++i;
    //             }
    //         }
    //     }
    // }
    // if(nums1.size()<nums2.size()){
    //     for(int i=0; i<n2;++i){
    //         for(auto b:nums1){
    //             if(nums2[i]==b){ // 如何只添加一次
    //                 ans.push_back(nums2[i]);
    //                 ++i;
    //             }
    //         }
    //     }
    // }
    

    // return ans;

    for(vector<int>::iterator it1=nums1.begin(),it2=nums2.begin();it1!=nums1.end()&&it2!=nums2.end();)
    {
        if(*it1<*it2 ) it1++;
        else if(*it1==*it2)
        {
            ans.push_back(*it1);
                it1++;
                it2++;
        }
        else if(*it1>*it2 ) it2++;
    }
    return ans;

}

int main(){
    // 1. 输入
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    // 2. 执行函数体
    vector<int> ans = intersect(nums1, nums2);

    // 3. 输出
    for(auto c:ans){
        cout<<c<<" ";
    }

}