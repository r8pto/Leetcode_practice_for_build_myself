#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
给你二叉树的根节点root，返回它节点值的前序遍历
1. 先访问根节点
2. 然后遍历左子树
3. 最后遍历右子树
*/
struct TreeNode{
    int val;  // 根节点
    TreeNode *left;   // 定义指向TreeNode类型的左指针（遍历左子树）
    TreeNode *right;  // 定义指向TreeNode类型的右指针（遍历右子树）

    // 定义了三个构造函数，可以按照该形式来实例化TreeNode对象
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> preorderTravelsal_without_digui(TreeNode* root); // 提前声明函数 
vector<int> preorderTraversal(TreeNode* root);   // 递归写法
void dfs(TreeNode* root, vector<int> &ret);

int main(){
    // 1. 输入，这个输入应该是指向TreeNode数据类型的指针
    TreeNode templ = {2};  // 采用了第二种构造方式
    TreeNode* left = &templ;
    TreeNode tempr = {3};
    TreeNode* right = &tempr;

    TreeNode node = {1,left,right};   // 采用了第三种构造方式
    TreeNode* root = &node;

    // 2. 执行函数体
    vector<int> ans = preorderTravelsal_without_digui(root);
    vector<int> ret = preorderTraversal(root);
    // 3. 输出结果
    cout<<"非递归解法："<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"递归解法："<<endl;
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 定义一个前序遍历的函数，返回类型为装着int类型的vector容器
// 形参为指向TreeNode的指针
vector<int> preorderTravelsal_without_digui(TreeNode* root){
    TreeNode* p = root;  // 都是指向TreeNode类型的指针
    vector<int> ret;  // 用于储存结果
    if(root != nullptr){  
        stack<TreeNode*> st;   // 定义一个类型为TreeNode*的栈（deque）
        st.push(p);  // 将根节点入栈
        while(!st.empty()){
            p = st.top(); // 栈中第一个节点的值 --- 根节点先访问
            st.pop();  // 弹出它

            ret.push_back(p->val);

            if(p->right != nullptr){  // 先压右子树，先压的最后才会遍历（pop）
                st.push(p->right);
            }

            if(p->left!=nullptr){   // 压入左子树
                st.push(p->left);
            }

        }
    }
    return ret;
}

// 递归写法
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ret;
    dfs(root, ret);
    return ret;
}
void dfs(TreeNode* root, vector<int> &ret){  // 递归算法
    if(root == nullptr){
        return;
    }
    ret.push_back(root->val);
    dfs(root->left, ret);
    dfs(root->right, ret);

}