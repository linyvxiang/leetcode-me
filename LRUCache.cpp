class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        int value = -1;
        map<int, KV_LIST::iterator>::iterator key_it = _key_map.find(key);
        if (key_it != _key_map.end()) {
            value = (*(key_it->second)).second;
            _list.erase(key_it->second);
            KV_LIST::iterator new_it = _list.insert(_list.begin(), make_pair(key, value));
            _key_map[key] = new_it;
        }
        return value;
    }

    void set(int key, int value) {
        map<int, KV_LIST::iterator>::iterator key_it = _key_map.find(key);
        if (key_it != _key_map.end()) {//already exist
            _list.erase(key_it->second);
            KV_LIST::iterator new_it = _list.insert(_list.begin(), make_pair(key, value));
            _key_map[key] = new_it;
        } else {//new key -> value
            if (_list.size() == _capacity) {
                int last_key = (_list.rbegin())->first;
                _list.erase(_key_map[last_key]);
                _key_map.erase(last_key);
            }
            KV_LIST::iterator new_it = _list.insert(_list.begin(), make_pair(key, value));
            _key_map[key] = new_it;
        }
    }
private:
    int _capacity;
    typedef list<pair<int, int> > KV_LIST;
    KV_LIST _list;
    map<int, KV_LIST::iterator> _key_map;
};
