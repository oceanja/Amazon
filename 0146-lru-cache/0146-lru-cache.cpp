*************************************** BRUTE****************************************

Step 1 – Restating the task
“The problem is to design an LRU Cache with get and put. The cache has a fixed capacity, and when it’s full, 
we must evict the least recently used item. Recency must always be updated on every access.”

Step 2 – My brute force attempt
“My first approach was very straightforward: I stored the cache as a vector of (key, value) pairs. 
The idea is to keep the most recently used element at the back and the least recently used at the front.

For get(key), I do a linear scan to find the key. If it exists, I store the value, erase the pair from its current position, 
and push it to the back. If it doesn’t exist, return -1.

For put(key, value), I again linearly scan to see if the key exists. If yes, I erase it and reinsert at the back with the new value.
If not, and the cache is full, I erase the first element (least recently used) and push the new one at the back. 
Otherwise, I just push it to the back.”

Step 3 – Why it’s correct but inefficient
“This logic preserves the LRU property — the queue-like ordering is always correct. 
But every operation (get and put) does a linear scan O(N), plus sometimes an erase from the middle O(N).
Over M operations, this can lead to O(M × N) ≈ O(N²) in the worst case.

So if the cache is large and we do a lot of operations, this brute force version becomes very slow.”

Step 4 – Complexity

get: O(N) search + O(N) erase → O(N).

put: O(N) search + O(N) erase/insert → O(N).

Over many operations, total runtime is O(N²) in worst case.

Space: O(N) for storing the cache.


class LRUCache {
public:
    
    vector<pair<int, int>> cache;
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                int val = cache[i].second;
                
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                
                return val;
            }
            
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        
        if(cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
        
    }
};



**********************************************************OPTIMAL********************************************************************************
Alright, so this is the LRU Cache problem. I need two operations, get and put, and both should be O(1). 
The tricky part is also maintaining recency — every time I use a key, it becomes most recent, 
and when the cache is full, I evict the least recent one.

My first idea was a vector: store (key, value) pairs, and whenever a key is used, move it to the back;
when I need to evict, remove from the front. That works in terms of correctness,
but the problem is performance — searching for a key is O(N), and erasing from the middle is also O(N).
So each operation could take O(N), and over many operations, it basically becomes O(N²). That’s too slow for large test cases.

Then I thought: what do I actually need? I need fast lookups by key, and I need to maintain ordering of usage. 
That immediately suggests combining two data structures:

A hashmap to give me O(1) access to the node for any key.

A doubly linked list to maintain usage order: I can move a node to the front in O(1) and pop the least recent from the back in O(1).

So the logic becomes:

For get(key): if it’s in the map, I grab the node, move it to the front, and return the value. If it’s not in the map, return -1.

For put(key, value): if the key already exists, I update the value and move it to the front.
If it’s a new key, I insert it at the front. And if the cache is already full, 
I remove the node from the back of the list (the least recently used), and erase it from the map.

This way, I always maintain the correct order, and both operations are constant time.

Complexity:

Time: get is O(1), put is O(1), since both hashmap operations and list operations are constant time.

Space: O(N), because I’m storing up to N keys in both the hashmap and the list.

So by combining the hashmap and doubly linked list, I reduced the brute force O(N) per operation down to O(1), which is the optimal design.”



class LRUCache {
public:
list<int> dll;
unordered_map<int,pair<list<int>::iterator,int>> mpp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentlyUsed(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);

        mpp[key].first=dll.begin();
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }

        makeRecentlyUsed(key);

        return mpp[key].second;

    }
    
    void put(int key, int value) {

        if(mpp.find(key)!=mpp.end()){
            mpp[key].second=value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
            n--;
        }

        if(n<0){
            int key_to_delete=dll.back();
            mpp.erase(key_to_delete);
            dll.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
