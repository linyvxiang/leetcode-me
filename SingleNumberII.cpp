#include <stdlib.h>
#include <string.h>

class Solution {
	public:
		int singleNumber(int A[], int n) {
			int bit_counter[sizeof(int) * 8];
			memset(bit_counter, 0, sizeof(bit_counter));
			int i;
			for(i = 0; i < n; i++)
				parse_number(bit_counter, A[i]);
			int ret = trans_bit_to_number(bit_counter);
			return ret;
		} 
	private:
		void parse_number(int *bit_counter, int number)
		{
			int bit_number = sizeof(int) * 8, i;
			for(i = 0; i < bit_number; i++) {
				bit_counter[i] += 0x1 & number;
				bit_counter[i] %= 3;
				number >>= 1;
			}
		}
		int trans_bit_to_number(int *bit_counter)
		{
			int bit_number = sizeof(int) * 8;
			int ret = 0, i;
			for(i = bit_number - 1; i >= 0; i--) {
				ret = (ret << 1) | bit_counter[i];
			}
			return ret;
		}
};
