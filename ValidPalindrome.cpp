class Solution {
	public:
		bool isPalindrome(string s) {
			if(s.empty())
				return true;

			int start = 0, end = s.size() - 1;
			while(start <= end) {
				int is_alp_s = check(s, start);
				int is_alp_e = check(s, end);
				if(is_alp_s && is_alp_e) {
					char c_s, c_e;
					c_s = get_ch(s, start);
					c_e = get_ch(s, end);
					if(c_s != c_e)
						return false;
					start++;
					end--;
				} else if(!is_alp_s && !is_alp_e) {
					start++;
					end--;
				} else if(is_alp_s && !is_alp_e) {
					end--;
				} else {
					start++;
				}
			}
			return true;
		}
	private:
		char get_ch(const string &s, int pos)
		{
			if('A' <= s[pos] && s[pos] <= 'Z')
				return s[pos] - 'A' + 'a';
			else
				return s[pos];
		}

		bool check(const string &s, int pos)
		{
			return ('A' <= s[pos] && s[pos] <= 'Z') ||
					('a' <= s[pos] && s[pos] <= 'z') ||
					('0' <= s[pos] && s[pos] <= '9');
		}
};
