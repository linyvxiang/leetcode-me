class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
	    int i, size = num.size();
	    int min_gap = 0x7fffffff;
	    sort(num.begin(), num.end());
	    int result;
	    for(i = 0; i < size - 2; i++) {
	        int low = i + 1, high = size - 1;
	        while(low < high) {
	            int sum = num[i] + num[low] + num[high];
	            if(abs(sum - target) < min_gap) {
	                min_gap = abs(sum - target);
	                result = sum;
	            }
	        if(sum > target)
	           high--;
	        else
	            low++;
	        }
	    }
	    return result;
    }
};
