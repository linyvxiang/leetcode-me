#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <ext/hash_map>
class LRUCache{
	public:
		typedef std::list<std::pair<int, int> >::iterator Pair_it;
		LRUCache(int capacity) {
			size_ = capacity;
			cur_size_ = 0;
		}

		int get(int key) {
			__gnu_cxx::hash_map<int, Pair_it>::iterator map_it = lru_map_.find(key);
			int ret = -1;
			if(map_it != lru_map_.end()) {
				//found
				Pair_it pair_it = map_it->second;
				ret = pair_it->second;
				data_.splice(data_.begin(), data_, pair_it);
				lru_map_.erase(map_it);
				lru_map_.insert(std::make_pair(key, data_.begin()));
			}

			return ret;
		}

		void set(int key, int value) {
			if(cur_size_ == size_) {
				//already full
				Pair_it pair_it = data_.end();
				pair_it--;
				int value_to_remove = pair_it->first;
				data_.remove(*pair_it);
				lru_map_.erase(value_to_remove);
				//next to insert the new value;
				data_.push_front(std::make_pair(key, value));
				lru_map_.insert(std::make_pair(key, data_.begin()));
			} else {
				// not full
				data_.push_front(std::make_pair(key, value));
				lru_map_.insert(std::make_pair(key, data_.begin()));
				cur_size_++;
			}

		}
	private:
		std::list<std::pair<int, int> > data_;
		__gnu_cxx::hash_map<int, Pair_it> lru_map_;
		int size_;
		int cur_size_;
};

int main()
{
	__gnu_cxx::hash_map<int, int> hash_map;
	hash_map[10] = 2;
	LRUCache cache(2048);
	cache.set(1, 2);	
	std::cout << cache.get(1) << std::endl;
	return 0;
}
