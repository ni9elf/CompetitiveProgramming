#include <unordered_map>
#include <string>
#include <bitset>
#include <sstring>

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        unordered_map<int, vector<string>> hours, minutes;
        bitset<6> bin_no;
        for (int i = 0; i < 60; ++i) {
            bin_no = i;
            int key = bin_no.count();            
            if (i < 12) {
                if (hours.find(key) == hours.end())
                    hours[key] = vector<string>{to_string(i)};
                else
                    hours[key].push_back(to_string(i));
                if (minutes.find(key) == minutes.end()) {
                    ostringstream ss;
                    ss << std::setw(2) << std::setfill('0') << i;
                    minutes[key] = vector<string>{ss.str()};                    
                }
                else {
                    ostringstream ss;
                    ss << std::setw(2) << std::setfill('0') << i;  
                    minutes[key].push_back(ss.str());
                }
            }
            else {
                if (minutes.find(key) == minutes.end()) {
                    ostringstream ss;
                    ss << std::setw(2) << std::setfill('0') << i;
                    minutes[key] = vector<string>{ss.str()};                    
                }
                else {
                    ostringstream ss;
                    ss << std::setw(2) << std::setfill('0') << i;  
                    minutes[key].push_back(ss.str());    
                }
            }
        }
        int bound = min(4, num);
        int j;
        vector<string> times;
        for (int i = 0; i <= bound; ++i) {
            j = num - i;
            for (auto time_hour : hours[i])
                for (auto time_minute : minutes[j])
                    times.push_back(time_hour + ":" + time_minute);
        }
    return times;
    }
};
