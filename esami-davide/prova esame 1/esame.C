#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "TApplication.h" 
#include "TGraph.h"
#include "TMarker.h"
#include "dlcgold.h"

using namespace std;



int main (int argc, char**argv){

int conta=0;

fstream ingresso,uscita;

ingresso.open("punti.dat",ios::in);
uscita.open("xy.dat",ios::out);

punto *a=new punto [1];	
	int N=1;
	ingresso>>a[0].x>>a[0].y>>a[0].m;
	while(!ingresso.eof()){  
		punto *vN=new punto [++N];
		for (int i=0;i<N-1;i++)
			vN[i]=a[i];
		delete a;
		a=vN;
		ingresso>>a[N-1].x>>a[N-1].y>>a[N-1].m;
	}
cout<< "I punti sono "<< N-1<<endl;
cout<<endl;
int n=N-1;
cout<<"******************************i miei punti hanno le seguenti caratteristiche:******************************"<<endl;
for(int u=0;u<n;u++)
cout<<"coordinata x: "<<a[u].x<<"\t coordinata y: "<<a[u].y<<"\t massa del punto: "<<a[u].m<<endl;


float massimo, minimo;
maxmin (a,n,&minimo,&massimo);

cout<<endl;
cout<<"il minimo delle masse è: "<<minimo<<" e il massimo è: "<<massimo<<endl;

cout<<endl;

float xcm,ycm;
centromassa(a, n-1, & xcm, & ycm);

cout<<"******************************ecco i dati del centro di massa del sistema di punti********************************"<<endl;
cout<<"coordinata x: "<<xcm<<"\t coordinata y: "<<ycm<<endl;

cout<<endl;


distanze (a, n, xcm, ycm);
quick (a,0, n);
cout<<"*********************ecco i punti in ordine secondo la distanza dal centro di massa*******************************"<<endl;
cout<<endl;
for(int i=0;i<n-1;i++)
	cout<<"coordinata x: "<<a[i].x<<" \t coordinata y: "<<a[i].y<<"\t valore massa: "<<a[i].m<<"\t valore distanza dal centro di massa: "<< a[i].dist<<endl;



float sigma=Deviazione(a, n);
	cout<<"La deviazione standard delle distanze è: "<<sigma<<endl;


float media=Media(a,n);
	cout<<"La media delle distanze è: "<<media<<endl;


for(int i=0;i<n-1;i++){
		if (a[i].dist>2*sigma)
			a[i].dist=666;
	}
	punto*vn=new punto[n];
	int j=0;
	for (int i=0;i<n-1;i++){
		if(a[i].dist!=666){
			vn[j].x=a[i].x;
			vn[j].y=a[i].y;
			vn[j].m=a[i].m;
			vn[j].dist=a[i].dist;			
			j++;
		}
	}

delete a;
	a=vn;
	cout<<"Ne sono sopravvissuti "<<j+1<<endl;
cout<<endl;

cout<<"*********************ecco i punti sopravvissuti sono*******************************"<<endl;
cout<<endl;

for(int i=0;i<j;i++){
		cout<<"coordinata x: "<<a[i].x<<" \t coordinata y: "<<a[i].y<<"\t valore massa: "<<a[i].m<<"\t valore distanza dal centro di massa: "<< a[i].dist<<endl;
uscita<<a[i].x<<"  "<<a[i].y<<endl;

}
cout<<endl;
cout<<"*********************************sto disegnando************************************"<<endl;
cout<<endl;

float *vettx=new float[n];
float *vetty=new float[n];
 
fstream dati;
dati.open("xy.dat",ios::in);
float var;
int z=0;
dati>>vettx[z]>>vetty[z];

while(!dati.eof()){
z++;
dati>>vettx[z]>>vetty[z];
}



TApplication app("App",&argc, argv);


TGraph *retta = new TGraph(j,vettx, vetty);

//retta->SetMarkerStyle(21);
 

retta->Draw("A*");

app.Run();



return 0;
}
