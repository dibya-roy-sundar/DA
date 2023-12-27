#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(node *root)
{
    if (root == NULL)
        return;                // base case
    cout << root->data << " "; // print the current element of tree
    preorder(root->left);      // recursive call for left subtree
    preorder(root->right);     // recursive call for right subtree
}
void postorder(node *root)
{
    if (root == NULL)
        return;                // base case
    postorder(root->left);     // recursive call for left subtree
    postorder(root->right);    // recursive call for right subtree
    cout << root->data << " "; // print the current element of tree
}
void inorder(node *root)
{
    if (root == NULL)
        return;                // base case
    inorder(root->left);       // recursive call for left subtree
    cout << root->data << " "; // print the current element of tree
    inorder(root->right);      // recursive call for right subtree
}

vector<int> itrpreorder(node *root)
{
    vector<int> ans;
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if (temp->right)
        {
            s.push(temp->right);
        }
        if (temp->left)
        {
            s.push(temp->left);
        }
    }

    return ans;
}
vector<int> itrpostorder(node *root)
{
    vector<int> ans;
    stack<node *> s;
    // stack<node*> s2;
    s.push(root);
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        // s2.push(temp);
        ans.insert(ans.begin(), temp->data);
        if (temp->left)
        {
            s.push(temp->left);
        }
        if (temp->right)
        {
            s.push(temp->right);
        }
    }
    // while(!s2.empty()){
    //     ans.push_back(s2.top()->data);
    //     s2.pop();
    // }

    return ans;
}
vector<int> itrinorder(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<node *> s;
    node *temp = root;
    while (true)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }
            temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }

    return ans;
}
vector<vector<int>> threeinone(node *root)
{
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    stack<pair<node *, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1) // pre
        {
            pre.push_back(it.first->data);
            s.push({it.first, ++it.second});
            if (it.first->left)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) // in
        {
            in.push_back(it.first->data);
            s.push({it.first, ++it.second});
            if (it.first->right)
            {
                s.push({it.first->right, 1});
            }
        }
        else if (it.second == 3) // post
        {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

// level order traversal / breadth first search(BFS)
vector<vector<int>> levelorder(node *root)
{
    vector<vector<int>> ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int maxdepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(maxdepth(root->left), maxdepth(root->right));
}
bool checkbalanced(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int left = maxdepth(root->left);   // left height
    int right = maxdepth(root->right); // right height
    if ((left - right) <= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if (checkbalanced(root->left) && checkbalanced(root->right))
    {
        return 1;
    }
    else
    {
        return 0;
    };
}
int maxi = 0;
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxdepth(root->left);   // left height
    int right = maxdepth(root->right); // right height
    if ((left + right) > maxi)
    {
        maxi = left + right;
    }
    diameter(root->left);
    diameter(root->right);
    return maxi;
}

bool identical(node *root1, node *root2)
{
    if (root1 == NULL && root2 != NULL)
    {
        return 0;
    }
    if (root2 == NULL && root1 != NULL)
    {
        return 0;
    }
    vector<int> v1 = itrinorder(root1);
    vector<int> v2 = itrinorder(root2);
    int count = 0;
    if (v1.size() == v2.size())
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                count++;
                break;
            }
        }
    }
    else
    {
        return 0;
    }
    if (count)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
vector<vector<int>> zigzag(node *root)
{
    vector<vector<int>> ans;
    vector<vector<int>> temp = levelorder(root);
    for (int i = 0; i < temp.size(); i++)
    {
        if (i % 2 != 0)
        {

            reverse(temp[i].begin(), temp[i].end());
        }
    }
    ans = temp;
    return ans;
}
void leaf(vector<int> &ans, node *root)
{
    // from left to right for anti clockwise
    if (root == NULL)
    {
        return;
    }
    if (!(root->left) && !(root->right))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
    {
        leaf(ans, root->left);
    }
    if (root->right)
    {
        leaf(ans, root->right);
    }
}
vector<int> boundary(node *root)
{
    // anticlockwise
    vector<int> ans;
    node *temp = root;
    while (true)
    { // left boundary excluding leaf
        if (temp->left)
        {
            ans.push_back(temp->data);
            temp = temp->left;
        }
        else if (temp->right)
        {
            ans.push_back(temp->data);
            temp = temp->right;
        }
        else
        { // leaf nodes

            break;
        }
    }

    // leaf
    leaf(ans, root);

    if (root->right)
    {
        temp = root->right;
    }
    stack<int> s;

    while (true)
    { // right boundary excluding leaf
        if (temp->right)
        {
            s.push(temp->data);
            temp = temp->right;
        }
        else if (temp->left)
        {
            s.push(temp->data);
            temp = temp->left;
        }
        else
        { // leaf nodes

            break;
        }
    }
    while (!(s.empty()))
    {
        int val = s.top();
        s.pop();
        ans.push_back(val);
    }

    return ans;
}
void insertion(map<int, map<int, multiset<int>>> &m, node *root, int i, int j)
{
    if (root == NULL)
    {
        return;
    }
    m[i][j].insert(root->data);
    if (root->left)
    {
        insertion(m, root->left, i - 1, j + 1);
    }
    if (root->right)
    {
        insertion(m, root->right, i + 1, j + 1);
    }
}
vector<vector<int>> vertical(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    // queue<pair<node*,pair<int,int>>> q;//node, vertical, level
    map<int, map<int, multiset<int>>> m; // vertical, level, mutiple node
    int i = 0, j = 0;                    // i=vertical,j=level
    insertion(m, root, i, j);            // recursive
    for (auto x : m)
    { // loop for vertical
        vector<int> col;
        for (auto y : x.second)
        {
            col.insert(col.end(), y.second.begin(), y.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
vector<int> topview(node *root)
{
    vector<int> ans;
    vector<vector<int>> temp = vertical(root);
    for (int i = 0; i < temp.size(); i++)
    {
        int k = temp[i].front();
        ans.push_back(k);
    }
    return ans;
}
vector<int> bottomview(node *root)
{
    vector<int> ans;
    queue<pair<node *, int>> q;
    map<int, int> m; // first is for vertical line and 2nd is for node
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int line = q.front().second;
        m[line] = temp->data;
        q.pop();
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)
        { // we consider right during overlapping so we write right at the end becuase of queue fifo principle
            q.push({temp->right, line + 1});
        }
    }
    for (auto x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}
vector<int> leftview(node *root)
{
    vector<int> ans;
    vector<vector<int>> temp = levelorder(root);
    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[i].front());
    }
    return ans;
}
vector<int> rightview(node *root)
{
    vector<int> ans;
    vector<vector<int>> temp = levelorder(root); // iterative
    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[i].back());
    }
    return ans;
}
void rightviewrec(node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    // for right view we use reverse pre order ie  root right left
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    if (root->right)
    {
        rightviewrec(root->right, lvl + 1, ans);
    }
    if (root->left)
    {
        rightviewrec(root->left, lvl + 1, ans);
    }
}
void leftviewrec(node *root, int lvl, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    // for right view we use reverse pre order ie  root right left
    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    if (root->left)
    {
        leftviewrec(root->left, lvl + 1, ans);
    }
    if (root->right)
    {
        leftviewrec(root->right, lvl + 1, ans);
    }
}
bool symm(node *left, node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right; // may be there is one null between two so left=null but right!=null so return false if both are null(equal) return true
    }
    if (left->data != right->data)
    {
        return false;
    }
    return (symm(left->left, right->right) && symm(left->right, right->left)); // if both equals then only symmetric
}

bool symmetric(node *root)
{
    if (root == NULL)
    {
        return true; // leaf node is always symmetrical
    }
    return symm(root->left, root->right);
}
bool solve(node *root, vector<int> &s, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data != key)
    {
        s.push_back(root->data);
    }
    else
    {
        s.push_back(root->data);
        return true;
    }
    if (solve(root->left, s, key) || solve(root->right, s, key))
    {
        return true; // that means we have done with searching process and we want to go back to parent function
    }
    s.pop_back();
    return false;
}
vector<int> roottonode(node *root, int key)
{
    vector<int> s;
    if (root == NULL)
    {
        return s;
    }
    solve(root, s, key);
    // for(int i=0;i<s.size();i++){
    //     cout<<s[i]<<" ";
    // }
    return s;
}
int lowcommancestor(node *root, int a, int b)
{
    vector<int> v1 = roottonode(root, a);
    vector<int> v2 = roottonode(root, b);
    int c;
    for (int i = 0; i < min(v1.size(), v2.size()); i++)
    {
        if (v1[i] == v2[i])
        {
            c = v1[i];
        }
    }
    return c;
}
int maxwidth(node *root)
{

    vector<vector<int>> v = levelorder(root); // s.c o(n)
    int maxi = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].size() > 1)
        { // if there is minimum 2 nodes
            if (pow(2, i) > maxi)
            {
                maxi = pow(2, i);
            }
        }
    }
    return maxi;
}
void childrensum(node *&root)
{
    if (!(root->left) && !(root->right))
    {
        return;
    }

    int l = 0, r = 0;
    if (root->left)
    {
        l = root->left->data;
    }
    if (root->right)
    {
        r = root->right->data;
    }

    if (root->data > (l + r))
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }
    else
    {
        root->data = l + r;
    }
    childrensum(root->left);
    childrensum(root->right);
    l = 0;
    r = 0;
    if (root->left)
    {
        l = root->left->data;
    }
    if (root->right)
    {
        r = root->right->data;
    }
    root->data = l + r;
}
void distancerev(node *target, map<node *, bool> &visited, map<node *, node *> &m, int dist, int k, vector<int> &ans)
{
    if (dist == k)
    {
        ans.push_back(target->data);
        return;
    }
    visited[target] = 1;
    if (target->left && visited[target->left] != 1)
    {
        distancerev(target->left, visited, m, dist + 1, k, ans);
    }
    if (target->right && visited[target->right] != 1)
    {
        distancerev(target->right, visited, m, dist + 1, k, ans);
    }
    if (m[target] && visited[m[target]] != 1)
    {
        distancerev(m[target], visited, m, dist + 1, k, ans);
    }
}
vector<int> distancek(node *root, int val, int k)
{
    node *target;

    vector<int> ans;
    queue<node *> q;
    map<node *, node *> m; // root, parent
    map<node *, bool> visited;
    q.push(root);
    while (!(q.empty()))
    {
        node *temp = q.front();
        if (temp->data == val)
        {
            target = temp;
        }
        visited[temp] = 0;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            m[temp->left] = temp; // temp ka left ke parent temp hai
        }
        if (temp->right)
        {
            q.push(temp->right);
            m[temp->right] = temp; // temp ka right ke parent temp hai
        }
    }
    distancerev(target, visited, m, 0, k, ans);
    return ans;
}
bool checkforleaf(node *target)
{
    if (target->left || target->right)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int timetaken(node *target, map<node *, node *> &m, map<node *, bool> &visited, int time)
{

    visited[target] = 1;
    int t1 = 0, t2 = 0, t3 = 0;
    if (!(checkforleaf(target)))
    {
        if (target->left && visited[target->left] != 1)
        {
            t1 = timetaken(target->left, m, visited, time + 1); // max timetaken to reach leaf node via left sub tree
        }
        if (target->right && visited[target->right] != 1)
        {
            t2 = timetaken(target->right, m, visited, time + 1); // max timetaken to reach leaf node via  right sub tree
        }
    }
    else
    {
        if (m[target] && visited[m[target]] != 1)
        {
            t3 = timetaken(m[target], m, visited, time + 1); // max timetaken to reach to leaf node via parent node
        }
        else
        {

            return time;
        }
    }
    if (m[target] && visited[m[target]] != 1)
    {
        t3 = timetaken(m[target], m, visited, time + 1); // max timetaken to reach to leaf node via parent node
    }

    return max({t1, t2, t3}); // returns the max
}
int burntree(node *root, int val)
{
    node *target;
    queue<node *> q;
    map<node *, node *> m; // root,parent
    map<node *, bool> visited;
    q.push(root);
    while (!(q.empty()))
    {
        node *temp = q.front();
        if (temp->data == val)
        {
            target = temp;
        }
        visited[temp] = 0;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            m[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            m[temp->right] = temp;
        }
    }
    int t = timetaken(target, m, visited, 0);
    return t;
}
int lheight(node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}
int rheight(node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}
int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = lheight(root);
    int rh = rheight(root);

    if (lh == rh)
    {
        return (pow(2, lh) - 1);
    }
    else
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
node *buildtree(vector<int> &preorder, vector<int> &inorder)
{ //// brute force
    // Check if either of the input vectors is empty
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }

    // The first element of preorder is the root of the current subtree
    int rootValue = preorder[0];
    node *root = new node(rootValue);

    // Find the index of the root in the inorder traversal
    auto rootPos = find(inorder.begin(), inorder.end(), rootValue);
    int leftSize = rootPos - inorder.begin();

    // Recursively build the left and right subtrees
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
    vector<int> leftInorder(inorder.begin(), rootPos);
    // vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
    // vector<int> rightInorder(rootPos + 1, inorder.end());
    preorder.erase(preorder.begin(), preorder.begin() + 1 + leftSize);
    inorder.erase(inorder.begin(), rootPos + 1);

    root->left = buildtree(leftPreorder, leftInorder);
    root->right = buildtree(preorder, inorder);

    return root;
}
//// optimal     approach
node *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> &m)
{
    if (prestart > preend || instart > inend)
    {
        return nullptr;
    }
    node *root = new node(preorder[prestart]);
    int rootindex = m[root->data]; // rootindex in inorder
    int leftsize = rootindex - instart;
    root->left = build(preorder, prestart + 1, prestart + leftsize, inorder, instart, rootindex - 1, m);
    root->right = build(preorder, prestart + leftsize + 1, preend, inorder, rootindex + 1, inend, m);
    return root;
}
node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    node *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    return root;
}

/// brute force
node *buildTrewee(vector<int> &inorder, vector<int> &postorder)
{
    // Check if either of the input vectors is empty
    if (postorder.empty() || inorder.empty())
    {
        return nullptr;
    }

    // The first element of preorder is the root of the current subtree
    int rootValue = postorder[postorder.size() - 1];
    node *root = new node(rootValue);

    // Find the index of the root in the inorder traversal
    auto rootPos = find(inorder.begin(), inorder.end(), rootValue);
    int leftSize = rootPos - inorder.begin();

    // Recursively build the left and right subtrees
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftSize);
    vector<int> leftInorder(inorder.begin(), rootPos);
    // vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
    // vector<int> rightInorder(rootPos + 1, inorder.end());
    postorder.pop_back();
    postorder.erase(postorder.begin(), postorder.begin() + leftSize);

    inorder.erase(inorder.begin(), rootPos + 1);

    root->left = buildTrewee(leftInorder, leftPostorder);
    root->right = buildTrewee(inorder, postorder);

    return root;
}

////optimal approach
node *buildi(vector<int> &postorder, int poststart, int postend, vector<int> &inorder, int instart, int inend, map<int, int> &m)
{
    if (poststart > postend || instart > inend)
    {
        return nullptr;
    }
    node *root = new node(postorder[postend]);
    int rootindex = m[root->data]; // rootindex in inorder
    int leftsize = rootindex - instart;
    root->left = buildi(postorder, poststart, poststart + leftsize - 1, inorder, instart, rootindex - 1, m);
    root->right = buildi(postorder, poststart + leftsize, postend - 1, inorder, rootindex + 1, inend, m);
    return root;
}

node *buildTre(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    node *root = buildi(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    return root;
}

    // Encodes a tree to a single string.
    string serialize(node *root)
    {
        string s1 = "";
        if (root == NULL)
        {
            return s1;
        }
        queue<node *> q;
        q.push(root);
        string s2 = to_string(root->data);
        s1.append(s2 + ",");
        while (!(q.empty()))
        {
            node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                s2 = to_string(temp->left->data);
                s1.append(s2 + ",");
            }
            else
            {
                s2 = "#,";
                s1.append(s2);
            }
            if (temp->right)
            {
                q.push(temp->right);
                s2 = to_string(temp->right->data);
                s1.append(s2 + ",");
            }
            else
            {
                s2 = "#,";
                s1.append(s2);
            }
        }
        return s1;
    }

    // Decodes your encoded data to tree.
    node* deserialize(string val)
    {
        if (val.size() == 0)
        {
            return NULL;
        }
        stringstream s(val);
        string str;
        getline(s, str, ',');
        queue<node *> q;
        node *root = new node(stoi(str));
        q.push(root);
        while (!(q.empty()))
        {
            node *temp = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                temp->left = new node(stoi(str));
                q.push(temp->left);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                temp->right = new node(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }



vector<int> inorderTraversal(node* root) {//t.c =not an individual n times the while loop runs throughout the combine n terms total will run for n it's near about o(n);
vector<int> inorder;
node *cur = root;
while(cur != NULL) {
if(cur->left == NULL) {
inorder.push_back(cur->data);
cur = cur -> right;
}
else {
node *prev = cur->left;
while(prev->right && prev->right != cur){
prev = prev->right;
}
if(prev-> right== NULL) {
prev->right = cur;
cur = cur->left;
}else {
prev->right = NULL;
inorder. push_back(cur->data);
cur = cur->right;
}
}
}

return inorder;
}
vector<int> preorderTraversal(node* root) {
vector<int> preorder;
node *cur = root;
while(cur != NULL) {
if(cur->left == NULL) {
preorder. push_back(cur->data);
cur = cur -> right;
}
else {
node *prev = cur->left;
while(prev->right && prev->right != cur){
prev = prev->right;
}
if(prev-> right== NULL) {
prev->right = cur;
preorder. push_back(cur->data);
cur = cur->left;
}else {
prev->right = NULL;

cur = cur->right;
}
}
}

return preorder;
}
int main()
{
    node *root = new node(1); // creating a root node of the tree with value as '1'
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);
    // root->right->right = new node(6);
    // root->left->left->right = new node(7);

    // node* root2=new node(5);

    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // levelorder(root);

    // vector<int> v1=itrpreorder(root);
    // vector<int> v2=itrpostorder(root);
    // vector<int> v3=itrinorder(root);
    // for(int i=0;i<v1.size();i++){
    //     cout << v1[i] <<" ";
    // }
    // cout << endl;
    // for(int i=0;i<v2.size();i++){
    //     cout << v2[i] <<" ";
    // }
    // cout << endl;
    // for(int i=0;i<v3.size();i++){
    //     cout << v3[i] <<" ";
    // }

    // vector<vector<int>> v1=threeinone(root);
    // vector<vector<int>> v2=levelorder(root);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<v1[i].size();j++){
    //         cout<<v1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<v2.size();i++){
    //     for(int j=0;j<v2[i].size();j++){
    //         cout<<v2[i][j]<<" ";
    //     }
    // }

    // cout<<maxdepth(root)<<endl;
    // if(checkbalanced(root)){
    //     cout<<"Balanced"<<endl;
    // }else
    // {
    // cout<<"Not Balanced";
    // };
    // cout<<diameter(root);

    // if(identical(root,root2)){
    //     cout<<"Identical Tree";

    // }else{
    //     cout<<"not identical";
    // }
    // vector<vector<int>> v3=zigzag(root);
    // for(int i=0;i<v3.size();i++){
    //     for(int j=0;j<v3[i].size();j++){
    //         cout<<v3[i][j]<<" ";
    //     }
    // }

    // vector<int> b=boundary(root);
    // for(int i=0;i<b.size();i++){
    //     cout<<b[i]<<" ";

    // }
    // vector<vector<int>> v4=vertical(root);
    //     for(int i=0;i<v4.size();i++){
    //         for(int j=0;j<v4[i].size();j++){
    //             cout<<v4[i][j]<<" ";
    //         }
    //     }
    // vector<int> t=topview(root);
    // for(int i=0;i<t.size();i++){
    //     cout<<t[i]<<" ";

    // }
    // vector<int> bot=bottomview(root);
    // for(int i=0;i<bot.size();i++){
    //     cout<<bot[i]<<" ";

    // }
    // vector<int> lv=leftview(root);
    // for(int i=0;i<lv.size();i++){
    //     cout<<lv[i]<<" ";

    // }
    // cout<<endl;
    // vector<int> rv=rightview(root);
    // for(int i=0;i<rv.size();i++){
    //     cout<<rv[i]<<" ";

    // }
    // vector<int> ans;
    // // rightviewrec(root,0,ans);
    // leftviewrec(root,0,ans);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";

    // }
    // if(symmetric(root)){
    //     cout<<"symmetric"<<endl;
    // }else{
    //     cout<<"not symmetric"<<endl;

    // }
    //
    // cout<<lowcommancestor(root,2,8 );
    // cout<<maxwidth(root);
    // childrensum(root);
    // preorder(root);
    // vector<int> v=distancek(root,5,3);
    // if(v.size()==0){
    //     cout<<"no node available "<<endl;
    // }else{
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";

    // }
    // }
    // cout << burntree(root, 6);
    // string s = serialize(root);
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << s[i];
    // }

    


    return 0;
}