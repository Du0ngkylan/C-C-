
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int n, m, maTranKe[100][100], mangDanhDau[100], nganXep[100], xp, dich, t;
char *fi="dothi.txt";
void docTep() {
	FILE *f;
	int i, j, k;

	f = fopen(fi, "r");
	if (f == NULL) {
		printf("Loi doc tep");
		exit(0);
	}

	fscanf(f, "%d%d", &n, &m);

	for (k = 1; k <= m; k++) {
		fscanf(f, "%d%d", &i, &j);
		maTranKe[i][j] = 1;
	}

	fclose(f);
}

void lietKe(int k) {
	int i, j, kiemTraDaQuaTChua;
	if (k > n)
		return;
	if (nganXep[k] == dich) {
		kiemTraDaQuaTChua = 0;
		for (j = 1; j <= k; j++)
			if (nganXep[j] == t)
				kiemTraDaQuaTChua = kiemTraDaQuaTChua + 1;

		if (kiemTraDaQuaTChua > 0) {
			for (j = 1; j <= k - 1; j++) {
				printf("%d -> ", nganXep[j]);
			}
			printf("%d\n", nganXep[k]);
		}
		return;
	}
	for (i = 1; i <= n; i++) {
		if (mangDanhDau[i] == 0 && maTranKe[nganXep[k]][i] == 1) {
			nganXep[k + 1] = i;
			mangDanhDau[i] = 1;
			lietKe(k + 1);
			mangDanhDau[i] = 0;
		}
	}
}
 int main() {
	int i;

	docTep();

	printf("Nhap dinh xp, dich , t:\n");
	scanf("%d%d%d", &xp, &dich, &t);

	for (i = 1; i <= n; i++)
		mangDanhDau[i] = 0;
	mangDanhDau[xp] = 1;
	nganXep[1] = xp;
	lietKe(1);
	getch();
	
}

