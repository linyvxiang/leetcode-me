class LRUCache{
	public:
		typedef std::list<std::pair<int, int> >::iterator Pair_it;
		LRUCache(int capacity) {
			size_ = capacity;
			cur_size_ = 0;
		}

		int get(int key) {
			std::map<int, Pair_it>::iterator map_it = lru_map_.find(key);
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
			std::map<int, Pair_it>::iterator map_it = lru_map_.find(key);
			if(map_it != lru_map_.end()) {
				//update
				Pair_it pair_it = map_it->second;
				pair_it->second = value;
				data_.splice(data_.begin(), data_, pair_it);
				lru_map_.erase(key);
				lru_map_.insert(std::make_pair(key, data_.begin()));
			} else if(cur_size_ == size_) {
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
		std::map<int, Pair_it> lru_map_;
		int size_;
		int cur_size_;
};
