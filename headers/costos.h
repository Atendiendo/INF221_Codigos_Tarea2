#ifndef COSTOS_H
#define COSTOS_H

#include <iostream>

extern int costoReplace[26][26];
extern int costoInsert[26];
extern int costoDelete[26];
extern int costoTranspose[26][26];

int costo_sub(char a, char b);
int costo_ins(char b);
int costo_del(char a);
int costo_trans(char a, char b);

#endif