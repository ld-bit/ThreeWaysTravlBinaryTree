#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
  TreeNode* right;
  TreeNode* left;
  int val;
};
class Solution {
public:
    void preOrder(vector<int>&arr,TreeNode* root)
    {
        TreeNode* cur=root;
        stack<TreeNode*>sk;
        while(cur||!sk.empty())
        {
            if(cur)
            {
                arr.push_back(cur->val);
                sk.push(cur);
                cur=cur->left;
            }
            else 
            {
                TreeNode* top=sk.top();
                sk.pop();
                if(top)
                cur=top->right;
            }
        }
    }
    void Inorder(vector<int>& arr,TreeNode* root)
    {
        TreeNode* cur = root;
        stack<TreeNode*>sk;
        while(cur || !sk.empty())
        {
            if(cur)
            {
                sk.push(cur);
                cur=cur->left;
            }
            else 
            {
                TreeNode* top=sk.top();
                sk.pop();
                if(top)
                {
                    arr.push_back(top->val);
                    cur=top->right;
                }
            }
        }
    }
    void postOrder(vector<int>& arr,TreeNode* root)
    {
        TreeNode* cur = root;
        stack<TreeNode*>sk;
        TreeNode* ptr=nullptr;
        while(cur || !sk.empty())
        {
            if(cur)
            {
                sk.push(cur);
                cur = cur -> left;
            }
            else 
            {
                TreeNode* top = sk.top();
                if(top->right ==nullptr || top->right == ptr)
                {
                    arr.push_back(top->val);
                    sk.pop();
                    ptr = top;
                }
                else 
                {
                    cur = top->right;
                }
            }
        }
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<int>pre;
        vector<int>inorder;
        vector<int>post;
        preOrder(pre,root);
        Inorder(inorder,root);
        postOrder(post,root);
        vector<vector<int>>res;
        res.push_back(pre);
        res.push_back(inorder);
        res.push_back(post);
        return res;
    }
};
int main()
{
    TreeNode* root = nullptr;
    Solution s;
    vector<vector< int>>arr;
    arr=s.threeOrders(root);
    return 0;
}
