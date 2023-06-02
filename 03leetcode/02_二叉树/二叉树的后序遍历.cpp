#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root){
    /*
     * 返回类型为vector<int> ， 函数名为postorderTraversal， 输入形参为TreeNode* root
     * 要实现后序遍历，就是先遍历左子树、再遍历右子树，最后遍历根节点
     */
    TreeNode* p = root;
    vector<int> ret;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    if(p!=nullptr){
        s1.push(p);      // 头结点先压入s1中
    }
    while(!s1.empty()){
        p = s1.top();		// 每次从s1中弹出一个结点
        s1.pop();			// 弹出的结点压入s2中
        s2.push(p);

        if(p->left != nullptr){      // 先压左
            s1.push(p->left);
        }
        if(p->right != nullptr){
            s1.push(p->right);       // 再压右
        }
    }

    // 这样s1的顺序就是 根右左，s2的顺序就是左右根
    while( !s2.empty() ){
        ret.push_back(s2.top()->val);
        s2.pop();
    }
    return ret;
}



int main(){
    // 1. 输入，这个输入应该是指向TreeNode数据类型的指针
    TreeNode templ = {2};  // 采用了第二种构造方式
    TreeNode* left = &templ;
    TreeNode tempr = {3};
    TreeNode* right = &tempr;

    TreeNode node = {1,left,right};   // 采用了第三种构造方式
    TreeNode* root = &node;

    // 2. 执行函数体
    vector<int> ans = postorderTraversal(root);
    // 3. 输出结果
    cout<<"非递归解法："<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

}