#include "deque.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	t_deque	deque;
	t_node	*cur;

	init_deque(&deque);
	//add_front(&deque, 3);
	//add_front(&deque, 2);
	//add_front(&deque, 5);
	printf("ar -> add rear\naf -> add front\ndr -> delete rear\ndf -> delete_front\ngf -> get front\ngr -> get rear\nUsage : [command]\n");
	while (1)
	{
		char	command[3] = {0,};
		int		data = 0;
		
		printf("Input command:");
		scanf("%s", command);
		if (command[0] == 'a')
		{
			printf("Input number:");
			scanf("%d", &data);
			if (command[1] == 'f')
				add_front(&deque, data);
			else
				add_rear(&deque, data);
		}
		else if (command[0] == 'd')
		{
			if (command[1] == 'f')
				delete_front(&deque);
			else
				delete_rear(&deque);
		}
		else
		{
			if (command[1] == 'f')
				printf("\nfront is %d\n", get_front(&deque));
			else
				printf("\nrear is %d\n", get_rear(&deque));
		}
		cur = deque.head;
		printf("\n- Current deque - \n");
		while (cur)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n\n");
	}
	return (0);
}
