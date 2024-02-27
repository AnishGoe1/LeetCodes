/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int bt_diameter(struct TreeNode* root, int *diameter)
{   
    if (root == NULL)
        return 0;
    
    int left_h = bt_diameter(root->left, diameter);
    int right_h = bt_diameter(root->right, diameter);
    int curr_dia = left_h + right_h;
    
    *diameter = MAX(*diameter, curr_dia);
    return 1 + MAX(left_h, right_h);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diameter = 0;
    bt_diameter(root, &diameter);
    return diameter;
}
