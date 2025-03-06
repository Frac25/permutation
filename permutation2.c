#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int permut(char *a, char **tab, int it, int l2);

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
	printf("test\n");

	char *a = "abcd";
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

//	tab[0][0] = a[0];

		permut(a, tab, 0, 0);

	i = 0;
	while(i < fn)
	{
		//printf("%c\n", tab[i][0]);
		printf("%s\n", tab[i]);
		i++;
	}

	return(0);
}

int permut(char *a, char **tab, int it, int l2)
{
	int n;

	int l;
	int m;
	int fn;

	n = ft_strlen(a);
	fn = ft_fn(n -1);
	printf("dans permut, n = %d , fn = %d\n", n, fn);

		if(a[0] == '\0')
		return(0);

	l = 0;
	while(l < n)
	{
		m = 0;
		while (m < fn)
		{
			printf("l = %d   l2 = %d   m = %d   fn = %d   l2*fn+m = %d   it = %d   l = %d   a[l] = %c\n", l, l2, m, fn, l2*fn+m, it, l, a[l]);
			tab[l2*fn+m][it]=a[l];

			m++;
		}

		char *b;
		int o;
		int p;
		b = malloc(sizeof(char) * n);
		o = 0;
		p = 0;
		while (o < n)
		{
			if(p != l)
			{
				b[o]=a[p];
				o++;
			}
			p++;
		}
		b[o]='\0';
		printf("b = %s\n", b);
		if (it <= 1)
		{
			permut(b, tab, it + 1, l2);
		}
		free(b);

		l2++;
		l++;
	}
	return(0);
}

