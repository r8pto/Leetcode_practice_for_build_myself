#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
 * 在一个非空数组中，找到那个之出现了一次的数字
 * 其他数字都出现了两次
 */
int singleNumber(vector<int>& nums){
    // 方法1：异或
    // int ret=0;
    // for(auto e:nums){
    //     // 任何数异或自己等于0, 异或0等于自己
    //     ret ^= e;  // 用异或的方式找
    // }
    // return ret;

    // 方法2：使用哈希表  --- 不成功 最后输入的元素会被输出
    unordered_set<int> un;
    int cnt =0;
    for(int x:nums){
        // 如果在集合中找到了这个元素，则说明有重复
        cnt=0;
        if(un.find(x)!=un.end()){
            un.erase(x);
            ++cnt;
        }else{
            un.insert(x);   // 不重复的是否再插入
        }
        
          // 将不重复的元素插入到哈希表中
    }
    if(cnt!=0){
        un.erase(nums[nums.size()-1]);  // 去掉最后一个元素，如何只有当最后一个重复的时候才去掉
    }
    
    return *un.begin();
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
    int ans = singleNumber(nums);

    // 3. 输出
    cout<<ans<<endl;
}