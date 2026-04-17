class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {

    }
};
class LRUCache {
public:
    unordered_map<int, Node*> cache;
    Node* right;
    Node* left;
    int cap;
    void remove(Node* node){
        Node* nxt= node->next;
        Node* pre = node->prev;
        pre->next = nxt;
        nxt->prev = pre;
        // delete(node);
    }
    void insert(Node* node){
        Node* pre = right->prev;
        pre->next = node;
        node->prev = pre;
        node->next = right;
        right->prev = node;
    }
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
        cache.clear();
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
            cache.erase(key);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if(cache.size()>cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
        }
    }
};
