#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
typedef struct
{
	int nomer;
	char name[21];
	char surname[21];
	int polv;
	char pol[6];
	int  age;
	long long int number;
}zapic;
void vvodname(zapic *a)
{
	printf("vvedite imya:");
	scanf("%s",&a->name);
}
void vivodname(zapic *a)
{
	printf("%s  ", a->name);
}
void vvodsurname(zapic *a)
{
	printf("vvedite familia:");
	scanf("%s",&a->surname);
}
void vivodsurname(zapic *a)
{
	printf("%s  ", a->surname);
}
void vvodpol(zapic *a)
{
	int p = 0;
	printf("vvedite pol(1 ili 2): ");
	scanf("%d",&a->polv);
	while (p != 1)
	{
		if (a->polv < 1 || a->polv > 2)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy pol: ");
			scanf("%d", &a->polv);
			p++;
		}
		else
		{
			p = 1;
		}
	}
	p = 0;
	if (a->polv == 1)
	{
		strncpy(a->pol,"man",6);
	}
	else
	{
		strncpy(a->pol,"man",6);
	}
}
void vivodpol(zapic *a)
{
	printf("%s\n", a->pol);
}
void vvodnumber(zapic *a)
{
	int p = 0;
	printf("vvedite nomer(vida 89999999999): ");
	scanf("%lld", &a->number);
	//  while (p != 1)
	//  {
	//  	 if (a->number < 80000000000 || a->number > 89999999999)
	//  	 {
	//  	 	printf("erorr!!!!");
	//  	 	printf("vvedite korektniy nomer: ");
	//  	 	scanf("%lld", &a->number);
	//  	 }
	//  	 else
	//  	 {
	//  	 	p = 1;
	//  	 }
	//  }
}
void vivodnumber(zapic *a)
{
	printf("%lld\n", a->number);
}
void vvodvozrast(zapic *a)
{
	int p = 0;
	printf("vvedite vozrast: ");
	scanf("%d", &a->age);
	while (p != 1)
	{
		if (a->age < 0 || a->age > 120)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy vozrast: ");
			scanf("%d let", &a->age);
		}
		else
		{
			p = 1;
		}
	}
}
void vivodvozrast(zapic *a)
{
	printf("%d\n", a->age);
}
void vivodnomer(zapic *a)
{
	printf("%d.", a->nomer);
}
void vvodelementa(zapic *a)
{
	vvodname(a);
	vvodsurname(a);
	vvodpol(a);
	vvodnumber(a);
	vvodvozrast(a);
}
void vivodelementa(zapic *a)
{
	vivodnomer(a);
	vivodname(a);
	vivodsurname(a);
	vivodpol(a);
	vivodnumber(a);
	vivodvozrast(a);
}
void swap(zapic *a1,zapic *a2,int n){
	zapic buff = { 0 };
	if (strcmp((a1)->surname, (a2)->surname) == 1)
	{
		buff = *(a2);
		*(a2) = *(a1);
		*(a1) = buff;
		buff.nomer = a2->nomer;
		a2->nomer = a1->nomer;
		a1->nomer = buff.nomer;
	}
}      
void sort(zapic *a,int n)
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			swap(a+i,a+j,n);
		}
	}
}
void del(zapic *a,const int n,int v)
{
 zapic buff ={0};
	if (v == 0)
	{
		memmove(a,a + 1,sizeof(zapic) * (n - 1));
		*(a + n - 1) = buff;
	}
	else if (v == n - 1)
	{
		*(a+v) = buff;
	}
	else
	{
		memmove(a+v,a + v+1,sizeof(zapic) * (n - 1 - v));
	}
}

void vstavka(zapic *a,int n,int v)
{
	memmove(a + v + 1,a + v,sizeof(zapic) * (n - v));
	vvodelementa(a + v);
}
void poisk(zapic *ar,int n,int a,int b)
{
	int i,c;
	c = 0;
	for (i = 0; i < n; i++)
	{
		if ((ar+i)->age >= a && (ar+i)->age < b)
		{
			vivodelementa(ar+i);
			c++;
		}
	}
	if(c == 0){
		printf("Nenaideno\n");
	}
}
int main()
{
	int x,p,i,n,v,v2,voz1,voz2;
	v = 0;
	n = 0;
	p = 1;
	char fileNamev,fileNamep;
	FILE *fpv;
	FILE *fpz;
	int size = sizeof(zapic);
	zapic *a = NULL;
	while (p != 0)
	{
		v = 0;
		x = 0;
		printf("1.dobavlenie elementa\n");
		printf("2.vstavka elementa\n");
		printf("3.udalenie elementa po nomery\n");
		printf("4.pokazat' vse elementi\n");
		printf("5.pokazat' element po nomery\n");
		printf("6.sortirovka po familii\n");
		printf("7.poisk element po vozrasty\n");
		printf("8.Zagruzit' danniye iz faila\n");
		printf("9.Cohranit' danniye v fail\n");
		printf("0.vixod\n");
		scanf("%d", &x);
		if (x < -1 || x > 9)
		{
			printf("EROORRRR!!!\n");
			printf("Viberite zanovo:");
			scanf("%d", &x);
		}
		switch (x)
		{
			case(1):
				a = realloc(a, (n + 1) * size);
				if(!a){
					printf("ERRORR");
					break;
				}
				else{
					vvodelementa(&a[n]);
					(a[n]).nomer = n;
					n++;
				}
				break;
			case(2):
				printf("vvedite nomer:");
				scanf("%d", &v);
				while (p!=1){
					if (v < 0 || v > n)
					{
						printf("EROORRRR!!!\n");
						printf("Vvedite pravilniy nomer:");
						scanf("%d", &v);
					}
					else{
						p = 1;
					}
				}
				p = 1;
				a = realloc(a,(n+1)*size);
				vstavka(a,n,v);
				for (i = v + 1; i <= n; i++)
				{
					a[i].nomer++;
				}
				n++;
				break;
			case(3):
				if(a[0].age != 0){
					printf("vvedite nomer:");
					scanf("%d", &v);
					while (p!=1){
						if (v < 0 || v > n)
						{
							printf("EROORRRR!!!\n");
							printf("Vvedite pravilniy nomer:");
							scanf("%d", &v);
						}
						else{
							p = 1;
						}
					}
					p = 1;
					for (i = v + 1; i < n; i++)
					{
						a[i].nomer--;
					}
					del(a,n,v);
					a = realloc(a,(n+1) * size);
					n--;
				}
				else{
					printf("Udalenie Nevozmozhno\n");
				}
				break;
			case(4):
				for (i = 0; i < n; i++)
				{
					vivodelementa(&a[i]);
				}
				break;
			case(5):
				printf("vvedite nomer:");
				scanf("%d", &v);
				while (p!=1){
					if (v < 0 || v > n)
					{
						printf("EROORRRR!!!\n");
						printf("Vvedite pravilniy nomer:");
						scanf("%d", &v);
					}
					else{
						p = 1;
					}
				}
				p = 0;
				vivodelementa(&a[v]);
				break;
			case(6):
				sort(&a[0],n);
				break;
			case(7):
				v2 = 0;
				printf("viberite vozrast:\n");
				printf("1.vzrosliy(40+):\n");
				printf("2.molodoi(20-39):\n");
				printf("3.rebenok(0-19):\n");
				scanf("%d",&v2);
				if (v2 < 0 || v2 > 120)
				{
					printf("EROORRRR!!!\n");
					printf("Vvedite realniy vozrast:");
					scanf("%d", &v2);
				}
				switch (v2)
				{
					case(1):
						voz1 = 40;
						voz2 = 100;
						poisk(&a[0],n,voz1, voz2);
						break;
					case(2):
						voz1 = 20;
						voz2 = 40;
						poisk(&a[0],n,voz1, voz2);
						break;
					case(3):
						voz1 = 0;
						voz2 = 20;
						poisk(&a[0],n,voz1, voz2);
						break;
				}
				break;
			case(8):
				printf("vvedite nazvaniye faila: ");
				scanf("%s",&fileNamev);
				strcat(&fileNamev,".txt");
				fpz = fopen(&fileNamev, "r");
				if (fpz == NULL) {
					perror("ERor");
					break;
				}
				i = 0;
				a = realloc(a, (i + 1) * size);
				while(fscanf(fpz,"%s %s %s %d %lld\n",a[i].name,a[i].surname,&a[i].pol,&a[i].age,&a[i].number)==5){
					a = realloc(a, (i + 1) * size);
					n++;
					a[i].nomer = n;
					printf("%s %s %s %d %lld\n",a[i].name,a[i].surname,a[i].pol,a[i].age,a[i].number);
					i++;
				}
				n = i;
				if(i == 0){
					a = realloc(a, n * size);
				}
				fclose(fpz);
				for(i = 0;i<n;i++){
					a[i].nomer = i;
				}
				break;
			case(9):
				printf("vvedite nazvaniye faila: ");
				scanf("%s",&fileNamev);
				strcat(&fileNamev,".txt");
				fpv = fopen(&fileNamev, "w");
				if (fpv == NULL) {
					perror("ERor");
					break;
				}
				for(i=0; i < n; i++)
				{
					fprintf(fpv,"%s %s %s %d %lld\n",a[i].name,a[i].surname,a[i].pol,a[i].age,a[i].number);
				}
				fclose(fpv);
				break;
			case(0):
				p = 0;
				free(a);
				break;
		}	
	}
	return 0;
	system("pause");
}
