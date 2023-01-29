#include "L00_tree.cpp"

/*
15. bouandary traversal
1. pehle left waale saare print karwa do (exclude leaf node)
     edge case
       jab kisi node ka left part NULL ho but uska right part leaf na ho
       tab hame bas uss node ke liye root->left ki jagah root->right karna hoga
2. phir saare leaf node print karwa do
3. uske baad last mei right waale saare print karwa do but in reverse order(exclude leaf node)
     edge case
       jab kisi node ka right part NULL ho but uska left part leaf na ho
       tab hame bas uss node ke liye root->right ki jagah root->left karna hoga
*/

void left(node * root, vector<int> & ans){
    if(root == NULL || (root->right == NULL && root->left == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        left(root->left,ans);
    }
    else{
        left(root->right, ans);
    }
}

void right(node *root, vector<int> &ans)
{
    if (root == NULL || (root->right == NULL && root->left == NULL))
    {
        return;
    }
    
    if (root->right)
    {
        left(root->right, ans);
    }
    else
    {
        left(root->left, ans);
    }
    ans.push_back(root->data);
}

void leaf(node * root, vector<int> & ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    leaf(root->left,ans);
    leaf(root->right,ans);
}

vector<int> boundary(node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);
    // step 1
    left(root->left, ans);
     
    // step 2
    leaf(root->left, ans);
    leaf(root->right, ans);

    //step 3
    right(root->right, ans);

    return ans;
}