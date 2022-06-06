def binary_search (lst, value):
    mid = len(lst) // 2
    index = False
    if (value > lst[mid] and len(lst) > 1):
        index = binary_search (lst[mid:], value)
    elif(value < lst[mid] and len(lst) > 1):
        index = binary_search (lst[:mid], value)
    if(value == lst[mid]):
        index = True
        return index
    return index