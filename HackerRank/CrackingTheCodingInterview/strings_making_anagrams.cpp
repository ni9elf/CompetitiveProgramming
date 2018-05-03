#include <iostream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

int number_needed(string a, string b) {
    unordered_map<char, int> freq_a, freq_b;    
    for (char c : a) {
        if (freq_a.find(c) == freq_a.end()) 
            freq_a[c] = 1;
        else
            freq_a[c] += 1;
        }
    for (char c : b) {
        if (freq_b.find(c) == freq_b.end())
            freq_b[c] = 1;
        else
            freq_b[c] += 1;
        }
    int count = 0;
    char key;
    for (int i = 97; i <= 122; ++i) {
        key = static_cast<char>(i);
        if (freq_a.find(key) != freq_a.end() && freq_b.find(key) != freq_b.end())
            count += abs(freq_a[key] - freq_b[key]);
        else if (freq_a.find(key) != freq_a.end()) 
            count += freq_a[key];
        else if (freq_b.find(key) != freq_b.end())
            count += freq_b[key];
        else
            continue;
        }            
    return count;        
    }


int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    
    return 0;
    }
