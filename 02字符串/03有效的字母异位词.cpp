#include<iostream>
#include<string>
using namespace std;

/*
 * 给定两个字符串s和t,编写一个函数来判断t是否是s的字母异位词。
 * 注意：若s和t中每个字符出现的次数都相同，则称s和t互为字母异位词
 */
bool isAnagram(string s, string t){
    decltype(s.size()) n=s.size(), m=t.size();
    if(n!=m){ // 首先要求输入字符长度一致，才可能是字母异位词
        return false;
    }
    // 先判断是否有不一样的字符
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            if(s[i]==t[j]){
                ++cnt;
            }
        }
        if(cnt==0){
            cout<<"here"<<endl;
            return false;
        }
    }

    // 然后再判断出现次数
    for(int i=0;i<n;++i){
        int cnt1=0;
        int cnt2=0;
        for(int j=0;j<n;++j){
            if(i!=j && s[i]==s[j]){
                ++cnt1;
            }
            if(i!=j && t[i]==t[j]){  // 因为字母出现的顺序不同也会出现问题，所以考虑一下用一个代表26个字母的数组？
                ++cnt2;
            }
        }
        if(cnt1!=cnt2){  // 只是用字母出现次数来定，多少不科学，不能确定是不是同一字母
            cout<<s[i]<<cnt1<<" "<<cnt2<<endl;
            return false;
        }
    }
    return true;
}

int main(){
    // 1. 输入
    string s,t;
    cin>>s>>t;

    // 2. 执行函数体
    bool ans = isAnagram(s, t);

    // 3. 输出答案
    cout<<ans<<endl;
}