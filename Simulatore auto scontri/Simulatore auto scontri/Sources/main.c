//
//  main.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 06/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

                                               /* Roberto Vecchio - I anno informatica - mat. 0124001871 */

                                         /* https://github.com/robertove93/Progetto-Programmazione-I---Parthenope*/

                                                                /* - Traccia progetto - */
                                                         /*-----------------------------------*/


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Si supponga di avere quattro macchine al centro dei quattro lati opposti di una griglia (vedi figura).

   <------MATRIX-------->
  00 01 02 03 04 05 06 07 ^
  10 11 12 13 14 15 16 17 | M
  20 21 22 23 24 25 26 27 | A
  30 31 32 33 34 35 36 37 | T      8 x 8 GRID
  40 41 42 43 44 45 46 47 | R
  50 51 52 53 54 55 56 57 | I
  60 61 62 63 64 65 66 67 | X
  70 71 72 73 74 75 76 77 ^

 
 
  Le macchine possono muoversi in una delle quattro posizioni vicine.La griglia è formata da mura esterne ed è di 8x8 caselle.
  Si supponga che ogni macchina si muova seguendo le seguenti regole:

   - La macchina 1 può andare a destra con probabilità 20% a sinistra con probabilità del 10% in avanti con probabilità del 30% e indietro con probabilità del 40%
   - La macchina 2 può andare a destra con probabilità 40% a sinistra con probabilità del 10% in avanti con probabilità del 15% e indietro con probabilità del 35%
   - La macchina 3 può andare a destra con probabilità 30% a sinistra con probabilità del 20% in avanti con probabilità del 5% e indietro con probabilità del 45%
   - La macchina 4 può andare a destra con probabilità 20% a sinistra con probabilità del 30% in avanti con probabilità del 25% e indietro con probabilità del 25%
 
  La simulazione finisce quando si verifica uno scontro tra almeno due macchine. L'algoritmo usa la function rand() in stdlib per generare numeri casuali.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                        /* - Spiegazione finalità del programma - */
                                                   /*-------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Il programma in questione, scritto in linguaggio C, ha lo scopo di simulare le probabilità di scontro di 4 auto partendo dal centro dei corrispettivi margini di
 una griglia 8x8, ad ogni turno, ad ogni auto viene chiesto un input da utente per permettere a quest'ultimo di tenere traccia degli spostamenti avvenuti e della
 loro corrispettiva direzione, è prevista, inoltre, un'interfaccia utente che permette di avere feedback sugli effettivi spostamenti avvenuti. Il software tiene
 traccia del tempo, sotto forma di turni, mostrando ad ogni ripetizione quanto tempo le auto hanno resisitito senza subire scontri. Le direzioni di spostamento
 intraprese dalle auto ad ogni turno sono completamente casuali, quindi, l'utente difficilmente subirà la stessa esperienza di utilizzo.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



                                                         /* - Inclusione di librerie standard - */
                                                    /*-----------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie standard utili per lo sviluppo del file main.c, quindi:
 
 - stdio.h : "standard input-output header" che contiene definizioni di macro, costanti e dichiarazioni di funzioni e tipi usati per gestire le varie operazioni di
   input/output. In particolare è stata inclusa allo scopo di utilizzare le funzioni : printf e scanf.
 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

                                                        /* - Inclusione di librerie non stardard - */
                                                   /*--------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Includo le librerie non standard, ovvero create da me, utili per lo sviluppo del file main.c, sono state incluse quindi le seguenti :
 
 - grid.h       : libreria creata allo scopo di fornire facilmente un'interfaccia utente, in particolare di stampare a video una griglia 8 x 8
                  (spiegazione dettagliata nell'header file).
 
 - car.h        : libreria creata allo scopo di gestire le varie operazioni che le auto devono svolgere ad ogni turno (spiegazione dettagliata nell'header file).
 
 - utilitylib.h : libreria creata allo scopo di gestire operazioni di utilità generale come la stampa del logo e della generazione di un numero pseudo-casuale
 
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "../Headers/grid.h"
#include "../Headers/car.h"
#include "../Headers/utilitylib.h"

                                                       /* - Inizializzazione array monodimensinale di car_struct - */
                                                 /*--------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 Inizializzo un array monodimensionale del tipo car_struct (definito in car.h) utile per rappresentare il concetto di auto nel contesto del software in questione e
 per applicare su di essi diverse operazioni, come spostamento, controllo di collisione ecc..
 
 Per semplificare la lettura del codice nel main.c di seguito le variabili che definiscono una singola struttura car_struct :
 
 {
   - nome auto
   - posizione x
   - posizione y
   - simbolo di rappresentazione su interfaccia grafica
   - probabilità di andare a destra in percentuale
   - probabilità di andare a sinistra in percentuale
   - probabilità di andare avanti in percentuale
   - probabilità di andare indietro in percentuale
 }
 
 --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

car_struct cars[] = {
    {"dodge Coronet", 3, 0, 'X', 20, 10, 30, 40},
    {"Ford Thunderbird", 0, 3, 'Y', 40, 10, 15, 35},
    {"chevrolet Corvette", 3, 7, 'W', 30, 20, 5, 45},
    {"cadillac Serie 70", 7, 3, 'Z', 20, 30, 25, 25}
};


                                                                              /* - main - */
                                                                  /*-----------------------------------*/

int main(int argc, const char * argv[]) {
    
    
                                                                    /* - Dichiarazione variabili - */
                                                               /*---------------------------------------*/
    
    
    int i;                // variabile di tipo intero, inizializzata a 0 nel for e utilizzata come indice nel medesimo ciclo
    
    int turn = 0;         // variabile di tipo intero utile per contare il numero di turni trascorsi senza collisioni. Ho sfruttato un'altra variabile oltre la i
                          // per migliorare la leggibilità del codice
    
    int random_num;       // variabile di tipo intero utile a memorizzare il numero randomico generato da ogni auto per la decisione della direzione di spostamento
    
    char choice[10];      // array monodiensionale di caratteri utile per gestire l'input da utente, in particolare, l'input può essere una qualsiasi lettera o numero
                          // quindi viene trattata come stringa
    
    char grid[8][8];      // array bidimensionale di caratteri, servirà successivamente per inizializzare e creare la mappa (griglia) necessaria per la simulazione
    
    bool isdmg = false;   // variabile booleana, tipo definito in car.h, che appunto può assumere lo stato false (0) o true (1), utile per compiere operazioni di controllo
                          // sulle colisioni
    
    direction dir_cars;   // variabile di tipo direction, ovvero, un enum definito in car.h utile per gestire il caso in cui le auto prendano una determinata direzione

    
    
                                                             /* - Stampa inteerfaccia utente iniziale - */
                                                        /*--------------------------------------------------*/
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Stampa del logo (disegnato in ascii) attraverso la funzione definita in utilitylib.h
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    printLogo();
    
    printf("\n\n             Benvenuto nel Simulatore di auto scontri!\n");
    printf("<------------------------------------------------------------------------>\n");
    
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Serie di printf, funzione utile per stampare a video (output) alcune informazioni, in particolare di seguito viene mostrato :
     
     - il nome delle auto
     - il simbolo rappresentativo
     - posizione x,y sulla griglia di partenza
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    printf("\nLe seguenti auto sono pronte per partire: \n\n");
    printf("- La %s con il simbolo      -------> %c    nella posizione |%d|%d|\n", cars[0].name,cars[0].symbol,cars[0].position_x,cars[0].position_y);
    printf("- La %s con il simbolo   -------> %c    nella posizione |%d|%d|\n", cars[1].name,cars[1].symbol,cars[1].position_x,cars[1].position_y);
    printf("- La %s con il simbolo -------> %c    nella posizione |%d|%d|\n", cars[2].name,cars[2].symbol,cars[2].position_x,cars[2].position_y);
    printf("- La %s con il simbolo  -------> %c    nella posizione |%d|%d|\n", cars[3].name,cars[3].symbol,cars[3].position_x,cars[3].position_y);
    
    printf("__________________________________________________________________________\n\n");
    
    printf("Di seguito un' interfaccia grafica della griglia di partenza:\n\n");
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Inizializzo la matrice a "vuoto" secondo le modalità definite dalla funzione in car.h. (spiegazione dettagliata nell'header file di appartenenza)
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    initCarMatrix(grid);
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Inizializzo la posizine auto in interfaccia utente
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    grid[3][0] = cars[0].symbol;
    grid[0][3] = cars[1].symbol;
    grid[3][7] = cars[2].symbol;
    grid[7][3] = cars[3].symbol;
    
    printf("\n ");
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Stampo la griglia secondo le modalità definite dalla funzione in grid.h (spiegazione dettagliata nell'header file di appartenenza)
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    printGrid(grid);
    
    
    
                                                        /* - Operazioni eseguite in ogni turno - */
                                                  /*--------------------------------------------------*/
    
    
    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------------
     
     Al centro di questo programma risiede questo ciclo while, che si occupa di ripetere il turno e le operazioni in esso contenute finchè il software non riconosce una
     collisione, ovvero, finchè le variabile isdmg (è danneggiata) è falsa, se quest'ultima è vera, allora due o più auto hanno la stessa coordinata x,y, quindi si sono
     scontrate e la simulazione necessita di terminare.
     
     --------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    while (!isdmg) {
        
        turn += 1;    //ad ogni turno incrementa di 1 così da tenere traccia del tempo trascorso senza collisioni
        
        
        /* ----------------------------------------------------------------------------------------------------------------------------------------------------------------
         
         Ad ogni turno per ogni auto c'è bisogno di svolegere una serie di operazioni organizzate in funzioni / procedure, quindi ho deciso di iterare l'array
         monodimensionale sfruttando la variabile i sopra dichiarata rappresentante l'indice che potrà assumere i valori 0,1,2,3.
         
         -----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        
        for (i = 0; i < N_CARS && !isdmg; i++) {
            
            /* ------------------------------------------------------------------------------------------------------------------------------------------------------------
             
             Ogni auto, quindi, ad ogni turno, genererà un numero casuale sfuttando la funzione nrand definita in utilitylib.h e il suo valore di ritorno per assegnarla
             alla variabile di tipo intero random_num inizialmente dichiarata.
             
             -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
            random_num =  nrand();
            
            /* ------------------------------------------------------------------------------------------------------------------------------------------------------------
             
             Per ogni auto, quindi, ad ogni turno, verrà calcolata la sua direzione di spostamento, sfuttando la funzione returnCarDirection definita in car.h e il
             suo valore di ritorno per assegnarla alla variabile di tipo direction dir_cars inizialmente dichiarata.
             
             -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
            
            dir_cars = returnCarDirection(random_num, cars +i);
            
            //Per ogni auto viene richiesto un input per permettere all'utente di prendere nota degli spostamenti avvenuti.
            printf("\n\n\nPremi una lettera qualsiasi e poi enter per muovere la ----> %c: ", cars[i].symbol);
            scanf("%s",choice);
            
            /* ------------------------------------------------------------------------------------------------------------------------------------------------------------
             
             A questo punto l'auto dovrà decidere la serie di operazioni da svolgere in funzione della direzione di spostamento pre-determinata, quindi viene sfruttato
             uno switch case per gestire le varie casistiche in funzione del valore assunto da dir_cars
             
             -------------------------------------------------------------------------------------------------------------------------------------------------------------*/
            switch (dir_cars) {
                    
                //caso in cui l'auto debba andare avanti
                case avanti:
                    
                    // se l'auto non è sul margine superiore, valore dato dalla funzione isNotOnTopMargin definita in car. h
                    // (spiegazione dettagliata nell'header file di appartenenza)
                    // allora svolgi tutte le operazioni utili per andare avanti, altrimenti resta fermo
                    if (isNotOnTopMargin(cars + i)) {
                        
                        // - Siamo quindi nel caso in cui l'auto non è sul margine superiore -
                        
                        //  cancella, quindi, il simbolo dell'auto nella vecchia posizione attraverso la funzione eraseOldCarPosition
                        //  (spiegazione dettagliata nell'header file di appartenenza)
                        eraseOldCarPosition(grid,cars + i);
                        
                        //  muovi l'auto in avanti attraverso la funzione moveForward (spiegazione dettagliata nell'header file di appartenenza)
                        moveForward(grid,cars + i);
                        
                        //  fornisce feedback all'utente su quanto è avvenuto
                        printf("La %s con simbolo %c si è spostata in avanti in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        //  Rincontrollo che la posizione non sia concidente con quella delle altre auto, utilizzando la funzione isClashed definita in car.h e utilizzando
                        //  il  suo valore di ritorno per assegnarla a isdmg
                        isdmg = isClashed(cars, i);
                        
                    }else{    //se è sul margine superiore l'auto resta ferma
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                //caso in cui l'auto debba andare indietro
                case indietro:
                    
                    // se l'auto non è sul margine inferiore, valore dato dalla funzione isNotOnBottomMargin definita in car. h
                    // (spiegazione dettagliata nell'header file di appartenenza)
                    // allora svolgi tutte le operazioni utili per andare indietro, altrimenti resta fermo
                    if (isNotOnBottomMargin(cars + i)){
                        
                        // - Siamo quindi nel caso in cui l'auto non è sul margine inferiore -
                        
                        //  cancella, quindi, il simbolo dell'auto nella vecchia posizione attraverso la funzione eraseOldCarPosition
                        //  (spiegazione dettagliata nell'header file di appartenenza)
                        eraseOldCarPosition(grid, cars + i);
                        
                        //  muovi l'auto indietro attraverso la funzione moveBack (spiegazione dettagliata nell'header file di appartenenza)
                        moveBack(grid,cars + i);
                        
                        //  fornisce feedback all'utente su quanto è avvenuto
                        printf("La %s con simbolo %c si è spostata in indietro in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        //  Rincontrollo che la posizione non sia concidente con quella delle altre auto, utilizzando la funzione isClashed definita in car.h e utilizzando
                        //  il  suo valore di ritorno per assegnarla a isdmg
                        isdmg = isClashed(cars, i);
                        
                    }else{    //se è sul margine superiore l'auto resta ferma
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                //caso in cui l'auto debba andare a destra
                case destra:
                    
                    // se l'auto non è sul margine destro, valore dato dalla funzione isNotOnRightMargin definita in car. h
                    // (spiegazione dettagliata nell'header file di appartenenza)
                    // allora svolgi tutte le operazioni utili per andare a destra, altrimenti resta fermo
                    if (isNotOnRightMargin(cars + i)){
                        
                        // - Siamo quindi nel caso in cui l'auto non è sul margine destro -
                        
                        //  cancella, quindi, il simbolo dell'auto nella vecchia posizione attraverso la funzione eraseOldCarPosition
                        //  (spiegazione dettagliata nell'header file di appartenenza)
                        eraseOldCarPosition(grid,cars + i);
                        
                        //  muovi l'auto a destra attraverso la funzione moveRight (spiegazione dettagliata nell'header file di appartenenza)
                        moveToRight(grid,cars + i);
                        
                        //  fornisce feedback all'utente su quanto è avvenuto
                        printf("La %s con simbolo %c si è spostata a destra in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        //  Rincontrollo che la posizione non sia concidente con quella delle altre auto, utilizzando la funzione isClashed definita in car.h e utilizzando
                        //  il  suo valore di ritorno per assegnarla a isdmg
                        isdmg = isClashed(cars, i);
                        
                    }else{    //se è sul margine superiore l'auto resta ferma
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                //caso in cui l'auto debba andare a sinistra
                case sinistra:
                    
                    // se l'auto non è sul margine sinistro, valore dato dalla funzione isNotOnLeftMargin definita in car. h
                    // (spiegazione dettagliata nell'header file di appartenenza)
                    // allora svolgi tutte le operazioni utili per andare sinistra, altrimenti resta fermo
                    if (isNotOnLeftMargin(cars + i)) {
                        
                        // - Siamo quindi nel caso in cui l'auto non è sul margine sinistro -
                        
                        //  cancella, quindi, il simbolo dell'auto nella vecchia posizione attraverso la funzione eraseOldCarPosition
                        //  (spiegazione dettagliata nell'header file di appartenenza)
                        eraseOldCarPosition(grid,cars + i);
                        
                        //  muovi l'auto a sinistra attraverso la funzione moveLeft (spiegazione dettagliata nell'header file di appartenenza)
                        moveToLeft(grid,cars + i);
                        
                        //  fornisce feedback all'utente su quanto è avvenuto
                        printf("La %s con simbolo %c si è spostata sinistra in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        //  Rincontrollo che la posizione non sia concidente con quella delle altre auto, utilizzando la funzione isClashed definita in car.h e utilizzando
                        //  il  suo valore di ritorno per assegnarla a isdmg
                        isdmg = isClashed(cars, i);
                        
                    }else{    //se è sul margine superiore l'auto resta ferma
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                default:
                    printf("C'è stato un errore, arrivederci");
                    exit(0);
            }
        }
        
        // ad ogni fine turno, quindi quando tutte le auto si sono mosse o rimaste ferme stampa il:
        // - tempo trascorso
        // - e la griglia
        
        // compreso il caso in cui si siano scontrate
        printf("__________________________________________________________________________\n\n\nTurno %d\n\n", turn);
        printGrid(grid);
        
    }
    
    //stampa quanti turni è durata la simulazione senza collisioni
    printf("\n\nComplimenti le auto hanno resistito %d turni senza scontrarsi !\n\n", turn-1);
    return 0;
}
