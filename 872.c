/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void addLeaf(struct TreeNode* root, int* ar, int* cnt)
{
    if(root->left == NULL && root->right == NULL)
    {
        ar[(*cnt)++] = root->val;
        return;
    }
    
    if(root->left)
        addLeaf(root->left,ar,cnt);
    if(root->right)
        addLeaf(root->right,ar,cnt);
    
    return;
}


bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){

    int root1ar[200] = {-1};
    int root2ar[200] = {-1};
    int cnt1 = 0;
    int cnt2 = 0;
    
    addLeaf(root1, root1ar, &cnt1);
    addLeaf(root2, root2ar, &cnt2);
    
    if(memcmp(root1ar,root2ar,200) == 0) return true;
    
    return false;
}
