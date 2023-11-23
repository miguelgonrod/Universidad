#!/usr/bin/env python3

from pomegranate import *
import json
import sys

class bayesian_network: # clase que contiene los métodos para crear la red bayesiana y calcular la probabilidad de la consulta
    def __init__(self, ruta):
        self.archivo = ruta
        self.distributions = None
        self.tables_data = None
        self.beliefs = None
        self.query = None
        self.edges = None
        self.child_parents = None
        self.states = None
        self.network = None
        self.predictions = None
    
    def loadData(self): # método que carga los datos del archivo de entrada y los procesa para crear la red bayesiana
        with open(self.archivo, 'r') as f:
            data = json.load(f)
            
        self.distributions, self.tables_data, self.beliefs, self.query, self.edges = self.process_input(data)
        self.child_parents = self.get_child_parents()
        self.update_distributions()

        self.states = self.generate_states()

        self.network = self.create_bayesian_network()
        self.network.bake()
        
        self.display_network_structure()

        self.predictions = self.network.predict_proba(self.beliefs)

        output_query, output_json = self.process_output()
        sanitized_filename = self.sanitize_filename(output_query)

        with open(sanitized_filename + '.json', 'w') as json_file:
            json_file.write(output_json)

        print(f'Archivo creado: "{output_query}" con el nombre de archivo depurado: {sanitized_filename}.json.')
    
    def process_input(self, data): # método que procesa los datos del archivo de entrada para crear la red bayesiana
        distributions = {}
        beliefs = {}
        query = []
        edges = []
        tables_data = []
        pos_temp = []
        neg_temp = []
        for node in data:
            table = []
            pos = []
            neg = []
            for key in node.keys():
                if key == 'BELIEF':
                    append = 0
                    new_key = node.get(key).replace('-', '')
                    beliefs[new_key] = node.get(key)
                elif key == 'QUERY':
                    append = 0
                    query.append(node.get(key))
                else:
                    if key.find('|') == -1:
                        append = 0
                        distributions[key] = DiscreteDistribution({key: node.get(key), '-' + key: 1 - node.get(key)})
                    else:
                        append = 1
                        info = key.split('|')
                        if info[1].find('-') == -1:
                            for i in range(len(info[1])):
                                edges.append((info[1][i], info[0]))
                        pos_row = []
                        neg_row = []
                        flag = 0
                        for i in range(len(info[1])):
                            if flag == 1:
                                flag = 0
                                continue
                            elif info[1][i] == '-':
                                pos_row.append(info[1][i]+ info[1][i + 1])
                                neg_row.append(info[1][i]+ info[1][i + 1])
                                flag = 1
                            else:
                                pos_row.append(info[1][i])
                                neg_row.append(info[1][i])
                        pos_row.append(info[0])
                        pos_row.append(node.get(key))
                        pos_temp = pos_row
                        neg_row.append('-' + info[0])
                        neg_row.append(1 - node.get(key))
                        neg_temp = neg_row
                    if append == 1:
                        pos.append(pos_temp)
                        neg.append(neg_temp)
            table = pos + neg
            if append == 1:
                tables_data.append(table)
        return distributions, tables_data, beliefs, query, edges

    def get_child_parents(self): # método que obtiene los padres de cada nodo
        child_parents = {}
        for e in self.edges:
            if e[1] in child_parents.keys():
                child_parents[e[1]].append(e[0])
            else:
                child_parents[e[1]] = [e[0]]
        return child_parents

    def update_distributions(self): # método que actualiza las distribuciones de probabilidad condicional
        conditional = {}
        for t in self.tables_data:
            if t[0][-2] in self.child_parents.keys():
                parents_table = []
                parents_list = self.child_parents[t[0][-2]]
                for p in parents_list:
                    parents_table.append(self.distributions[p])
                conditional[t[0][-2]] = ConditionalProbabilityTable(t, parents_table)
                self.distributions.update(conditional)

    def generate_states(self): # método que genera los estados de la red bayesiana
        states = {}
        for state in self.distributions:
            states[state] = State(self.distributions[state], name=state)
        return states

    def create_bayesian_network(self): # método que crea la red bayesiana
        network = BayesianNetwork()
        for s in self.states:
            network.add_state(self.states[s])
        for e in self.edges:
            network.add_edge(self.states[e[0]], self.states[e[1]])
        return network

    def enumerate_reduction(self): # método que calcula la probabilidad de la consulta usando enumeración
        
        result = 0
        for value in [True, False]:
            extended_beliefs = self.beliefs.copy()
            extended_beliefs[self.query[0]] = value
            result += self.network.predict_proba(extended_beliefs)[0].parameters[0] if value else 1 - self.network.predict_proba(extended_beliefs)[0].parameters[0]
        return result

    def process_output(self, use_enumeration=False): # método que procesa la salida de la red bayesiana
        output_query = ''
        output_probability = ''
        if use_enumeration:
            probability = self.enumerate_reduction()
            output_query = self.query[0] + '|' + str(self.beliefs)
            output_probability = probability
        else:
            for state, prediction in zip(self.network.states, self.predictions):
                original_query = self.query[0]
                q = self.query[0].replace('-', '')
                if q == state.name:
                    output_predictions = ''
                    for key in self.beliefs.keys():
                        output_predictions += self.beliefs[key]
                    output_query = original_query + '|' + output_predictions
                    output_probability = prediction.parameters[0]
        output_json = json.dumps(output_probability)
        return output_query, output_json

    def display_network_structure(self): # método que muestra la estructura de la red bayesiana
        print("Bayesian Network Structure:")
        for edge in self.edges:
            print(f"{edge[1]} <- {edge[0]}")
        print("\n")

    def sanitize_filename(self, filename): # método que depura el nombre del archivo de salida
        invalid_chars = set(r'\/:*?"<>|')
        return ''.join('_' if c in invalid_chars else c for c in filename)
    
if __name__ == '__main__': # método principal
    engine = bayesian_network(sys.argv[1])
    engine.loadData()