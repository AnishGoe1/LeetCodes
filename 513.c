int depth(struct TreeNode* root) {
    if(!root) return 0;
    return 1 + fmax(depth(root->left), depth(root->right));
}

void dfs(struct TreeNode* root, int len, int* ans) {
    if(!root) return;
    if(!len) *ans = root->val;
    dfs(root->right, len-1, ans);
    dfs(root->left, len-1, ans);
}

int findBottomLeftValue(struct TreeNode* root) {
    int len = depth(root), ans = 0;
    dfs(root, len-1, &ans);
    return ans;
}
