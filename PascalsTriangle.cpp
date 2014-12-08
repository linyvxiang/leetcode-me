class Solution {
	public:
		vector< vector<int> > generate(int numRows) {
			vector<vector<int> > ret;
			if(numRows == 0)
				return ret;
			vector<int> cur_row;
			cur_row.push_back(1);
			ret.push_back(cur_row);
			int i, j;
			for(i = 1; i < numRows; i++) {
				cur_row.clear();
				for(j = 0; j < i + 1; j++) {
					if(j - 1 < 0)
						cur_row.push_back(ret[i - 1][j]);
					else if(j == i) {
						if(i == 1)
							cur_row.push_back(1);
						else
							cur_row.push_back(ret[i - 1][j - 1]);
					}
					else
						cur_row.push_back(ret[i - 1][j - 1] +
											ret[i - 1][j]);
				}
				ret.push_back(cur_row);
			}
			return ret;
		}
};
