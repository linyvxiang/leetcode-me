class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> res;
		vector<int> tmp;
		if(num.empty() || num.size() < 3)
			return res;
		int a, b, c;
		int i = 0, size = num.size();
		sort(num.begin(), num.end());
		while(i < size - 2){
			a = num[i];
			int low = i + 1, high = size - 1;
			while(low < high) {
				if(num[low] + num[high] + a == 0) {
					tmp.push_back(a);
					tmp.push_back(num[low]);
					tmp.push_back(num[high]);
					res.push_back(tmp);
					tmp.clear();
					low++;
					high--;
					while(low < high && num[low] == num[low - 1])
						low++;
					while(high > low && num[high] == num[high + 1])
						high--;
				} else if(num[low] + num[high] + a > 0) {
					high--;
				} else {
					low++;
				}
			}
			i++;
			while(i < size - 2 && num[i] == num[i - 1])
				i++;
		}
		return move(res);
	}
} ;
