class BSTIterator {
private:
    stack<TreeNode*> mystack;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            mystack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* tmpNode = mystack.top();
        mystack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext() {
        return !mystack.empty();
    }
};