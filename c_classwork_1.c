#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct student {
    char surname[20]; // nazwisko
    int album; // nr albumu
    int dept; // kod wydzialu
};

void print (struct student t[], int n) {

    for (int i=0; i<n; i++) printf("%s %d %d\n", t[i].surname, t[i].album, t[i].dept);

}

void print_tab (int tab[], int n) {
    for (int i=0; i<n; i++) printf ("%d ", tab[i]);
    printf("\n");
}


int department (struct student x) {
    return x.dept;
}

int compare (const void* a, const void* b) {
    struct student* aa = (struct student *) a;
    struct student* bb = (struct student *) b;
    if (department(*aa) == department(*bb)) return 0;
    else if (department(*aa) < department(*bb)) return -1;
    else return 1;
}

int main(void) {
    int N;
    scanf("%d", &N);

    struct student* lista = (struct student*) malloc (N * sizeof(*lista));

    int lw = 0;

    for (int i=0; i<N; i++) {
        int same = 0;
        scanf("%s", lista[i].surname);
        scanf("%d", &lista[i].album);
        scanf("%d", &lista[i].dept);
        if (i>0) {
            for (int j=0; j<i; j++) {
                if (lista[j].dept == lista[i].dept) same = 1;
            }
        }
        if (!same) lw++;
    }

    qsort(lista, N, sizeof(*lista), compare);
//    printf("\nPosortowana lista: \n");
//    print(lista, N);
    printf("\n\nLiczba wydzialow: %d \n", lw);

    struct student** array_2 = (struct student**) malloc (lw * sizeof(struct student *));

    int *lenw = (int*) malloc (lw * sizeof(*lenw));

    for (int i=0; i<lw; i++) lenw[i] = 1;

    int tmp, j = 0;

    for (int i = 0; i < lw; i++) {
        tmp = j;
        while (lista[j].dept != i) j++;
        lenw[i-1]=(j-tmp);
        array_2[i] = &lista[j];
    }
    lenw[lw-1] = N - j;

    printf("\n LENW: \n");
    print_tab(lenw, lw);

    printf("\n\n");

    int num_dept;
    scanf("%d", &num_dept);


//    int i = 0;
//    for (i = 0; i<N; i++) {
//		if (lista[i].dept == num_dept)
//			break;
//	}

    printf("Students of this department: \n");

    struct student* k = array_2[num_dept];
    for (int i=0; i<lenw[num_dept]; i++) {
        printf("%s %d %d\n", (k+i)->surname, (k+i)->album, (k+i)->dept);
    }
    printf("\n");

}
