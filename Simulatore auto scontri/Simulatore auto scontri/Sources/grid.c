//
//  grid.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//
//    1   2   3   4   5   6   7   8
//   --- --- --- --- --- --- --- ---
// 1|   |   |   |   |   |   |   |   |1
//   --- --- --- --- --- --- --- ---
// 2|   |   |   |   |   |   |   |   |2
//   --- --- --- --- --- --- --- ---
// 3|   |   |   |   |   |   |   |   |3
//   --- --- --- --- --- --- --- ---
// 4|   |   |   |   |   |   |   |   |4
//   --- --- --- --- --- --- --- ---
// 5|   |   |   |   |   |   |   |   |5
//   --- --- --- --- --- --- --- ---
// 6|   |   |   |   |   |   |   |   |6
//   --- --- --- --- --- --- --- ---
// 7|   |   |   |   |   |   |   |   |7
//   --- --- --- --- --- --- --- ---
// 8|   |   |   |   |   |   |   |   |8
//   --- --- --- --- --- --- --- ---
//    1   2   3   4   5   6   7   8


#include "../Headers/grid.h"

void printColumnNumbers(){
    int i = 1;
    int j;
    
    //questo blocco serve per stampare i numeri in alto
    for(j = 0; j <= 4 * N_ROWS_COLUMNS; j++){ //per j che va da 0 a 4 che moltiplica nr. colonne, spazio,spazio,numero,spazio
        
        if(j % 4 == 2) //se j diviso 4 ha resto 2 vuol dire che mi trovo nella posizione 3 allora sono centrato e posso scrivere la
            //cordinata
            printf("%d",i++);
        else//altrimenti printa uno spazio perchè se non lo facessi i numeri srebbero attaccati
            printf(" ");
        
    }
}

void printPartialGrid(char matrix_to_print[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    int i,j;
    
    printf("\n");//una volta fatto vado a capo
    
    
    
    for(i = 0; i <= 2 * N_ROWS_COLUMNS; i++){ // per i che è uguale a 0 che va a 2 che moltiplica il numero di righe
        //ogni riga ha spazio vuoto e | e poi spazio vuoto, quindi avremo tre posizioni 0-1-2
        
        //printa numero alla sinistra della tabella
        if(i % 2 != 0) // se faccio l'elemento iesimo / 2 avrò reso zero per 0 e 2 ma non per 1 quindi quando non è vero sono centrato
            printf("%d",(i/2)+1);//quindi stampo i/2 + 1 altrimenti salta di due posizioni a causa dell'interazione del ciclo
        
        for(j = 0; j <= 2 * N_ROWS_COLUMNS; j++){//per j che va da 0 a 2 che moltiplica nr. colonne(16), incrementa
            
            //printa --- nelle posizioni pari
            if(i%2==0)//se la posizione iesima / 2 da resto zero
            {
                if(j==0)//se j = 0 printa spazio
                    printf(" ");
                if(j%2==0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else//altrimenti mi trovo in posizione dispari e printa ---
                    printf("---");
            }
            //printa |  nelle posizioni dispari
            else{
                //se pari printa |
                if(j % 2== 0)
                    printf("|");
                else
                    printf(" %c ", matrix_to_print[i/2][j/2]);//altrimenti tre spazi
            }
        }
        
        //istruzione di fine riga quindi se dispari stampa 1 o valori successivi
        if(i%2!=0)
            printf("%d",(i/2)+1);
        
        printf("\n");
    }
    //spazio
    printf(" ");
}


void printGrid(char inputMatrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    
    printColumnNumbers();
    printPartialGrid(inputMatrix);
    printColumnNumbers();
    
}


