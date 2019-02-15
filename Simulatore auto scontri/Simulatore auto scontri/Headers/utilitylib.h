//
//  utilitylib.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 09/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//



                                                                     /* - Scopo della libreria - */
                                                                /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                    -----------------------------
                                                            |---->  |        utilitylib.h       |  <----|
                                                                    -----------------------------
 
                La libreria in questione nasce con lo scopo raggruppare costanti e funzioni di utilità generica per il progetto delle auto scontro
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                                   /* - definisco la libreria - */
                                                              /*-----------------------------------*/
#ifndef utilitylib_h
#define utilitylib_h


                                                                  /* - definizione di costanti - */
                                                              /*-----------------------------------*/
#define N_ROWS_COLUMNS 8
#define N_CARS 4


                                        /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                                   /*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard, utili per lo sviluppo di alcune funzioni, sono state incluse quindi le librerie :
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
 input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 - time.h : è l'header file della libreria standard del C che fornisce un accesso standardizzato alle funzioni di acquisizione e manipolazione del tempo.
 
 -stdlib.h : è l'header file che, all'interno della libreria standard del C, dichiara funzioni e costanti di utilità generale: allocazione della memoria, controllo
             dei processi, e altre funzioni generali comprendenti anche i tipi di dato. In particolare sono stati utilizzate le funzioni rand() e srand()
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


                                                                  /* - prototipi di funzioni - */
                                                             /*------------------------------------*/


/*stampa il logo del programma*/
void printLogo(void);
/*ritorna un numero randomico tra 1 e 100*/
int nrand(void);

#endif /* utilitylib_h */
