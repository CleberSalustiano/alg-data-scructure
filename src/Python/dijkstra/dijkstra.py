import math
infinito = math.inf

# Entrada de grafo é feita através de matriz.
# Os identificadores dos vértices são dados pelo grafo[x]
# E o "grafo[x][y]" é a distância do vértice x em relação ao y. 
grafo = [[0, 7, 9, infinito, infinito, 14],
         [7, 0, 10, 15, infinito, infinito],
         [9, 10, 0, 11, infinito, 2],
         [infinito , 15, 11, 0, 6, infinito],
         [infinito, infinito, infinito, 6, 0, 9],
         [14, infinito, 2, infinito, 9, 0]]

dijkstra = [0]
for i in range(1, len(grafo)):
  dijkstra.append(infinito) 

for i in range(0, len(grafo)):
  for j in range(0, len(grafo)):
    if (dijkstra[j] > (grafo[i][j] + dijkstra[i])):
      dijkstra[j] = (grafo[i][j] + dijkstra[i])

print(dijkstra)