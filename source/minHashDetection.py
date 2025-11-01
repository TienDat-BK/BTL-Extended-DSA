from HSmodule import *
from source.Preprocessor import Shingling, TextEmbedder

class MinHashDetection:
    def __init__(self):
        self.preprocessor = Shingling()
        self.hasher = MinHash()
        self.searcher = LSHSearch()
        self.searcher.setDisFunc("jarcard")
        self.outputDim = 64

    def detect(self, ListOfText : list ):
        ListOfVecRecord = self.preprocessor(ListOfText)  

        # cấu hình hasher cho phù hợp với kích thước vector đầu vào
        sizeOfVector = len(ListOfVecRecord[0].vec)
        self.hasher.setInOutput( sizeOfVector, self.outputDim)
        
        listVecHashed = self.hasher.hashing(ListOfVecRecord)

        clusters = self.searcher.classify(listVecHashed)

        # clustering đang là dạng list of list of VecRecord
        
        return clusters
