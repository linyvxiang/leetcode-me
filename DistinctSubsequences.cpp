class Solution {
	public:
		int numDistinct(string S, string T) {
			int ret[T.size()][S.size()];
			memset(ret, 0, sizeof(int) * (T.size()) * (S.size()));
			int i, j;
			for(i = 0; i < T.size(); i++) {
				for(j = 0; j < S.size(); j++) {
					if(T[i] == S[j]) {
						if(i != 0 && j != 0)
							ret[i][j] = ret[i - 1][j - 1] + ret[i][j - 1];
						else if(i == 0 && j == 0)
							ret[i][j] = 1;
						else if(i == 0)
							ret[i][j] = ret[i][j - 1] + 1;
					} else {
						if(j != 0)
							ret[i][j] = ret[i][j - 1];
						else
							ret[i][j] = 0;
					}
				}
			}
			return ret[T.size() - 1][S.size() - 1];
		}
};
