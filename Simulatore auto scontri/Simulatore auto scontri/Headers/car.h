//
//  car.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

/* - definisco la libreria - */
#ifndef car_h
#define car_h

/* - definizione di costanti - */
#define MAX_NAME_LENGHT 20

/* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
#include <stdio.h>
#include "utilitylib.h"

/* - definizioni di nuovi tipi enum - */
typedef enum { destra = 1, sinistra, avanti, indietro } direction;
typedef enum { false, true} bool;

/* - definizioni di nuovi tipi struct - */
typedef struct car {
    
    char name[MAX_NAME_LENGHT];
    int position_x;
    int position_y;
    char symbol;
    int right_percent;
    int left_percent;
    int forwars_percent;
    int back_percent;
    
}car_struct;


                                       /* - prototipi di funzioni - */
                                   /*-----------------------------------*/


/* - inizializza la posizione delle auto - */
void initCarPosition(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - inizializza matrice - */
void initCarMatrix(char[N_ROWS_COLUMNS][N_ROWS_COLUMNS]);
/* - ritorna la direzione dell'auto - */
int returnCarDirection(int, int, int, int);
/* - verifica lo scontro - */
bool isClashed(car_struct *, int);
/* - verifico che non sia sul margine sinistro - */
bool isNotOnLeftMargin(car_struct *);
/* - verifico che non sia sul margine destro - */
bool isNotOnRightMargin(car_struct *);
/* - verifico che sia sul margine superiore - */
bool isNotOnTopMargin(car_struct *);
/* - verifico che non sia sul margine inferiore - */
bool isNotOnBottomMargin(car_struct *);
/* - cancello posizione precedente - */
void eraseOldCarPosition(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - muovi la macchina a sinistra - */
void moveToLeft(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - muovi la macchina a destra - */
void moveToRight(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - muovi la macchina in avanti - */
void moveForward(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - muovi la macchina indietro - */
void moveBack(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);

#endif /* car_h */
