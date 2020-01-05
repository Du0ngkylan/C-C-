/*
 * binaryTree.c
 *
 *  Created on: Aug 11, 2013
 *      Author: BlueWhale
 */

/*
 * Tao cau truc cay nhi phan tim kiem
 * 1/ Nhap mot so nguyen vao va tim xem co nut nao chua so nguyen do hay khong?
 * 2/ Nhap 2 so nguyen p va q va kiem tra xem p co phai la to tien cua q hay kong?
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Khai bao cau truc cua moi nut
typedef struct Node {
	int datum;
	struct Node * left;
	struct Node * right;
} Node;

typedef struct Node * Tree;

//Not goc cua cay se khoi tao
Tree root = NULL;

//Tao mot nut mang du lieu la datum
Tree createNode(int datum) {
	Tree node = (Tree) malloc(sizeof(Node));
	if (node != NULL) {
		node->datum = datum;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

//Them mot nut moi vao cay co goc la root
void addNode(Tree * root, int datum) {
	if ((*root) == NULL) {
		Tree node = createNode(datum);
		*root = node;
	} else {
		if ((*root)->datum >= datum) {
			addNode(&((*root)->left), datum);
		} else {
			addNode(&((*root)->right), datum);
		}
	}
}

int n; //So phan tu cua mang nhap vao
int a[100]; //Mang nhap vao

//Nhap so phan tu va mang tu ban phim
void inputData() {
	printf("Nhap so phan tu: n = ");
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		printf("Nhap phan tu a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

//Tao cay tim kiem nhi phan co cac nut mang cac phan tu cua mang nhap vao
void createTree(Tree * root) {
	int i;
	for (i = 0; i < n; i++) {
		addNode(root, a[i]);
	}
}

//Vieng tham nut tree va in gia tri cua nut do
void visit(Tree tree) {
	printf(" %d", tree->datum);
}

//Duyet theo kieu tien to dung de quy
void preOrder(Tree tree) {
	if (tree != NULL) {
		visit(tree); //Tham nut goc dau tien
		preOrder(tree->left); //Tham cay con ben trai
		preOrder(tree->right); //Tham cay con ben phai
	}
}

/* Tim nut goc co chua gia tri la datum
 * Neu cay co chua nut do thi ham tra ve gia tri la dia chi nut do
 * Neu khong co thi ham se tra ve gia tri NULL.
 */
Tree findNode(Tree root, int datum) {
	if (root == NULL) {
		return NULL;
	} else {
		if (root->datum == datum) { //Neu nut dang xet la root chua datum thi ta gan
									//root cho ham
			return root;
		} else { //Trai lai se tim o cay con ben trai va ben phai
			Tree leftTree = findNode(root->left, datum); //leftTree la ket qua tim o cay con ben trai
			if ( leftTree != NULL) {
				return leftTree;
			} else { //Khong tim thay o cay con ben trai
				Tree rightTree = findNode(root->right, datum); //rightTree la ket qua tim o cay con ben phai
				if ( rightTree != NULL) {
					return rightTree;
				}
			}
		}
	}
	return NULL;
}

//Kiem tra xem p co phai la to tien cua q hay khong
void testAncestor(int p, int q) {
	//Tim o cay co goc chua nut p (findNode(root, p)) xem no co chua nut q hay khong
	if (findNode(findNode(root, p), q) == NULL) {
		printf("\n%d khong phai la to tien cua %d", p, q);
	} else {
		printf("\n%d la to tien cua %d", p, q);
	}
}

//Dem so con cua mot nut cho truoc
void countDescendant(int * count, Tree tree) {
	if (tree != NULL) {
		(*count)++;
		countDescendant(count, tree->left);
		countDescendant(count, tree->right);
	}
}

//Tim chieu cao cua cay con co nut bat dau la tree
int height;//Bien nay bang chieu cao cong them 1
void findHeight(Tree tree, int currentHeight) {
	if (tree == NULL) {
		if (currentHeight > height) {
			height = currentHeight;
		}
	} else {
		findHeight(tree->left, currentHeight + 1);
		findHeight(tree->right, currentHeight + 1);
	}
}

//Kiem tra mot cay nhi phan co la day du
int testFull = 1; //Bien kiem tra cay nhi phan day du, no bang 1 neu cay da cho day du, va bang 0 neu trai lai
				  //Ban dau mac dinh bien nay bang 1
void TestFullBT(Tree tree) { //Ham kiem tra cay nhi phan day du
	if (tree == NULL)
		return;
	if ((tree->left == NULL) & (tree->right != NULL)) { //Neu co cay con ben phai ma khong co cay con ben trai
														//thi cay khong day du, gan testFull = 0
		testFull = 0;
	} else {
		if ((tree->left != NULL) & (tree->right == NULL)) { //Neu co cay con ben trai ma khong co cay con ben phai
															//thi cay khong day du, gan testFull = 1
			testFull = 0;
			return;
		} else { //Tam thoi dang thoa man dieu kien day du
			TestFullBT(root->left); //Kiem tra tiep cay con ben trai
			TestFullBT(root->right); //Kiem tra tiep cay con ben phai
		}
	}
}

//Kiem tra cay nhi phan co la hoan hao
int testPerfect = 1; //Bien kiem tra, bang 1 neu cay la hoan hao va bang 0 neu trai lai,
					// ban dau mac dinh bien nay bang 0
void testPT(Tree tree) { //Ham kiem tra cay con tree co la hoan hao
	if (tree == NULL) { //Neu cay con la rong thi thoat ra
		return;
	} else {
		findHeight(tree->left, 0);
		int leftHeight = height; //Chieu cao cua cay con ben trai cua tree
		findHeight(tree->right, 0);
		int rightHeight = height; //Chieu cao cua cay con ben phai cua tree
		if (leftHeight != rightHeight) { //Neu chieu cao cua cay con ben trai khac chieu cao cua cay con
										 //ben phai thi khong thoa man dieu kien cua cay hoan hao
			testPerfect = 0;
		} else { //Trai lai thi tam thoi dang thoa man dieu kien cua cay hoan hao
			testPT(tree->left); //Kiem tra tiep cay con ben trai
			testPT(tree->right); //Kiem tra tiep cay con ben phai
		}
	}
}

int main() {
	setbuf(stdout, NULL);

	inputData();
	createTree(&root);
	preOrder(root);

	//Nhap mot so nguyen vao va kiem tra xem cay co goc la root co nut nao chua no hay khong
//	int findInt; //Gia tri cua nut can kiem tra
//	printf("\n Nhap gia tri nut can kiem tra: ");
//	scanf("%d", &findInt);
//	if (findNode(root, findInt) != NULL){
//		printf("Tim duoc nut co chua %d", findInt);
//	} else {
//		printf("Khong tim duoc nut co chua %d", findInt);
//	}

	//Nhap va kiem tra xem p co phai la to tien cua q
//	int p, q;
//	printf("\nNhap hai so nguyen:\n");
//	printf("p = ");
//	scanf("%d",&p);
//	printf("q = ");
//	scanf("%d",&q);
//	testAncestor(p, q);

	//Nhap mot so nguyen p, kiem tra xem no co trong cay hay khong
	//va dem so con chau cua p
//	int descendantQuantity = 0;
//	int p;
//	printf("\n Nhap so nguyen can kiem tra: ");
//	scanf("%d", &p);
//	Tree nodeP = findNode(root, p);
//	if ( nodeP != NULL) {
//		printf("\n %d co trong cay", p);
//		countDescendant(&descendantQuantity, nodeP);
//		descendantQuantity--;
//		printf("\n So con chau cua p la %d", descendantQuantity);
//
//		printf("\n Cac con chau cua p la: \n");
//		preOrder(nodeP->left);
//		preOrder(nodeP->right);
//	} else {
//		printf("\n %d khong co trong cay", p);
//	}

	//Nhap mot so nguyen p tu ban phim va tim chieu cao cua cay con co  nut goc la so nguyen vua nhap
//	int p;
//	printf("\nNhap nut can tim chieu cao: ");
//	scanf("%d", &p);
//	findHeight(findNode(root, p), 0);
//	printf ("chieu cao cua cay con cua nut vua nhap la %d", height - 1);

	//Kiem tra xem cay nhi phan da cho co la hoan hao hay khong
	testPT(root);
	if (testPerfect == 1) {
		printf("\n Cay nhi phan da cho la hoan hao");
	} else {
		printf("\n Cay nhi phan da cho la khong hoan hao");
	}


	//Kiem tra cay nhi phan co la day du hay khong
	TestFullBT(root);
	if (testFull == 1) {
		printf ("\n Cay nhi phan da cho la day du");
	} else {
		printf ("\n Cay nhi phan day cho khong day du");
	}
	getch();
	return 0;
}

