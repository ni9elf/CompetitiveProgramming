#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

//we can avoid making pairs if we are fine with storing the number of inversion as a global variable
//to avoid a global variable, the inversion count is stored along with the array as a pair

pair <vector<int>, long long int> merge(pair <vector<int>, long long int> pair1, pair <vector<int>, long long int> pair2) {
    long long int inversions = pair1.second + pair2.second;
    vector<int> seq1 = pair1.first;
    vector<int> seq2 = pair2.first;
    vector<int> seq3;
    vector<int>::iterator it1 = seq1.begin();
    vector<int>::iterator it2 = seq2.begin();
     
    while (it1 != seq1.end() or it2 != seq2.end()) {
        if (it1 == seq1.end()) {
            seq3.insert(seq3.end(), it2, seq2.end());
            break;
            }
        else if (it2 == seq2.end()) {
            seq3.insert(seq3.end(), it1, seq1.end());
            break;
            }
        else if ((*it1) <= (*it2)) {
            seq3.push_back(*it1);
            it1 += 1;            
            }
        else {
            seq3.push_back(*it2);
            it2 += 1;
            inversions += (seq1.end() - it1); 
            }
        }
    /*
    for (auto it : seq1)
        cout << it << " ";
    cout << endl;
    for (auto it : seq2)
        cout << it << " ";
    cout << endl;  
    for (auto it : seq3)
        cout << it << " ";
    cout << endl;   
    cout << "inv" << inversions << endl;
    */
    return make_pair(seq3, inversions);
    }


pair <vector<int>, long long int> merge_sort(pair <vector<int>, long long int> mypair) {
    vector<int> seq = mypair.first;      
    if (seq.size() == 1)
        return mypair;
    else {
        vector<int> seq1;
        seq1.assign(seq.begin(), seq.begin() + floor(seq.size()/2));
        vector<int> seq2;
        seq2.assign(seq.begin() + floor(seq.size()/2), seq.end());
        return merge(merge_sort(make_pair(seq1, 0)), merge_sort(make_pair(seq2, 0)));
        }
    }


int main() {
    int d, count, num;    
    vector<int> seq;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        cin >> count;
        seq.clear();
        for (int j = 0; j < count; ++j) {
            cin >> num;
            seq.push_back(num);
            }
        cout << merge_sort(make_pair(seq, 0)).second << endl;
        }    
    
    return 0;
    }
