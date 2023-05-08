#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
中序遍历：
1. 首先，遍历左子树
2. 其次，遍历根节点
3. 最后，遍历右子树
*/

struct TreeNode{
    int val;  // 代表节点上的值
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){} //构造函数1
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}      
};

vector<int> inorderTraversal(TreeNode* root);
void dfs(TreeNode* root, vector<int>& ret);

int main(){
    // 1. 输入，这个输入应该是指向TreeNode数据类型的指针
    TreeNode templ = {2};  // 采用了第二种构造方式
    TreeNode* left = &templ;
    TreeNode tempr = {3};
    TreeNode* right = &tempr;

    TreeNode node = {1,left,right};   // 采用了第三种构造方式
    TreeNode* root = &node;

    // 2. 函数体
    vector<int> ans = inorderTraversal(root);

    // 3. 输出
    for(auto i : ans){
        cout<<i;
    }


}

vector<int> inorderTraversal(TreeNode* root){
    TreeNode* p = root;
    vector<int> ans; // 函数返回结果
    if(root != nullptr){  // 如果root指向的对象不为空的话
        stack<TreeNode*> st;  // 定义一个可以装TreeNode*的栈
        while(!st.empty() || p!=nullptr){  // 栈不为空的情况下便一直输入
            if(p!=nullptr){
                st.push(p);  // 先让根节点入栈
                p = p->left;  // 然后让左节点入栈，这样便内先弹出左节点

            }else{   // 说明左节点和根结点已经全部入栈，则输出他们
                p = st.top();
                st.pop();
                ans.push_back(p->val);
                p= p->right;  // 让右子树节点入栈
            }
           
        }

    }
    return ans;
}

    vector<int> inorderTraversal_digui(TreeNode* root) {
        vector<int> ret;
        dfs(root,ret);  // 中序遍历递归函数，左 根 右
        return ret;
    }
    void dfs(TreeNode* root, vector<int>& ret){
        if(root == nullptr){
            return;
        }
        dfs(root->left, ret);           // 左
        ret.push_back(root->val);       // 根
        dfs(root->right, ret);          // 右
    }
