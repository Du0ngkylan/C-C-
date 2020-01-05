/*
 * danhsach_sv.h
 *
 *  Created on: Oct 11, 2012
 *      Author: NgoHuong
 */

#ifndef DANHSACH_SV_H_
#define DANHSACH_SV_H_

struct Node *addNode(struct Node *list, char name[]);
struct Node* readList(struct Node *list);
void sortList(struct Node *list);
struct Node *insertNode(struct Node *list);
struct Node *deleteNode(struct Node *list);
void in_ds(struct Node *list);
//void free(struct Node *list);

#endif /* DANHSACH_SV_H_ */
