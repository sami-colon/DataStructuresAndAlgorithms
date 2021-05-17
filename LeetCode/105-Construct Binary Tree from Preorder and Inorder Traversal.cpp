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
TreeNode* helper(vector<int> &pre, vector<int> &in, int start, int end, int x)
{
    if(start <= end)
    {
        TreeNode* ans = new TreeNode(pre[x]);
        int i = 0;
        for(i=start; i<=end; i++)
        {
            if(in[i] == pre[x])
                break;
        }
        // cout<<x<<" "<<i<<endl;
        ans->left = helper(pre, in, start, i-1, x+1);
        ans->right = helper(pre, in, i+1, end, x+1+(i-start));
        return ans;
    }
    return NULL;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* ans;
    if(!preorder.size())
        return ans;
    ans = helper(preorder, inorder, 0, preorder.size()-1, 0);
    return ans;
    }
};