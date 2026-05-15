/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    int ans;
  public:
    int findMaxSum(Node *root) {
        // code here
        ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
    
    int helper(Node* root, int& ans) {
        if(root == NULL) return 0;
        int leftAns = max(0, helper(root->left, ans));
        int rightAns = max(0, helper(root->right, ans));
        ans = max(ans, root->data + leftAns + rightAns);
        return max(leftAns, rightAns) + root->data;
    }
};