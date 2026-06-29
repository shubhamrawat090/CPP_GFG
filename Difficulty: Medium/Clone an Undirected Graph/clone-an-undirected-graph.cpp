// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        // code here
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        q.push(node);
        oldToNew[node] = new Node(node->val);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(Node* nbr: curr->neighbors) {
                if(oldToNew.find(nbr) == oldToNew.end()) {
                    oldToNew[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[nbr]);
            }
        }
        return oldToNew[node];
    }
};
