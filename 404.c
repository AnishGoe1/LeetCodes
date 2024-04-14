int result;
void preorder(struct TreeNode* root,int temp)
{
    if(root==NULL) return;
    if(temp==0 && root->left==NULL && root->right==NULL)
        result=result+root->val;
    preorder(root->left,0);
    preorder(root->right,1);
}
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root==NULL) 
        return 0;
    result=0;
    preorder(root->left,0);
    preorder(root->right,1);
    return result;

}
