'''
Created on 19 March 2017

@author: Nigel Fernandez
'''

#board indexing: top row has index 0 and bottom row has index 2*n-2
import sys
from collections import defaultdict

def all_sums(i, j, n, board):
    #print (i, j)
    if(i == 0):
        return set([abs(board[0][0])])
    if(i < n):
        if(j == 0):
            #go top right only
            return set([board[i][j] + sum_ for sum_ in all_sums(i-1, j, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j, n, board)])
        elif(j == len(board[i])-1):
            #go top left only
            return set([board[i][j] + sum_ for sum_ in all_sums(i-1, j-1, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j-1, n, board)])
        else:
            #go top left and right
            return set([board[i][j] + sum_ for sum_ in all_sums(i-1, j-1, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j-1, n, board)] + [board[i][j] + sum_ for sum_ in all_sums(i-1, j, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j, n, board)])
    else:
        #go top left and right
        return set([board[i][j] + sum_ for sum_ in all_sums(i-1, j, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j, n, board)] + [board[i][j] + sum_ for sum_ in all_sums(i-1, j+1, n, board)] + [board[i][j] - sum_ for sum_ in all_sums(i-1, j+1, n, board)])        


def towards_zero(board, n):
    #start traversing from bottom row upwards to top row
    return min([abs(sum_) for sum_ in all_sums((2*n-2), 0, n, board)])


if __name__ == '__main__':
    #start = timer()
    while(True):
        #get no of rows in board
        line = sys.stdin.readline().strip()
        line = line.split(' ')
        n = int(line[0])
        #print (n)
        if (n == 0):
            break
        #get board
        board = []
        for i in range(2*n - 1):
            line = sys.stdin.readline().strip()
            row = line.split(' ')
            row = [int(no) for no in row]
            board.append(row)
        #for row in board:
        #    print (row)
        #find towards zero for board
        sys.stdout.write(str(towards_zero(board, n)) + '\n')
    #end = timer()
    #print(end - start) 
