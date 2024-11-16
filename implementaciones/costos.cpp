#include "../headers/costos.h"

int costo_sub(char a, char b) {
    int costo;

    costo = costoReplace[a-97][b-97];

    return costo;
}

int costo_ins(char b) {
    int costo;

    costo = costoInsert[b-97];

    return costo;
}

int costo_del(char a) {
    int costo;

    costo = costoDelete[a-97];

    return costo;
}

int costo_trans(char a, char b) {
    int costo;

    costo = costoTranspose[a-97][b-97];

    return costo;
}