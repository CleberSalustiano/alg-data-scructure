def selectionSort(array):
  index = 0
  for i in range(0, len(array)):
    minor = array[i]
    for j in range(i, len(array)):
      if (array[j] < minor):
        minor = array[j]
        index = j 
    if (array[index] > array[i] or minor == array[i]):
        continue
    array[index] = array[i]
    array[i] = minor