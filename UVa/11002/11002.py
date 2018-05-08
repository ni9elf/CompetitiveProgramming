'''
Created on 19 March 2017

@author: Nigel Fernandez
'''

'''
The optimization is based on the fact that if the set of sums for a cell contains all numbers in [0, 50] then any cells on top of this cell will also contain [0, 50]. Recursively, we will finally reach the top cell which will contain the set of sums having [0, 50]. Since the top cell value will be from [-50, 50] the final answer will be zero. Hence if any set sum has [0, 50] then stop and output 0.

Also, we need to store only the absolute sum values since either + or - can be used to compute future sum values of cells above.
'''

import sys
from collections import defaultdict
#from timeit import default_timer as timer

def towards_zero(board, n):
    #for line in board:
    #    print (line)
    table = defaultdict(set)
    for i in range(len(board)):  
        #print (i)  
        for j in range(len(board[i])):
            if (i == 0):
                table['00'] = set([abs(int(board[i][j]))]) 
            elif (i < n):
                if (i < n and j == 0):
                    #go top right only
                    #notice that only absolute values are stored                                    
                    table[str(i) + str(j)] = set([abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j)]])
                elif (i < n and (j == len(board[i])-1)):
                    #go top left only                
                    table[str(i) + str(j)] = set([abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j-1)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j-1)]])
                else:
                    #go top left and right                
                    table[str(i) + str(j)] = set([abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j-1)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j-1)]] + [abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j)]])
            else:
                #go top left and right            
                table[str(i) + str(j)] = set([abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j)]] + [abs(int(board[i][j]) + sum_) for sum_ in table[str(i-1) + str(j+1)]] + [abs(int(board[i][j]) - sum_) for sum_ in table[str(i-1) + str(j+1)]])
            #check is the set of sums contains [0,50], if yes, then return answer 0
            if(set(range(0, 51)).issubset(table[str(i) + str(j)])):
                #print (str(i) + str(j))      
                return 0
    #for i in range(len(board)):          
        #for j in range(len(board[i])):
        #    print (table[str(i)+str(j)])
    return min(table[str(2*n-2) + str(0)])                                
    
    
if __name__ == '__main__':
    #start = timer()
    while(True):
        #get no of rows in board
        line = sys.stdin.readline().strip()
        line = line.split(' ')
        n = int(line[0])
        if (n == 0):
            break
        #get board
        board = []
        for i in range(2*n - 1):
            line = sys.stdin.readline().strip()
            row = line.split(' ')
            board.append(row)
        #for row in board:
        #    print (row)
        #find towards zero for board
        sys.stdout.write(str(towards_zero(board, n)) + '\n')
    #end = timer()
    #print(end - start) 
