class TimeMap {
private:
    map<string, map<int, string>> tmap;

public:
    TimeMap() {
        tmap = {};
    }
    
    void set(string key, string value, int timestamp) {
        // tmap.insert({key, map<int, string>{{timestamp, value}}});
        tmap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto r = tmap.find(key);
        if(r == tmap.end()) return "";
        auto found = (r->second).upper_bound(timestamp);
        // obviously we don't want the exact result that means we fucked up by searching for something too small 
        if(found == r->second.begin()) return "";
        --found;
        string result = found->second;
        return result;
    }
};
