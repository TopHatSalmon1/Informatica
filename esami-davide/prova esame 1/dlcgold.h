#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct punto{

float x,y,m,dist;

};

float media2float(float, float);
float varianza2float(float,float);
int giocaComputer();
int caricaDati(float [],int);
void stampa(float [], int);
void swapArrayFloat(float [],int, int);
void bubble(int [], int);
void scambia2(int [], int);
float acaso01();
float acasoAB(float,float);
float generaFloat(float , float);
void inizializzaRand();
float mediavett( float[] , int  );
float stdDevvett( float[] , int   );
void merge(int [],int,int,int);
void merge_sort(int[],int, int);
int binaria(int*, int,  int );
int binarySearch(int [], int, int, int);
int resize(int **, int, int);
void selectionsort(int list[], int lenght);
int sequenziale(int [], int , int);
double max(const int , double []);
double min(const int , double []);
int perm(int [], int );
float sommaquad(float[], int);
float distanza(float, float, float, float);
void printVettInt(int [], int);
void mergep(int *,int,int,int);
void merge_sortp(int*,int, int);
float maxf(int , float []);
float minf(int , float []);			
void bubblef(int, float []);		
void scambia2f(int, float []);
void maxmin (punto*,int, float*, float*);
void sommatorie (punto*,int, float*, float*, float*);
void centromassa (punto*, int, float*, float*);
void distanze (punto*, int , float , float );
void quick (punto*,int, int);
void Scambiostruct (punto*, int, int);
float Deviazione(punto*, int );
float Media (punto*, int );
