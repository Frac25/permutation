#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int ft_strlen(char *a)
{
	int i;

	i = 0;
	while(a[i])
		i++;
	return(i);
}

char *ft_calloc(int n)
{
	char *a;
	int i;

	a = malloc(sizeof(char) * (n + 1));
	i = 0;
	while(i <= (n + 1))
	{
		a[i] = '\0';
		i++;
	}
	return(a);
}

int tri(char *a)
{
	int i = 0;
	char c;

	while(i  < ft_strlen(a) - 1)
	{
		if(a[i] > a[i + 1])
		{
			c = a[i];
			a[i] = a[i+1];
			a[i+1] = c;
			i = 0;
		}
		else
			i++;
	}
	return(0);
}

int permut(char *t, char *f)
{
	char c;
	char *fix = ft_calloc(ft_strlen(f) + 1);
	char *tab = ft_calloc(ft_strlen(t) - 1);
	int i = 0;
	int j = 0;
	int k = 0;
	int l = ft_strlen(t);

	if(l == 1)
	{
		printf("%s%s\n", f, t);
		return(0);
	}

	while(i < l)
	{
		//fixe le debut

		j = 0;
		while(f[j])
		{
			fix[j] = f[j];
			j++;
		}
		fix[j] = t[0];


		//ecrit le rest
		j = 0;
		while(t[j + 1])
		{
			tab[j] = t[j + 1];
			j++;
		}
		tab[j] = '\0';

	//	printf("tab = %s et fix = %s\n", tab, fix);
		permut(tab, fix);

		i++;

		c = t[0];
		t[0] = t[i];
		t[i] = c;
//		printf("t = %s et f = %s\n\n", tab, fix);


	}

	return(0);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("argc KO\n");
		return(0);
	}

	int n = ft_strlen(argv[1]);
	char *a = ft_calloc(n);
	char *b = ft_calloc(0);

	int i = 0;
	while (argv[1][i])
	{
		a[i] = argv[1][i];
		i++;
	}

	tri(a);

	printf("a = %s et b = %s\n", a, b);

	permut(a, b);

	free(a);
	free(b);

	return(0);
}
