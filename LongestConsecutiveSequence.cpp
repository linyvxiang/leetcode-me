class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			if(num.empty())
				return 0;
			vector<int> new_numbers;
			sort(num.begin(), num.end());
			new_numbers.push_back(num[0]);
			int i;
			for(i = 1; i < num.size(); i++) {
				if(num[i] != new_numbers[new_numbers.size() - 1])
					new_numbers.push_back(num[i]);
			}

			int max_len = 1, cur_len = 1;
			for(i = 1; i < new_numbers.size(); i++) {
				if(new_numbers[i] == new_numbers[i - 1] + 1)
					cur_len++;
				else {
					max_len = max(max_len, cur_len);
					cur_len = 1;
				}
			}
			return max(max_len, cur_len);
	}
};

