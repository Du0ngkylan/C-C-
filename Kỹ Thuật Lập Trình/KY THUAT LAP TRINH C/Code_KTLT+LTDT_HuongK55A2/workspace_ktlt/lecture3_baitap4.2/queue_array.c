/*
 * queue_array.c
 *
 *  Created on: Nov 30, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float queue[100];

int front = 0, rear = 0, count = 0;

int isEmpty()
{

}

void enQueue(float x)
{
	if (count < 100)
	{
		queue[front + count] = x;
		count++;
	}
}

float deQueue()
{
	if (count > 0)
	{
		count-- ;
		return queue[front++];
	}
	else
		return 0;
}

float deQueueQueue()
{
	if (count > 0)
	{
		float x = queue[front];
		count--;
		front++;
		if (front == 100)
			front = 0;
		return x;
	}
	else
		return 0;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));
	while (1)
	{
		int x ;
		printf("\n\n Nhap x = ");
		scanf("%d",&x);
		enQueue(x);
		if (x == 0)
			break;
	};
	deQueue();

	printf("\n\n Cac phan tu co trong queue la : ");
	while(1)
	{
	    printf("\t%d", deQueueQueue());
	    deQueue();
	}
	return 0;
}


