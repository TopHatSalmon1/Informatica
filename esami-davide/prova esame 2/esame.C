#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "TApplication.h" 
#include "TGraph.h"
#include "dlcgold.h"

int main(int argc, char**argv){

int conta=0;
float var;

fstream ingresso;
fstream ingresso2;
	ingresso.open("dati.dat",ios::in);
	ingresso>>var;

	while(!ingresso.eof()){
	conta++;
	ingresso>>var;

	}

ingresso.close();
ingresso.clear();
ingresso.open("dati.dat",ios::in);
ingresso2.open("dati.dat",ios::in);
int conta2=0;
int n=50+1;
int j=conta-n;
float min, max, nmin, nmax;

float *punti=new float [conta];
float *npunti=new float [conta];
float *ascisse=new float [n];
		for(int i=conta+1;i>=0;i--)
		ingresso>>punti[i];
			//for(int i=1;i<n;i++)
			//cout<<punti[i]<<endl;


			for(int i=0;i<n;i++)
			ascisse[i]=i+0;	
			
	for(int i=0;i<n;i++){

		float d=sqrt(1+pow(punti[i+1]-punti[i],2));
		if(i==0){
				max=d;
				min=d;
			}
				if(max<d){
					max=d;
						  }
				
						if(min>d){
						min=d;
							}
				}	
			cout<<"il minimo delle distanze tra i punti è: "<<min<<endl;
			
			cout<<"il massimo delle distanze tra i punti è: "<<max<<endl;
cout<<endl;
for(int i=conta+1;i>=0;i--)
		ingresso2>>npunti[i];

bubblef(n,npunti);

cout<<"***********************ecco il vettore riordinato e il vettore originale**********************"<<endl;

for(int i=0;i<n;i++)
cout<<"i punti del vettore riordinato sono: "<<npunti[i]<<"\t e i punti del vettore sono: "<<punti[i]<<endl;

for(int i=0;i<n;i++){

		float nd=sqrt(1+pow(npunti[i+1]-npunti[i],2));
		if(i==0){
				nmax=nd;
				nmin=nd;
			}
				if(nmax<nd){
					nmax=nd;
						  }
				
						if(nmin>nd){
						nmin=nd;
							}
				}	
			cout<<endl;
			cout<<"il minimo delle distanze tra i punti riordinati è: "<<nmin<<endl;
			
			cout<<"il massimo delle distanze tra i punti riordinati è: "<<nmax<<endl;
cout<<endl;

TApplication app("App",&argc, argv);


TGraph *retta = new TGraph(n,ascisse, punti);


 

retta->Draw("A*");

app.Run();

return 0;
}
