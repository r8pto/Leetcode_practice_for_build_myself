#include<iostream>
#include<vector>
using namespace std;
/*
 * 1. 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 2. 最高位数字存放在数组的首位，数组中每个元素只存储单个数字。
 */

vector<int> plusOne(vector<int>& digits){
    // 如果不进位就很简单，但考虑到进位的问题
    // 可能每一位数都有进位的可能
    // 还有可能出现999 进一位变成四位数1000，这个如何实现
    decltype(digits.size()) n = digits.size();
    for(int i=n-1;i>=0;--i){
        if(digits[i]!=9){
            digits[i]+=1;
            break;
        }else{
            if(i!=0){
                digits[i]=0;
                continue;
            }
            if(i==0){
                // cout<<"i=0"<<endl;
                digits.insert(digits.begin(),1);
                digits[i+1] = 0;
                continue;
            }

        }
    }
    return digits;
}

// 其他同学的解
// vector<int> plusOne(vector<int>& digits) {
//     if(digits[0]==0){digits[0]=1;}    // 如果为0则直接为1,这一步可以省略其实
//     else 
//       {int i=1,size=digits.size();
//           if(digits[digits.size()-1]==9)   // 如果是9继续加，等成为10时再处理
//             {digits[digits.size()-i]++;   
//               while(i<size&&digits[digits.size()-i]==10) 
//                 {digits[digits.size()-i]=0,i++,digits[digits.size()-i]+=1;}
//               if(digits[digits.size()-i]==10)  // 如果第一位为10，则将该位置1,后面补0
//                 {digits[digits.size()-i]=1,digits.push_back(0);}
       
//         }
//           else{digits[digits.size()-1]+=1;}
//       }
//     return digits;
//     }

// 作者：空
// 链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2cv1c/?discussion=5NijuA
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main(){
    // 1. 输入
    int n;
    cin>>n;
    vector<int> digits;
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        digits.push_back(j);
    }
    // 2. 执行加一函数体
    vector<int> ans = plusOne(digits);
    // 3. 输出
    for(auto c:ans){
        cout<<c<<" ";
    }
}