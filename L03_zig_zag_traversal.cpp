#include "L00_tree.cpp"
/*14.
zig - zag traversal of the tree 
1.similar to level order traveral
2.we will insert node in queue same as level order but for storing values in the 
  array we will make a bool variable which will indicate that the order in which we have to 
  store the values in vector is left to right or right to left

*/
vector<int> zigzag(node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<node * > q;
    q.push(root);
    bool order = true; // true means left to right
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size;i++){
            node *front = q.front();
            q.pop();
            int index = order ? i : size - i;
            temp[index] = front->data;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        order = !order;
        for(auto i : temp){
            ans.push_back(i);
        }
    }
    return ans;
}
