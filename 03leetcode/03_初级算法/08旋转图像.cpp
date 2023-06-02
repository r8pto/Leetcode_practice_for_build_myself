#include<iostream>
#include<vector>
using namespace std;
/*
 * 将一个n x n的二维矩阵原地旋转90度，不使用其他矩阵
 */
void rotate(vector<vector<int>>& matrix){
    decltype(matrix.size()) n = matrix.size(), m =matrix[0].size();
    // n为行数，m为列数
    //1. 先让矩阵上下交换
    for(int i=0;i<n/2;++i){  // 若是偶数则会重复交换，故这里不能等于i<=n/2
        for(int j=0;j<m;++j){
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }

    //2. 让矩阵对角线交换
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){  // 让j小于等于i确保只运行半个三角形
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main(){
    // 1. 输入
    vector<vector<int>> matrix1 = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    vector<vector<int>> matrix2 = {{5,1,9,11},
                                   {2,4,8,10},
                                   {13,3,6,7},
                                   {15,14,12,16}};
    // 2. 使用函数进行旋转
    rotate(matrix1);
    // 3. 输出
    for(auto v : matrix1){
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
