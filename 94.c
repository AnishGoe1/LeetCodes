int i=0;
int arr[101]={0};
void inorder(struct TreeNode* s)
{
    if(s!=NULL)
    {
        inorder(s->left);
        arr[i++]=s->val;
        inorder(s->right);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    inorder(root);
    int* ans=malloc(i*sizeof(int));
    for(int j=0;j<i;j++) ans[j]=arr[j];
    *(returnSize)=i;
    i=0;
    return ans;
}
