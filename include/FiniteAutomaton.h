#ifndef H_FINITEAUTOMATON_H
#define H_FINITEAUTOMATON_H
typedef struct FiniteAutomaton FiniteAutomaton;
#include "State.h"
#include <stdbool.h>

/**
 * @brief Struct of a finite automaton
 * @param alphabet : alphabet of the automaton
 * @param initialState : initial state of the automaton
 * @param numberOfStates : number of states of the automaton
 * @param states : array of states of the automaton
 * @param transition : transition matrix of the automaton, the first transition table corresponds to the first state, the second to the second state, and the last to the index of the letter in the alphabet.
 * @param alphabetSize : size of the alphabet
 */
struct FiniteAutomaton{ 
    char *alphabet;     
    int initialState;    
    int numberOfStates;
    State *states;        
    int ***transition;   
    int alphabetSize;
};

void initAutomaton(FiniteAutomaton *automaton, char *alphabet, int numberOfStates, int alphabetSize);

void addTransition (FiniteAutomaton *automaton, State start, State end, int letter );
void deleteTransition (FiniteAutomaton *automaton, State start, State end, int letter );

void displayAutomaton(FiniteAutomaton *automaton);

void deleteAutomaton(FiniteAutomaton *automaton);

#endif
