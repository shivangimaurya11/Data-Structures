/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root,int &k,int &count,int &ans)
    {
        if(root==NULL)
            return ans;
        inorder(root->left,k,count,ans);
        count++;
        if(count==k)
            ans=root->val;
        inorder(root->right,k,count,ans);
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans=0;
        return inorder(root,k,count,ans);
    }
};