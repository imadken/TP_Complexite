#include<stdio.h>


//pgcd(a,b)=pgcd(b,a mod b)


int rec(int a ,int b){

if(a % b == 0) return b;

else return rec( b , a % b );

}


int iter(int a ,int b){

int temp;

while(a % b != 0){

temp = b;

b = a % b;

a = temp;

}
return b;


}




int main(){



printf("recursive => %d \n\n",rec(16456,7821468));
printf("iterative => %d",iter(16456,7821468));

}