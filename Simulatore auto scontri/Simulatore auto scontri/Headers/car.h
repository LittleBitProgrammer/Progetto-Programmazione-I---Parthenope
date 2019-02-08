//
//  car.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#ifndef car_h
#define car_h
#define MAX_NAME_LENGHT 20

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum { destra = 1, sinistra, avanti, indietro } direction;
typedef enum { false, true} bool;

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

/*inizializza la posizione delle auto*/
void initCarPosition(char [8][8], car_struct *);              //va bene in car.h
/*inizializza matrice*/
void initMatrix(char[8][8]);
/*ritorna la direzione dell'auto*/
int returnDirection(int, int, int, int);
/*ritorna numero randomico*/
int nrand(void);
/*verifica lo scontro*/
bool isClashed(car_struct *);                                 //va bene in car.h
/*verifico che non sia sul margine sinistro*/
bool isNotOnLeftMargin(car_struct *, int);                    //va bene in car.h
/*verifico che non sia sul margine destro*/
bool isNotOnRightMargin(car_struct *, int);                   //va bene in car.h
/*verifico che sia sul margine superiore*/
bool isNotOnTopMargin(car_struct *, int);                     //va bene in car.h
/*verifico che non sia sul margine inferiore*/
bool isNotOnBottomMargin(car_struct *, int);                  //va bene in car.h
/*cancello posizione precedente*/
void eraseOldCarPosition(char [8][8], int, car_struct *);     //va bene in car.h
/*muovi la macchina a sinistra*/
void moveToLeft(char [8][8], int, car_struct *);              //va bene in car.h
/*muovi la macchina a destra*/
void moveToRight(char [8][8], int, car_struct *);             //va bene in car.h
/*muovi la macchina in avanti*/
void moveForward(char [8][8], int, car_struct *);             //va bene in car.h
/*muovi la macchina indietro*/
void moveBack(char [8][8], int, car_struct *);                //va bene in car.h


#endif /* car_h */
