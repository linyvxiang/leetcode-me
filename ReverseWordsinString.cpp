class Solution {
	public:
		void reverseWords(string &s) {
			if(s.empty())
				return ;
			int start_pos = 0, end_pos = 0;
			string res;
			while(end_pos < s.size()) {

				while(end_pos < s.size() && s[end_pos] == ' ')
					end_pos++;
				if(end_pos == s.size())
						break;
				start_pos = end_pos;

				while(end_pos < s.size() && s[end_pos] != ' ')
					end_pos++;

				if(!res.empty())
					res  += ' ';

				string tmp_str(s, start_pos, end_pos - start_pos);
				reverse(0, tmp_str.size() - 1, tmp_str);
				res += tmp_str;
				
			}
			if(!res.empty())
				reverse(0, res.size() - 1, res);
			s = res;

		}

	private:
		void reverse(int start_pos, int end_pos, string &s)
		{
			while(start_pos < end_pos)	
				std::swap(s[start_pos++], s[end_pos--]);

		}

};
