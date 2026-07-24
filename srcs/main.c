#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	t_mode	mode;
	int		bench;
	if (argc == 1)
		return (0);

	i = 1;
	mode = mode_none;
	bench = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			mode = mode_simple;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			mode = mode_medium;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			mode = mode_complex;
		else if (ft_strcmp(argv[i], "--adaptative") == 0)
			mode = mode_adaptative;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			bench = 1;
		else
			return (1);
		i++;
	}

	if (mode == mode_none)
		return (1);

	return (0);
}
