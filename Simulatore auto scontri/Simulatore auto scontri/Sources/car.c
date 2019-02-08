//
//  car.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

//rinominare in crashsim.h
#include "car.h"
#include "grid.h"

void initCarPosition(char matrix[8][8], car_struct *cars){
    matrix[3][0] = cars[0].symbol;
    matrix[0][3] = cars[1].symbol;
    matrix[3][7] = cars[2].symbol;
    matrix[7][3] = cars[3].symbol;
}

void initMatrix(char matrix[8][8]){
    int i,j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            matrix[i][j] = ' ';
        }
    }
}

int nrand(){
    srand((unsigned int)time(NULL));
    
    return rand()%100;
}


/*correggere funzione*/
int returnDirection( int random_num, int f_per, int s_per, int t_per){
    
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

bool isClashed(car_struct *cars){
    int i,j;
    bool isDamaged = false;
    
    for (i = 0; i < N_CARS; i++) {
        for (j = 0; j < N_CARS; j++) {
            if (i != j && cars[i].position_x == cars[j].position_x && cars[i].position_y == cars[j].position_y) {//macchina[i] != macchina[j]
                printf("la macchina con simbolo %c e l'altra con simbolo %c si sono scontrate nella posizione",cars[i].symbol,cars[j].symbol);
                isDamaged = true;
                return isDamaged;
                
            }
        }
    }
    return isDamaged;
}

bool isNotOnLeftMargin(car_struct *cars, int index){
    return cars[index].position_y > 0;
}

bool isNotOnRightMargin(car_struct *cars, int index){
    return cars[index].position_y < 7;
}

bool isNotOnTopMargin(car_struct *cars, int index){
    return cars[index].position_x > 0;
}

bool isNotOnBottomMargin(car_struct *cars, int index){
    return cars[index].position_x < 7;
}

void eraseOldCarPosition(char matrix[8][8], int index, car_struct *cars){
    matrix[cars[index].position_x][cars[index].position_y] = ' ';
}

void moveToLeft(char matrix[8][8], int index, car_struct *cars){
    cars[index].position_y -= 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina a destra*/
void moveToRight(char matrix[8][8], int index, car_struct *cars){
    cars[index].position_y += 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina in avanti*/
void moveForward(char matrix[8][8], int index, car_struct *cars){
    cars[index].position_x -= 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
/*muovi la macchina indietro*/
void moveBack(char matrix[8][8], int index, car_struct *cars){
    cars[index].position_x += 1;
    matrix[cars[index].position_x][cars[index].position_y] = cars[index].symbol;
}
