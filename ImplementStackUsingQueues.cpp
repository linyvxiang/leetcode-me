class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue_.push(x);
        top_ = x;
    }
    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp_queue;
        int new_top;
        while (queue_.size() > 1) {
            tmp_queue.push(queue_.front());
            new_top = queue_.front();
            queue_.pop();
        }
        top_ = new_top;
        swap(queue_, tmp_queue);
    }
    // Get the top element.
    int top() {
        return top_;
    }
    // Return whether the stack is empty.
    bool empty() {
        return queue_.empty();
    }
private:
    queue<int> queue_;
    int top_;
};
