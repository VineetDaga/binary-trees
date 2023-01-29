#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

//9. to find height of the tree
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}

//10. diametre of the tree is the longest distance between any two node of the tree
/*
three things are there in this
1. diameter from the left side
2. diamter from the right side
3. combination from both left side and left side

max of 1,2,3 will give the diameter of the tree
*/

// time complexity is N^2
int diameter(node *root)
{
    if (root == NULL)
    {
        return;
    }
    int l = diameter(root->left);
    int r = diameter(root->right);
    int h = height(root->left) + height(root->left) + 1;

    int ans = max(l, max(r, h));
    return ans;
}
// in this method the time complexity is O(N)
pair<int, int> dia(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> l = dia(root->left);
    pair<int, int> r = dia(root->right);

    int left = l.first;
    int right = r.first;
    int h = l.second + r.second + 1;

    pair<int, int> ans;
    ans.first = max(left, max(right, h));
    ans.second = max(l.second, r.second) + 1;

    return ans;
}

/*
11. check for balanced treein this we check that the
given tree is balance or not by using the formula
bool ans = abs(height(left) - height(right))<=1
for all the nodes
*/

// method 1
// time complexity is N^2

bool balanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool l = balanced(root->left);
    bool r = balanced(root->right);
    bool temp = (abs(height(root->left) - height(root->right)) <= 1);

    return (l && r && temp);
}

// method 2
pair<bool, int> bal(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> l = bal(root->left);
    pair<bool, int> r = bal(root->right);

    pair<bool, int> ans;
    bool left = l.first;
    bool right = r.first;
    bool temp = abs(l.second - r.second) <= 1;

    ans.second = max(l.second, r.second) + 1;
    ans.first = left && right && temp;

    return ans;
}

//12. SUM tree the sum of left part of the tree and the right part of the tree should be equal to the root
// for every node of the tree

// the complexity is O(N)
pair<bool, int> sum(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> l = sum(root->left);
    pair<bool, int> r = sum(root->right);

    bool left = l.first;
    bool right = r.first;
    bool con = (root->data == l.second + r.second);

    pair<bool, int> ans;
    if (left && right && con)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

//13. identical tree
/*
steps
1. check left and right (previous node)
2. check current node
3. move to next node
*/
bool identical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    else if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    else if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    else
    {
        bool left = identical(r1->left, r2->left);
        bool right = identical(r1->right, r2->right);
        bool con = (r1->data == r2->data);

        return (left && right && con);
    }
}