#include<iostream>
#include<string>
#include<vector>
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
    // 这里可以创建一个有26个元素的vector,如果出现则+1,最后判断两个vecotr是否相等
    vector<int> v1_n(26,0);
    vector<int> v2_m(26,0);
    for(int i=0;i<n;++i){
        v1_n[s[i]-'a']+=1;
    }
    for(int i=0;i<m;++i){
        v2_m[t[i]-'a']+=1;
    }
    if(v1_n==v2_m){
        return true;
    }else{
        return false;
    }
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