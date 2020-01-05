/*
 * library.h
 *
 *  Created on: Mar 6, 2012
 *      Author: MrThai
 */

#include "dataStructure.h"
#ifndef LIBRARY_H_
#define LIBRARY_H_

node *addNode (node * ,char * ,int);
node *createList (char *);
void printList (node *);
node *reverse (node *);
void selectionSort(node *);

#endif /* LIBRARY_H_ */
