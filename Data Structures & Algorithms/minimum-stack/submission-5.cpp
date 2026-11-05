class MinStack {
    stack<int> vals_, mins_;

   public:
    MinStack() {}

    void push(int val) {
        vals_.push(val);
        if (mins_.empty() || val <= mins_.top()) {
            mins_.push(val);
        }
    }

    void pop() {
        if (!vals_.empty() && !mins_.empty() && vals_.top() == mins_.top()) {
            mins_.pop();
        }
        vals_.pop();
    }

    int top() { return vals_.top(); }

    int getMin() { return mins_.empty() ? 0 : mins_.top(); }
};
