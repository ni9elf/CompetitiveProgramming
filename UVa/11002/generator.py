from random import randint

if __name__ == '__main__':
    #no of cells in middle row
    for k in range(1, 30):
        mid = k
        #no of test cases
        for _ in range(10):
            print (mid)
            for i in range(1, mid):
                for j in range(i):
                    print (str(randint(-50,50)) + ' ', end='')
                print ()
            for i in range(mid):
                for j in range(mid-i):
                    print (str(randint(-50,50)) + ' ', end='')
                print ()
    print (0)
    
