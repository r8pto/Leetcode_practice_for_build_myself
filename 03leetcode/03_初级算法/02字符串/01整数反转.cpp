#include<iostream>
#include<vector>
#include<string>
#include<climits>   // MAX_INT和MIN_INT
using namespace std;
/*
 * 反转一个有符号整数的数值部分
 */
// int reverse(int x){   // 溢出错误
//     // 1. 首先应该让x变为string类型
//     string s = to_string(x);
//     decltype(s.size()) n = s.size();
//     if(n==1){
//         return x;
//     }
//     // 2. 然后判断其有无符号,以中间的数为对称轴，交换两头的数
//     if(s[0] == '-'){
//         if(n==2){
//             return x;
//         }
//         for(int i=1;i<=n/2;++i){
//             swap(s[i],s[n-i]);
//         }
//     }else{
//         for(int i=0;i<n/2;++i){
//             swap(s[i],s[n-1-i]);
//         }
//     }
//     // 4. 将字符串转为int型变量
//     int ans = stoi(s);
//     return ans;
// }

int reverse(int x) {
    int res = 0;
    // 使用辗转相除法
    while (x != 0) {
        if (res > INT_MAX / 10 || res < INT_MIN / 10 ) {
            return 0;
        }
        int tmp = x % 10;
        int newRes = res * 10 + tmp;
        //如果数字溢出，直接返回0
        if ((newRes - tmp) / 10 != res)
            return 0;
        res = newRes;
        x = x / 10;
    }
    return res;
}

// 作者：数据结构和算法
// 链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/xnx13t/?discussion=75mpqm
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){
    // 1.输入
    int x;
    cout<<"please input a signed intger"<<endl;
    cin>>x;

    // 2. 执行函数体
    int ans = reverse(x);

    // 3. 输出
    cout<<ans<<endl;
    
}