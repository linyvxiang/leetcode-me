class Solution {
public:
	vector<vector<int>> find_3_sum(vector<int> num, int start, int end, int target)
	{
		int i = start;
		vector<vector<int>> res;
		while(i < end - 2){
			int low = i + 1, high = end - 1;
			while(low < high) {
				int cur_sum = num[i] + num[low] + num[high];
				if(cur_sum == target) {
					vector<int> tmp;
					tmp.push_back(num[i]); 
					tmp.push_back(num[low]);
					tmp.push_back(num[high]);
					res.push_back(tmp);
					low++;
					while(low < high && num[low] == num[low - 1])
						low++;
					high--;
					while(high > low && num[high] == num[high + 1])
						high--;
				} else if(cur_sum > target) {
					high--;
				} else {
					low++;
				}
			}
			i++;
			while( i < end - 2 && num[i] == num[i - 1])
				i++;
		}
		return move(res);
	}
	
    vector<vector<int> > fourSum(vector<int> &num, int target) {
 		vector<vector<int>> res;
		int size = num.size();
		if(num.empty() || size < 4)
			return res;
		int i = 0;
		sort(num.begin(), num.end());
		while(i < size - 3) {
			vector<vector<int>> tmp = find_3_sum(num, i + 1, size, target - num[i]);
			if(!tmp.empty()) {
				int j;
				for(j = 0; j < tmp.size(); j++) {
					tmp[j].insert(tmp[j].begin(), num[i]);
					res.push_back(tmp[j]);
				}
			}
			i++;
			while(i < size - 3 && num[i] == num[i - 1])
			    i++;
		}
		return move(res);
    }
};
