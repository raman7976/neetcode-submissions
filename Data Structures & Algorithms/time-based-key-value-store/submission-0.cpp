#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    // FIX 1: Added missing outer closing bracket '>' for vector.
    // FIX 2: Used unordered_map instead of map for O(1) average lookup time.
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // FIX 3: Return empty string "" instead of NULL (returning NULL for std::string is invalid C++).
        if (mpp.find(key) == mpp.end()) return "";
        
        // FIX 4: Store a reference to the vector to simplify syntax and avoid redundant map lookups.
        const auto& vec = mpp[key];
        string ans = "";
        
        // FIX 5: Binary search boundaries MUST use vector indices (0 to size()-1), 
        // not actual timestamp values.
        int low = 0;
        int high = vec.size() - 1;

        // FIX 6: Removed buggy 'if(timestamp >= high)' shortcut which used a timestamp 
        // as a vector index and caused out-of-bounds/syntax errors.

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // FIX 7: Compare vec[mid].first (timestamp) instead of mpp[mid].first
            // (mpp expected a string key, passing 'mid' int caused a compiler error).
            if (vec[mid].first <= timestamp) {
                // FIX 8: Store the candidate answer and move right (low = mid + 1)
                // to see if a larger timestamp <= target exists.
                ans = vec[mid].second;
                low = mid + 1;
            } else {
                // FIX 9: Timestamp at mid is strictly greater than target, search left.
                high = mid - 1;
            }
        }

        return ans;
    }
};