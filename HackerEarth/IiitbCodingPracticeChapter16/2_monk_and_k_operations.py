import sys

dp_table = {}

def max_power(arr, k, l, r):
    key = str(k)+'$'+str(l)+'$'+str(r)
    if(k == 0):
        return arr[0]*arr[-1]    
    elif(key in dp_table):
        return dp_table[key]        
    else:
        ans = max(max_power(arr[1:], k-1, l+1, r), max_power(arr[:-1], k-1, l, r-1))
        dp_table[key] = ans
        return ans

t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    dp_table = {}
    line = sys.stdin.readline().rstrip()
    line = line.split(" ")
    n = int(line[0])
    k = int(line[1])
    line = sys.stdin.readline().rstrip()
    inp = line.split(" ")
    arr = [int(el) for el in inp]
    
    ans = []
    for i in range(k):
        ans.append(arr[i]*arr[-k+i-1])
    
    print max(ans)
    #print max_power(arr, k, 0, len(arr)-1)


    #for key, value in dp_table.items():
    #    print key, value    
    
