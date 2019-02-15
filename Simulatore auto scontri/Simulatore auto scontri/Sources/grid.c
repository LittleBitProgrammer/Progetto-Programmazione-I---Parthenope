//
//  grid.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//


                                                                    /* - Scopo della libreria - */
                                                                /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                     -----------------------------
                                                            |---->  |           grid.c           |  <----|
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





                                                                   /* - Inclusione header file - */
                                                               /*-----------------------------------*/
#include "../Headers/grid.h"





                                                                          /* - Funzioni - */
                                                               /*-----------------------------------*/



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        printColNumbers
 
 * input:       nessuno
 
 * output:      stampa l'indice di colonna con spaziatura
 
 * descrizione: procedura che permette di stampare l'indice colonna
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void printColumnNumbers(){
    //variabile di tipo intero inzializzata a 1 perchè l'interfaccia utente non prevede che le colonne partino da indice pari a 0
    int i = 1;
    //variabile utile per iterare il ciclo for
    int j;
    
    /* ciclo for che stampa l'indice colonna, il numero colonne è stato moltiplicato per 4 in quanto per stampare il tipo di griglia sopra mostrata, ho bisogno di
     stampare caratteri di spaziatura tranne che nella posizione 2, il format è: spazio, spazio, numero, spazio*/
    for(j = 0; j <= 4 * N_ROWS_COLUMNS; j++){
        
        //se j diviso 4 ha resto 2 vuol dire che mi trovo nella posizione 2 allora sono centrato e posso scrivere l'indice colonna
        if(j % 4 == 2)
            printf("%d",i++);
        else//altrimenti printa uno spazio perchè se non lo facessi i numeri srebbero attaccati e non potrei seguire il format sopra mostrato
            printf(" ");
        
    }
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        printPartialGrid
 
 * input:       array bidimensionale di grandezza 8x8 da associare alla griglia
 
 * output:      stampa griglia in stile battaglia navale senza indice colonna
 
 * descrizione: procedura utile per stampare griglia in stile battaglia navale senza indice colonna
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void printPartialGrid(char matrix_to_print[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    //indice di riga e colonna
    int i,j;
    
    printf("\n");
    
    //ciclo for che itera la riga, ma moltiplicata per 2 per stampare anche il divisore riga
    for(i = 0; i <= 2 * N_ROWS_COLUMNS; i++){
        
        //printa numero alla sinistra della tabella
        if(i % 2 != 0)
            printf("%d",(i/2)+1);
        
        //ciclo for che itera la colonna, ma moltiplicata per 2 per stampare anche il divisore colonna
        for(j = 0; j <= 2 * N_ROWS_COLUMNS; j++){
            
            if(i%2==0)//se la posizione iesima / 2 da resto zero
            {
                if(j==0)//se j = 0 printa spazio
                    printf(" ");
                if(j%2==0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else//altrimenti mi trovo in posizione dispari e printa ---
                    printf("---");
            }
            //altrimenti
            else{
                //se pari printa |
                if(j % 2== 0)
                    printf("|");
                else
                    printf(" %c ", matrix_to_print[i/2][j/2]);//altrimenti printa tre caratteri spaziatura / valore presente nell'elemento [i][j] della matrice
            }
        }
        
        //printa numero alla destra della tabella
        if(i%2!=0)
            printf("%d",(i/2)+1);
        
        printf("\n");
    }
    printf(" ");
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        printGrid
 
 * input:       array bidimensionale di grandezza 8x8 da associare alla griglia
 
 * output:      stampa griglia in stile battaglia navale compreso di indice colonna
 
 * descrizione: procedura utile per stampare griglia in stile battaglia navale compreso di indice colonna, semplicemente raggruppa in un unica procedura quelle
                precedentemente dichiarate
 
 * versione:    1.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void printGrid(char inputMatrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    
    printColumnNumbers();
    printPartialGrid(inputMatrix);
    printColumnNumbers();
    
}


