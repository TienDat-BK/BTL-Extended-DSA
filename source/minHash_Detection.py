from HSmodule import *
from source.Preprocessor import Shingling, TextEmbedder

class MinHashDetection:
    def __init__(self):
        self.preprocessor = Shingling()
        self.hasher = MinHash()
        self.searcher = Search()
        self.searcher.setDisFunc("hamming")
        self.outputDim = 128

    def detect(self, ListOfText : list ):
        ListOfVecRecord = self.preprocessor(ListOfText)  

        # cấu hình hasher cho phù hợp với kích thước vector đầu vào
        sizeOfVector = len(ListOfVecRecord[0].vec)
        self.hasher.setInOutput(sizeOfVector, outputDim = self.outputDim)

        clusters = self.searcher.classify(ListOfVecRecord) 

        # clustering đang là dạng list of list of VecRecord
        
        return clusters
