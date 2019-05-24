# include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

static void quick_sort(int beg, int end, int *arr)
{
	int		left;
	int		right;
	int		piv;
  
	left = beg;
	right = end;
	piv = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < piv)
			left++;
		while (arr[right] > piv)
			right--;
		if (left <= right)
		{
			if(arr[left] != arr[right])
				ft_swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (beg < right && right != end)
		quick_sort(beg, right, arr);
	if (end > left && left != beg)
		quick_sort(left, end, arr);
}

t_stack		*find_mediana(int argc, char **argv, t_stack *stack)
{
	int		arr[argc - 2];
	int		length;
	int		tmp[argc - 2];
	int		mediana;
	t_stack	*med;

	length = argc - 1;
	while (argc > 1)
	{
		arr[argc - 2] = ft_atoi(argv[argc - 1]);
		tmp[argc - 2] = arr[argc - 2];
		argc--;
	}
	quick_sort(tmp[1], tmp[length - 1], tmp);
	mediana = tmp[length / 2 - 1];
	while (length > 0)
	{
		if (arr[length - 1] == mediana;)
			break ;
		length--;
	}
	med = find_elem(length, stack);
	return (med);
}

t_stack		*find_elem(int number, t_stack *stack)
{
	t_stack	*mediana;

	mediana = stack;
	while (number > 0)
	{
		mediana = mediana->prev;
		number--;
	}
	return (mediana);
}

t_stack 	*find_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->prev)
		last = last->prev;
	return (last);
}
