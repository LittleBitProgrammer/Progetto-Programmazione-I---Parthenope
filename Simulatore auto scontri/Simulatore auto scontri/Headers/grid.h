//
//  grid.h
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 08/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#ifndef grid_h
#define grid_h

#include <stdio.h>
#include "utilitylib.h"

/*stampa intestazione griglia*/
void printColumnNumbers(void);
/*stampa solo la griglia centrale*/
void printPartialGrid(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS]);
/*stampa griglia per intero*/
void printGrid(char [N_ROWS_COLUMNS][N_ROWS_COLUMNS]);

#endif /* grid_h */
