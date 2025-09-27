#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct zapic
{
	int nomer;
	char name [21];
	char surname[21];
	int polv;
	char *pol;
	int  age;
	long long int number;
};

void vvodnomer(struct zapic  * x)
{
	int p = 0;
	printf("vvedite nomer: ");
	scanf("%d", &x->nomer);
	while(p != 1)
	{
		if(x->nomer < 0 || x->nomer > 20)
		{
			printf("errorr!!!!!");
			printf("vvedite korektniy nomer: ");
			scanf("%d",&x->nomer);
		}
		else
		{
			p = 1;
		}
	}
}

void vvodimya(struct zapic  * x)
{
	printf("vvedite imya: ");
	scanf("%s", x->name);
}

void vvodfamilia(struct zapic  * x)
{
	printf("vvedite familia: ");
	scanf("%s", x->surname);
}

void vvodpol(struct zapic  * x)
{
	int p = 0;
	printf("vvedite pol(1 ili 2): ");
	scanf("%d", &x->polv);
	while (p != 1)
	{
		if (x->polv < 1 || x->polv > 2)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy pol: ");
			scanf("%d", &x->polv);
			p++;
		}
		else
		{
			p = 1;
		}
	}
	p = 0;
	if(x->polv == 1)
	{
		x->pol = "man";
	}
	else
	{
		x->pol = "woman";
	}
}

void vvodvozrast(struct zapic  * x)
{
	int p =0;
	printf("vvedite vozrast: ");
	scanf("%d", &x->age);
	while (p != 1)
	{
		if (x->age < 0 || x->age > 160)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy vozrast: ");
			scanf("%d", &x->age);
		}
		else
		{
			p = 1;
		}
	}
}

void vvodnumber(struct zapic  * x)
{
	int p = 0;
	printf("vvedite nomer(vida 89999999999): ");
	scanf("%lld", &x->number);
	while (p != 1)
	{
		if (x->number < 80000000000 || x->number > 89999999999)
		{
			printf("erorr!!!!");
			printf("vvedite korektniy nomer: ");
			scanf("%lld", &x->number);
		}
		else
		{
			p = 1;
		}
	}
}

void vvodel(struct zapic  * x)
{
	vvodnomer(x);
	vvodimya(x);
	vvodfamilia(x);
	vvodpol(x);
	vvodvozrast(x);
	vvodnumber(x);
}

void vivodnomer(struct zapic *x)
{
	printf("%d. ",x->nomer);
}

void vivodimya(struct zapic *x)
{
	printf("%s ",x->name);
}

void vivodfamilia(struct zapic *x)
{
	printf("%s ",x->surname);
}

void vivodpol(struct zapic *x)
{
	printf("%s ",x->pol);
}

void vivodvozrast(struct zapic *x)
{
	printf("%d ",x->age);
}

void vivodnumber(struct zapic *x)
{
	printf("%lld ",x->number);
}

void vivodel(struct zapic *x)
{
	vivodnomer(x);
	vivodimya(x);
	vivodfamilia(x);
	vivodpol(x);
	vivodvozrast(x);
	vivodnumber(x);
	printf("\n");
	
}

void poisk(struct zapic *x,struct zapic *y)	
{
	int n;
	int p = 0;
	printf("vvedite interval dlya poiska(1,2,3): ");
	scanf("%d",&n);
	while (p != 1)
	{
		if (n < 0 || n > 3 )
		{
			printf("erorr!!!!");
			printf("vvedite interval poiska(1,2,3): ");
			scanf("%d ",&n);
		}
		else
		{
			p = 1;
		}
	}
	p = 0;
	if(n == 1)
	{
		if (x->age >= 0 && x->age < 30)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(x);
		}
		if (y->age >= 0 && y->age < 30)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(y);
		}
	}
	if(n == 2)
	{
		if (x->age >= 30 && x->age < 60)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(x);
		}
		if (y->age >= 30 && y->age < 60)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(y);
		}
	}
	if (n == 3)
	{
		if (x->age >= 60 && x->age < 160)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(x);
		}
		if (y->age >= 60 && y->age <160)  
		{
			p++;
			printf("naiden %d element:",p);
			vivodel(y);
		}	
	}
	if(p == 0)
	{
		printf("ne naideno!!!!\n");
	}
}

void redact(struct zapic *x,struct zapic *y)
{
	struct zapic c = {0};
	if (strcmp(x->surname, y->surname) == 1)
	{
		c.nomer  = x->nomer;
		x->nomer = y->nomer;
		y->nomer = c.nomer;
	}
	vivodel(y);
	vivodel(x);
}
int main()
{
	struct zapic a = { 0 };
	struct zapic b = { 0 };
	vvodel(&a);
	vvodel(&b);
	redact(&a,&b);
	poisk(&a,&b);
	vivodel(&a);
	vivodel(&b);
	return 0;
	system("pause");
}
