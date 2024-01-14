#include<stdio.h>
#include<stdlib.h>
#include "FiniteAutomaton.h"
#include <stdbool.h>
#include <string.h>

/**
*    Initialization of the Automaton
*    @param automaton automate to initialize
*    @param alphabet alphabet of the automate
*    @param nbOfState  number of states of the automate
     @param alphabetSize size of the alphabet
*    @brief  This function initialize the automate with the alphabet and the number of states 
*/
void initAutomaton(FiniteAutomaton *automaton, char *alphabet, int nbOfState, int alphabetSize) { // OK

    automaton -> alphabet = alphabet ;   //init alphabet
    automaton -> numberOfStates = nbOfState ; //init nombre State
    automaton ->initialState = 0; // par default etat initial est a la position 0
    automaton -> states = malloc(nbOfState*sizeof(State));   // init des State par default
    automaton -> alphabetSize = alphabetSize;
    for (int i = 0; i < nbOfState; i++) {
        automaton->states[i].stateNumber = i;  // numero par default
        automaton->states[i].isFinal = false;    // par default non final
    }

    automaton -> transition = malloc(nbOfState*sizeof(int **)); // init de la matrice des transition

    for (int i = 0; i < nbOfState; i++) {
        automaton -> transition[i] = malloc(nbOfState*sizeof(int *));
        for (int j = 0; j < nbOfState; j++){
            automaton->transition[i][j] = malloc(automaton->alphabetSize*sizeof(int));
            for (int k = 0; k < automaton->alphabetSize; k++){
                automaton->transition[i][j][k] = 0; // par default les transitions sont a 0
            }
        }
    }
}
/**
 * @brief Add a transition to an automaton
 * @param automaton : automaton to which we want to add a transition
 * @param start : start state of the transition
 * @param end : end state of the transition
 * @param letter : letter of the transition
*/
void addTransition (FiniteAutomaton *automaton, State start, State end, int letter ){ // OK
    if (start.stateNumber < 0 || start.stateNumber >= automaton->numberOfStates ||
        end.stateNumber < 0 || end.stateNumber >= automaton->numberOfStates ||
        letter < 0 || letter >= automaton->alphabetSize) {
        printf("Error: Invalid transition parameters.\n");
        return;
    }

    automaton -> transition[start.stateNumber][end.stateNumber][letter] = 1 ;
}
/**
    Delete one transition of an automaton
    @param automaton : automaton to delete a transition
    @param depart : start state of the transition
    @param fin : end state of the transition
*/
void deleteTransition (FiniteAutomaton *automaton, State start, State end,int letter ){ // OK

    automaton -> transition[start.stateNumber][end.stateNumber][letter] = 0 ;
}
/**
    Display the automaton
    @param automaton : automaton to display
*/
void displayAutomaton(FiniteAutomaton *automaton){ 

    int nbrTransitions = automaton->alphabetSize;
    for (int i = 0; i < automaton->numberOfStates; i++)
    {
        for (int j = 0; j < automaton->numberOfStates; j++)
        {
            for (int k = 0; k < nbrTransitions; k++)
            {
                if (automaton->transition[i][j][k] == 1)
                {
                    printf("%d -- %c -- %d\n",automaton->states[i].stateNumber,automaton->alphabet[k],automaton->states[j].stateNumber);
                }
            }
        }
        printf("\n");
    }
}
/**
    Delete an automaton
    @param automate : automaton to delete
*/
void deleteAutomaton(FiniteAutomaton *automaton){ // OK

    free(automaton->states);
    for (int i = 0; i < automaton->numberOfStates; i++)
    {
        for (int j = 0; j < automaton->numberOfStates; j++)
        {
            free(automaton->transition[i][j]);
        }
        free(automaton->transition[i]);
    }
    free(automaton->transition);
    free(automaton);
}


