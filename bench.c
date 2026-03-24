#include "push_swap.h"

int	total_ops(t_data *data)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
		total += data->ops[i++];
	return (total);
}

static char	*get_strategy(int flag)
{
	if (flag == 0)
		return ("Simple O(n^2)");
	if (flag == 1)
		return ("Medium O(n*sqrt(n))");
	if (flag == 2)
		return ("Complex O(n log n)");
	return ("Adaptive");
}

static void	print_percent(double d, int fd)
{
	int	whole;
	int	frac;

	whole = (int)(d * 100);
	frac = (int)(d * 10000) % 100;
	ft_putnbr_fd(whole, fd);
	write(fd, ".", 1);
	if (frac < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(frac, fd);
}

void	print_bench(t_data *data, double disorder, int flag)
{
	static char	*names[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	write(2, "Disorder:  ", 11);
	print_percent(disorder, 2);
	write(2, "%\n", 2);
	write(2, "Strategy:  ", 11);
	write(2, get_strategy(flag), ft_strlen(get_strategy(flag)));
	write(2, "\n", 1);
	write(2, "Total ops: ", 11);
	ft_putnbr_fd(total_ops(data), 2);
	write(2, "\n", 1);
	i = 0;
	while (i < 11)
	{
		write(2, names[i], ft_strlen(names[i]));
		write(2, ": ", 2);
		ft_putnbr_fd(data->ops[i], 2);
		write(2, "\n", 1);
		i++;
	}
}