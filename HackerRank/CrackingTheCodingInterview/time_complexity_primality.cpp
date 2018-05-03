#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    for (int j = 3; j <= static_cast<int>(sqrt(n)); j+=2)
        if (n % j == 0)
            return false;
    return true;
    }  


int main() {
    int p, n;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> n;                
        if(n == 2)
            cout << "Prime" << endl;
        else if (n % 2 != 0 and n > 1 and is_prime(n))
            cout << "Prime" << endl;
        else
            cout << "Not prime" << endl;
        }
    
    return 0;
    }
