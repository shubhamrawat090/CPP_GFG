/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root == NULL) return root;
        if(n1 == root || n2 == root) return root;
        
        Node* rightAns = LCA(root->right, n1, n2);
        Node* leftAns = LCA(root->left, n1, n2);
        
        if(leftAns && rightAns) return root;
        if(leftAns) return leftAns;
        return rightAns;
    }
};