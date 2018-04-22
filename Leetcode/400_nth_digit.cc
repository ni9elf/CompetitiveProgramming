class Solution {
public:
    int findNthDigit(int n) {
        double sum = 9, x = 9;
        int y = 1;        
        //handling corner case when n is in [1, 9]
        if (n <= sum)
            return n;
        while(true) {
            if (n < sum) {
                //roll back to previous bounds
                sum -= x*y;
                x = x/10;
                break;
            }
            else {
                x = x*10;
                y += 1;
                sum += x*y;
            }
        }
        n = n - static_cast<int>(sum);
        int offset = n / y;        
        int place = n % y;
        if (place == 0) {
            offset = n / y;   
            place = y-1;        
        }
        else {            
            offset = n/y + 1;
            place -= 1;
        }
        double number = stod(string(y-1, '9')) + offset;
        //converting from char to int by subtracting from '0'
        int digit = to_string(number)[place] - '0';        
        return digit;
    }
};
