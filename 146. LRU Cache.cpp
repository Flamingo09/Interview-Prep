//https://www.youtube.com/watch?v=FN8U19xxGog&t=1700s
class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, int>> valueMap;
    queue<int> accessed;
    void add_to_occurance(int key) {
        accessed.push(key);
        valueMap[key].second++;
    }
public:
    LRUCache(int given_capacity) {
        capacity=given_capacity;
    }
    
    int get(int key) {
        auto it=valueMap.find(key);
        if(it == valueMap.end()) {
            return -1;
        }
        add_to_occurance(it->first);
        return it->second.first;
    }
    
    void put(int key, int value) {
        if((int) valueMap.size() < capacity) {
            valueMap[key].first=value;
            add_to_occurance(key);
            return;
        }
        auto it= valueMap.find(key);
        if(it != valueMap.end()) {
            it->second.first=value;
            add_to_occurance(key);
            return;
        }
        
        while(1) {
            int deleteCandidate = accessed.front();
            accessed.pop();
            if(--valueMap[deleteCandidate].second == 0 ) {
                valueMap.erase(deleteCandidate);
                break;
            }
        }
        
        valueMap[key].first=value;
        add_to_occurance(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
