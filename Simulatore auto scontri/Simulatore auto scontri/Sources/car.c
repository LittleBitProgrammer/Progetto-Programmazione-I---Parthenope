//
//  car.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                                                   /* - Scopo della libreria - */
                                                              /*-----------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
                                                                    -----------------------------
                                                            |---->  |           car.c           |  <----|
                                                                    -----------------------------
 
 La libreria in questione nasce con lo scopo di semplificare le operazioni, ripetute che le auto devono svolgere finchè quest'ultime non collidono, infatti anche il
 controllo, della collisione è affidato ad una funzione presente in libreria, ma anche operazioni come movimento e controllo sulla posizioni sono presenti nel seguente
 file.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                               /* - Inclusione header file - */
                                                            /*-----------------------------------*/
#include "car.h"


                                                                     /* - Funzioni - */
                                                           /*-----------------------------------*/



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        initCarMatrix
 
 * input:       - array bidimensionale con grandezza 8 x 8
 
 * output:      assegna a tutti gli elementi della matrice un carattere spaziatura
 
 * descrizione: procedura che accetta in input una matrice (array bidimensionale) per inizializzare con un carattere di spaziatura tutti gli elementi della matrice
                fornita. Si osservi che il numero di colonne e righe non è richiesto in input in quanto viene già definito dalla costante N_ROWS_COLUMNS, poichè la
                traccia esplicita che la griglia deve essere 8x8. Nel contesto dell'esercizio in questione, la procedura risulta molto utile per mostrare l'interfaccia
                utente e quindi rappresentare la griglia con spazi vuoti dove l'auto non è presente.
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void initCarMatrix(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    int i,j;
    for (i = 0; i < N_ROWS_COLUMNS; i++) {
        for (j = 0; j < N_ROWS_COLUMNS; j++) {
            matrix[i][j] = ' ';
        }
    }
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        returnCarDirection
 
 * input:       - numero randomico, necessario per calcolare la direzione di spostamento
                - array monodimensionale di car_struct per ricavare le percentuali di spostamento in una determinata direzione
 
 * output:      ritorna un numero intero che sarà successivamente corrisposto a un enum di direction
 
 * descrizione: function che dato in input un numero randomico e un array monodimensionale di car_struct, ritorna attraverso dei controlli un numero intero che potrà
                essere sfruttato per assegnarlo a una variabile di tipo direction (enum che può assumere i 4 valori di direzione).
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int returnCarDirection( int random_num, car_struct *car){
    
    //assegna a una variabile la percentuale di andare a destra per migliorare la leggibilità del codice
    //percentuale di andare a destra è definita dal range 0...right_perent
    int first_percent = car->right_percent;
    //assegna a una variabile la percentuale di andare a sinistra per migliorare la leggibilità del codice
    //percentuale di andare a sinistra è definita dal range right_percent...(right_perent + left_percent)
    int second_percent = first_percent + car->left_percent;
    //assegna a una variabile la percentuale di andare avanti per migliorare la leggibilità del codice
    //percentuale di andare avanti è definita dal range (right_perent + left_percent)...(right_perent + left_percent + forwards_percent)
    int third_percent = second_percent + car->forwars_percent;
    
    //controllo quindi in quale range si trova il numero randomico per ritornare una direzione piuttosto che un altra
    if (random_num <= first_percent) {
        return 1;
    }else if(random_num > first_percent && random_num <= second_percent ){
        return 2;
    }else if(random_num > second_percent && random_num <= third_percent ){
        return 3;
    }else{
        return 4;
    }
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        isClashed
 
 * input:       - array monodimensionale di car_struct per ricavare le variabili position_x e position_y
                - indice di tipo intero dell'auto che deve confrontare la propria posizione con quella delle restanti
 
 * output:      ritorna un valore booleano (0 per false e 1 per true), che verifica se le auto si sono scontrate
 
 * descrizione: function che dato in input un array monodimendionale di car_struct e l'indice dell'auto che si vuole confrontare, verifica che la posizione della vettura
                in questione non coincida con quella delle altre 3, facendo quindi un controllo sulle variabili position_x e position_y
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool isClashed(car_struct *cars, int index){
    //indice utilizzato per il ciclo for
    int i;
    //is damaged è una variabile booleana inizializzata a false, perchè due auto non si sono scontrate fino a quando le due position_x e le due position_y coincidono
    bool isDamaged = false;
    
    //lancio un ciclo for utile per iterare le restanti auto
    for (i = 0; i < N_CARS; i++) {
        //se index non è uguale a i (quindi l'elemnto da confrontare non è uguale a se stesso) e la posizione x,y dell'auto al momento (index) è uguale alla posizione x,y
        //dell'auto al momento (i)
        if (index != i && cars[index].position_x == cars[i].position_x && cars[index].position_y == cars[i].position_y) {
            //allora due auto si sono scontrate, setta la variabile booleana a true e ritornala prima di fare altri controlli
            printf("\nDue auto si sono scontrate :(\n");
            isDamaged = true;
            return isDamaged;
            
        }
    }
    //altrimenti ritorna isDamaged a false
    return isDamaged;
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        isNotOnLeftMargin
 
 * input:       - array monodimensionale di car_struct per ricavare la variabile position_y
 
 * output:      ritorna un valore booleano (0 per false e 1 per true), che verifica se l'auto si trova sul margine sinistro della griglia
 
 * descrizione: function che dato in input un array monodimendionale di car_struct, verifica che la posizione della vettura non sia sul margine sinistro della griglia
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool isNotOnLeftMargin(car_struct *cars){
    return cars->position_y > 0;
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        isNotOnRightMargin
 
 * input:       - array monodimensionale di car_struct per ricavare la variabile position_y
 
 * output:      ritorna un valore booleano (0 per false e 1 per true), che verifica se l'auto si trova sul margine destro della griglia
 
 * descrizione: function che dato in input un array monodimendionale di car_struct, verifica che la posizione della vettura non sia sul margine destro della griglia
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool isNotOnRightMargin(car_struct *cars){
    return cars->position_y < N_ROWS_COLUMNS-1;
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        isNotOnTopMargin
 
 * input:       - array monodimensionale di car_struct per ricavare la variabile position_x
 
 * output:      ritorna un valore booleano (0 per false e 1 per true), che verifica se l'auto si trova sul margine superiore della griglia
 
 * descrizione: function che dato in input un array monodimendionale di car_struct, verifica che la posizione della vettura non sia sul margine superiore della griglia
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool isNotOnTopMargin(car_struct *cars){
    return cars->position_x > 0;
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        isNotOnBottomMargin
 
 * input:       - array monodimensionale di car_struct per ricavare la variabile position_x
 
 * output:      ritorna un valore booleano (0 per false e 1 per true), che verifica se l'auto si trova sul margine inferiore della griglia
 
 * descrizione: function che dato in input un array monodimendionale di car_struct, verifica che la posizione della vettura non sia sul margine inferiore della griglia
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool isNotOnBottomMargin(car_struct *cars){
    return cars->position_x < N_ROWS_COLUMNS-1;
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        eraseOldCarPosition
 
 * input:       - array bidimensionale con grandezza  8 x 8
                - array monodimensionale di car_struct per ricavare la variabile position_x e postion_y
 
 * output:      assegna un carattere di spaziatura alla vecchia posizione sulla griglia
 
 * descrizione: procedura che dato in input un array bidimensionale di caratteri e un array monodimendionale di car_struct, assegna un carattere di spaziatura alle
                coordinate x,y dell'auto, in particolare serve per cancellare il simbolo auto dalla vecchia posizione per poi effetture lo spostamento in una
                particolare direzione con una delle procedure sotto elencate.
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void eraseOldCarPosition(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    matrix[cars->position_x][cars->position_y] = ' ';
}




/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        moveToleft
 
 * input:       - array bidimensionale con grandezza massima 8 x 8, grandezza definita dalla costante N_ROWS_COLUMNS
                - array monodimensionale di car_struct per ricavare la variabile position_x e postion_y
 
 * output:      simula lo spostamento auto nella direzione di sinistra assegnando quindi il simbolo nella nuova cordinata x,y
 
 * descrizione: procedura che dato in input un array bidimensionale di caratteri e un array monodimendionale di car_struct, simula lo spostamento auto nella direzione
                di sinistra assegnando quindi il simbolo nella nuova cordinata x,y
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void moveToLeft(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    cars->position_y -= 1;
    matrix[cars->position_x][cars->position_y] = cars->symbol;
}



/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        moveToRight
 
 * input:       - array bidimensionale con grandezza massima 8 x 8, grandezza definita dalla costante N_ROWS_COLUMNS
                - array monodimensionale di car_struct per ricavare la variabile position_x e postion_y
 
 * output:      simula lo spostamento auto nella direzione di destra assegnando quindi il simbolo nella nuova cordinata x,y
 
 * descrizione: procedura che dato in input un array bidimensionale di caratteri e un array monodimendionale di car_struct, simula lo spostamento auto nella direzione
                di destra assegnando quindi il simbolo nella nuova cordinata x,y
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void moveToRight(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    cars->position_y += 1;
    matrix[cars->position_x][cars->position_y] = cars->symbol;
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        moveForward
 
 * input:       - array bidimensionale con grandezza massima 8 x 8, grandezza definita dalla costante N_ROWS_COLUMNS
                - array monodimensionale di car_struct per ricavare la variabile position_x e postion_y
 
 * output:      simula lo spostamento auto nella direzione avanti assegnando quindi il simbolo nella nuova cordinata x,y
 
 * descrizione: procedura che dato in input un array bidimensionale di caratteri e un array monodimendionale di car_struct, simula lo spostamento auto nella direzione
                avanti assegnando quindi il simbolo nella nuova cordinata x,y
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void moveForward(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    cars->position_x -= 1;
    matrix[cars->position_x][cars->position_y] = cars->symbol;
}


/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * nome:        moveBack
 
 * input:       - array bidimensionale con grandezza massima 8 x 8, grandezza definita dalla costante N_ROWS_COLUMNS
                - array monodimensionale di car_struct per ricavare la variabile position_x e postion_y
 
 * output:      simula lo spostamento auto nella direzione indietro assegnando quindi il simbolo nella nuova cordinata x,y
 
 * descrizione: procedura che dato in input un array bidimensionale di caratteri e un array monodimendionale di car_struct, simula lo spostamento auto nella direzione
                indietro assegnando quindi il simbolo nella nuova cordinata x,y
 
 * versione:    2.0
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void moveBack(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    cars->position_x += 1;
    matrix[cars->position_x][cars->position_y] = cars->symbol;
}
