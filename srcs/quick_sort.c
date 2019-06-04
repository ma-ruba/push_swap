# include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

static int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            ft_swap(&arr[i], &arr[j]); 
        } 
    } 
    ft_swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

static void quick_sort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
} 

t_stack		*find_mediana(t_stack *stack, int nb)
{
	int		*arr;
	int		i;
	t_stack	*copy;
	int		*tmp;

	i = -1;
	tmp = (int*)malloc(sizeof(int) * nb);
	arr = (int*)malloc(sizeof(int) * nb);
	copy = stack;
	while (++i < nb)
	{
		arr[i] = copy->data;
		copy = copy->prev;
	}
	while (--i >= 0)
		tmp[i] = arr[i];
	quick_sort(tmp, 0, nb - 1);
	copy = stack;
	while (copy->data != tmp[nb / 2])
		copy = copy->prev;
	free(tmp);
	free(arr);
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
