import random

'''
Hay diferentes tipos de tablas ya hechas, para hacer mas facil la
revision de la tarea. Modificar a gusto.
'''

#--------------------ARCHIVO cost_insert.txt--------------------
costos = []

#Fila con solo 1's
for i in range(26): costos.append(1)

#Fila incremental
#for i in range(26): costos.append(i)

#Fila random
#for i in range(26): costos.append(random.randint(0, 26))

with open("Codigo/costos/cost_insert.txt", "w") as file:
    file.write(" ".join(map(str, costos)) + "\n")
#---------------------------------------------------------------



#--------------------ARCHIVO cost_delete.txt--------------------
costos = []

#Fila con solo 1's
for i in range(26): costos.append(1)

#Fila incremental
#for i in range(26): costos.append(i)

#Fila random
#for i in range(26): costos.append(random.randint(0, 26))

with open("Codigo/costos/cost_delete.txt", "w") as file:
    file.write(" ".join(map(str, costos)) + "\n")
#---------------------------------------------------------------



#--------------------ARCHIVO cost_replace.txt--------------------
#Genera matriz con diagonal principal en 0 y el resto con 1
matriz = [[0 if i == j else 1 for j in range(26)] for i in range(26)]

#Genera matriz con diagonal principal en 0 y el resto va incrementando a medida que se alejan de ella
#matriz = [[0 if i == j else abs(i - j) + 1 for j in range(26)] for i in range(26)]

#Genera matriz con numeros aleatorios
'''
matriz = [[0 if i == j else random.randint(0, 9) for j in range(26)] for i in range(26)]
# Reflejar la matriz
for i in range(26):
    for j in range(i + 1, 26):
        matriz[j][i] = matriz[i][j]
'''

with open("Codigo/costos/cost_replace.txt", "w") as file:
    for fila in matriz:
        file.write(" ".join(map(str, fila)) + "\n")
#---------------------------------------------------------------



#--------------------ARCHIVO cost_transpose.txt--------------------
#Genera matriz con diagonal principal en 0 y el resto con 1
matriz = [[0 if i == j else 1 for j in range(26)] for i in range(26)]

#Genera matriz con diagonal principal en 0 y el resto va incrementando a medida que se alejan de ella
#matriz = [[0 if i == j else abs(i - j) + 1 for j in range(26)] for i in range(26)]

#Genera matriz con numeros aleatorios <= 9
'''
matriz = [[0 if i == j else random.randint(0, 9) for j in range(26)] for i in range(26)]
# Reflejar la matriz
for i in range(26):
    for j in range(i + 1, 26):
        matriz[j][i] = matriz[i][j]
'''

with open("Codigo/costos/cost_transpose.txt", "w") as file:
    for fila in matriz:
        file.write(" ".join(map(str, fila)) + "\n")
#---------------------------------------------------------------