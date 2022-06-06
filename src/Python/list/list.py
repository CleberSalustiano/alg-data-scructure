def appendList(lst, value):
  lst += [value]
  return lst

def insertList(lst, index, value):
  if len(lst) < index:
    print ('ERROR: The index > lenList')
  elif len(lst) == index:
    appendList(lst, value)
  else:
    left, right = lst[:index], lst[index:]
    lst = left + [value] + right
    return lst

def removeList(lst, index):
  if len(lst) <= index:
    print ('ERROR: The index > lenList')
    return lst
  else:
    left, right = lst[:index], lst[index+1:]
    lst = left + right
    return lst

def lenList(lst):
  index = 0
  for element in lst:
    index += 1
  return index

def firstList(lst):
  return lst[0]

def finalList(lst):
  return lst[lenList(lst) - 1]

def indexList(lst, value):
  index = 0
  for element in lst:
    if element == value:
        return index
    else:
        index += 1
  print('ERROR: This value does not exist in this list')

def clearList(lst):
  lst = []
  return lst

def cloneList(lst):
  newLst = lst
  return newLst