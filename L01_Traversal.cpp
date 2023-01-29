#include <iostream>
#include <queue>
#include <stack>
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

//1. building of tree
// time complexity = O(number of nodes)
// space complexity = O(height)
node *buildtree(node *root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter data in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

//2. level order traversal
// time complexity is = O(no of nodes)
// space complexity is O(no of nodes)
void levelorder(node *root)
{
    if (root = NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();

        if (n = NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << n->data << " ";
            if (n->left != NULL)
            {
                q.push(n->left);
            }
            if (n->right != NULL)
            {
                q.push(n->right);
            }
        }
    }
}

//3. reverse order traversal
// same complexity
void reverse(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);
        if (temp = NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }
    }
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

//4. inorder left root right
//same 
void inorder(node *root)
{
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//5. preorder root left right
//same
void preorder(node *root)
{
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//6. post order left right root
//same
void post(node *root)
{
    post(root->left);
    post(root->right);
    cout << root->data << " ";
}

//7. building of tree in level order format
node *tree(node *root)
{
    cout << "Enter the value of root " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter the data left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter the data right of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

//8. count number of leaf node
int leaf(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = leaf(root->left);
    int r = leaf(root->right);

    return l + r;
}
