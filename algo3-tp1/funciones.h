

#ifndef TP1_FUNCIONES_H
#define TP1_FUNCIONES_H
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

vector<int> decToBin(int n);
int min(int X,int Y);
int optimo(int x, int y);
int sumarUno(int x);

int solveFuerzaBruta(vector<int> &elementos, int objetivo);

int solveBacktracking(vector<int> &elementos, int objetivo);
void fBacktracking(vector<int> &elementos, vector<bool> &usados, int objetivo, int &min, int suma);
int solveBacktrackingIterativo(vector<int> &elementos, int objetivo);

int fDinamica(vector<int>& elem, vector<vector<int> > &yaCalculados, int obj, int i);
int solveDinamica(vector<int> &elementos, int objetivo);



#endif //TP1_FUNCIONES_H
