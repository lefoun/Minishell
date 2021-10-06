# include "minishell.h"

void	ft_catch_error(bool error_check, int error_cause)
{
	if (error_check == false)
		return ;
	if (error_cause == MALLOC_ERROR)
	{
		perror("Error ! Malloc Failed.\n");
	}
	else if (error_cause == CMD_NOT_FOUND)
	{
		perror("Error ! command doesn't exist")
	}
	exit(1);
}