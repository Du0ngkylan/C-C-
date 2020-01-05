#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct Set{
	char Subset[100][100];
	int numSubset;
}set;
set a[100], b[100];
int aLength, bLength;
void khoitao(){
	bLength=0;
	aLength=1;
	set root;
	root.numSubset=1;
	strcpy(root.Subset[0], "1");
	a[0]=root;
}
void addIntoSubset(set node,int i, int k){
	char s[100];
	sprintf(s,"%d", k);
	strcat(node.Subset[i], s);
	b[bLength++]= node;
}
void addNewSubset(set node, int k){
	char s[100];
	sprintf(s,"%d", k);
	strcat(node.Subset[node.numSubset], s);
	node.numSubset++;
	b[bLength++]= node;
}
void printSet(set set){
	int i= set.numSubset;
	printf("{");
	for(i=0;i<set.numSubset;i++){
		printf("%s", set.Subset[i]);

	}
	printf("}\n");
}
void print(){
	int i;
	for(i=0;i<aLength;i++){
		printf("%d", i+1);
		printSet(a[i]);
	}
}
void partition(int n){
	int i,j,k;
	for(k=2;k<n+1;k++){
		bLength=0;
		for(i=0;i<aLength;i++){
			set node= a[i];
			for(j=0;j<node.numSubset;j++){
				addIntoSubset(node,j,k);
			}
			addNewSubset(node,k);
		}
		aLength=bLength;
		for(i=0;i<aLength;i++){
			a[i]=b[i];
		}
	}
	print();
}
int main(){
	khoitao();
	printf("cac phan hoach sinh ra la:\n");
	partition(4);
	getch();
	return 0;
}
