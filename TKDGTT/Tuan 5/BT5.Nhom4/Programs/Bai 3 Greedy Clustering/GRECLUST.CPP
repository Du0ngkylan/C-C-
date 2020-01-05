/*
   Name: Greedy Clustering
   Author: Group 1
   Copyringht: Group 1
   Description: group n objects into k group in close distances
   Date: 15h35 2012 Apr 16th
*/

#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int const MAXSIZEV=50;//Maximal number of objects
int const MAXSIZEE=(int)(MAXSIZEV*(MAXSIZEV-1)/2);//Maximal number of distances between differential objects
int n; //Number of object
float a[MAXSIZEV][MAXSIZEV];//Distance matrice of objects
int m; //Number of edges in the constructed graph
int fEnd[MAXSIZEE],lEnd[MAXSIZEE];//The ends of each edge in the constructed graph
float weitEd[MAXSIZEE];//Weight of edges
int edge[MAXSIZEE],ver[MAXSIZEV];//Mark the selected edges and vertices
int edgeArr[MAXSIZEV-1];//Array stored the edges of MST
int quaClus;//The quantity of clusters
float newWeitEd[MAXSIZEV-1];//Weight of selected edges


//Input the number of objects and the Distance Matrice from file MatranKC.txt
void InputData(){
	FILE *f;
	f = fopen("MatranKC.txt","r");
	if (!f){
		printf("\n Error openning file"); getch(); exit(0);
		}
	fscanf(f,"%d %d",&n,&quaClus);//Read the number of objects
	//Read distances between objects from the distance matrice
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	fscanf(f,"%f",&a[i][j]);
	fclose(f);
}

//Construct the graph
void StructureGraph(){
    m=(int)(n*(n-1)/2);
	int k=1;//Counter of edges
	for (int i=1; i<=n-1; i++)
	for (int j=i+1; j<=n; j++){
           edge[k]=0;
           fEnd[k]=i;
           lEnd[k]=j;
           weitEd[k]=a[i][j];//Set the weight value of each edge
           k++;      
	}
	for (int i=1; i<=n; i++) ver[i]=0;
}

//Sort the edges in order of increasing distance by Quicksort
void Swap(int *a, int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;  
}

void Swap(float *a, float*b){
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}

int PivotList(float list[],int first, int last)
{
        int lower=first;
        int upper=last+1;
        float pivotvalue=list[first];
        do
        {
                do
                {
                        upper--;
                        //counts++;
                }
                while (list[upper]>pivotvalue);
                do
                {
                        lower++;
                        //counts++;
                }
                while (list[lower]<pivotvalue);
                
                Swap(&fEnd[upper],&fEnd[lower]);
                Swap(&lEnd[upper],&lEnd[lower]);
                Swap(&weitEd[upper],&weitEd[lower]);
                      
                //counts;
        }
        while (lower<upper);
        Swap(&fEnd[upper],&fEnd[lower]);
        Swap(&lEnd[upper],&lEnd[lower]);
        Swap(&weitEd[upper],&weitEd[lower]);
        Swap(&fEnd[first],&fEnd[upper]);
        Swap(&lEnd[first],&lEnd[upper]);
        Swap(&weitEd[first],&weitEd[upper]);
        return upper;
}

void QuickSort(float list[], int first, int last)
{
        if (first<last)
        {
                int pivot=PivotList(list,first,last);
                QuickSort(list,first, pivot-1);
                QuickSort(list,pivot+1,last);
        }
}

void PrintEd(){
     cout<<endl<<"___________________________________________";
     for (int i=1; i<=m; i++)
         cout<<endl<<fEnd[i]<<"-->"<<lEnd[i]<<" "<<weitEd[i];
}

void SpanTree()
{
    int test;  
    //Start with the first edge
    edgeArr[1]=1;
    newWeitEd[1]=weitEd[1];
	edge[1]=1;
	ver[fEnd[1]]=ver[lEnd[1]]=1;
	
	int next=1;
    int i=0;
	while(next<=n-2)
	{
		test=0;
		i=1;
		while ((test==0)and (i<=m)){
			if(edge[i]==0)
				if((ver[fEnd[i]]+ver[lEnd[i]])==1)
				{
                    next++;                               
					edgeArr[next]=i;
					newWeitEd[next]=weitEd[i];
                    edge[i]=1;
					ver[fEnd[i]]=1;
					ver[lEnd[i]]=1;
					test=1;
				}
			i++;
		}
	}
}

void PrintTree()
{
    cout<<endl<<"___________________________________________\n";   
	int i;
	for(i=1;i<=n;i++)
		if(ver[i]==0)
		{
			printf("\n The given graph has no spanning tree");	getch();	exit(0);
		}
	printf("The minimal spanning tree:\n");
	for(i=1;i<=n-1;i++)
    if (edgeArr[i]!=0)
			printf("%d->%d--%f\n",fEnd[edgeArr[i]],lEnd[edgeArr[i]],weitEd[edgeArr[i]]);
}

//Sort the edges of MST
int PivotListMST(float list[], int first, int last)
{
        int lower=first;
        int upper=last+1;
        float pivotvalue=list[first];
        do
        {
                do
                {
                        upper--;
                        //counts++;
                }
                while (list[upper]>pivotvalue);
                do
                {
                        lower++;
                        //counts++;
                }
                while (list[lower]<pivotvalue);
                Swap(&edgeArr[upper],&edgeArr[lower]);
                Swap(&newWeitEd[upper],&newWeitEd[lower]);
                //counts;
        }
        while (lower<upper);
        Swap(&edgeArr[upper],&edgeArr[lower]);
        Swap(&newWeitEd[upper],&newWeitEd[lower]);
        Swap(&edgeArr[first],&edgeArr[upper]);
        Swap(&newWeitEd[first],&newWeitEd[upper]);
        return upper;
}

void QuickSortMST(float list[], int first, int last)
{
        if (first<last)
        {
                int pivot=PivotListMST(list,first,last);
                QuickSortMST(list, first, pivot-1);
                QuickSortMST(list,pivot+1,last);
        }
}

//Delete quaClu-1 edges to receive quaClu Clusters
void DelEdgMST(){
     for (int i = n-1; i >= n-quaClus+1; i--){
         edgeArr[i]=0; 
         fEnd[edgeArr[i]]=0;
         lEnd[edgeArr[i]]=0;
         }
}

//Print the clusters
void PrintClusters()
{
    cout<<endl<<"___________________________________________\n";   
	int i;
	
	printf("The clusters as an image of connected components:\n");
	for(i=1;i<=n-1;i++)
    if (edgeArr[i]!=0)
			printf("%d->%d--%f\n",fEnd[edgeArr[i]],lEnd[edgeArr[i]],weitEd[edgeArr[i]]);
}

int main(){
	InputData();
	StructureGraph();	
	QuickSort(weitEd,1,m);
	PrintEd();
	SpanTree();
	PrintTree();
	QuickSortMST(newWeitEd,1,n-1);
	DelEdgMST();
	PrintClusters();
	getch();
	return 0;
}
