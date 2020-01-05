#include <stdio.h>
#include <conio.h>


void main()
{
	
	for(int i = 1; i <= 10; i++ )
	{
		if(i == 5)
			continue;
		printf("%d ",i);
	}
	/* TH để if(i == 5) break;
	  1 2 3 4
	*/
	/* TH để if(i == 5) continue;
	  1 2 3 4 6 7 8 9 10
	*/
	_getch();
}