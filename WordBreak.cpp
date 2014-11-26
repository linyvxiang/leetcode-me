class Solution {
	public:
		bool wordBreak(string s, unordered_set<string> &dict) {
			bool ret[s.size() + 1];
			memset(ret, false, sizeof(ret));
			ret[0] = true;
			int i, j, len = s.size();
			for(i = 1; i <= len; i++) {
				for(j = i - 1; j >= 0; j--) {
					if(ret[j] && dict.find(string(s, j, i - j)) != dict.end()) {
						ret[i] = true;
						break;
					}
				}
			}
			return ret[len];	
		}
};

