#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int permut(char *a, char *b);

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

int main(int argc, char **argv)
{
	char *a;
	char *b;
	int i;

	a = ft_calloc(ft_strlen(argv[1]));
	i = 0;
	while(argv[1][i])
	{
		a[i] = argv[1][i];
		i++;
	}
	b = ft_calloc(ft_strlen(a));
	if(argc != 2)
	{
		printf("\n");
		return(0);
	}

 	permut(a, b);
	free(a);
	free(b);
	return(0);
}

int permut(char *a, char *b)
{
	int n;
	int i;
	int l;
	char c;
	char *d;
	char *e;

	n = ft_strlen(a);
	l = 0;
	d = ft_calloc(n);
	e = ft_calloc(n);

	if(n == 1)
	{
		printf("%s%s\n", b, a);
		return(0);
	}
	l = 0;
	while(l < n)
	{
		i = 0;
		while(b[i] != '\0')
		{
			d[i] = b[i];
			i++;
		}
		d[i] = a[0];
		i = 0;
		while(a[i+1] != '\0')
		{
			e[i] = a[i+1];
			i++;
		}
		e[i] = '\0';
		permut(e, d);
		l++;
		c = a[0];
		a[0] = a[l];
		a[l] = c;
	}
	free(d);
	free(e);
	return(0);
}

