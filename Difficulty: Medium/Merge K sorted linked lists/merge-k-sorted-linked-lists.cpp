/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        int k = arr.size();
        for(int i=0; i<k; i++) {
            if(arr[i] != NULL) {
                minHeap.push(arr[i]);
            }
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        while(!minHeap.empty()) {
            Node* top = minHeap.top();
            minHeap.pop();
            tail->next = top;
            top = top->next;
            tail = tail->next;
            if(top != NULL) {
                minHeap.push(top);
            }
        }
        return dummy->next;
    }
};