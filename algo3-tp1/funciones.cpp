//
// Created by Luca on 9/11/2018.
//
#include "funciones.h"



int min(int x,int y){ return (x) < (y) ? x : y; }

int sumarUno(int x){return x==INT32_MAX ? INT32_MAX : x+1;}

int optimo(int x, int y){
    if(x == -1){
        return y;
    }
    if( y == -1){
        return x;
    }
    return min(x,y);
}


int solveFuerzaBruta(vector<int>& elementos, int objetivo){

    int suma,aux;

    int cantidad = -1;

    int lim = pow(2.0,(float)elementos.size())-1;

    for (int i=1; i < lim ;i++){
        suma = 0;
        aux = 0;

        bitset<32> bin(i);

        for (int j = 0; j<32;j++){
            if(bin[j]){
                suma = suma + elementos[j];
                aux++;
            }
        }

        if(suma == objetivo){
            if(aux < cantidad or cantidad == -1){
                cantidad = aux;
            }
        }
    }

    return cantidad;
}


bool factibilidad(vector<int> elem,int obj){
    int res=0;
    for(int i=0;i<elem.size();i++){
        res += elem[i];
        if(res>= obj){
            return true;
        }
    }
    return false;

}

int solveBacktracking(vector<int> &elementos, int objetivo){

    int min = elementos.size()+1;
    vector<bool> usados (elementos.size(),true);
    int suma = 0;

    for (int i = 0; i < elementos.size(); i++) {
        suma += elementos[i];
    }

    fBacktracking(elementos,usados,objetivo,min,suma);
    return min;
}

int cantUsados(vector<bool> s){
    int res =0;
    for(auto it=s.begin();it!=s.end();it++){
        if(*it){
            res++;
        }
    }
    return res;
}

void fBacktracking(vector<int> &elementos, vector<bool> &usados,int objetivo,int& min, int suma){

    int res = cantUsados(usados);

    if(min>res){
        if(suma == objetivo){
            min = res;
        }
    }


    for(int i=0;i<elementos.size() ;i++){

        if(usados[i]) {
            if (suma - elementos[i] >= objetivo) {
                usados[i] = false;
                fBacktracking(elementos, usados, objetivo, min, suma - elementos[i]);
                usados[i] = true;
            }
        }

    }


}

int solveDinamica(vector<int> &elementos, int objetivo){

    vector<vector<int> > yaCalculados(objetivo+1,vector<int>(elementos.size()+1,-1));

    int res = fDinamica(elementos,yaCalculados,objetivo,elementos.size());

    return res != INT32_MAX ? res : -1;
}


int fDinamica(vector<int>& elem, vector<vector<int> > &yaCalculados, int obj, int i){

    if (yaCalculados[obj][i] == -1){
        if(i==0 and obj==0)
        { yaCalculados[obj][i] = 0;}
        if(i==0 and obj!=0)
        { yaCalculados[obj][i] = INT32_MAX;}
        if(i>0 and elem[i-1]>obj)
        { yaCalculados[obj][i] = fDinamica(elem,yaCalculados,obj,i-1);}
        if(i>0 and elem[i-1]<= obj)
        { yaCalculados [obj][i]= min(fDinamica(elem,yaCalculados,obj,i-1),sumarUno(fDinamica(elem,yaCalculados,obj-elem[i-1],i-1)));}
    }

    return  yaCalculados[obj][i];

}



int solveBacktrackingIterativo(vector<int> &elementos, int objetivo){

    int suma,aux;

    int cantidad = -1;

    for (int i=1; i < pow(2.0,(float)elementos.size()) ;i++){
        suma = 0;
        aux = 0;

        bitset<32> bin(i);

        for (int j = 0; j<32 and suma<objetivo and (aux < cantidad or cantidad == -1);j++){
            if(bin[j]==1){
                suma = suma + elementos[j];
                aux++;
            }
        }

        if(suma == objetivo){
            if(aux < cantidad or cantidad == -1){
                cantidad = aux;
            }
        }
    }
    return cantidad;
}


