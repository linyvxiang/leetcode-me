#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		vector<vector<string> > partition(string s) {
			vector<vector<string> > ret;
			vector<string> tmp_ret;
			if(s.empty())
				return ret;

			string tmp = "";
			do_partition(s, tmp, 0, ret, tmp_ret);
			return ret;
		}
	private:
		void do_partition(string &s, string &cur_str, int cur_pos, 
							vector<vector<string> > &ret,
							vector<string> &tmp_ret)
		{
			if(check_str(cur_str) && cur_pos == s.size()) {
				if(!tmp_ret.empty()) 
					ret.push_back(tmp_ret);
				return ;
			}
			int i;
			for(i = cur_pos; i <  s.size(); i++) {
				string str = cur_str + string(s, cur_pos, i - cur_pos + 1);
				if(check_str(str)) {
					tmp_ret.push_back(str);
					string tmp = "";
					do_partition(s, tmp, i + 1, ret, tmp_ret);
					tmp_ret.pop_back();
				} 
			}

		}
		bool check_str(string &s)
		{
			int end = s.size() - 1, start = 0;
			while(start <= end) {
				if(s[start++] != s[end--])
					return false;
			}
			return true;
		}
};

int main()
{
	string str = "amanaplanacanalpanama";
	vector<vector<string> > ret;
	Solution s;
	ret = s.partition(str);
	/*
	int i, j;
	for(i = 0; i < ret.size(); i++) {
		for(j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	*/
	cout << ret.size() << endl;
	
	return 0;
}
