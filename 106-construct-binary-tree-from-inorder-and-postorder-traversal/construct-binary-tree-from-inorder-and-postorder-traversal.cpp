class Solution {
public:

    TreeNode* build(vector<int>& postorder, int poststart, int postend,
                    vector<int>& inorder, int instart, int inend,
                    map<int, int>& inmap) {

        if (poststart > postend || instart > inend) return NULL;

        // Root comes from postorder END
        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = inmap[root->val];
        int numsleft = inroot - instart;

        // Left subtree
        root->left = build(postorder, poststart, poststart + numsleft - 1,
                           inorder, instart, inroot - 1, inmap);

        // Right subtree
        root->right = build(postorder, poststart + numsleft, postend - 1,
                            inorder, inroot + 1, inend, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        return build(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1,
                     inmap);
    }
};