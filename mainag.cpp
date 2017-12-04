#include "ag.h"

<<<<<<< HEAD


int main(){

    int pop[POP][4];
=======
int main(){

    int pop[POP][4];
    int parents[TCROSS];
>>>>>>> origin/master

    for(size_t i = 0; i < POP; i++){
        for(size_t j = 0; j < 3; j++){
            pop[i][j] = (random()%SIZE_M) +1;
        }
        pop[i][3] = execute(pop[i][0], pop[i][1], pop[i][2]);

<<<<<<< HEAD
        cout << "colisoes:" << pop[i][3] << endl;
    }


    int tournamentelements[TOUR];
    
    for(i = 0; i < TCROSS; i++){
        for (j = 0; j < TOUR; j++) {
=======
        //cout << "colisoes:" << pop[i][3] << endl;
    }


    int tournamentelements[TOUR], number;
    
    for(size_t i = 0; i < TCROSS; i++){
        for (size_t j = 0; j < TOUR; j++) {
>>>>>>> origin/master
            number = random()%POP;
            while(!verify(tournamentelements, number, j)){
                number = random()%POP;
            }
            tournamentelements[j] = number;

        }
        parents[i] = maxelement(pop, tournamentelements, TOUR);
    }
<<<<<<< HEAD

    for(i = 1; i < TCROS; i = i + 2){
        number = rand()%10;
        //printf("%d\n",number);
        crossover(solutions, solutions[parents[i-1]], solutions[parents[i]], number, i);
    }




    


=======
    cout << "passou" << endl;
    for(size_t i = 1; i < TCROSS; i = i + 2){
        number = random()%10;
        //printf("%d\n",number);
        crossover(pop, pop[parents[i-1]], pop[parents[i]], number, i);
    }


    int n1, n2, p;

    for(size_t i = POP; i < TPOP; i++){
    
        p = random()%POP;
        n1 = random()%10;
        n2 = random()%10;
        while (n1 == n2) {
            n2 = random()%10;
        }
        if(p <= PMUT){
            number = pop[i][n1];
            pop[i][n1] = pop[i][n2];
            pop[i][n2] = number;
            pop[i][3] = execute(pop[i][0],pop[i][1],pop[i][2]);
        }
        
    }

    quickSort(pop, 0, TPOP - 1, 10);
>>>>>>> origin/master

}