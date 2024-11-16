import matplotlib.pyplot as plt
import pandas as pd
import os

input_dir = "Codigo/Output"

largos = list(range(3, 15))

for caso in range(1, 9):
    filename = f"Caso{caso}.txt"
    filepath = os.path.join(input_dir, filename)
    
    if os.path.exists(filepath):
        data = pd.read_csv(filepath, sep=" ", header=None, names=["FuerzaBruta", "ProgDinamica"])

        plt.figure()
        plt.plot(largos, data["FuerzaBruta"], marker="o", label="Fuerza Bruta")
        plt.plot(largos, data["ProgDinamica"], marker="o", label="Programación Dinámica")
        if caso >= 3:
            plt.yscale('log')
        plt.title("Tiempo vs Largo")
        plt.xlabel("Largo de las cadenas")
        plt.ylabel("Tiempo (ms)")
        plt.legend()
        plt.grid(True)
        
        output_dir = "Codigo/Graficos"
        output_path = os.path.join(output_dir, f"Grafico_Caso{caso}.png")
        plt.savefig(output_path)
        plt.close()

print("Gráficos generados exitosamente.")
