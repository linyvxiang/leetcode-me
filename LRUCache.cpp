struct Node {
	int key_, val_;
	Node *next_;
	Node *prev_;
};

class LRUCache{
	public:

	
		LRUCache(int capacity) {
			size_ = capacity;
			cur_size_ = 0;
			head = NULL;
			tail = NULL;

		}

		int get(int key) {
			struct Node *ret = get_value(key);
			return ret ? ret->val_ : -1;
		}

		void set(int key, int value) {
			put_value(key, value);
		}
	private:
		int size_;
		int cur_size_;
		Node *head, *tail;
		struct Node* get_value(int key);
		void put_value(int key, int value);
};

struct Node* LRUCache::get_value(int key)
{
	if(cur_size_ == 0)
		return NULL;	
	struct Node *ret = NULL;
	struct Node HEAD, *cur, *prev;
	HEAD.next_ = head;
	cur = HEAD.next_;
	prev = &HEAD;
	while(cur) {
		if(cur->key_== key) {
			// move this node to head of the list
			ret = cur;
			//only one node
			if(head == tail)
				break;

			prev->next_ = cur->next_;
			if(cur->next_)
				cur->next_->prev_ = prev;
			else
				tail = prev;
			//insert to head
			cur->next_ = HEAD.next_;
			HEAD.next_->prev_ = cur;	
			head = cur;
			break;
		}
		cur = cur->next_;
		prev = prev->next_;
	}

	return ret;
}

void LRUCache::put_value(int key, int value)
{
	if(cur_size_ == 0) {
		head = (struct Node *)malloc(sizeof(struct Node));
		head->next_ = NULL;
		head->prev_ = NULL;
		tail = head;
		head->key_ = key;
		head->val_ = value;
		cur_size_++;
	} else {
		struct Node *n = get_value(key);
		if(n) {
			//update
			n->val_ = value;
			if(head != tail) {
				if(tail != n && head != n) {
					n->next_->prev_ = n->prev_;
					n->prev_->next_ = n->next_;
					n->next_ = head;
					head->prev_ = n;
					head = n;
				} else if(tail == n) {
					tail = n->prev_;
					tail->next_ = NULL;
					n->next_ = head;
					head->prev_ = n;
					head = n;
				}
			}
		} else if(cur_size_ == size_) {
			//full now, remove the tail

			//only one node
			if(head == tail) {
				head->key_ = key;
				head->val_ = value;
				return ;
			}
			struct Node *tmp = tail;
			tail = tail->prev_;
			tail->next_ = NULL;
			tmp->key_ = key;
			tmp->val_ = value;
			tmp->next_ = head;
			tmp->prev_ = NULL;
			head->prev_ = tmp;
			head = tmp;
		} else {
			cur_size_++;
			struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
			tmp->key_ = key;
			tmp->val_ = value;
			tmp->next_ = head;
			tmp->prev_ = NULL;
			head->prev_ = tmp;
			head = tmp;
		}
	}
}
