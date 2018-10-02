#include "dlcgold.h"


float media2float(float a, float b){        
	int N=2;
	float m2float=(a+b)/N;
	return m2float; 	
	
 }


//***************************************************************************


float varianza2float(float ab, float mm){       //aa=a*a;
						//bb=b*b;
						//float ab=a+b;
	int N=2;
		float var2float=(mm/N)-((ab/N)*(ab/N));
return var2float;
}


//**************************************************************************

int giocaComputer(){

    int caso;

    srand(time(NULL));

    caso = rand();

    return caso%99;

}


//**************************************************************************

int caricaDati(float d[],int dimMax){

    int num;
    
    do{
    cout << endl <<"Quanti dati? (Max: " << dimMax <<")" <<endl;
    cin >>num;
    }while(num > dimMax || num <=0);

    for(int i=0; i<num; i++){
        cout <<"Dato: " ;
        cin >>d[i];
    }
    
    return num;
}

//*************************************************************************

void stampa(float d[], int l){

    cout <<endl << "Stampo vettore: " <<endl;
    for(int i=0; i<l; i++)
        cout << d[i] <<endl;
}

//*************************************************************************

void swapArrayFloat(float v[], int pos1, int pos2){

    //Variabile di appoggio
    float appo;
    appo = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = appo;

}

//*************************************************************************

void bubble(int v[], int n){
	for(int i = 0; i<n-1; i++) {
		if (v[i] > v[i+1]){
			scambia2(v, i);
			for(int k = i; k>0 && v[k]<v[k-1];k--){
				scambia2(v, k-1);
			} 
		}
	}
}

//*************************************************************************

void scambia2(int v[], int i){
	int a;
	a=v[i];
	v[i]=v[i+1];
	v[i+1]=a;
}

//*************************************************************************


float acaso01(){
    return ((float) rand())/RAND_MAX;

}

//*************************************************************************

float acasoAB(float a,float b){

    return acaso01()*(b-a)+a;

}

//*************************************************************************

float generaFloat(float min, float max){
	float r;
	
	r =  (max-min)*rand()/RAND_MAX + min;
	return r;
}

//*************************************************************************

void inizializzaRand(){
	srand(time(NULL));
}

//*************************************************************************

float mediavett( float dati[], int n ){
	float media=0.0f;
	for (int i=0 ; i< n ; i++){
		media+= dati[i];
	}
	float mvett= media / n;
	return mvett;
}

//*************************************************************************

float stdDevvett( float dati[] , int n  ){
	float devstvett= 0.0f;
	float mean;
	mean = mediavett(dati, n );
	for ( int i=0 ; i< n ; i++){	
		devstvett+= pow( dati[i] - mean , 2);
	}
	
	devstvett/= (n-1);
	devstvett = sqrt(devstvett);
	return devstvett;
}

//*************************************************************************

void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2; 
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

//*************************************************************************

void merge(int a[],int low,int mid,int high){


    int h,i,j,k;
    int b[1000]; 
    h=low; 
    i=low; 
    j=mid+1; 

    while((h<=mid)&&(j<=high)){ 
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++; 
        }
        else{
            b[i]=a[j];
            j++; 
        }
        i++; 
    }

    if(h>mid){ 
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){ 
            b[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++) a[k]=b[k]; 
}

//*************************************************************************

  int binaria(  int *list, int lunghezza, int cerca){
	int primo=0;
	int ultimo= lunghezza-1;
	int medio, conta=0;
	bool found=false;
	//cout<<primo<<" "<<ultimo;
		while(primo<=ultimo && !found){
	 	medio=(primo+ultimo)/2;
			if(list[medio]==cerca)
			found=true;
			//if(list[medio]==list[medio+1])
			//conta++;}
			else {
				if(list[medio]>cerca)
				ultimo=medio -1;
				
				else
				primo=medio +1;
			}
						}
		
		if(found) 
		return medio;
		else 
		return -1;
}

//*************************************************************************

int binarySearch(int v[], int value, int low, int high) {
     int mid;

     if (high < low)
         return -1;
     mid = low + ((high - low) / 2); 
     if (v[mid] > value)
         return binarySearch(v, value, low, mid-1);
     else if (v[mid] < value)
         return binarySearch(v, value, mid+1, high);
     else
         return mid; 
 }

//*************************************************************************

int resize(int **pv, int oldDim, int newDim){
    int *pappo;
    if(oldDim > newDim)
        return -1;

    pappo=new int[newDim];
    if(pappo==NULL)
        return -2;

    for(int i=0; i<oldDim; i++)
        pappo[i]=(*pv)[i];
    delete [] (*pv);
    *pv=pappo;

    return newDim;
}

//*************************************************************************

void selectionsort(int list[], int lenght){
   int min;
   int var;
  
   
     for(int a=0; a< lenght -1;a++)
      {
        min=a;
          for(int minx= a+1;minx<lenght;minx++)
          if(list[minx]<list[min])
          min= minx;
          var=list [min];
          list[min]=list[a];
          list[a]=var;
}

 }

//*************************************************************************

int sequenziale( int list[], int listlenght, int cerca){

    int loc;
    bool found =false;
    for(loc=0;loc<listlenght;loc++)
    if(list[loc]==cerca)
    {
    found =true;
    break;
    }
    if(found)
    return loc;
    else
    return -1;
}

//*************************************************************************

double max(int x[], int N){
	bubble(x,N);
	return x[N-1];
}

//*************************************************************************

double min( int x[], int N){
	bubble(x, N);
	return x[0];
}

//*************************************************************************

float sommaquad(float v[], int lungh){
	float sommaquadra = 0;
	for(int j = 0; j < lungh; j++){
		sommaquadra = sommaquadra + (v[j]*v[j]);
	}
	return sommaquadra;
}

//*************************************************************************

float distanza(float x1, float y1, float x2, float y2){
	float dist = 0;
	dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return dist;
}

//*************************************************************************


void printVettInt(int v[], int used){

    cout << endl << "Stampo vettore: " << endl;
    for(int i=0; i<used; i++){
        cout << endl << v[i];
    }
    cout << endl;
}

//*************************************************************************

void merge_sortp(int *intlist,int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2; 
        merge_sort(intlist,low,mid);
        merge_sort(intlist,mid+1,high);
        merge(intlist,low,mid,high);
    }
}

//*************************************************************************

void mergep(int *intlist,int low,int mid,int high){


    int h,i,j,k;
    int b[100]; 
    h=low; 
    i=low;  
    j=mid+1; 

    while((h<=mid)&&(j<=high)){ 
        if(intlist[h]<=intlist[j]){
            b[i]=intlist[h];
            h++;
        }
        else{
            b[i]=intlist[j];
            j++; 
        }
        i++; 
    }

    if(h>mid){ 
        for(k=j;k<=high;k++){
            b[i]=intlist[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){ 
            b[i]=intlist[k];
            i++;
        }
    }
    for(k=low;k<=high;k++) intlist[k]=b[k]; 
}

//*************************************************************************

float maxf(int N, float x[]){
	bubblef(N, x);
	return x[N-1];
}

//*************************************************************************

float minf( int N, float x[]){
	bubblef(N, x);
	return x[0];
}

//*************************************************************************

void bubblef(int n, float v[]){
	for(int i = 0; i<n-1; i++) {
		if (v[i] > v[i+1]){
			scambia2f(i, v);
			for(int k = i; k>0 && v[k]<v[k-1];k--){
				scambia2f(k-1, v);
			} 
		}
	}
}

//*************************************************************************

void scambia2f(int i, float v[]){
	float a;
	a=v[i];
	v[i]=v[i+1];
	v[i+1]=a;
}

//***************************************************************************

void maxmin (punto*v,int n, float* min, float *max){
	*min=v[0].m;	
	*max=v[0].m;	
	for(int i=0;i<n;i++){
		float d=v[i].m;
		if (*min>d)
			*min=d;
		if (*max<d)
			*max=d;	
	}		
	return;
}

//**************************************************************************

void distanze (punto*v, int n, float xcm, float ycm){
	for (int i=0;i<n;i++){
		float x2=pow((v[i].x-xcm),2);
		float y2=pow((v[i].y-ycm),2);
		float d=pow((x2+y2),0.5);
		v[i].dist=d;
	}
	return;
}

//*************************************************************************

void sommatorie (punto*v,int n, float*M, float*Mx, float*My){
	for (int i=0;i<n;i++){
		*M=*M+v[i].m;
		*Mx=*Mx+(v[i].m * v[i].x);
		*My=*My+(v[i].m * v[i].y);
	}
	return;
}

//*************************************************************************

void centromassa (punto*v, int n, float* xcm, float* ycm){
	float M=0;
	float Mx=0;
	float My=0;
	sommatorie (v,n,& M,& Mx,& My);	
	*xcm=Mx/M;
	*ycm=My/M;
	return;
} 

//**************************************************************************

void quick (punto *v,int sx, int dx){
	int i,j;
	float m;
	i=sx;
	j=dx;
	m=(v[sx].dist+v[dx].dist)/2;
	do{
		while (v[i].dist<m) 
			i++;
		while (m<v[j].dist) 
			j--;
		if (i<=j){
			Scambiostruct(v,i,j);
			i++;
			j--;
		}
	} while (j>=i);
	if (sx<j) 
		quick (v,sx,j);
	if (i<dx)
		quick (v,i,dx);
	return;
	
}

//************************************************************************

void Scambiostruct (punto*v, int i, int j){
	float a,b,c,d;
	a=v[i].x;
	b=v[i].y;
	c=v[i].m;
	d=v[i].dist;
	v[i].x=v[j].x;
	v[i].y=v[j].y;
	v[i].m=v[j].m;
	v[i].dist=v[j].dist;
	v[j].x=a;
	v[j].y=b;
	v[j].m=c;
	v[j].dist=d;
	return;
}

//**************************************************************************

float Deviazione(punto*v, int n){
	float dev=0;
	float d=Media(v,n);
	for (int i=0;i<n;i++){
		dev=dev+ pow((v[i].dist-d),2);
		dev=pow((dev/n-1),0.5);
	return d;
	}
}

//**************************************************************************

float Media (punto*v, int n){
	float media=0;
	for (int i=0;i<n;i++)
			media= media+v[i].dist;
	media =media/n;
	return media;
}

