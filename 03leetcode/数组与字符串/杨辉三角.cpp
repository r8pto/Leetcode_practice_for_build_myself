#include<iostream>
#include<vector>

using namespace std;
/*给定一个非负整数 numRows，生成「杨辉三角」的前 n
umRows 行。在「杨辉三角」中，每个数是它左上方和右上方的
数的和。*/

int main(){
    int numRows;
    // 1. 输入杨辉三角的行数
    cin >> numRows;
    
    // 2. 处理部分
    vector<vector<int>> ans;  // 为什么不可以用ans[0] = {1}的方式赋值
    if(numRows==0){
        cout<<"no thing "<<endl;
    }
    ans.push_back(vector<int>(1, 1));  // 只初始化了第一个元素
    for(int i=1; i<numRows; i++){
        vector<int> a(i+1);
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                a[j]=1;
            }else{
                a[j]=ans[i-1][j-1] + ans[i-1][j];
            }
        }
        ans.push_back(a);
    }
    
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}