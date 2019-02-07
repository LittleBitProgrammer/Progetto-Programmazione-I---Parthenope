//
//  main.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 06/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

// <------MATRIX-------->
//00 01 02 03 04 05 06 07 ^
//10 11 12 13 14 15 16 17 | M
//20 21 22 23 24 25 26 27 | A
//30 31 32 33 34 35 36 37 | T      8 x 8 GRID
//40 41 42 43 44 45 46 47 | R
//50 51 52 53 54 55 56 57 | I
//60 61 62 63 64 65 66 67 | X
//70 71 72 73 74 75 76 77 ^


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define
#define MAX_NAME_LENGHT 20
#define N_ROWS_COLUMNS 8
#define N_CARS 4

//enum
typedef enum { destra = 1, sinistra, avanti, indietro } direction;
typedef enum { false, true} bool;

//struct
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

car_struct cars[] = {
    {"dodge Coronet", 3, 0, 'X', 20, 10, 30, 40},
    {"Ford Thunderbird", 0, 3, 'Y', 40, 10, 15, 35},
    {"chevrolet Corvette", 3, 7, 'W', 30, 20, 5, 45},
    {"cadillac Serie 70", 7, 3, 'Z', 20, 30, 25, 25}
};


void printGrid(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS]);
bool isDamaged(car_struct *);
int assignenum(int, int, int, int);
int nrand(void);

int main(int argc, const char * argv[]) {
    
    int i,j;
    int random_num;
    int turn = 0;
    int choice;
    direction dir_cars;
    
    char grid[8][8];

    //inizializzo matrice a vuoto
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            grid[i][j] = ' ';
        }
    }
    
    grid[3][0] = cars[0].symbol;
    grid[0][3] = cars[1].symbol;
    grid[3][7] = cars[2].symbol;
    grid[7][3] = cars[3].symbol;
    
    
    printf("\n");//creo spazio dal bordo
    printf(" ");//creo spazio
    
    printGrid(grid);
    //isDamaged(cars);
    
    while (!isDamaged(cars)) {
        
        for (i = 0; i < 4; i++) {
            turn += 1;
            random_num =  nrand();
            dir_cars = assignenum(random_num, cars[i].right_percent, cars[i].left_percent, cars[i].forwars_percent);
            
            switch (dir_cars) {
                case avanti:
                    
                    if (cars[i].position_x > 0) {
                        
                        grid[cars[i].position_x][cars[i].position_y] = ' ';
                        cars[i].position_x -= 1;
                        grid[cars[i].position_x][cars[i].position_y] = cars[i].symbol;
                        printf("La %s con simbolo %c si è spostata in avanti in [%d][%d]\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                    }else{
                        printf("La %s con simbolo %c èrimasta ferma\n\n", cars[i].name, cars[i].symbol);
                    }
                    
                    break;
                    
                case indietro:
                    if (cars[i].position_x < N_ROWS_COLUMNS-1){
                        
                        grid[cars[i].position_x][cars[i].position_y] = ' ';
                        cars[i].position_x += 1;
                        grid[cars[i].position_x][cars[i].position_y] = cars[i].symbol;
                        printf("La %s con simbolo %c si è spostata in indietro in [%d][%d]\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                    }else{
                        printf("La %s con simbolo %c èrimasta ferma\n\n", cars[i].name, cars[i].symbol);
                    }
                    break;
                case destra:
                    
                    if (cars[i].position_y < N_ROWS_COLUMNS-1){
                        
                        grid[cars[i].position_x][cars[i].position_y] = ' ';
                        cars[i].position_y += 1;
                        grid[cars[i].position_x][cars[i].position_y] = cars[i].symbol;
                        printf("La %s con simbolo %c si è spostata a destra in [%d][%d]\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                    }else{
                        printf("La %s con simbolo %c èrimasta ferma\n\n", cars[i].name, cars[i].symbol);
                    }
                    
                    break;
                case sinistra:
                    
                    if (cars[i].position_y > 0) {
                        
                        grid[cars[i].position_x][cars[i].position_y] = ' ';
                        cars[i].position_y -= 1;
                        grid[cars[i].position_x][cars[i].position_y] = cars[i].symbol;
                        printf("La %s con simbolo %c si è spostata sinistra in [%d][%d]\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                    }else{
                        printf("La %s con simbolo %c èrimasta ferma\n\n", cars[i].name, cars[i].symbol);
                    }
                    
                    break;
                    
                default:
                    return 0;
                    
            
            }
            printf("premi 1 per passare al prossimo turno: ");
            scanf("%d",&choice);
        }
        printf("\n\n==========================================\n\n\n");
        printGrid(grid);
    }
    
    
    return 0;
}








































void printGrid(char grid[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    int i = 1,j;
    //questo blocco serve per stampare i numeri in alto
    for(j = 0; j <= 4 * N_ROWS_COLUMNS; j++){ //per j che va da 0 a 4 che moltiplica nr. colonne, spazio,spazio,numero,spazio
        
        if(j % 4 == 2) //se j diviso 4 ha resto 2 vuol dire che mi trovo nella posizione 3 allora sono centrato e posso scrivere la
            //cordinata
            printf("%d",i++);
        else//altrimenti printa uno spazio perchè se non lo facessi i numeri srebbero attaccati
            printf(" ");
        
    }
    
    
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
                    printf(" %c ", grid[i/2][j/2]);//altrimenti tre spazi
            }
        }
        
        //istruzione di fine riga quindi se dispari stampa 1 o valori successivi
        if(i%2!=0)
            printf("%d",(i/2)+1);
        
        printf("\n");
    }
    //spazio
    printf(" ");
    
    //stampa numero sotto stesso di sopra
    for(j = 0, i = 1; j <= 4 * N_ROWS_COLUMNS; j++){
        if(j%4==2)
            printf("%d", i++);
        else
            printf(" ");
    }
    
    printf("\n");
}

bool isDamaged(car_struct *cars){
    int i,j;
    bool isDamaged = false;
    
    for (i = 0; i < N_CARS; i++) {
        for (j = 0; j < N_CARS; j++) {
            if (i != j) {//macchina[i] != macchina[j]
                //printf("confronto nella prima if\n");
                //printf("confronto macchina[%d], con macchina[%d]\n", i,j);
                if (cars[i].position_x == cars[j].position_x && cars[i].position_y == cars[j].position_y) {
                    printf("la macchina con simbolo %c e l'altra con simbolo %c si sono scontrate nella posizione",cars[i].symbol,cars[j].symbol);
                    isDamaged = true;
                }
            }
        }
    }
    
    return isDamaged;
}

int nrand(){
    srand((unsigned int)time(NULL));
    
    return rand()%100;
}

int assignenum( int random_num, int f_per, int s_per, int t_per){
    
    int first = f_per;
    int second = f_per +s_per;
    int third = f_per +s_per +t_per;
    
    if (random_num < first) {
        printf("\n\nnumero randomico = %d, DESTRA\n\n\n", random_num);
        return 1;
    }else if(random_num >= first && random_num< second ){
        printf("\n\nnumero randomico = %d, SINISTRA\n\n\n", random_num);
        return 2;
    }else if(random_num >= second && random_num< third ){
        printf("\n\nnumero randomico = %d, AVANTI\n\n\n", random_num);
        return 3;
    }else{
        printf("\n\nnumero randomico = %d, INDIETRO\n\n\n", random_num);
        return 4;
    }
}
