class Solution {
    public:
        int findMin(vector<int>& nums) {
            return find_min(nums, 0, nums.size() - 1);
        }
    private:
        int find_min(const vector<int>& num, int left, int right) {
            if (left == right || right == left + 1) {
                return min(num[left], num[right]);
            }
            int mid = (left + right) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid]+ 1) {
                return num[mid + 1];
            } else if (num[mid] < num[mid - 1] && num[mid] < num[mid + 1]) {
                return num[mid];
            } else {
                return min(find_min(num, left, mid - 1), find_min(num, mid + 1, right));
            }
        }
};
