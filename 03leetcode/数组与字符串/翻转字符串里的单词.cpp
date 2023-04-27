#include<iostream>
#include<string>
#include<cctype>   // 可以检测空格
#include<vector>
using namespace std;

int main(){
    // 1. 给定一段字符串
    string str;
    // str = "the sky is blue";
    getline(cin, str);  // getline 可以接受空格，直接用cin就不行


    // 2. 分析一波，每个单词肯定是以空格为隔断，如果遇到空格就当成一个完整的单词
    decltype(str.size()) n = str.size();
    vector<string> ans;
    string word;
    for(int i=0; i<n+1; i++){
        word.push_back(str[i]);
        if(isspace(str[i]) || i==n-1){
            if(i==n-1){
                word=word+" ";   // 手动添加空格
            }
            ans.push_back(word);
            word="";
        }
        //cout<<str[i];
         
    }
    
    // int count =0;
    // for(auto c:str){
    //     if(isspace(c)){
    //         count++;
    //     }
    // }
    // for(int i=0;i<count+1;i++){
    //     string word; // 用来存放每一个完整的单词
    //     for(auto c:str){  // 这里要想办法弹出str中的c
    //         word.push_back(c);
    //         str.pop_back();
    //         if(isspace(c)){
    //             cout<<word;
    //             break;
    //         }
    //     }
    // }

// 别人代码
//     int N = s.length();
//     int i = 0, j = 0;
//     while (i < N)
//     {
//         while (i < N && s[i] == ' ')
//         {
//             i++;
//         }
//         while (i < N && s[i] != ' ')
//         {
//             swap(s[j++], s[i++]);
//         }
//         j = j + 1;
//     }
//     N = s.length()-1;
//     while (s[N] == ' ')
//     {
//         N--;
//     }
// //  去除多余空格
//     s = s.substr(0, N+1);
//     reverse(s.begin(), s.end());

//     int start = 0, end = 0, tmp;
//     while (start < N)
//     {
//         while (end < N&& s[end] != ' ')
//         {
//             end++;
//         }
//         tmp = s[end] == ' ' ? end - 1 : end;
//         while (start < tmp)
//         {
//             swap(s[start++], s[tmp--]);
//         }
//         start = end + 1;
//         end = start ;
//     }
    
//     return s;

    decltype(ans.size()) l = ans.size();
    for(int i = l-1;i>=0;i-- ){
        cout<<ans[i];
    }
    return 0;

}