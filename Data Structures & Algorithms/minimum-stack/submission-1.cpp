class MinStack {
private:
    struct node{
        int val;
        node* next;
    };
    node* n;
    map<int, int> vals;
public:
    MinStack() {
        n = nullptr;
    }
    
    void push(int val) {
        node* prev = new node{val, n};
        vals[val]++;
        n = prev;
    }
    
    void pop() {
        node* del = n;
        n = n->next;
        vals[del->val]--;
        if(vals[del->val] == 0){
            vals.erase(del->val);
        }
        delete del;
    }
    
    int top() {
        return n->val;
    }
    
    int getMin() {
        return vals.begin()->first;
    }
};
