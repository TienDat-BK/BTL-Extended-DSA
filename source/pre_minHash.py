from HSmodule import *
def shingle(text : str, k : int):
  shingles = list()
  for i in range(len(text) - k + 1):
    shingles.append(text[i:i+k])
  return set(shingles)

def preprocessing(texts : list, k : int):
      # k ở đây là n-gram size
      # tạo shingle sets
      shingles_set = [shingle(t, k) for t in texts]  #O(n)    n là tổng độ dài toàn bộ văn bản 

      # tạo vocab
      vocab = list(set().union(*shingles_set))    #O(n)

      # ánh xạ nhị phân
      vectors = [[1 if x in s else 0 for x in vocab] for s in shingles_set]   #O(m x V)     m là số văn bản, V là số phần tử của vocab
      listVecRecord = [VectorRecord(vec = x, id = id ) for id, x in enumerate(vectors)]       #O(m)

      return listVecRecord
