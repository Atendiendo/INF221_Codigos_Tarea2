#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "headers/fuerzaBruta.h"
#include "headers/programacionDinamica.h"
using namespace std;
int costoReplace[26][26];
int costoInsert[26];
int costoDelete[26];
int costoTranspose[26][26];

string cadena1, cadena2;

void leerCostos() {
    ifstream fileDelete("costos/cost_delete.txt");
    ifstream fileInsert("costos/cost_insert.txt");
    ifstream fileReplace("costos/cost_replace.txt");
    ifstream fileTranspose("costos/cost_transpose.txt");

    // Leer costoReplace
    if (fileReplace.is_open()) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                fileReplace >> costoReplace[i][j];
            }
        }
        fileReplace.close();
    }

    // Leer costoInsert
    if (fileInsert.is_open()) {
        for (int i = 0; i < 26; ++i) {
            fileInsert >> costoInsert[i];
        }
        fileInsert.close();
    }

   // Leer costoDelete
    if (fileDelete.is_open()) {
        for (int i = 0; i < 26; ++i) {
            fileDelete >> costoDelete[i];
        }
        fileDelete.close();
    }

    // Leer costoTranspose
    if (fileTranspose.is_open()) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                fileTranspose >> costoTranspose[i][j];
            }
        }
        fileTranspose.close();
    }
}

void leerInput(int caso, int largo) {
    ifstream archivo("Input/Caso"+ to_string(caso) +"/entrada" + to_string(caso) + "_" + to_string(largo) + ".txt");
    string linea;

    getline(archivo, linea);
    cadena1 = linea;
    getline(archivo, linea);
    cadena2 = linea;

}

int main() {
    leerCostos();

    for (int j = 1; j < 9; j++) {

        ofstream fileOutput("Output/Caso" + to_string(j) + ".txt");
        cout << "-----------CASO" + to_string(j) + "--------------\n" << endl;

        for (int i = 3; i < 15; i++) {
            leerInput(j, i);

            cout << "Cadena 1: " << cadena1 << endl;
            cout << "Cadena 2: " << cadena2 << endl;
            cout << "Largo cadenas: " << i << endl;

            cadena1.erase(std::remove(cadena1.begin(), cadena1.end(), '\r'), cadena1.end());
            cadena1.erase(std::remove(cadena1.begin(), cadena1.end(), '\n'), cadena1.end());
            cadena2.erase(std::remove(cadena2.begin(), cadena2.end(), '\r'), cadena2.end());
            cadena2.erase(std::remove(cadena2.begin(), cadena2.end(), '\n'), cadena2.end());

            int costoFB;
            double avgFBTime = 0.0;

            if (i <= 13){
                double totalFBTime = 0.0;

                for (int k = 0; k < 10; k++) {
                    cout << "Ejecucion " + to_string(k) + " Fuerza bruta" << endl;
                    auto startFB = chrono::high_resolution_clock::now();
                    costoFB = fuerzaBruta(cadena1, cadena2, 0, 0);
                    auto endFB = chrono::high_resolution_clock::now();
                    totalFBTime += chrono::duration<double, milli>(endFB - startFB).count();
                }
                avgFBTime = totalFBTime / 10;

                cout << "Costo fuerza bruta: " << costoFB << endl;
                cout << "Tiempo de ejecución (Fuerza Bruta): " << avgFBTime << " ms" << endl;
            } else {
                cout << "Ejecucion 0 Fuerza bruta" << endl;

                auto startFB = chrono::high_resolution_clock::now();
                costoFB = fuerzaBruta(cadena1, cadena2, 0, 0);
                auto endFB = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> elapsedFB = endFB - startFB;

                avgFBTime = elapsedFB.count();

                cout << "Costo fuerza bruta: " << costoFB << endl;
                cout << "Tiempo de ejecución (Fuerza Bruta): " << avgFBTime << " ms" << endl;
            }
            

            int costoPD;
            double totalPDTime = 0.0;

            
            for (int k = 0; k < 10; k++) {
                cout << "Ejecucion " + to_string(k) + " Programacion dinamica" << endl;
                auto startPD = chrono::high_resolution_clock::now();
                costoPD = programacionDinamica(cadena1, cadena2);
                auto endPD = chrono::high_resolution_clock::now();
                totalPDTime += chrono::duration<double, milli>(endPD - startPD).count();
            }

            double avgPDTime = totalPDTime / 10;
            cout << "Costo programacion dinamica: " << costoPD << endl;
            cout << "Tiempo de ejecución (Programación Dinámica): " << avgPDTime << " ms" << endl;

            fileOutput << avgFBTime << " " << avgPDTime << endl;
        }
        fileOutput.close();
        cout << "\n";
    }
    return 0;
}