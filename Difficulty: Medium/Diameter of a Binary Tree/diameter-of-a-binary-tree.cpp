/*
Definition for Node
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
    int diameter(Node* root) {
        // code here
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    int helper(Node* root, int& ans) {
        if(root == NULL) return 0;
        int leftHeight = helper(root->left, ans);
        int rightHeight = helper(root->right, ans);
        int ht = max(leftHeight, rightHeight);
        int dia = leftHeight + rightHeight;
        ans = max(ans, dia);
        return 1 + ht;
    }
};