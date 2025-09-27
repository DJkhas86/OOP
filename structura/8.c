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
	char* pol;
	int  age;
	long long int number;
}zapic;
void vvodname(zapic array[],int a)
{
	printf("vvedite imya:");
	scanf("%s",&array[a].name);
}
void vivodname(zapic array[], int a)
{
	printf("%s  ", array[a].name);
}
void vvodsurname(zapic array[], int a)
{
	printf("vvedite familia:");
	scanf("%s",&array[a].surname);
}
void vivodsurname(zapic array[], int a)
{
	printf("%s  ", array[a].surname);
}
void vvodpol(zapic array[],int a)
{
	int p = 0;
	printf("vvedite pol(1 ili 2): ");
	scanf_s("%d",&array[a].polv);
	while (p != 1)
	{
		if (array[a].polv < 1 || array[a].polv > 2)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy pol: ");
			scanf_s("%d", &array[a].polv);
			p++;
		}
		else
		{
			p = 1;
		}
	}
	p = 0;
	if (array[a].polv == 1)
	{
		array[a].pol = "man";
	}
	else
	{
		array[a].pol = "woman";
	}
}
void vivodpol(zapic array[],int a)
{
	printf("%s\n", array[a].pol);
}
void vvodnumber(zapic array[],int a)
{
	int p = 0;
	printf("vvedite nomer(vida 89999999999): ");
	scanf_s("%lld", &array[a].number);
	while (p != 1)
	{
		if (array[a].number < 80000000000 || array[a].number > 89999999999)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy nomer: ");
			scanf_s("%lld", &array[a].number);
		}
		else
		{
			p = 1;
		}
	}
}
void vivodnumber(zapic array[],int a)
{
	printf("%lld\n", array[a].number);
}
void vvodvozrast(zapic array[],int a)
{
	int p = 0;
	printf("vvedite vozrast: ");
	scanf_s("%d", &array[a].age);
	while (p != 1)
	{
		if (array[a].age < 0 || array[a].age > 160)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy vozrast: ");
			scanf_s("%d let", &array[a].age);
		}
		else
		{
			p = 1;
		}
	}
}
void vivodvozrast(zapic array[], int a)
{
	printf("%d\n", array[a].age);
}
void vivodnomer(zapic array[], int a)
{
	printf("%d.", array[a].nomer);
}
void vvodelementa(zapic array[], int a)
{
	vvodname(array, a);
	vvodsurname(array, a);
	vvodpol(array, a);
	vvodnumber(array, a);
	vvodvozrast(array, a);
}
void vivodelementa(zapic array[], int a)
{
	vivodnomer(array, a);
	vivodname(array, a);
	vivodsurname(array, a);
	vivodpol(array, a);
	vivodnumber(array, a);
	vivodvozrast(array, a);
}      
void sort(zapic array[])
{
	zapic buff[4] = { 0 };
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j > i)
			{
				if (strcmp(array[i].surname, array[j].surname) == 1 && array[i].age != 0 && array[j].age != 0)
				{
					buff[i] = array[j];
					array[j] = array[i];
					array[i] = buff[i];
				}
			}
		}
	}
}
void del(zapic array[], const int a)
{
	zapic buff[4] = { 0 };
	if (a == 0)
	{
		memmove(array, array + 1, sizeof(zapic) * (3 - 1));
	}
	else if (a == 3)
	{
		array[a] = buff[a];
	}
	else
	{
		memmove(array + a, array + a + 1, sizeof(zapic) * (3 - a));
		array[3] = buff[3];
	}
}
void vstavka(zapic array[], int a)
{
	int i = 0;
	memmove(array + 1 + a,array + a,sizeof(zapic) * (3 - a));
	vvodelementa(array, a);
}
void poisk(zapic array[], int a, int b)
{
	for (int i = 0; i < 4; i++)
	{
		if (array[i].age >= a && array[i].age < b)
		{
			vivodelementa(array, i);
		}
	}
}
int main()
{
	zapic kniga[4] = { 0 };
	int x,p,i,n,v,v2,voz1,voz2;
	v = 0;
	n = 0;
	p = 1;
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
				vvodelementa(kniga, n);
				kniga[n].nomer = n;
				n++;
				break;
			case(2):
				printf("vvedite nomer:");
				scanf("%d", &v);
				if (v < 0 || v > 4)
				{
					printf("EROORRRR!!!\n");
					printf("Vvedite pravilniy nomer:");
					scanf("%d", &v);
				}
				vstavka(kniga, v);
				for (i = v+1; i < 4; i++)
				{
					kniga[i].nomer++;
				}
				n++;
				break;
			case(3):
				printf("vvedite nomer:");
				scanf("%d", &v);
				if (v < 0 || v > 4)
				{
					printf("EROORRRR!!!\n");
					printf("Vvedite pravilniy nomer:");
					scanf("%d", &v);
				}
				del(kniga, v);
				for (i = v; i <= 4; i++)
				{
					kniga[i].nomer--;
				}
				n--;
				break;
			case(4):
				for (i = 0; i < 4; i++)
				{
					if (kniga[i].age != 0)
					{
						vivodelementa(kniga, i);
					}
				}
				break;
			case(5):
				printf("vvedite nomer:");
				scanf("%d", &v);
				if (v < 0 || v > 4)
				{
					printf("EROORRRR!!!\n");
					printf("Vvedite pravilniy nomer:");
					scanf("%d", &v);
				}
				vivodelementa(kniga, v);
			case(6):
				sort(kniga);
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
						poisk(kniga, voz1, voz2);
						break;
					case(2):
						voz1 = 20;
						voz2 = 40;
						poisk(kniga, voz1, voz2);
						break;
					case(3):
						voz1 = 0;
						voz2 = 20;
						poisk(kniga, voz1, voz2);
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