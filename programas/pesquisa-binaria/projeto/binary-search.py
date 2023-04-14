def binary_search(list, item):

    low = 0
    high = len(list) - 1

    while low <= high:
        
        half = int((low + high)/2)
        chute = list[half]
        
        if chute == item:
            return half
        
        if chute > item:
            high = half - 1
        
        else:
            low = half + 1
    
    return None

my_list = [1,3,5,7,9]

print(binary_search(my_list, 7))