#include <stdio.h>
#include <stdlib.h>

void merge(int valores[], int numeroMenor, int numeroMaior, int media){


}


void mergeSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int media = (inicio + fim)/2;
        mergeSort(vetor, inicio, media); //fazendo a divisão ao meio pela esquerda
        mergeSort(vetor, media+1, fim); //fazendo a divisão ao meio pela direita


    }
}



int main(){
    return 0;

}