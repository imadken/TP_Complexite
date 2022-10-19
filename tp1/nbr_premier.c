#include<stdio.h>
#include<time.h>
#include<math.h>




int algo1 (unsigned long long int nbr){

for (unsigned long long int i=2 ; i < nbr; i++){
      
      if(nbr % i == 0) return 0;
      
}
 //printf("premier   ") ; 
return 1;
}

int algo2 (unsigned long long int nbr){

for ( unsigned long long int i=2 ; i<=nbr/2; i++){
      
      if(nbr % i == 0) return 0;
      
}
 //printf("premier   ") ; 
return 1;
}

int algo3 (unsigned long long int nbr){

if((nbr != 2) && (nbr%2 == 0)) return 0;

else{

if (nbr != 2){

for ( unsigned long long int i=3 ; i<=nbr-2; i+=2){
      
      if(nbr % i == 0) return 0;
    
                                   }
             }
     }
   //printf("premier   ") ;  
return 1;     
}


int algo4 (unsigned long long int nbr){

if((nbr != 2) && (nbr%2 == 0)) return 0;

else{

if (nbr != 2){

for (  unsigned long long int i=3 ; i<=nbr/2; i+=2){
      
      if(nbr % i == 0) return 0;
    
                                   }
             }
     }

 //printf("premier   ") ;      
return 1;  
}

int algo5 (unsigned long long int nbr){



for (unsigned long long int i=2 ; i<=sqrt(nbr); i++){
      
      if(nbr % i == 0) return 0;
      
}
//printf("premier   ") ;  
return 1;
}

int algo6 (unsigned long long int nbr){

if((nbr != 2) && (nbr%2 == 0)) return 0;
 
else{

if (nbr != 2){

for ( unsigned long long int i=3 ; i<=sqrt(nbr); i+=2){
      
      if(nbr % i == 0) return 0;
    
                                   }
             }
     }
   //printf("premier   ") ;  
return 1;  
}


// la tache 1 du tp

void tache01(){
// {5297,389299,34583291,9934239587,979020560239}
unsigned long long int primes[5]= {7919,104729,24512053,1705483033,333250198343};

double delta;

clock_t t1,t2;


for (int i =0 ;i<5;i++){

printf("-------------------------------------\n");
printf("le nombre premier  => %llu\n",primes[i]);
printf("-------------------------------------\n\n");

///////////


printf("algo 6 :");

t1 =clock();

algo6(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);

///////////////

printf("algo 5 :");

t1 =clock();

algo5(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);

//////////////

printf("algo 4 :");

t1 =clock();

algo4(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);

////////////////

printf("algo 3 :");

t1 =clock();

algo3(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);


/////////////

printf("algo 2 :");

t1 =clock();

algo2(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);


/////////////
printf("algo 1 :");

t1 =clock();

algo1(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

printf(" %f \n\n",delta);
}



}

void tache03(){
// {5297,389299,34583291,9934239587,979020560239}

unsigned long long int primes[5]= {104729,24512053,1705483033};

double delta;

clock_t t1,t2;

double moy;


// for (int i =0 ;i<5;i++){
for (int i =0 ;i<3;i++){

printf("-------------------------------------\n");
printf("le nombre premier  => %llu\n",primes[i]);
printf("-------------------------------------\n\n");

///////////

moy = 0;

printf("algo 6 :");

for(int t=0;t<50;t++){

t1 =clock();

algo6(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

moy += delta;

}



printf(" %f \n\n",moy/50);

///////////////

printf("algo 5 :");

moy =0;

for(int t=0;t<20;t++){


t1 =clock();

algo5(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

moy += delta;
}
printf(" %f \n\n",moy/50);

//////////////

printf("algo 4 :");

moy =0;

for(int t=0;t<50;t++){
t1 =clock();

algo4(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;
moy += delta;
}
printf(" %f \n\n",moy/50);

////////////////

printf("algo 3 :");
moy =0;

for(int t=0;t<50;t++){
t1 =clock();

algo3(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

moy += delta;
}

printf(" %f \n\n",moy/50);


/////////////

printf("algo 2 :");

moy =0;

for(int t=0;t<50;t++){

t1 =clock();

algo1(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

moy += delta;
}
printf(" %f \n\n",moy/50);


/////////////
printf("algo 1 :");

moy =0;

for(int t=0;t<50;t++){

t1 =clock();

algo1(primes[i]);

t2 = clock();

delta = (t2-t1)/CLOCKS_PER_SEC;

moy += delta;

}

printf(" %f \n\n",moy/50);
}



}


int main(){

//tester les algo
/*
printf(algo1(7919) ==1 ? "premier\n":"non premier\n");
printf(algo2(7919) ==1 ? "premier\n":"non premier\n");
printf(algo3(7919) ==1 ? "premier\n":"non premier\n");
printf(algo4(7919) ==1 ? "premier\n":"non premier\n");
printf(algo5(7919) ==1 ? "premier\n":"non premier\n");
printf(algo6(7919) ==1 ? "premier\n":"non premier\n");
*/


tache01();









}
