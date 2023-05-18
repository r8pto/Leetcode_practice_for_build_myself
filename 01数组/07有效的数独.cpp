#include<iostream>
#include<vector>
using namespace std;
/* 判断一个9x9的数独是否有效。只需要根据以下规则，
 * 验证已经填入的数字是否有效
 * 1. 1-9在每行只能出现一次
 * 2. 1-9在没列只能出现一次
 * 3. 在3x3的宫内只能出现一次
 * 
 * {{"5","3",".",".","7",".",".",".","."}, 
    {"6",".",".","1","9","5",".",".","."}, 
    {".","9","8",".",".",".",".","6","."}, 
    {"8",".",".",".","6",".",".",".","3"}, 
    {"4",".",".","8",".","3",".",".","1"}, 
    {"7",".",".",".","2",".",".",".","6"}, 
    {".","6",".",".",".",".","2","8","."}, 
    {".",".",".","4","1","9",".",".","5"}, 
    {".",".",".",".","8",".",".","7","9"}};

 */
// 写一个判断行是否有重复的函数
// bool isHang(vector<char> &hang){
//     decltype(hang.begin()) beg = hang.begin(),beg2;
//     for(;beg!=hang.end();++beg){
//         for(beg2=beg+1;beg2!=hang.end();++beg2){
//             if(*beg!='.'&&*beg==*beg2){
//                 return false;
//             }
//         }
//     }
//     return true;
// }


// bool isValidsudoku(vector<vector<char>>& board){
//     // 1. 首先判断一个行中的字符有无重复，这是最简单的，每一行对应一个vector
//     // 同时还不能把点也当作判断的条件，把点与数字区分开if(!="."&&)
//     decltype(board.size()) n = board.size();
//     for(int i=0;i<n;++i){  // 检查每一行
//         if(!isHang(board[i])){
//             return false;
//         }
//     }

//     // 2. 检查每一列


//     // 3. 检查每一个空格

//     return true;
// }   


bool isValidSudoku(vector<vector<char>>& board) {
    // 定义三个计数器
    int row[9][9]={0};
    int column[9][9]={0};
    int box[9][9]={0};
    // 将数组框挨个遍历！这里是有限的
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int box_index = i / 3 * 3 + j / 3;   // 计算9宫格的索引号
            int temp = board[i][j]-'0'-1;   // 计算索引 
            if(temp=='.'-'0'-1) continue;   // 如果等于点则继续算
            if (row[i][temp]==1 || column[j][temp]==1 || box[box_index][temp]==1) return false;
            ++row[i][temp];
            ++column[j][temp];
            ++box[box_index][temp];
        }

    }
    return true;
}
// 作者：duyanshu
// 链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2f9gg/?discussion=YZKhCK
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main(){
    // 1. 输入  用单引号才是对应char型
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}, 
                                  {'6','.','.','1','9','5','.','.','.'}, 
                                  {'.','9','8','.','.','.','.','6','.'}, 
                                  {'8','.','.','.','6','.','.','.','3'}, 
                                  {'4','.','.','8','.','3','.','.','1'}, 
                                  {'7','.','.','.','2','.','.','.','6'}, 
                                  {'.','6','.','.','.','.','2','8','.'}, 
                                  {'.','.','.','4','1','9','.','.','5'}, 
                                  {'.','.','.','.','8','.','.','7','9'}};
    // 函数体测试
    bool b = isValidSudoku(board);

    cout<<"ture or false? "<< b << endl;
}