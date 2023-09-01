
#ifndef	HEAD_H
# define HEAD_H

# include <stdio.h>

# define CMP_RR(a, b) ((a) == (b));
# define CMP_PB(a, b) ((a) < (b));
# define CMP_LB(a, b) ((a) > (b));

typedef struct	node
{
	int			data;
	char		text;
	struct		*left;
	struct		*right;
	struct		*parent;
} 				node;

#endif
