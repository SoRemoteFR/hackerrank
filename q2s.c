
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_env
{
	int size_in;
	int	size_out;
}				t_env;

typedef struct	s_elm
{
	int				data;
	struct s_elm	*next;
}				t_elm;

void	stack_push(t_elm **stack, t_elm *elm)
{
	if (!stack || !elm)
		return ;
	elm->next = *stack;
	*stack = elm;
}

t_elm	*stack_pop(t_elm **stack)
{
	t_elm *tmp;
	if (!*stack)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	return (tmp);
}

t_elm	*stack_new(int data)
{
	t_elm *stack;

	if (!(stack = (t_elm*)malloc(sizeof(t_elm))))
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	stack_print(t_elm *stack, int size)
{
	if (size == 0)
		return ;
	printf("TOP\n");
	while (size--)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
	printf("BOTTOM\n");
}

// push a onto b
void	in2out(t_elm **stack_a, t_elm **stack_b, t_env *env)
{
	t_elm	*tmp;
	env->size_out += env->size_in;
	while(env->size_in > 0)
	{
		tmp = stack_pop(stack_a);
		stack_push(stack_b, tmp);
		env->size_in -= 1;
	}
}


void	enqueue(t_elm **in, t_elm *elm, t_env *env)
{
	stack_push(in, elm);
	env->size_in += 1;
}

void	dequeue(t_elm **in, t_elm **out, t_env *env)
{
	if (env->size_in == 0 && env->size_out == 0)
		return ;
	if (env->size_out == 0)
	{
		in2out(in, out, env);
	}
	stack_pop(out);
	env->size_out -= 1;
}

void	print_queue(t_elm **in, t_elm **out, t_env *env)
{
	if (env->size_in == 0 && env->size_out == 0)
		return ;
	if (env->size_out == 0)
    {
        in2out(in, out, env);
    }
	printf("%d\n", (*out)->data);
}

int		main()
{
	t_elm 	*in, *out;
	int		g, x, req;
	t_env	env;
	FILE	*fd;

	fd = fopen("input", "r");
	env.size_in = 0;
	env.size_out = 0;
	in = (t_elm*)malloc(sizeof(t_elm));
	out = (t_elm*)malloc(sizeof(t_elm));


	fscanf(fd, "%d", &g);
	int i = 0;
	while (i < g)
	{
		fscanf(fd, "%d", &req);
		if (req == 1)
		{
			fscanf(fd, "%d", &x);
			enqueue(&in, stack_new(x), &env);
		}
		else if (req == 2)
		{
			dequeue(&in, &out, &env);
		}
		else if (req == 3)
		{
			print_queue(&in, &out, &env);
		}
		i++;
	}
	return (0);
}	

	
