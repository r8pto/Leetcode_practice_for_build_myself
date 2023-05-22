#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
 * 给定一个字符串s,找到它的第一个不重复的字符，并返回它的索引，如果不存在，则返回-1
 */
int firstUniqChar(string s){
    decltype(s.size()) n = s.size();
    // 1. 暴力枚举法，输出外层循环数即可
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            if(j!=i && s[i]==s[j]){
                ++cnt;
                break;
            }
        }
        if(cnt==0){
            return i;
        }
    }
    return -1;
}

int main(){
    // 1. 输入
    string s;
    cin>>s;

    // 2. 执行函数体
    int ans = firstUniqChar(s);

    // 3. 输出答案
    cout<<ans<<endl;

}
