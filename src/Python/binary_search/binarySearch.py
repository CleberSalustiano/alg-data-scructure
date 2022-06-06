def binary_search(array, value):
  mid = len(array) // 2
  while(len(array) > 1):
    if value > array[mid]:
      array = array[mid:]
      mid = len(array) // 2
    elif value < array[mid]:
      array = array[:mid]
      mid = len(array) // 2
      array[mid] > value
    else:
      return True
  return False
