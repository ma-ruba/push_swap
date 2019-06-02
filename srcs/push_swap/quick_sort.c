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

t_stack		*find_mediana(t_stack *stack, int nb)
{
	int		arr[nb - 1];
	int		i;
	t_stack	*copy;
	int		*tmp;

	i = -1;
	tmp = (int*)malloc(sizeof(int) * (nb - 1));
	copy = stack;
	while (++i < nb)
	{
		arr[i] = *copy->data;
		copy = copy->prev;
	}
	while (--i >= 0)
		tmp[i] = arr[i];
	quick_sort(tmp[0], tmp[nb - 1], tmp);
	copy = stack;
	while (*copy->data != tmp[nb/2 - 1])
		copy = copy->prev;
	free(tmp);
	return (copy);
}

/*t_stack		*find_elem(int number, t_stack *stack)
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

*/
