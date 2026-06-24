/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> oldnewPair;
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* newNext = nullptr;
        Node* newRand = nullptr;
        Node* newhead = new Node(head->val);
        oldnewPair.insert(pair<Node*, Node*> (head, newhead));
        if(oldnewPair.find(head->next) != oldnewPair.end()){
            newNext = oldnewPair.find(head->next)->second;
        } else {
            newNext = copyRandomList(head->next);
            cout<<"leak1"<<endl;
            oldnewPair.insert(pair<Node*, Node*> (head->next, newNext));
        }
        if(oldnewPair.find(head->random) != oldnewPair.end()){
            newRand = oldnewPair.find(head->random)->second;
        } else {
            newRand = copyRandomList(head->random);
            cout<<"leak2"<<endl;
            oldnewPair.insert(pair<Node*, Node*> (head->random, newRand));
        }
        newhead->next = newNext;
        newhead->random = newRand;
        return newhead;
    }
};
