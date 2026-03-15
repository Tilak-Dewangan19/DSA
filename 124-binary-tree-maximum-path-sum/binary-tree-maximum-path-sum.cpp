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
int pathsum(TreeNode* root, int &maxi){
    if(root == nullptr) return 0;
    int lv = max(0, pathsum(root->left, maxi));
    int rv = max(0, pathsum(root->right, maxi));
    maxi = max(maxi, root->val+lv+rv);
    return root->val+max(lv, rv);
}
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        pathsum(root, maxi);
        return maxi;


        
    }
};