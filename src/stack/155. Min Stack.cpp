class MinStack {
private:
    stack<int> data;
    stack<int> min;
public:
    void push(int x) {
        if (min.empty() || x <= getMin()) {
            min.push(x);
        }
        data.push(x);
    }

    void pop() {
        if (top() == getMin()) {
            min.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};