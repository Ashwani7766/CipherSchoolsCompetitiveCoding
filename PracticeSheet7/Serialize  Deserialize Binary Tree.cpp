#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data) {
      val = data;
      left = NULL;
      right = NULL;
   }
};
void insert(TreeNode **root, int val) {
   queue<TreeNode *> q;
   q.push(*root);
   while (q.size()) {
      TreeNode *temp = q.front();
      q.pop();
      if (!temp->left) {
         if (val != NULL)
            temp->left = new TreeNode(val);
         else
            temp->left = new TreeNode(0);
         return;
      }
      else {
         q.push(temp->left);
      }
      if (!temp->right) {
         if (val != NULL)
            temp->right = new TreeNode(val);
         else
            temp->right = new TreeNode(0);
         return;
      }
      else {
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v) {
   TreeNode *root = new TreeNode(v[0]);
   for (int i = 1; i < v.size(); i++) {
      insert(&root, v[i]);
   }
   return root;
}
void inord(TreeNode *root) {
   if (root != NULL) {
      inord(root->left);
      cout << root->val << " ";
      inord(root->right);
   }
}
class Codec {
public:
   string serialize(TreeNode *root) {
      string ret = "";
      queue<TreeNode *> q;
      q.push(root);
      while (!q.empty()) {
         TreeNode *curr = q.front();
         q.pop();
         if (!curr) {
            ret += "N";
            ret += " ";
            continue;
         }
         ret += to_string(curr->val);
         ret += " ";
         q.push(curr->left);
         q.push(curr->right);
      }
      return ret;
   }
   TreeNode *deserialize(string data) {
      if (data[0] == 'N')
         return NULL;
      string temp = "";
      vector<string> v;
      for (int i = 0; i < data.size(); i++) {
         if (data[i] == ' ') {
            v.push_back(temp);
            temp = "";
            continue;
         }
         temp += data[i];
      }
      TreeNode *newRoot = new TreeNode(stoi(v[0]));
      queue<TreeNode *> q;
      q.push(newRoot);
      int i = 1;
      while (!q.empty() && i < v.size()) {
         TreeNode *parent = q.front();
         q.pop();
         if (v[i] != "N") {
            parent->left = new TreeNode(stoi(v[i]));
            q.push(parent->left);
         }
         i++;
         if (v[i] != "N") {
            parent->right = new TreeNode(stoi(v[i]));
            q.push(parent->right);
         }
         i++;
      }
      return newRoot;
   }
};
main() {
   Codec ob;
   vector<int> v = {1,2,3,4,5};
   TreeNode *root = make_tree(v);
   cout << "Given Tree: ";
   inord(root);
   cout << endl;
   string ser = ob.serialize(root);
   cout << "Serialize: " << ser << endl;
   TreeNode *deser = ob.deserialize(ser);
   cout << "Deserialized Tree: ";
   inord(root);
}
