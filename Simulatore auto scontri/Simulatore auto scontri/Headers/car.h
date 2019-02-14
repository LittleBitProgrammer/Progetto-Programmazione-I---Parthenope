//
//  car.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                /* - Scopo della libreria - */
                                                           /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                -----------------------------
                                                        |---->  |           car.h           |  <----|
                                                                -----------------------------
 
 La libreria in questione nasce con lo scopo di semplificare le operazioni, ripetute che le auto devono svolgere finchè quest'ultime non collidono, infatti anche il
 controllo, della collisione è affidato ad una funzione presente in libreria, ma anche operazioni come movimento e controllo sulla posizioni sono presenti nel seguente
 file
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                                /* - definisco la libreria - */
                                                            /*-----------------------------------*/

#ifndef car_h
#define car_h

                                                               /* - definizione di costanti - */
                                                            /*-----------------------------------*/

//definisco la lunghezza massima del nome di un auto
#define MAX_NAME_LENGHT 20



                                      /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                                 /*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard e non utili per lo sviluppo di alcune funzioni, sono state incluse quindi le librerie :
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
             input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 - utilitylib.h : librieria composta da costanti e funzioni di utilità generica, in particolare vengono utilizzate le costanti N_CARS e N_ROWS_COLUMNS in diverse
                  funzioni
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "utilitylib.h"


                                                              /* - definizioni di nuovi tipi enum - */
                                                         /*---------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Definisco un nuovo tipo enumerativo chiamato direction, che in particolare può assumere 4 valori :
 
 - destra
 - sinistra
 - avanti
 - indietro
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum { destra = 1, sinistra, avanti, indietro } direction;

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco il tipo booleano, dove false assume il valore di 0 e true assume il valore di 1, utile per gestire alucune logiche del software, infatti, viene anche
 utilizzato nel main.c
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum { false, true} bool;



                                                           /* - definizioni di nuovi tipi struct - */
                                                       /*---------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Definisco il tipo car_struct come struttura le cui variabili rappresentano :
 
 {
 - nome auto [lunghezza massima del nome]
 - posizione x
 - posizione y
 - simbolo di rappresentazione su interfaccia grafica
 - probabilità di andare a destra in percentuale
 - probabilità di andare a sinistra in percentuale
 - probabilità di andare avanti in percentuale
 - probabilità di andare indietro in percentuale
 }
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
                                                             /*------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco i prototipi di funzioni che vengono discussi nel dettaglio nel file source car.c
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/* - inizializza la posizione delle auto - */
void initCarPosition(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *);
/* - inizializza matrice - */
void initCarMatrix(char[N_ROWS_COLUMNS][N_ROWS_COLUMNS]);
/* - ritorna la direzione dell'auto - */
int returnCarDirection(int, car_struct *);
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
