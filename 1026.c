/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) (a>b?a:b)

int FindMaxMinVal(struct TreeNode* root, int max, int min)

{

    if(!root) return (max - min);

    

    max = root->val > max ? root->val : max;

    min = root->val < min ? root->val : min;

    

    int left = FindMaxMinVal(root->left, max, min);

    int right = FindMaxMinVal(root->right, max, min);

    

    return max(right,left);

}

int maxAncestorDiff(struct TreeNode* root){

    

    return FindMaxMinVal(root,root->val,root->val);

}
