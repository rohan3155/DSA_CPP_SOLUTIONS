class MinStack {
public:
    stack<long long> s;
    long long minVal;

    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};
