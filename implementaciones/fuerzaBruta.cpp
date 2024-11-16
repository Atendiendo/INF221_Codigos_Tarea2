#include "../headers/fuerzaBruta.h"
#include "../headers/costos.h"

int fuerzaBruta(string cadena1, string cadena2, int indexCadena1, int indexCadena2) {
    if (indexCadena1 == cadena1.size() || cadena1.empty()) {
        int costo = 0;
        for (int k = indexCadena2; k < cadena2.size(); ++k) {
            costo += costo_ins(cadena2[k]);
        }
        return costo;
    }

    if (indexCadena2 == cadena2.size() || cadena2.empty()) {
        int costo = 0;
        for (int k = indexCadena1; k < cadena1.size(); ++k) {
            costo += costo_del(cadena1[k]);
        }
        return costo;
    }

    int costos[4];

    costos[0] = costo_sub(cadena1[indexCadena1], cadena2[indexCadena2]) + fuerzaBruta(cadena1, cadena2, indexCadena1 + 1, indexCadena2 + 1);

    costos[1] = costo_ins(cadena2[indexCadena2]) + fuerzaBruta(cadena1, cadena2, indexCadena1, indexCadena2 + 1);

    costos[2] = costo_del(cadena1[indexCadena1]) + fuerzaBruta(cadena1, cadena2, indexCadena1 + 1, indexCadena2);

    costos[3] = 2147483647;
    if (indexCadena1 + 1 < cadena1.size() && indexCadena2 + 1 < cadena2.size()) {
        if (cadena1[indexCadena1] == cadena2[indexCadena2 + 1] && cadena1[indexCadena1 + 1] == cadena2[indexCadena2]) {
            if (cadena1[indexCadena1] != cadena1[indexCadena1 + 1]){
                costos[3] = costo_trans(cadena1[indexCadena1], cadena1[indexCadena1 + 1]) + fuerzaBruta(cadena1, cadena2, indexCadena1 + 2, indexCadena2 + 2);
            }
        }
    }

    int minimo = 2147483647;
    for (int i = 0; i < 4; i++) {
        if (costos[i] < minimo) minimo = costos[i];
    }
    
    return minimo;
}