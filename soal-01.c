#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct matriks{
    float i, j, k;
} vektor;

float vectorLength (vektor a){
//Menentukan panjang vektor
    return (sqrt(pow(a.i, 2)+pow(a.j, 2)+pow(a.k, 2)));
}

vektor crossProduct(vektor a, vektor b){
//Menentukan hasil perkalian cross
    vektor result;
    result.i = (a.j)*(b.k) - (a.k)*(b.j);
    result.j = (a.k)*(b.i) - (a.i)*(b.k);
    result.k = (a.i)*(b.j) - (a.j)*(b.i);
    return result;
}

float dotProduct(vektor a, vektor b){
//Menentukan hasil perkalian dot
    return ((a.i)*(b.i)+(a.j)*(b.j)+(a.k)*(b.k));
}

void printVector(vektor a){
//Mencetak vektor ke layar
    if(a.i>=0){
        printf("%.2fi", a.i);
    } else{
        printf("- %.2fi", ((-1)*a.i));
    }
    if(a.j>=0){
        printf(" + %.2fj", a.j);
    } else{
        printf(" - %.2fj", ((-1)*a.j));
    }
    if(a.k>=0){
        printf(" + %.2fk", a.k);
    } else{
        printf(" - %.2fk", ((-1)*a.k));
    }
    printf("\n");
}

vektor vectorProjection(vektor a, vektor b){
//Menentukan vektor proyeksi orthogonal
    vektor result;
    float dot;
    dot = dotProduct(a, b)/pow(vectorLength(b), 2);
    result.i = dot*(b.i);
    result.j = dot*(b.j);
    result.k = dot*(b.k);
    return result;
}

int main(){
    char msg;
    int n, i;
    vektor *vec;
    vektor F;
    vec = malloc(100 * sizeof(vektor));

    msg = 'y';
    n = 1;
    printf("Vektor %d\n", n);

    while(msg != 'n'){
        //input vektor
        printf("Masukkan komponen i: ");
        scanf("%f", &vec[n-1].i);
        printf("Masukkan komponen j: ");
        scanf("%f", &vec[n-1].j);
        printf("Masukkan komponen k: ");
        scanf("%f", &vec[n-1].k);
        printf("Vektor %d : ", n);
        printVector(vec[n-1]);
        printf("Masukkan vektor lagi? [y/n]: ");
        scanf(" %c", &msg);

        if(msg=='y'){
            n++;
            printf("\nVektor %d\n", n);
        } else{
            printf("\nMenghitung fungsi F.....\n");
        }
    }

    i = 0;
    F = vec[0];
    if(n==2){
        //Kasus 2 vektor
        F = crossProduct(F, vec[1]);
    } else{
        //Kasus lebih dari 2 vektor
        for(i=1; i<n-1; i++){
            F = vectorProjection(F, vec[i]);
        }
        F = crossProduct(F, vec[n-1]);
    }

    printf("Vektor hasil fungsi F = ");
    printVector(F);
    free(vec);
}
