int calNum(struct TreeNode*root,int treeNumber){
    if(root==NULL)
        return 0;  
    
    if(root->left==NULL && root->right==NULL)
        return treeNumber*10+root->val;
    else
        return calNum(root->left,treeNumber*10+root->val)+calNum(root->right,treeNumber*10+root->val);

}


int sumNumbers(struct TreeNode* root){
int result =calNum(root,0);
    return result;
    
}
