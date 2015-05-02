class MinStack {
    public:
        void push(int x) {
            if (_num.empty() || x < _min_num.top().num) {
                _min_num.push(MinNum(x));
            } else if (x == _min_num.top().num) {
                _min_num.top().ref++;
            }
            _num.push(x);
        }

        void pop() {
            if (_min_num.top().num == _num.top()) {
                _min_num.top().ref--;
                if (_min_num.top().ref == 0) {
                    _min_num.pop();
                }
            }
            _num.pop();
        }

        int top() {
            return _num.top();
        }

        int getMin() {
            return _min_num.top().num;
        }
    private:
        struct MinNum {
            int num;
            int ref;
            MinNum(int num) : num(num), ref(1) {}
        };
        std::stack<MinNum> _min_num;
        std::stack<int> _num;
};
