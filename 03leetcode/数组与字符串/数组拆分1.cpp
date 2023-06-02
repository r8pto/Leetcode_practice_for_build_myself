#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    // 1. 输入
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        nums.push_back(j);
    }

    // 2. 程序处理体
    // 方法一： 排序之后偶数元素下标之和
    sort(nums.begin(), nums.end());
    int sum=0;
    // 偶数元素下标之和
    for(int i=0; i<n;i++){
        if(i%2==0){
            sum+=nums[i];
        }
    }
    cout<<sum;

    // 方法二：运用双指针，不排序
    // int* p1 = &nums[0];
    // int all_sum = 0;
    
    
    
    // 每个数只能被用一次， 如何实现？实现了就能正常分类输出
    // for(p1; p1<&nums[n]; ++p1){
    //     int i = 10001;
    //     int* temp1,*temp2=&i;
    //     int sum = 0;
    //     for(int* p2 = p1+1; p2<&nums[n]; ++p2){
    //         if(min(*p1,*p2)>=sum){
    //             sum=min(*p1,*p2);
    //             if(p1!=p2){
    //                 temp1 = p1;
    //                 cout<<*temp1<<" a ";
    //                 if(*p1 < *p2){
    //                     if(*p2 < *temp2){
    //                     temp2 = p2;
    //                     cout<<*temp2<<" b ";
    //                     }else{
    //                         temp2 = p2;
    //                     }
    //                 }
 
    //             }
                
                
    //         }

    //     } 
    //     if(*temp1!=0 && *temp2!=0){
    //         *temp1 = 0;  // 将已经用过的置为0
    //         *temp2 = 0;
    //     }

    //     all_sum+=sum;  
    // }

    // cout<<all_sum;
    // 3. 输出
    // for(auto c:nums){
    //     cout<<c<<endl;
    // }
}