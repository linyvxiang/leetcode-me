class MinStack {
	public:
		void push(int x) {
			data_.push(x);
			if(minimum_.empty()) {
				minimum_.push(std::make_pair(x, 1));
			} else if(x == minimum_.top().first) {
				minimum_.top().second++;
			} else if(x < minimum_.top().first) {
				minimum_.push(std::make_pair(x, 1));
			}

		}

		void pop() {
			if(!data_.empty()) {
				int top_value = data_.top();
				if(top_value != minimum_.top().first) {
					data_.pop();
				} else {
					data_.pop();
					minimum_.top().second--;
					if(minimum_.top().second == 0)
						minimum_.pop();
				}
			}
		}

		int top() {
			return data_.top();
		}

		int getMin() {
			return minimum_.top().first;
		}
	private:
		std::stack<int> data_;
		std::stack<std::pair<int, int> > minimum_;

};
