#include<iostream>
#include<vector>

using namespace std;

/*给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
快慢指针
*/

int main(){
    // 1. 输入
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n;i++){
        int j;
        cin>>j;
        nums.push_back(j);
    }
    // 2. 处理部分，通过快慢指针实现
    // 2.1 指针初始化
    // cout << "i am hear"<<endl;
    // 用指针的通过不了leetcode
    int *begin = &nums[0];
    int *slow = begin, *fast = begin;
    int *last = &nums[n];

    int count = 0;  // 初始化一个计数器
    if(n==1 && *begin==1){
        count =1;
    }
    // 慢指针有问题，一定要让其指向1
    while(fast<last){
        int temp = 0;
        // 没有运行到最后一个
        if(*fast!=1){
            temp = fast - slow;
            slow = fast+1;
        }
        // 运行到最后一个时
        if(fast == last-1 && *slow==1){
            temp = fast-slow+1;
        }
        if(temp>count){
            count = temp;
        }
        ++fast;
    }
    // // 写一个用索引的
    // int fast =0, slow=0,count=0;
    // while(fast<n){
    //     if(nums[fast]==1){   // 要学会逆向思考
    //         count = max(fast - slow + 1, count);
    //     }else{
    //         slow = fast+1;
    //     }
    //     ++fast;
    // }
    std::cout << count<<endl;

}