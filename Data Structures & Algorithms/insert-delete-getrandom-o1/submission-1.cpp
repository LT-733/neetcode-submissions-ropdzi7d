#include <random>

class RandomizedSet {
public:
    unordered_map<int, int> lookup;
    vector<int> actuallist;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(lookup.find(val) != lookup.end()) return false;
        actuallist.push_back(val);
        lookup[val] = actuallist.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(lookup.find(val) == lookup.end()) return false;
        // return false;
        swap(actuallist.back(), actuallist[lookup.find(val)->second]);
        actuallist.pop_back();
        lookup[actuallist[lookup.find(val)->second]] = lookup.find(val)->second;
        lookup.erase(val);
        return true;
    }
    
    int getRandom() {
        default_random_engine gen;
        uniform_int_distribution<int> dist(0, actuallist.size()-1);
        int d = dist(gen);
        return actuallist[d];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */