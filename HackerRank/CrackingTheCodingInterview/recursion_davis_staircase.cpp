#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> way_map;  
    
int find_ways(int height) {
    int val;
    if (way_map.find(height) != way_map.end())
        return way_map[height];
    else {
        val = find_ways(height - 3) + find_ways(height - 2) + find_ways(height - 1);
        way_map[height] = val;
        return val;
        }
    }

int main() { 
    way_map[1] = 1;
    way_map[2] = 2;
    way_map[3] = 4;
    int t, height, ways;
    cin >> t;    
    for (int i = 0; i < t; ++i) {
        cin >> height;
        ways = find_ways(height);
        cout << ways << endl;
        }        
    
    return 0;
    }
