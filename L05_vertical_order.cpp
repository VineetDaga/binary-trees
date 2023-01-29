#include "L00_tree.cpp"
#include<map>

/*
16. vertical traversal
isme hum distance wise travel karte h
jese ki root node 0 h ek number line mei 
toh left part -1 hoga aur right part +1 hoga 
aur jese jese hum left mei jaate rahenge woh number line ki tarah aur negavtive hota rahega
and same for right side

so basically in vertical order traversal mei hame jo node sabse pehle number line mei aayegi usse sabse pehle print karwana hai 
aur agar ki distance pe do ya usse jyada node aati hai toh phir uss case mei hum level ke order mei print karwa denge unhe jiska level kam woh pehle print ho jayega 

isme do data structure ki jarurat padegi hame 
1. map <int(horizontal distance),map<int(level ke live) ,vector<int>(node ka data store karwaane ke liye)>
2. queue<pair<node* , pair<int(horizontal distance),int(level)>>

uske baad level order traversal maarenge phir saara data map mei store karwa lenge 
uske baad map ka data vector mei daal denge 
*/

vector<int> vertical(node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map < int, map<int, vector<int>>> sab;
    queue<pair<node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()){
        pair<node *, pair<int, int>> p = q.front();
        q.pop();
        int hd = p.second.first;
        int level = p.second.second;

        sab[hd][level].push_back(p.first->data);

        if(p.first->left){
            q.push(make_pair(p.first->left, make_pair(hd - 1, level + 1)));
        }
        if (p.first->right)
        {
            q.push(make_pair(p.first->right, make_pair(hd + 1, level + 1)));
        }
    }

    for( auto i :sab){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}