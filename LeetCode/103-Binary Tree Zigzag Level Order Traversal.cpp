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
    vector<vector<int>> zigzagLevelOrder(TreeNode* A) {
        vector<vector<int> > ans;
    if(!A)
        return ans;
    queue<TreeNode*>q;
    q.push(A);
    int c=1;
    while(!q.empty())
    {
        queue<TreeNode*>temp;
        vector<int> tempAns;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr)
            {
                tempAns.push_back(curr->val);
                temp.push(curr->left);
                temp.push(curr->right);
            }
        }
        q = temp;
        if(c%2 == 0)
            reverse(tempAns.begin(), tempAns.end());
        if(tempAns.size())
            ans.push_back(tempAns);
        c++;
    }
    return ans;
    }
};