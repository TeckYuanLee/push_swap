#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char* argv[])
{
	char** 	str;
	int		i;

	i = 1;
	str = ft_calloc(argc - 1, sizeof(char *));
	while(argv[i])
	{
		str[i - 1] = ft_calloc(ft_strlen(*argv), sizeof(char));
		str[i - 1] = argv[i];
		//str[i] = ft_atoi(*argv);
		printf("%s\n", str[i - 1]);
		free(str[i - 1]);
		i++;
	}
	free(str);
}
