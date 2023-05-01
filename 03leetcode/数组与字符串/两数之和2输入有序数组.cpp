#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> numbers;
    int n,target;
    // 1. 输入数组numbers 和 求和目标target
    cin>>n>>target;
    for(int i=0; i<n;++i){
        int j;
        cin>>j;
        numbers.push_back(j);
    }

    // 1.2 按照题目要求，将数组按照非递减顺序排列
    sort(numbers.begin(), numbers.end());

    // 2. 函数体通过指针找到相加等于目标的和，并返回
    // decltype(numbers.size()) n = numbers.size();
    // 方法一：本人方法，通过枚举实现
    // int *p1 = &numbers[0];
    // int *begin = p1;
    // int *last = &numbers[n-1];
    // // 时间复杂度有点高
    // for(;p1<=last;++p1){
    //     for(int *p2 = p1+1;p2<=last;++p2){
    //         if(*p1 + *p2 == target){
    //             int x1 = p1-begin+1;
    //             int x2 = p2-begin+1;
    //             string s = "[";  // 第一个相加的数一定要是字符串
                
    //             string ans = s + to_string(x1) + "," + to_string(x2) + "]";
    //             // cout<<"["<<p1-begin+1<<","<<p2-begin+1<<"]"<<endl;
    //             cout<<ans;
    //             p1 = last+1;
    //             break;
    //         }
    //     }
    // }

    // 方法二：对撞指针,时间复杂度下降，空间复杂度没有降低，因为我用了指针，可以直接用index
    int *left = &numbers[0];
    int *begin = left;
    int *right = &numbers[n-1];
    string s = "[";
    while(left<right){
        if(*left+*right == target){
            string ans = s + to_string(left-begin+1) + "," + to_string(right-begin+1) + "]";
            cout<<ans;
            break;
        }else if(*left+*right<target){
            ++left;
        }else{
            --right;
        }
    }

    return 0;
}