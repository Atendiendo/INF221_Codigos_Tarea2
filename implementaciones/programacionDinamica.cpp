#include "../headers/programacionDinamica.h"
#include "../headers/costos.h"

int programacionDinamica(string cadena1, string cadena2) {
    int memoria[cadena1.size() + 1][cadena2.size() + 1]{0};

    int costoAnterior = 0;
    for (int i = cadena2.size() - 1; i >= 0; i--) {
        int costo = costoAnterior + costo_ins(cadena2[i]);
        costoAnterior = costo;
        memoria[cadena1.size()][i] = costo;
    }
    costoAnterior = 0;
    for (int i = cadena1.size() - 1; i >= 0; i--) {
        int costo = costoAnterior + costo_del(cadena1[i]);
        costoAnterior = costo;
        memoria[i][cadena2.size()] = costo;
    }

    for (int i = cadena1.size() - 1; i >= 0; i--) {
        for (int j = cadena2.size() - 1; j  >= 0; j--) {
            int costos[4];
            costos[0] = memoria[i + 1][j + 1] + costo_sub(cadena1[i], cadena2[j]);
            costos[1] = memoria[i][j + 1] + costo_ins(cadena2[j]);
            costos[2] = memoria[i + 1][j] + costo_del(cadena1[i]);

            costos[3] = 2147483647;
            if (i < cadena1.size() - 1 && j < cadena2.size() - 1 && cadena1[i] == cadena2[j + 1] && cadena1[i + 1] == cadena2[j] && cadena1[i] != cadena1[i + 1]) {
                costos[3] = memoria[i + 2][j + 2] + costo_trans(cadena1[i], cadena1[i + 1]);
            }

            int minimo = 2147483647;
            for (int k = 0; k < 4; k++) {
                if (costos[k] < minimo) minimo = costos[k];
            }
            memoria[i][j] = minimo;
        }
    }

    return memoria[0][0];
}