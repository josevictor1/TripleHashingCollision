#include "ag.h"



int main(){

    int pop[POP][4];

    for(size_t i = 0; i < POP; i++){
        for(size_t j = 0; j < 3; j++){
            pop[i][j] = (random()%SIZE_M) +1;
        }
        pop[i][3] = execute(pop[i][0], pop[i][1], pop[i][2]);

        cout << "colisoes:" << pop[i][3] << endl;
    }


    int tournamentelements[TOUR];
    
    for(i = 0; i < TCROSS; i++){
        for (j = 0; j < TOUR; j++) {
            number = random()%POP;
            while(!verify(tournamentelements, number, j)){
                number = random()%POP;
            }
            tournamentelements[j] = number;

        }
        parents[i] = maxelement(pop, tournamentelements, TOUR);
    }

    for(i = 1; i < TCROS; i = i + 2){
        number = rand()%10;
        //printf("%d\n",number);
        crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
    }




    



}