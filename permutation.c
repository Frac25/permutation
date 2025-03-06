#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int permut(char *a, char **tab, int it, int z);

int ft_strlen(char *a)
{
	int i;

	i = 0;
	while(a[i])
		i++;
	return(i);
}

int ft_fn(int n)
{
	int i;
	int fn;

	fn = 1;
	i = 1;
	while(i <= n)
	{
		fn= fn * i;
		i++;
	}

	return(fn);
}

int main(void)
{
	char a[] = "abcd";
	char **tab;
	int i;
	int n;
	int fn;

	n =ft_strlen(a);
	fn = ft_fn(n);
	printf("dans main, n = %d , fn = %d\n", n, fn);

	tab = malloc(sizeof(char*) * (fn + 1));
	tab[fn] = NULL;

	i = 0;
	while(i < fn)
	{
		tab[i] = malloc(sizeof(char) *( n + 1));
		tab[i][n] = '\0';
		i++;
	}

	permut(a, tab, 0, 0);

	i = 0;
	while(i < fn)
	{
		printf("%c%c\n", tab[i][0], tab[i][1]);
	//	printf("%s\n", tab[i]);
		i++;
	}

	return(0);
}

int permut(char *a, char **tab, int it, int z)
{
	int n;
	int l;
	int m;
	int k;
	int fn;
	char c;

	n = ft_strlen(a);
	fn = ft_fn(n -1);
//	printf("dans permut, n = %d , fn = %d\n", n, fn);

	if(a[0] == '\0')
	{
		printf("return0\n");
		return(0);
	}

	k = 0;
	while(k < ft_fn(n)){
	l = 0;
	while(l < n)
	{
		printf("a = %s\n", a);
		m = 0;
		while (m < fn)
		{
			printf("l = %d   m = %d   fn = %d   z = %d   k = %d   it = %d   a[l] = %c\n", l, m, fn, z, k, it, a[0]);
			tab[z + k][it] = a[0];
			k++;
			m++;
		}


		char b[5];
		int i;

		i = 0;
		while(a[i+1])
		{
			b[i] = a[i + 1];
			i++;
		}
		b[i] = '\0';

		if(it < 1)
		{
			printf("permut de : l = %d   m = %d   fn = %d   z = %d   k = %d   it = %d   b = %s\n", l, m, fn, z, k, it, b);
			permut(b, tab, it + 1, z);
			z =  z + fn;
		}
		else
			printf("it >= 1\n");


		l++;



		c = a[0];
		a[0] = a[l];
		a[l] = c;


//		printf("a2 = '%s'\n", a);

	}
	}
	return(0);
}

