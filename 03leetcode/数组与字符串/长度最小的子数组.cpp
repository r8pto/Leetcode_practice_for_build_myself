#include<iostream>
#include<vector>

using namespace std;
/*给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 
[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c0w4r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/


int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums;
    // 1. 输入
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        nums.push_back(j);
    }
    // 2. 处理体
    // 1）如果快指针和慢指针区间中的数相加大于target则返回区间长度
    // 2）通过max(fast-slow+1,count)来更新count
    // int *begin = &nums[0];
    // int *last = &nums[n];
    // int *fast = begin,*slow = begin;
    // int count=n;
    // int sum=0;
    // // 这个程序有一个缺点，在于其只能正着走
    // // 加入指针收缩
    // while(fast<last){
    //     if(sum>=target){
    //         int temp = sum;
    //         int length = fast -slow +1;
    //         count = min(count, length);
    //         if((sum -*slow)>=target){ // 快指针要等慢指针
    //             sum -= *slow;
    //             ++slow;
    //         }else{  // 这里加两次的问题不能解决
    //             if(temp-*fast<target){
    //                 sum+=*fast;
    //                 ++fast;
    //             }

    //         }
    //     }else{
    //         sum+=*fast;  // 不能让sum一直都加
    //         ++fast; // 让快指针等慢指针
    //     }
    //     //cout<<count<<ends;
    //     cout<<sum<<"s ";
    //     cout<<count<<"c ";
        
    // }
    
    int fast=0, slow=0,sum=0,count=n;
    for(; fast<n; ++fast){
        sum+=nums[fast];
        if(sum>=target){
            while(1){
                if(sum-nums[slow]>=target){
                    sum-=nums[slow++];
                }else{
                    break;
                }
            }
            if(fast-slow+1<count){
                count = fast-slow +1;
            }
        }
    }
    if(count<nums.size()+1){
        cout<<count<<endl;
    }else{
        cout<<0<<endl;
    }

    cout <<count<<endl;
    return 0;

}