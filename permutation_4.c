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
	char fix[ft_strlen(f) + 1];
	char tab[ft_strlen(t) - 1];
	int i = 0;
	int j = 0;
	int l = ft_strlen(t);

	if(l == 1)
	{
		printf("%s%s\n", f, t);
		return(0);
	}
	while(i < l)
	{
		j = 0;
		while(j < ft_strlen(f))
		{
			fix[j] = f[j];
			j++;
		}
		fix[j] = t[0];
		fix[j + 1] = '\0';
		j = 0;
		while(j + 1 < ft_strlen(t))
		{
			tab[j] = t[j + 1];
			j++;
		}
		tab[j] = '\0';
		permut(tab, fix);
		i++;
		c = t[0];
		t[0] = t[i];
		t[i] = c;
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

	char a[ft_strlen(argv[1]) + 1 ];
	char b[1];
	b[0] = '\0';
	int i = 0;
	while (argv[1][i])
	{
		a[i] = argv[1][i];
		i++;
	}
	a[i] = '\0';
	tri(a);
	permut(a, b);
	return(0);
}
