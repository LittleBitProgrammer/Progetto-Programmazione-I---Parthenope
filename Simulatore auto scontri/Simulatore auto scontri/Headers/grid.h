//
//  grid.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                /* - Scopo della libreria - */
                                                           /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                -----------------------------
                                                        |---->  |           grid.h           |  <----|
                                                                -----------------------------
 
 La libreria in questione nasce con lo scopo di semplificare le operazioni di creazione di una griglia in stile battaglia navale, infatti la funzione printGrid stamperà
 a video la seguente interfaccia grafica:
 
 
                                                               1   2   3   4   5   6   7   8
                                                              --- --- --- --- --- --- --- ---
                                                            1|   |   |   |   |   |   |   |   |1
                                                              --- --- --- --- --- --- --- ---
                                                            2|   |   |   |   |   |   |   |   |2
                                                              --- --- --- --- --- --- --- ---
                                                            3|   |   |   |   |   |   |   |   |3
                                                              --- --- --- --- --- --- --- ---
                                                            4|   |   |   |   |   |   |   |   |4
                                                              --- --- --- --- --- --- --- ---
                                                            5|   |   |   |   |   |   |   |   |5
                                                              --- --- --- --- --- --- --- ---
                                                            6|   |   |   |   |   |   |   |   |6
                                                              --- --- --- --- --- --- --- ---
                                                            7|   |   |   |   |   |   |   |   |7
                                                              --- --- --- --- --- --- --- ---
                                                            8|   |   |   |   |   |   |   |   |8
                                                              --- --- --- --- --- --- --- ---
                                                               1   2   3   4   5   6   7   8
 
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                              /* - definisco la libreria - */
                                                          /*-----------------------------------*/
#ifndef grid_h
#define grid_h



                                        /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                                   /*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard e non, utili per lo sviluppo di alcune funzioni, sono state incluse quindi le librerie :
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
 input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 - utilitylib.h : librieria composta da costanti e funzioni di utilità generica, in particolare vengono utilizzate le costanti N_CARS e N_ROWS_COLUMNS in diverse
 funzioni.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "utilitylib.h"


                                                                 /* - prototipi di funzioni - */
                                                            /*------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Qui definisco i prototipi di funzioni che vengono discussi nel dettaglio nel file source grid.c
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*stampa indice colonna griglia*/
void printColumnNumbers(void);
/*stampa solo la griglia centrale*/
void printPartialGrid(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS]);
/*stampa griglia per intero*/
void printGrid(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS]);

#endif /* grid_h */
