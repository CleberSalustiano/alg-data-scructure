class List:
    data = []
    
    def __init__(self, data):
      self.data = data
      if data == '':
        self.data = []
    
    def appendList(self, value):
      self.data += [value]
    
    def insertFirst(self, value):
      self.data = [value] + self.data
    
    def insertList(self, index, value):
      if len(self.data) < index:
        print ('ERROR: The index > lenList')
      elif len(self.data) == index:
        self.appendList(self.data, value)
      else:
        left, right = self.data[:index], self.data[index:]
        self.data = left + [value] + right
    
    def removeList(self, index):
      if len(self.data) <= index:
        print ('ERROR: The index > lenList')
      else:
        left, right = self.data[:index], self.data[index+1:]
        self.data = left + right
    
    def lenList(self):
      index = 0
      for element in self.data:
        index += 1
      return index
    
    def firstList(self):
      return self.data[0]
     
    def finalList(self):
      return self.data[self.lenList() - 1]

    def indexList(self, value):
      index = 0
      for element in self.data:
        if element == value:
            return index
        else:
            index += 1
      print('ERROR: This value does not exist in this list')
      return -1
      
      
    def clearList(self):
      self.data = []
    
    def cloneList(self):
      return self
      
    def reverseList(self):
      newLst = self.data
      self.data = []
      for element in newLst:
        self.insertFirst(element)
