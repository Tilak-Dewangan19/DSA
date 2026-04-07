class Solution {
public:
    // unordered_map<int, int> mp; // value -> index in inorder

    // TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
    //                 vector<int>& inorder, int inStart, int inEnd) {
        
    //     if (preStart > preEnd || inStart > inEnd)
    //         return NULL;

    //     TreeNode* root = new TreeNode(preorder[preStart]);

    //     int inRoot = mp[root->val];  // index in inorder
    //     int numsLeft = inRoot - inStart;

    //     root->left = build(preorder, preStart + 1, preStart + numsLeft,
    //                        inorder, inStart, inRoot - 1);

    //     root->right = build(preorder, preStart + numsLeft + 1, preEnd,
    //                         inorder, inRoot + 1, inEnd);

    //     return root;
    // }

    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     vector<int> inorder = preorder;
    //     sort(inorder.begin(), inorder.end());

    //     // store inorder indices
    //     for (int i = 0; i < inorder.size(); i++) {
    //         mp[inorder[i]] = i;
    //     }

    //     return build(preorder, 0, preorder.size() - 1,
    //                  inorder, 0, inorder.size() - 1);
    // }
  
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
