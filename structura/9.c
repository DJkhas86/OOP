#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
#define sizemassiv 4
typedef struct
{
	int nomer;
	char name[21];
	char surname[21];
	int polv;
	char* pol;
	int  age;
	long long int number;
}zapic;
void vvodname(zapic *array,const int a)
{
	printf("vvedite imya:");
	scanf("%s",&array->name);
}
void vivodname(zapic *array,const int a)
{
	printf("%s  ", array->name);
}
void vvodsurname(zapic *array,const int a)
{
	printf("vvedite familia:");
	scanf("%s",&array->surname);
}
void vivodsurname(zapic *array,const int a)
{
	printf("%s  ", array->surname);
}
void vvodpol(zapic *array,const int a)
{
	int p = 0;
	printf("vvedite pol(1 ili 2): ");
	scanf("%d",&array->polv);
	while (p != 1)
	{
		if (array->polv < 1 || array->polv > 2)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy pol: ");
			scanf("%d", &array->polv);
			p++;
		}
		else
		{
			p = 1;
		}
	}
	p = 0;
	if (array->polv == 1)
	{
		array->pol = "man";
	}
	else
	{
		array->pol = "woman";
	}
}
void vivodpol(zapic *array,const int a)
{
	printf("%s\n", array->pol);
}
void vvodnumber(zapic *array,const int a)
{
	int p = 0;
	printf("vvedite nomer(vida 89999999999): ");
	scanf("%lld", &array->number);
	//  while (p != 1)
	//  {
	//  	 if (array->number < 80000000000 || array->number > 89999999999)
	//  	 {
	//  	 	printf("erorr!!!!");
	//  	 	printf("vvedite korektniy nomer: ");
	//  	 	scanf("%lld", &array->number);
	//  	 }
	//  	 else
	//  	 {
	//  	 	p = 1;
	//  	 }
	//  }
}
void vivodnumber(zapic *array,const int a)
{
	printf("%lld\n", array->number);
}
void vvodvozrast(zapic *array,const int a)
{
	int p = 0;
	printf("vvedite vozrast: ");
	scanf("%d", &array->age);
	while (p != 1)
	{
		if (array->age < 0 || array->age > 120)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy vozrast: ");
			scanf("%d let", &array->age);
		}
		else
		{
			p = 1;
		}
	}
}
void vivodvozrast(zapic *array,const int a)
{
	printf("%d\n", array->age);
}
void vivodnomer(zapic *array,const int a)
{
	printf("%d.", array->nomer);
}
void vvodelementa(zapic *array,const int a)
{
	vvodname(array, a);
	vvodsurname(array, a);
	vvodpol(array, a);
	vvodnumber(array, a);
	vvodvozrast(array, a);
}
void vivodelementa(zapic *array,const int a)
{
	vivodnomer(array, a);
	vivodname(array, a);
	vivodsurname(array, a);
	vivodpol(array, a);
	vivodnumber(array, a);
	vivodvozrast(array, a);
}
void swap(zapic *array1,zapic *array2,const int a){
	zapic buff[4] = { 0 };
	if (strcmp((array1)->surname, (array2)->surname) == 1 && (array1)->age != 0 && (array2)->age != 0)
				{
					buff[1] = *(array2);
					*(array2) = *(array1);
					*(array1) = buff[1];
					buff[1].nomer = array2->nomer;
					array2->nomer = array1->nomer;
					array1->nomer = buff[1].nomer;
				}
}      
void sort(zapic *array,const int a)
{
	zapic buff[4] = { 0 };
	int i,j;
	for(i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (j > i)
			{
				swap(array+i,array+j,a);
			}
		}
	}
}
void del(zapic *array,const int r,int a)
{
	zapic buff[10] = { 0 };
	if (a == 0)
	{
		memmove(array,array+1,sizeof(zapic) * (r - 1));
		*(array + r - 1) = buff[a];
	}
	else if (a == sizemassiv - 1)
	{
		*array = buff[a];
	}
	else
	{
		memmove((array),array + 1,sizeof(zapic) * (r - 1 - a));
		*(array-a+r-1) = buff[a];
	}
}
void vstavka(zapic *array,const int r,int a)
{
	int i = 0;
	memmove((array + 1),array,sizeof(zapic) * (r - 1 - a));
	vvodelementa(array, r);
}
void poisk(zapic *array,const int r,int a,int b)
{
	int i,c;
	c = 0;
	for (i = 0; i < r; i++)
	{
		if ((array+i)->age >= a && (array+i)->age < b)
		{
			vivodelementa(array+i,r);
			c++;
		}
	}
	if(c == 0){
		printf("Nenaideno\n");
	}
}
int main()
{
	int x,p,i,n,v,v2,voz1,voz2,r;
	v = 0;
	n = 0;
	p = 1;
	r = sizemassiv;
	zapic kniga[10] = { 0 };
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
		printf("0.vixod\n");
		scanf("%d", &x);
		if (x < -1 || x > 8)
		{
			printf("EROORRRR!!!\n");
			printf("Viberite zanovo:");
			scanf("%d", &x);
		}
		switch (x)
		{
			case(1):
				vvodelementa(kniga + n, r);
				kniga[n].nomer = n;
				n++;
				break;
			case(2):
				if(kniga[r - 1].age == 0){
					p = 0;
					printf("vvedite nomer:");
					scanf("%d", &v);
					while (p!=1){
						if (v < 0 || v > r)
						{
							printf("EROORRRR!!!\n");
							printf("Vvedite pravilniy nomer:");
							scanf("%d", &v);
						}
						else{
							p = 1;
						}
					}
					vstavka(kniga + v,r,v);
					for (i = v+1; i < r; i++)
					{
						kniga[i].nomer++;
					}
					kniga[n].nomer = n;
					n++;
				}
				else{
					printf("Vstavka Nevozmozhna\n");
				}
				break;
			case(3):
				if(kniga[0].age != 0){
					printf("vvedite nomer:");
					scanf("%d", &v);
					while (p!=1){
						if (v < 0 || v > r)
						{
							printf("EROORRRR!!!\n");
							printf("Vvedite pravilniy nomer:");
							scanf("%d", &v);
						}
						else{
							p = 1;
						}
					}
					for (i = v + 1; i <= r; i++)
					{
						kniga[i].nomer--;
					}
					del(kniga + v, r,v);
					n--;
				}
				else{
					printf("Udalenie Nevozmozhno\n");
				}
				break;
			case(4):
				for (i = 0; i < r; i++)
				{
					if(kniga[i].age != 0){
						vivodelementa(kniga + i, r);
					}
				}
				break;
			case(5):
				printf("vvedite nomer:");
				scanf("%d", &v);
				if (v < 0 || v > r)
				{
					printf("EROORRRR!!!\n");
					printf("Vvedite pravilniy nomer:");
					scanf("%d", &v);
				}
				vivodelementa(kniga + v, r);
			case(6):
				sort(kniga,r);
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
						poisk(kniga,r,voz1, voz2);
						break;
					case(2):
						voz1 = 20;
						voz2 = 40;
						poisk(kniga,r,voz1, voz2);
						break;
					case(3):
						voz1 = 0;
						voz2 = 20;
						poisk(kniga,r,voz1, voz2);
						break;
				}
				break;
			case(0):
				p = 0;
				break;
		}
	}
	return 0;
	system("pause");
}
