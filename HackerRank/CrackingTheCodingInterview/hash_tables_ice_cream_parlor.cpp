#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void get_ids(long long int money, vector<long long int> coins) {
    unordered_map<long long int, int> vals;
    int i = 1;
    for (long long int val : coins) {        
        vals[val] = i;
        i += 1;
        }
    
    //for (auto &item : vals)
    //    cout << item.first << " " << item.second << endl;
        
    int index = 1;
    for (long long int val : coins) { 
        if (vals.find(money - val) != vals.end()) {
            cout << index <<  " " << vals[money - val] << endl;
            break;
            }
        index += 1;
        }
    }


int main() {
    int t, n;
    long long int money, val;
    vector<long long int> coins;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> money;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> val;
            coins.push_back(val);
            }
        get_ids(money, coins);
        coins.clear();
        }        
    
    return 0;
    }
