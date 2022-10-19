#include <stdio.h>
#include <stdlib.h>
// #include <random.h>
#include <time.h>

void triee_inv(long long int taille ,FILE *file){

    for ( long long int  i=taille;i>=0 ;i--){

fprintf(file,"%ld \n",i);
}

}
void triee(long long int taille ,FILE *file){

    for ( long long int  i=0 ;i<taille;i++){

fprintf(file,"%ld \n",i);
}
}


void random(long long int taille ,FILE *file){

    for ( long long int  i=0 ;i<taille;i++){

fprintf(file,"%d \n",rand()%taille);
}
}

int main(){

//triee
FILE *ft1=fopen("10-4.txt","w");
FILE *ft2=fopen("10-5.txt","w");
FILE *ft3=fopen("10-6.txt","w");
FILE *ft4=fopen("10-7.txt","w");
FILE *ft5=fopen("10-8.txt","w");
FILE *ft6=fopen("5x10-4.txt","w");
FILE *ft7=fopen("5x10-5.txt","w");
FILE *ft8=fopen("5x10-6.txt","w");
FILE *ft9=fopen("5x10-7.txt","w");

triee(10000,ft1);
triee(100000,ft2);
triee(1000000,ft3);
triee(10000000,ft4);
triee(100000000,ft5);
triee(5*10000,ft6);
triee(5*100000,ft7);
triee(5*1000000,ft8);
triee(5*10000000,ft9);

//inverse
FILE *fi1=fopen("10-4_inv.txt","w");
FILE *fi2=fopen("10-5_inv.txt","w");
FILE *fi3=fopen("10-6_inv.txt","w");
FILE *fi4=fopen("10-7_inv.txt","w");
FILE *fi5=fopen("10-8_inv.txt","w");
FILE *fi6=fopen("5x10-4_inv.txt","w");
FILE *fi7=fopen("5x10-5_inv.txt","w");
FILE *fi8=fopen("5x10-6_inv.txt","w");
FILE *fi9=fopen("5x10-7_inv.txt","w");

triee_inv(10000,fi1);
triee_inv(100000,fi2);
triee_inv(1000000,fi3);
triee_inv(10000000,fi4);
triee_inv(100000000,fi5);
triee_inv(5*10000,fi6);
triee_inv(5*100000,fi7);
triee_inv(5*1000000,fi8);
triee_inv(5*10000000,fi9);



//random
FILE *fr1=fopen("10-4_rand.txt","w");
FILE *fr2=fopen("10-5_rand.txt","w");
FILE *fr3=fopen("10-6_rand.txt","w");
FILE *fr4=fopen("10-7_rand.txt","w");
FILE *fr5=fopen("10-8_rand.txt","w");
FILE *fr6=fopen("5x10-4_rand.txt","w");
FILE *fr7=fopen("5x10-5_rand.txt","w");
FILE *fr8=fopen("5x10-6_rand.txt","w");
FILE *fr9=fopen("5x10-7_rand.txt","w");
random(10000,fr1);
random(100000,fr2);
random(1000000,fr3);
random(10000000,fr4);
random(100000000,fr5);
random(5*10000,fr6);
random(5*100000,fr7);
random(5*1000000,fr8);
random(5*10000000,fr9);




}