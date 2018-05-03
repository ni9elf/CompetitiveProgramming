'''
Created on 19 March 2014

@author: Nigel Fernandez
'''

import sys

if __name__ == '__main__':
    while(True):
        line = sys.stdin.readline()
        if(line == ''):
            break
        strength = line.split(' ')
        sys.stdout.write(str(abs(int(strength[0]) - int(strength[1]))) + '\n')            
