//
//  car.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "car.h"
#include "grid.h"

void initCarPosition(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    matrix[3][0] = cars[0].symbol;
    matrix[0][3] = cars[1].symbol;
    matrix[3][7] = cars[2].symbol;
    matrix[7][3] = cars[3].symbol;
}

void initCarMatrix(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS]){
    int i,j;
    for (i = 0; i < N_ROWS_COLUMNS; i++) {
        for (j = 0; j < N_ROWS_COLUMNS; j++) {
            matrix[i][j] = ' ';
        }
    }
}

/*correggere funzione*/
int returnCarDirection( int random_num, int f_per, int s_per, int t_per){
    
    int first = f_per;
    int second = f_per +s_per;
    int third = f_per +s_per +t_per;
    
    if (random_num < first) {
        return 1;
    }else if(random_num >= first && random_num< second ){
        return 2;
    }else if(random_num >= second && random_num< third ){
        return 3;
    }else{
        return 4;
    }
}

bool isClashed(car_struct *cars, int index){
    int i;
    bool isDamaged = false;
    
    for (i = 0; i < N_CARS; i++) {
        if (index != i && cars[index].position_x == cars[i].position_x && cars[index].position_y == cars[i].position_y) {
            printf("Due o più macchine si sono scontrate :(\n");
            isDamaged = true;
            return isDamaged;
            
        }
    }
    return isDamaged;
}

bool isNotOnLeftMargin(car_struct *cars){
    return cars->position_y > 0;
}

bool isNotOnRightMargin(car_struct *cars){
    return cars->position_y < N_ROWS_COLUMNS-1;
}

bool isNotOnTopMargin(car_struct *cars){
    return cars->position_x > 0;
}

bool isNotOnBottomMargin(car_struct *cars){
    return cars->position_x < N_ROWS_COLUMNS-1;
}

void eraseOldCarPosition(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], car_struct *cars){
    matrix[cars->position_x][cars->position_y] = ' ';
}

void moveToLeft(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], int index, car_struct *cars){
    cars[index].position_y -= 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina a destra*/
void moveToRight(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], int index, car_struct *cars){
    cars[index].position_y += 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina in avanti*/
void moveForward(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], int index, car_struct *cars){
    cars[index].position_x -= 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina indietro*/
void moveBack(char matrix[N_ROWS_COLUMNS][N_ROWS_COLUMNS], int index, car_struct *cars){
    cars[index].position_x += 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
