class Solution {
	public:
		int findMin(vector<int> &num) {
			return do_find_min(num, 0, num.size() - 1);
		}
	private:
		int do_find_min(const vector<int> &num, int start, int end)
		{
			if(start == end)
				return num[start];
			if(start == end - 1)
				return num[start] < num[end] ? num[start] : num[end];
			int mid = (start + end) >> 1;

			if(num[mid - 1] > num[mid] && num[mid] < num[mid + 1])
				return num[mid];

			if(num[mid - 1] < num[mid] && num[mid] > num[mid + 1])
				return num[mid + 1];
			if(num[mid - 1] < num[mid] && num[mid] < num[mid + 1]) 
				return min(do_find_min(num, start, mid - 1),
				            do_find_min(num, mid + 1, end));

		}
};
