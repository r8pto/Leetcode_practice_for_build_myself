#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    // 处理字符串，使得奇偶回文串统一处理，如"aba"处理成"^#a#b#a#$"
    int n = s.length();
    string t = "^#";
    for (int i = 0; i < n; i++) {
        t += s[i];
        t += "#";
    }
    t += "$";
    int n_t = t.length();
    vector<int> p(n_t, 0);  // i位置上的回文子串的半径（不包括中心点）
    int center = 0, right = 0;  // center表示最右边的回文子串的中心点，right表示最右边的回文子串的右边界
    for (int i = 1; i < n_t - 1; i++) {
        if (i < right) {
            // 根据回文串对称性，有p[i] = min(p[2*center-i], right-i)
            p[i] = min(p[2*center-i], right-i);
        }
        // 如果回文串中心点左侧右侧对称的字符相等，则扩展回文串
        while (t[i+p[i]+1] == t[i-p[i]-1]) {
            p[i]++;
        }
        // 如果扩展后的回文串右侧位置超出了最右边的回文串，则更新center和right
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    // 找到最长回文子串的中心点和半径
    int max_len = 0, center_idx;
    for (int i = 1; i < n_t - 1; i++) {
        if (p[i] > max_len) {
            max_len = p[i];
            center_idx = i;
        }
    }
    return s.substr((center_idx - max_len) / 2, max_len);
}

int main(){
    string str;
    // 1. 输入
    while(cin>>str){
        cout<<"输入结束"<<endl;
        break;
    }
    int n = str.size();
    // 2. 函数体


    // 3. 输出
    cout<<longestPalindrome(str)<<endl;
    // for(char s : str){
    //     cout<<s<<endl;
    // }

}
