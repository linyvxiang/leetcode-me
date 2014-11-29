#include <unordered_set>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <iterator>
using namespace std;
class Solution {
public:
	int ladderLength(string start, string end,
		const unordered_set<string> &dict) {
		queue<string> Q;
		map<string, bool> used;
		unordered_set<string>::const_iterator it = dict.begin();
		while(it != dict.end()) {
			used[*it] = false;
			it++;
		}
		int cur_level = 1, cur_level_count = 1, next_level_count = 0;
		Q.push(start);
		used[start] = true;

		while(!Q.empty()) {
			string str = Q.front();
			Q.pop();
			cur_level_count--;

			int cur_pos = 0;
			for(; cur_pos < str.size(); cur_pos++) {
				char ch;
				string tmp = str;
				for(ch = 'a'; ch <= 'z'; ch++) {
					if(ch != str[cur_pos]) {
						tmp[cur_pos] = ch;
						if(tmp == end) {
							if(dict.find(start) != dict.end()) //start is in the dict
								/*because start is int the dict, so when find the end, the value
								 * of cur_level *already* indlue the start node, so only to plus
								 * one to include the end node
								 */
						 	   return cur_level + 1;
							else
								return cur_level + 2;
						}
						if(dict.find(tmp) != dict.end() && 
								used[tmp] == false) {
							used[tmp] = true;
							Q.push(tmp);
							next_level_count++;
						}
					}
				}
			}
			if(cur_level_count == 0) {
				cur_level_count = next_level_count;
				next_level_count = 0;
				cur_level++;
			}
		}
		return 0;
	}
};


int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dog");
	dict.insert("tot");
	dict.insert("hog");
	dict.insert("hop");
	dict.insert("pot");
	dict.insert("dot");
	/*
	string start = "a";
	string end = "c";
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	*/
	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;
	return 0;
}
