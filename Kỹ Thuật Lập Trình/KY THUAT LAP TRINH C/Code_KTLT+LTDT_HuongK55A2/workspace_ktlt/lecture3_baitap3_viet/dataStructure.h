/*
 * dataStructure.h
 *
 *  Created on: Mar 4, 2012
 *      Author: MrThai
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

typedef struct node 	{
	char word [30];
	int frequency;
	struct node *next;
}	node ;

#endif /* DATASTRUCTURE_H_ */
