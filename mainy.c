#include <stdlib.h>
#include <errno.h>
int main(void)
{
	char *bidule = malloc(-1);
	perror("Minishell");
	printf("%d\n", errno);
	return (0);
}
