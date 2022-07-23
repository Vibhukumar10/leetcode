/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Node *newNode = new Node(node->val);
        if(node==NULL) return node;
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        mp.insert({node,new Node(node->val)});
        
        q.push(node);
        while(!q.empty()) {
            // int sz=q.size();
            // for(int i=0;i<sz;i++) {
                Node *temp=q.front();q.pop();
                for(Node* neighbor:temp->neighbors) {
                    if(mp.find(neighbor)==mp.end()) {
                        mp.insert({neighbor,new Node(neighbor->val)});
                        q.push(neighbor);
                    }
                    mp[temp]->neighbors.push_back(mp[neighbor]);
                }
            // }
        }
        
        return mp[node];
    }
};