class MyStack {
    // implement a queue
    queue<int> queue1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size = queue1.size();
        queue1.push(x);
        for (int i = 0; i < size; i++){
            queue1.push(queue1.front()); // so it copy it at the back of queue for the front one
            queue1.pop(); // and removes that first element
        }
    }
    
    int pop() {
        int frontone = queue1.front();
        queue1.pop(); // this pops it but can't use for return apparently
        return frontone;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        if(queue1.empty()){
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
