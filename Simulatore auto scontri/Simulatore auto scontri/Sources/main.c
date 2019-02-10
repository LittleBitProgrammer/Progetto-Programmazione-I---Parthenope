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

//griglia con numero colonne modulare

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Headers/grid.h"
#include "../Headers/car.h"
#include "../Headers/utilitylib.h"

car_struct cars[] = {
    {"dodge Coronet", 3, 0, 'X', 20, 10, 30, 40},
    {"Ford Thunderbird", 0, 3, 'Y', 40, 10, 15, 35},
    {"chevrolet Corvette", 3, 7, 'W', 30, 20, 5, 45},
    {"cadillac Serie 70", 7, 3, 'Z', 20, 30, 25, 25}
};

int main(int argc, const char * argv[]) {
    
    int i;
    int turn = 0;
    int random_num;
    char choice[10];
    char grid[8][8];
    bool isdan = false;
    direction dir_cars;

    printLogo();
    
    printf("\n\n             Benvenuto nel Simulatore di auto scontri!\n");
    printf("<------------------------------------------------------------------------>\n");
    
    printf("\nLe seguenti auto sono pronte per partire: \n\n");
    printf("- La %s con il simbolo      -------> %c    nella posizione |%d|%d|\n", cars[0].name,cars[0].symbol,cars[0].position_x,cars[0].position_y);
    printf("- La %s con il simbolo   -------> %c    nella posizione |%d|%d|\n", cars[1].name,cars[1].symbol,cars[1].position_x,cars[1].position_y);
    printf("- La %s con il simbolo -------> %c    nella posizione |%d|%d|\n", cars[2].name,cars[2].symbol,cars[2].position_x,cars[2].position_y);
    printf("- La %s con il simbolo  -------> %c    nella posizione |%d|%d|\n", cars[3].name,cars[3].symbol,cars[3].position_x,cars[3].position_y);
    
    printf("__________________________________________________________________________\n\n");
    
    printf("Di seguito una interfaccia grafica della griglia di partenza:\n\n");
    
    initCarMatrix(grid);
    initCarPosition(grid,cars);
    
    printf("\n");//creo spazio dal bordo
    printf(" ");//creo spazio
    
    printGrid(grid);
    
    while (!isdan) {
        
        turn += 1;
        
        for (i = 0; i < N_CARS && !isdan; i++) {
            
            random_num =  nrand();
            dir_cars = returnCarDirection(random_num, cars[i].right_percent, cars[i].left_percent, cars[i].forwars_percent);
            
            printf("\n\n\nPremi una lettera qualsiasi e poi enter per muovere la ----> %c: ", cars[i].symbol);
            scanf("%s",choice);
            
            switch (dir_cars) {
                    
                case avanti:
                    
                    if (isNotOnTopMargin(cars, i)) {
                        
                        eraseOldCarPosition(grid, i,cars);
                        moveForward(grid, i, cars);
                        
                        printf("La %s con simbolo %c si è spostata in avanti in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        isdan = isClashed(cars, i);
                        
                    }else{
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                case indietro:
                    
                    if (isNotOnBottomMargin(cars, i)){
                        
                        eraseOldCarPosition(grid, i, cars);
                        moveBack(grid, i, cars);
                        
                        printf("La %s con simbolo %c si è spostata in indietro in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        isdan = isClashed(cars, i);
                        
                    }else{
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                case destra:
                    
                    if (isNotOnRightMargin(cars, i)){
                        
                        eraseOldCarPosition(grid, i, cars);
                        moveToRight(grid, i, cars);
                        
                        printf("La %s con simbolo %c si è spostata a destra in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        isdan = isClashed(cars, i);
                        
                    }else{
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                case sinistra:
                    
                    if (isNotOnLeftMargin(cars, i)) {
                        
                        eraseOldCarPosition(grid, i, cars);
                        moveToLeft(grid, i ,cars);
                        
                        printf("La %s con simbolo %c si è spostata sinistra in |%d|%d|\n", cars[i].name, cars[i].symbol,cars[i].position_x+1, cars[i].position_y+1);
                        
                        isdan = isClashed(cars, i);
                        
                    }else{
                        
                        printf("La %s con simbolo %c è rimasta ferma\n\n", cars[i].name, cars[i].symbol);
                        
                    }
                    
                    break;
                    
                default:
                    printf("C'è stato un errore, arrivederci");
                    exit(0);
            }
        }
        
        printf("__________________________________________________________________________\n\n\nTurno %d\n\n", turn);
        printGrid(grid);
        
    }
    printf("\n\nComplimenti le auto hanno resistito %d turni senza scontrarsi !\n\n", turn-1);
    return 0;
}
