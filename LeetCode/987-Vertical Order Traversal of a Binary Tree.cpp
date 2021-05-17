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
void helper(TreeNode* A, map<int, map<int,vector<int> > >&m, int x = 0, int y = 0)
{
    if(!A)
        return;
    m[y][x].push_back(A->val);
    helper(A->left, m, x+1, y-1);
    helper(A->right, m, x+1, y+1);
    return;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* A) {
    map<int, map<int,vector<int> > >m;
    helper(A, m);
    vector<vector<int> > ans;
    for(auto y:m)
    {
        vector<int>t;
        for(auto x:y.second)
        {
            sort(x.second.begin(), x.second.end());
            for(auto z:x.second)
            {
                t.push_back(z);
            }
        }
        ans.push_back(t);
    }
    return ans;
    }
};