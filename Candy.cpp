#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;
class Solution {
	public:
		int candy(vector<int> &ratings) {
			if(ratings.empty())
				return 0;
			if(ratings.size() == 1)
				return 1;
			vector<int> num(ratings.size(), 1);
			num[0] = 1;
			num[ratings.size() - 1] = 1;
			int i;
			for(i = 1; i < ratings.size(); i++) {
				if(ratings[i] > ratings[i - 1])
					num[i] = num[i - 1] + 1;
				else
					num[i] = 1;
			}
			int total_num = num[ratings.size() - 1];
			for(i = ratings.size() - 2; i >= 0; i--) {
				if(ratings[i] > ratings[i + 1])
					num[i] = max(num[i + 1] + 1, num[i]);
				else
					num[i] = max(1, num[i]);
				total_num += num[i];
			}
			return total_num;
		}
};





int main()
{
	vector<int> ratings;
	//ratings.push_back(1);
	//ratings.push_back(3);
	//ratings.push_back(4);
	//ratings.push_back(2);
	ratings.resize(8893);
	int i;
	for (i = 0; i < 8893; i++)
		ratings[i] = i + 1;
	Solution s;
	std::cout << s.candy(ratings) << std::endl;
	return 0;
}
