#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution {
	public:
		int evalRPN(vector<string> &tokens) {
			if(tokens.empty())
				return 0;
			stack<int> tmp_res;
			stack<char> op;
			int cur_pos = 0;
			for(cur_pos = 0; cur_pos < tokens.size(); cur_pos++) {
				if(tokens[cur_pos].size() == 1 && !(tokens[cur_pos][0]
							>= '0' && tokens[cur_pos][0] <= '9')) {
					int num2 = tmp_res.top();
					tmp_res.pop();
					int num1 = tmp_res.top();
					tmp_res.pop();
					if(tokens[cur_pos][0] == '+') {
						tmp_res.push(num1 + num2);
					} else if(tokens[cur_pos][0] == '-') {
						tmp_res.push(num1 - num2);
					} else if(tokens[cur_pos][0] == '*') {
						tmp_res.push(num1 * num2);
					} else if(tokens[cur_pos][0] == '/') {
						tmp_res.push(num1 / num2);
					}
				} else {
					int op_num = atoi(tokens[cur_pos].c_str());
					tmp_res.push(op_num);
				}
			}

			int ret = tmp_res.top();
			return ret;

		}
};
