class Grafo:
    def __init__(self, transitions, string, initial, final):
        self.nodes = []
        self.transitions = transitions
        self.string = string
        self.initial = initial
        self.final = final
        self.valid = False
    
    def createGraph(self):
        self.validator(self.string, self.initial)
        if (self.valid == True):
            print("La cadena es valida")
            
        else:
            print("La cadena no es valida")
    
    def validator(self, word, actualNode):
        print(actualNode)
        print("ACtual: %s" % (word)) 
        
        if word[0] in self.transitions[actualNode].keys():
            if len(word) == 1:
                if self.transitions[actualNode][word[0]] in self.final:
                    print("entra")
                    self.valid = True
                    pass
                
            else:
                if len(self.transitions[actualNode][word[0]]) == 1:
                    print("entra 2")
                    self.validator(word[1::], self.transitions[actualNode][word[0]][0])
                
                else:
                    for state in range(0, len(self.transitions[actualNode][word[0]])):
                        print("for")
                        self.validator(word[1::], self.transitions[actualNode][word[0]][state])
                        print("second for")
        
        else:
            pass
            
                

  
def main():
    transitions = {
        'q0': {'0': ('q0', 'q1'), '1': ('q0', )},
        'q1': {'1': ('q2', )},
        'q2': {'all': ('q_error', )}
    }
    validator = Grafo(transitions, "011001", "q0", ("q2", ))

    validator.createGraph()


if __name__ == "__main__":
    main()