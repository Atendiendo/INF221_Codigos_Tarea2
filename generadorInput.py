import random
import string
import os

os.makedirs("Codigo/Input", exist_ok=True)

def cadenaAleatoria(longitud):
    caracteres = string.ascii_lowercase
    return ''.join(random.choice(caracteres) for _ in range(longitud))

def generar_cadena_repetida(longitud):
    cadena = []
    while len(cadena) < longitud:
        letra = random.choice(string.ascii_lowercase)
        repeticiones = random.randint(1, 3)
        cadena.extend([letra] * repeticiones)
    return ''.join(cadena[:longitud])

def intercambiar_caracteres(cadena, num_intercambios):
    lista_cadena = list(cadena)
    intercambios_realizados = set()

    while len(intercambios_realizados) < num_intercambios:
        i = random.randint(0, len(cadena) - 2)
        j = i + 1
        
        if (i, j) not in intercambios_realizados and (j, i) not in intercambios_realizados:
            lista_cadena[i], lista_cadena[j] = lista_cadena[j], lista_cadena[i]
            intercambios_realizados.add((i, j))
    
    return ''.join(lista_cadena)

longitudes = range(3, 15)


# Caso 1: Cadena 1 vacía, cadena 2 con contenido
for i in longitudes:
    cadena1 = ""
    cadena2 = cadenaAleatoria(i)
    os.makedirs(f"Codigo/Input/Caso1", exist_ok=True)
    with open(f"Codigo/Input/Caso1/entrada1_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 2: Cadena 2 vacía, cadena 1 con contenido
for i in longitudes:
    cadena1 = cadenaAleatoria(i)
    cadena2 = ""
    os.makedirs(f"Codigo/Input/Caso2", exist_ok=True)
    with open(f"Codigo/Input/Caso2/entrada2_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 3: Cadenas iguales
for i in longitudes:
    cadena1 = cadenaAleatoria(i)
    cadena2 = cadena1
    os.makedirs(f"Codigo/Input/Caso3", exist_ok=True)
    with open(f"Codigo/Input/Caso3/entrada3_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")


# Caso 4: Cadenas con caracteres repetidos
for i in longitudes:
    cadena1 = generar_cadena_repetida(i)
    cadena2 = generar_cadena_repetida(i)

    os.makedirs(f"Codigo/Input/Caso4", exist_ok=True)

    with open(f"Codigo/Input/Caso4/entrada4_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 5: Cadenas con transposición necesaria
for i in longitudes:
    cadena1 = cadenaAleatoria(i)
    cadena2 = cadena1
    if i <= 7:
        num_intercambios = 1
    elif i <= 10:
        num_intercambios = 2
    else:
        num_intercambios = 3
    cadena2 = intercambiar_caracteres(cadena1, num_intercambios)
    os.makedirs(f"Codigo/Input/Caso5", exist_ok=True)
    with open(f"Codigo/Input/Caso5/entrada5_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 6: Cadenas de un solo carácter
for i in longitudes:
    letra1 = generar_cadena_repetida(1)
    cadena1 = letra1 * i
    letra2 = generar_cadena_repetida(1)
    cadena2 = letra2 * i
    os.makedirs(f"Codigo/Input/Caso6", exist_ok=True)
    with open(f"Codigo/Input/Caso6/entrada6_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 7: Cadenas con patrones repetitivos
for i in longitudes:
    cadena1 = "tratratratratr"[:i]
    cadena2 = "artartartartar"[:i]
    os.makedirs(f"Codigo/Input/Caso7", exist_ok=True)
    with open(f"Codigo/Input/Caso7/entrada7_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")

# Caso 8: Cadenas sin caracteres en común
for i in longitudes:
    cadena1 = cadenaAleatoria(i)
    cadena2 = cadenaAleatoria(i)
    while set(cadena1).intersection(set(cadena2)):
        cadena2 = cadenaAleatoria(i)
    os.makedirs(f"Codigo/Input/Caso8", exist_ok=True)
    with open(f"Codigo/Input/Caso8/entrada8_{i}.txt", "w") as archivo:
        archivo.write(f"{cadena1}\n{cadena2}\n")
