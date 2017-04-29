/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tassio
 *
 * Created on 25 de Março de 2017, 17:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10], inicio, fim, meio;

void intercala(int *a, int inicio, int meio, int fim) {

    int i, j, k, *t;
    // intercalacao no vetor temporario t
    i = inicio;
    j = meio + 1;
    k = 0;
    t = (int *) malloc(sizeof (int) * (fim - inicio + 1));

    while (i < meio + 1 || j < fim + 1) {
        if (i == meio + 1) { // i passou do final da primeira metade, pegar v[j]
            t[k] = a[j];
            j++;
            k++;
        } else {
            if (j == fim + 1) {
                // j passou do final da segunda metade, pegar v[i]
                t[k] = a[i];
                i++;
                k++;
            } else {
                if (a[i] < a[j]) {
                    t[k] = a[i];
                    i++;
                    k++;
                } else {
                    t[k] = a[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for (i = inicio; i <= fim; i++) {
        a[i] = t[i - inicio];
    }
    free(t);
}

void mergeSort(int *a, int inicio, int fim) {
    int meio;
    if (inicio == fim) return;

    // ordenacao recursiva das duas metades
    meio = (inicio + fim) / 2;
    mergeSort(a, inicio, meio);
    mergeSort(a, meio + 1, fim);
    intercala(a, inicio, meio, fim);

}

int main(int argc, char** argv) {

    srand(time(NULL));
    for (int t = 1; t <= 10; t++) {
        a[t] = rand() % 10;
    }
    inicio = 1;
    fim = 10;

    printf("Entrada = ");
    for (int t = 1; t <= 10; t++) {
        printf("%d ", a[t]);
    }

    printf("\nOdenação = ");
    mergeSort(a, inicio, fim);
    for (int t = 1; t <= 10; t++) {
        printf("%d ", a[t]);
    }

    return (EXIT_SUCCESS);
}

