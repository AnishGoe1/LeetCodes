/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depthAndFindVal(struct TreeNode* root, int val, bool* exist, int* HightStart){

    if(root == NULL)

        return -1;

    

    int hight =  1 + fmax(depthAndFindVal(root->left, val, exist, HightStart), depthAndFindVal(root->right, val, exist, HightStart));

    if(root->val == val){

        *exist = true;

        *HightStart = hight;        

    }

    return hight;

}

//caculate depth

int depth(struct TreeNode* root){

    if(root == NULL)

        return -1;

    return 1 + fmax( depth(root->left) , depth(root->right) );

}

//find path from root's child(left or right) to start 

void findPath(struct TreeNode* root, int start, struct TreeNode** data, int dataIdx, struct TreeNode** path, int* pathIdx){

    if(root == NULL)

        return ;

    data[dataIdx] = root;

    if(root->val == start){

        *pathIdx = dataIdx + 1 ; 

        for(int i = 0; i < *pathIdx ; i++){

            path[i] = data[i];

        }

        return;

    }

    

    findPath(root->left, start, data, dataIdx+1, path, pathIdx);

    findPath(root->right, start, data, dataIdx+1 , path, pathIdx);

}

int amountOfTime(struct TreeNode* root, int start){

    bool Lexist = false;

    bool Rexist = false;

    int  HightStart = 0;

    int LHight = depthAndFindVal(root->left, start, &Lexist, &HightStart  ) + 1;

    int RHight = depthAndFindVal(root->right, start, &Rexist, &HightStart ) + 1;

    

    //special case, root->val == start

    if(root->val == start)

        return fmax(LHight, RHight) ;

    

    int n = fmax(LHight, RHight) ;

    struct TreeNode** data = malloc(n * sizeof(struct TreeNode*)) ;

    int dataIdx = 0;

    struct TreeNode** path = malloc(n * sizeof(struct TreeNode*)) ;

    int pathIdx = 0;

    struct TreeNode* temp;

    if(Lexist == true){

        temp = root->left;   

    }

    else{

        temp = root->right;

    }

    

    findPath(temp, start, data, dataIdx, path, &pathIdx);

    

    int ans;

    if(Lexist == true){

        ans = RHight + pathIdx;

    }

    else{

        ans = LHight + pathIdx;

    }

    

    int StartHigh = depth(path[pathIdx-1]);

    ans = fmax(ans, StartHigh);

    int k = 1;

    for(int i = pathIdx - 2; i >=0; i--){

        int d;

        if(path[i]->left == path[i+1])

            d = depth(path[i]->right) ;

        else

            d = depth(path[i]->left) ;

        ans = fmax(ans, d + 1 + k);

        k++;

    }

    return ans;

}
