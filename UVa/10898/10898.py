'''
Created on 19 March 2017

@author: Nigel Fernandez
'''

import sys

def list_to_string(numList):
    s = ''.join(map(str, numList))
    return s

    
def budget(order, items, combos, table, no_of_items):
    '''
    Uses the following recurrence equation:
    budget(order) = minimum(combo choices) if combos can be applied else complete order by individual items
    where
    combo_choice = price_of_combo + budget(updated_order)
    note: we don't include individual items in the minimum check since we know that combos will be cheaper than items
    '''
    #check for base case: if order is an individual item
    for index, item in enumerate(items):
        if (order == item):
            return table[item]    
    indices = []
    #find which all combos can be used
    for index, combo in enumerate(combos):
        flag_use = 1
        for i in range(len(order)):
            #we don't want to buy extra food
            if ((int(order[i]) - int(combo[i])) < 0):
                flag_use = 0
        if (flag_use == 1):
            indices.append(index) 
    #if some combo options exist   
    if(len(indices) != 0):
        prices = []
        for index in indices:
            combo = combos[index]
            updated_order = str(int(order) - int(combo)).zfill(no_of_items)
            prices.append(table[combo] + budget(updated_order, items, combos, table, no_of_items)) 
        return min(prices)    
    else:
        #satisfy order through individual item orders only
        price = 0
        for i in range(len(order)):
            if(int(order[i]) > 0):
                item = str(10**(no_of_items - i - 1)).zfill(no_of_items)
                price = price + (table[item] * int(order[i]))                
        order = ''.zfill(no_of_items)
        return price


if __name__ == '__main__':
    while(True):
        #reading individual items
        line = sys.stdin.readline().strip()
        if(line == ''):
            break   
        line = line.split(' ')
        no_of_items = int(line[0])
        table = {}  
        items = []      
        for i in range(1, len(line)):
            item = str(10**(no_of_items - i)).zfill(no_of_items)
            items.append(item)
            table[item] = int(line[i])       
        #reading combo meals
        line = sys.stdin.readline().strip()
        no_of_combos = int(line)
        combos = []
        for i in range(no_of_combos):
            line = sys.stdin.readline().strip()
            line = line.split(' ')
            combo = list_to_string(line[0:-1])
            combos.append(combo)
            table[combo] = int(line[-1])            
        #for key, value in table.items():
        #    print (key, value) 
        #reading orders
        line = sys.stdin.readline().strip()          
        no_of_orders = int(line)       
        for i in range(no_of_orders):
            line = sys.stdin.readline().strip()
            line = line.split(' ')
            order = list_to_string(line)
            sys.stdout.write(str(budget(order, items, combos, table, no_of_items)) + '\n')        
