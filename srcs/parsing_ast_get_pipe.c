#include "minishell.h"


char	*get_cmd_suffix_string(char *str)
{
	char	*cmd_suffix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && !is_operator(str[i]))
		++i;
	cmd_suffix = malloc((i + 1) * sizeof(*cmd_suffix));
	ft_catch_error(cmd_suffix == NULL, MALLOC_ERROR, cmd_suffix);
	while (j < i)
	{
		cmd_suffix[j] = str[j + i];
		++j;
	}
	cmd_suffix[j] = '\0';
	return (cmd_suffix);
}

int	get_cmd_suffix(char *str, t_token **head)
{
	int		i;
	char	*cmd_suffix;
	char	**splited_cmd_suffix;
	int		ret;

	i = 0;
	cmd_suffix = get_cmd_suffix_string(str);
	splited_cmd_suffix = ft_split(cmd_suffix, ' ');
	ft_catch_error(splited_cmd_suffix == NULL, MALLOC_ERROR, cmd_suffix);
	i = 0;
	while (splited_cmd_suffix[i])
	{
		ret = ft_elem_pushback(head, ft_create_elem(splited_cmd_suffix[i],
								CMD_SUFFIX));
		if (ret == 2)
				return (ft_free_tab(splited_cmd_suffix, MALLOC_ERROR));
		++i;
	}
	return (0);
}

int	get_pipe_cmd_and_suffix(char *str, int index, t_token **head)
{
	char	*cmd;
	int		ret;
	int		i;
	int		j;

	(void)index;
	if (*str != '|' || (*str == '|' && str[1] == '|'))
		return (1);
	i = 1;
	while (is_whitespace(str[i]))
		++i;
	j = 0;
	while (str[i + j] && !is_whitespace(str[i + j]))
		++j;
	cmd = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(cmd, PIPE));
	if (ret == - 1)
	{
		free(cmd);
		return (2);
	}
	ret = get_cmd_suffix(str + j, head);
	return (ret);
}