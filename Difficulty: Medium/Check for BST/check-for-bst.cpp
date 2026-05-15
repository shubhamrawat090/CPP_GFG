/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isBST(Node* root) {
        // code here
        return helper(root, INT_MIN, INT_MAX);
    }
    
    bool helper(Node* root, int rangeStart, int rangeEnd) {
        if(root == NULL) return true;
        if(root->data <= rangeStart || root->data >= rangeEnd) return false; // out of range
        return helper(root->left, rangeStart, root->data) && helper(root->right, root->data, rangeEnd);
    }
};