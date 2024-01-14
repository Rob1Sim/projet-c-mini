#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "State.h"
#include "FiniteAutomaton.h"

int main() {
    
    FiniteAutomaton *fa = malloc(sizeof(FiniteAutomaton));
    char alphabet[]= {'a','b'} ;
   
    initAutomaton(fa, alphabet, 2, 2);

 
    addTransition(fa,fa -> states[0],fa -> states[0],1);
    addTransition(fa,fa -> states[0],fa -> states[1],0);
    addTransition(fa,fa -> states[1],fa -> states[0],1);
    addTransition(fa,fa -> states[1],fa -> states[1],0);
    displayAutomaton(fa);
    deleteAutomaton(fa);
    return 0;
}
