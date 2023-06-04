//
//  main.cpp
//  antesExamen
//
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;


struct nodo{
    int nDato;
    struct nodo *PtrSig;
};

//operaciones con la pila
typedef nodo nodoPila;
typedef nodoPila *PtrNodoPila;

//Funciones
void push(PtrNodoPila *PtrCima, int nDato);
int pop(PtrNodoPila *PtrCima);
void ImprimirPila(PtrNodoPila ptrActual);


//int pilaLlena();
//int pilaVacia();

int main(int argc, const char * argv[]) {
    
    PtrNodoPila ptrPila = NULL;
    push(&ptrPila, 25);
    
    PtrNodoPila ptrActual = ptrPila;
    ImprimirPila(ptrActual);
    
    //PtrNodoPila temp = ptrPila;
    
    //pop(&temp);
    
    ImprimirPila(ptrActual);
    return 0;
}

/*void push(PtrNodoPila PtrCima, int nDato){
    PtrNodoPila PtrNuevo;
    
    //Asigna espacio para almacenar datos
    PtrNuevo = (PtrNodoPila)malloc(sizeof(nodoPila));
    
    if(PtrNuevo !=NULL){
        PtrNuevo->nDato = nDato;//Asigna dato
        PtrNuevo->PtrSig=PtrCima;//Crea enlace
        PtrCima = PtrNuevo;//enlaza
    }else{
        cout<<"No fue posible asignar memoria dinamica";
    }
}*/


void push(PtrNodoPila *ptrCima, int entry){
    PtrNodoPila ptrNuevo; /** Apuntador al nuevo nodo */
    ptrNuevo = (PtrNodoPila)malloc(sizeof(nodoPila));
    /** Inserta el nuevo nodo encima de la pila */
    if(ptrNuevo != NULL){
        ptrNuevo -> nDato = entry;
        ptrNuevo -> PtrSig = *ptrCima;
        *ptrCima = ptrNuevo;
    }else{
        printf("%d No se inserto. Memoria insuficiente. \n",entry);
    }
}

int pop( PtrNodoPila *ptrCima ) {
    PtrNodoPila TempPtr;
    int TempnDato;
    TempPtr = *ptrCima;
    TempnDato = (*ptrCima)->nDato;
    *ptrCima = (*ptrCima)->PtrSig;
    free(TempPtr);
    return TempnDato;
}

/*void ImprimirPila(PtrNodoPila ptrActual){
    if(ptrActual == NULL){
        cout<<"La pila esta vacia\n";
    }else{
        while(ptrActual !=NULL){
            printf("%d ->", ptrActual->nDato);
            ptrActual = ptrActual->PtrSig;
        }
    }
}*/

void ImprimirPila(PtrNodoPila ptrActual){
    cout << ptrActual << endl;
}


