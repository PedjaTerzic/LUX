#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t a,s,N,M;
unsigned long  i,k,b,n,d;
char sign = 'm';
char cont_prog = 'n';

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set_ui(p,d);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}

}

int main(void)
{
	
putchar ('\n');
     printf("                       ***** LUX *****\n\n\n");
	


mpz_t r,r1,r2;
	

do {

printf("For k*b^n-1 enter m . For k*b^n+1 enter p : ");

//getchar();
//sign = getchar();

scanf(" %c", &sign);


printf("Enter the coefficient :");
scanf("%lu",&k);
printf("Enter the base :");
scanf("%lu",&b);
printf("Enter the exponent :");
scanf("%lu",&n);
	
if(1 << n<=k)
{
printf("Coefficient must be less than 2^exponent");
}
else if(b%2 != 0)
{
printf("Base must be an even number");
}
else if(n<3)
{
	printf("Exponent must be greater than two");
}
else {
	


mpz_init(r);
mpz_init(r1);
mpz_init(r2);
mpz_init(a);
	
if(sign =='m' || sign =='M')
	
{
	

	
mpz_init(M);
mpz_ui_pow_ui(M,b,n);
mpz_mul_ui(M,M,k);
mpz_sub_ui(M,M,1);
	

d=3;
	
while(!(mpz_ui_kronecker(d-2,M)==1 && mpz_ui_kronecker(d+2,M)==-1))
{
d++;
}

mpz_set_ui(a,d);
P(r1,b/2,a);
P(r2,k*b/2,r1);
mpz_init_set(s,r2);
mpz_mod(s,s,M);



for (i = 1; i <= n-2; i++)
{
P(r,b,s);
mpz_mod(s,r,M);
}
mpz_clear(M);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu*%lu^%lu-1 is prime\n" , k,b,n);
}
else
{
printf("%lu*%lu^%lu-1 is composite\n" , k,b,n); 
}
mpz_clear(s);
	
}
	
else if(sign =='p' || sign =='P')
	
{
	
mpz_init(N);
mpz_ui_pow_ui(N,b,n);
mpz_mul_ui(N,N,k);
mpz_add_ui(N,N,1);
	

d=3;
	
while(!(mpz_ui_kronecker(d-2,N)==-1 && mpz_ui_kronecker(d+2,N)==-1))
{
d++;
}

mpz_set_ui(a,d);
P(r1,b/2,a);
P(r2,k*b/2,r1);
mpz_init_set(s,r2);
mpz_mod(s,s,N);



for (i = 1; i <= n-2; i++)
{
P(r,b,s);
mpz_mod(s,r,N);
}
mpz_clear(N);
if(mpz_cmp_ui(s,0)==0)
{
printf("%lu*%lu^%lu+1 is prime\n" , k,b,n);
}
else
{
printf("%lu*%lu^%lu+1 is composite\n" , k,b,n); 
}
mpz_clear(s);
	
}
}
putchar ('\n');	
fflush(stdout);
//getchar();//getchar();
 //return 0;
printf("Do you want to start again? (y/n) : ");
getchar();
cont_prog = getchar();
putchar ('\n');
}
while (cont_prog == 'y' || cont_prog == 'Y');
//system("pause");
return 0;
}