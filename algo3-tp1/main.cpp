#include <iostream>
#include <vector>
#include <chrono>
#include "funciones.h"

using namespace std;

int main() {

    bool outputLindo = true;

    /*
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;*/

    int n,obj;
    //cin >> n >>obj;

    vector<int> elementos;

    /*for (int i=0;i<n;i++){
        int valor;
        cin >> valor;
        elementos.push_back(valor);
    }*/

    n = 8;
    obj = 45;

    elementos.push_back(10);
    elementos.push_back(5);
    elementos.push_back(15);
    elementos.push_back(25);
//    elementos.push_back(5);
//    elementos.push_back(10);
//    elementos.push_back(5);
//    elementos.push_back(10);
//    elementos.push_back(10);
//    elementos.push_back(5);
//    elementos.push_back(10);
//    elementos.push_back(15);
//    elementos.push_back(20);




    if(outputLindo){

    auto startFuerzaBruta = chrono::steady_clock::now();
    int solFuerzaBruta = solveFuerzaBruta(elementos,obj);
    auto endFuerzaBruta = chrono::steady_clock::now();
    auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
    cout << "Fuerza bruta: " << solFuerzaBruta << endl;
    cout << "Tiempo utilizado por Fuerza Bruta:" <<chrono::duration <double, micro> (diffFuerzaBruta).count() << " microsegs" << endl;

    cout << endl;
    cout << endl;
    auto startBacktracking = chrono::steady_clock::now();
    int solBacktracking = solveBacktracking(elementos,obj);//,INT16_MAX);
    auto endBacktracking = chrono::steady_clock::now();
    auto diffBacktracking = endBacktracking - startBacktracking;
    cout << "Backtracking: " << solBacktracking << endl;
    cout << "Tiempo utilizado por Backtracking " <<chrono::duration <double, micro> (diffBacktracking).count() << " microsegs" << endl;


    cout << endl;
    cout << endl;
    auto startBacktrackingIterativo = chrono::steady_clock::now();
    int solBacktrackingIterativo = solveBacktrackingIterativo(elementos,obj);
    auto endBacktrackingIterativo = chrono::steady_clock::now();
    auto diffBacktrackingIterativo = endBacktrackingIterativo - startBacktrackingIterativo;
    cout << "Backtracking Iterativo: " << solBacktrackingIterativo << endl;
    cout << "Tiempo utilizado por Backtracking Iterativo: " <<chrono::duration <double, micro> (diffBacktrackingIterativo).count() << " microsegs" << endl;

    cout << endl;
    cout << endl;
    auto startDinamica = chrono::steady_clock::now();
    int solDinamica = solveDinamica(elementos,obj);
    auto endDinamica = chrono::steady_clock::now();
    auto diffDinamica = endDinamica - startDinamica;
    cout << "Dinamica: " << solDinamica << endl;
    cout << "Tiempo utilizado por Dinamica " <<chrono::duration <double, micro> (diffDinamica).count() << " microsegs" << endl;
    }

    else{

    auto startFuerzaBruta = chrono::steady_clock::now();
    //int solFuerzaBruta = solveFuerzaBruta(elementos,obj);
    auto endFuerzaBruta = chrono::steady_clock::now();
    auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
    cout << elementos.size()  << ',' <<chrono::duration <double, micro> (diffFuerzaBruta).count();

    auto startBacktracking = chrono::steady_clock::now();
    //int solBacktracking = solveBacktracking(elementos,obj);
    auto endBacktracking = chrono::steady_clock::now();
    auto diffBacktracking = endBacktracking - startBacktracking;
    cout << ',' <<chrono::duration <double, micro> (diffBacktracking).count();

    auto startDinamica = chrono::steady_clock::now();
    int solDinamica = solveDinamica(elementos,obj);
    auto endDinamica = chrono::steady_clock::now();
    auto diffDinamica = endDinamica - startDinamica;
    cout << ',' <<chrono::duration <double, micro> (diffDinamica).count();

    auto startBacktrackingIterativo = chrono::steady_clock::now();
    int solBacktrackingIterativo = solveBacktrackingIterativo(elementos,obj);
    auto endBacktrackingIterativo = chrono::steady_clock::now();
    auto diffBacktrackingIterativo = endBacktrackingIterativo - startBacktrackingIterativo;
    cout << ',' <<chrono::duration <double, micro> (diffBacktrackingIterativo).count();
    }

    return 0;
}