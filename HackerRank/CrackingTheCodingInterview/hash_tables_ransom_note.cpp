#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool check (vector<string> mag, vector<string> note) {
    unordered_map<string, int> freq;
    
    for (string s : mag) {
        if (freq.find(s) == freq.end())
            freq[s] = 1;
        else
            freq[s] += 1;            
        }    
    
    for (string s : note) {
        if (freq.find(s) == freq.end())
            return false;
        else {
            freq[s] -= 1;
            if (freq[s] == 0) {
                freq.erase(s);
                }
            }
        }
    return true;
    }


int main() {
    int m, n;
    cin >> m >> n;
    vector <string> mag, note;
    
    string word;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        mag.push_back(word);
        }
    
    for (int i = 0; i < n; ++i) {
        cin >> word;
        note.push_back(word);
        }
    
    if (check(mag, note) == true)
        cout << "Yes";
    else
        cout << "No";         
    return 0;
    }
    
