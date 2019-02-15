//
//  utilitylib.c
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


                                /* - inclusione di libererie necessarie per la completezza di alcune funzioni - */
                          /*------------------------------------------------------------------------------------------*/

#include "utilitylib.h"


                                                                  /* - Funzioni - */
                                                           /*---------------------------*/

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        printLogo
 
 * input:       nessuno
 
 * output:      stampa a video il logo del programma
 
 * descrizione: procedura che quando richiamata stampa a video il logo del programma
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void printLogo(){
    printf("\n\n                     ___\n                       _-_-  _/\\______\\__\n                    _-_-__  / ,-. -|-  ,-.`-.\n                       _-_- `( o )----( o )-'\n                              `-'      `-'\n");
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        nrand
 
 * input:       nessuno
 
 * output:      restituisce un intero randomico
 
 * descrizione: function che genera e restituisce un numero randomico nel range 1..100
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int nrand(){
    srand((unsigned int)time(NULL));
    
    return rand()%100+1;
}
