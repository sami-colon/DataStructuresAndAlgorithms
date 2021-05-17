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

map<int,int>m;
TreeNode* helper(vector<int> &A, vector<int> &B, int start, int end, int pos) {
    if(start <= end)
    {
        TreeNode* ans = new TreeNode(B[pos]);
        ans->left = helper(A, B, start, m[B[pos]] - 1, pos-1-(end- m[B[pos]]));
        ans->right = helper(A, B, m[B[pos]] + 1, end, pos-1);
        return ans;
    }
    return NULL;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& A, vector<int>& B) {
    m.clear();
    for(int i=0; i<A.size(); i++)
    {
        m[A[i]] = i;
    }
    TreeNode* ans = helper(A,B,0,A.size()-1, B.size()-1);
    return ans;
    }
};