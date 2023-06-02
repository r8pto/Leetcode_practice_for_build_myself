#include<iostream>
#include<string>

using namespace std;

string reverseWords(string s){
    // 遇到空格或字符串末尾则说明是一个单词
    string ans;
    string words;
    int i=0;
    decltype(s.size()) n = s.size();
    while(i<n){
        words = "";
        while(1){   // 提取每一个单词
            if(isspace(s[i])||i==n){
                break;
            }
            words.push_back(s[i]);
            ++i;
        }
        // 将words反转后装入
        decltype(words.size()) m = words.size();
        // 运用双指针交换字符顺序
        // cout<<m<< " ";
        for(int j=0, k=m-1;j<k;j++,k--){
            swap(words[j], words[k]);
        }
        ans+=words;
        if(i!=n){
            ans += " "; // 拼接一个空格
        }
        
        ++i;  // 空格也要++
    }
    return ans;
}

int main(){
    // 1. 输入
    string s = "Let's take LeetCode contest"; // 直接用题目中的例子
    // 2. 函数体
    string ans = reverseWords(s);

    // 3. 输出
    for(auto c:ans){
        cout<<c;
    }
}