//
//  utilitylib.c
//  Simulatore auto scontri
//
//  Created by Roberto Vecchio on 09/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include "utilitylib.h"

/*stampa logo*/
void printLogo(){
    printf("\n\n                     ___\n                       _-_-  _/\\______\\__\n                    _-_-__  / ,-. -|-  ,-.`-.\n                       _-_- `( o )----( o )-'\n                              `-'      `-'\n");
}

int nrand(){
    srand((unsigned int)time(NULL));
    
    return rand()%100+1;
}
