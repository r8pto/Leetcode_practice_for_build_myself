#include<iostream>
#include<vector>

using namespace std;

/*给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。*/
vector<int> getRow(int rowIndex){
    vector<int> ans(rowIndex+1,1);  // 将其全部初始化为1
    // 需要一个数组来存储临时的值
    vector<int> temp;
    if(rowIndex==0){return ans;}
    for(int i=1;i<=rowIndex;++i){
            temp = ans;
            for(int j=0; j<=i;++j){
                if(j==0 || j==i){
                    ans[j]=1;
                }else{
                    ans[j]=temp[j]+temp[j-1];
                }
                
            }
            
        }
    
    return ans;

}

int main(){
    int rowIndex;
    // 1. 输入一个索引
    cin>>rowIndex;

    // 2. 函数体部分
    vector<int> ans = getRow(rowIndex);

    // 3. 输出
    for(auto i : ans){
        cout<<i<<" ";
    }
}