#include<iostream>
#include<string>
#include<cstring>  // 包含strlen
#include<vector>

using namespace std;


vector<int> buildNext(string s) {
    vector<int> next;
    int m = s.size(), j = 0;
    int t = -1;
    next.resize(m);
    // 因为第一个字母没有前缀，所以next[0] = -1
    next[0] = t;
    while (j < m - 1) {
        // t < 0 也就是 t == -1,要从模式串的第一位开始匹配，然后主串也要向后移一下
        if (t < 0 || s[j] == s[t]) {
            j++;
            t++;
            next[j] = t;
        } else {
            t = next[t];
        }
    }
    return next;

}
int strStr(string haystack, string needle) {
    vector<int> next;
    if (needle.size() == 0) return 0;
    next = buildNext(needle);
    // 指向主串
    int n = haystack.size(), i = 0;
    // 指向模式串
    int m = needle.size(), j = 0;
    while (i < n && j < m) {
        // j < 0 说明 j==-1要从头开始匹配了
        if (j < 0 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            // haystack[i] 和 needle[j]不匹配，要从模式串下标为next[j]的继续匹配，也就是最长公共前缀后缀的长度
            j = next[j];
        }
    }
    // 如果j == m证明模式串匹配完毕，在主串中找到了模式串，范围模式串在主串中出现的第一个下标，i - j
    if (j == m) {
        return i - j;
    }
    return -1;
}



int main(){
    // 1. 输入需要处理的字符串
    string haystack;   // 主串
    string needle;  // 模式串
    cin>>haystack>>needle;

    // 2. 解决方法
    // 2.1 暴力解决，复杂度（n*m）
    // int n,m,count=0;
    // n = haystack.size();
    // m = needle.size();
    // //cout<<n<<m;
    // for(int i=0; i<n;i++){
    //     cout<<i<<" ";
    //     for(int j=0;j<m;j++){
    //         if(haystack[i]==needle[j]){  // 如果第一个数相等，则继续
    //             i++;
    //             if(j==m-1){
    //                 count++;
    //                 cout<<i-m;
    //                 i = n;   // 只想找到第一个一样的
    //             }
    //         }else{
    //             i = i-j;
    //             break;
    //         }
    //     }
    // }

    // if(count==0){
    //     cout<<-1;
    // }
    // 2. 实现字符串匹配算法（KMP)
    cout<<strStr(haystack, needle);

    
}