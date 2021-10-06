#include "minishell.h"

int	get_cmd_suffix(char *str, t_token **head)
{
	int		i;
	int		j;
	char	*cmd_suffix;
	char	**cmd_suffix_splited;
	int		ret;

	i = 0;
	while (str[i] && !is_operator(str[i]))
		i++;
	cmd_suffix = malloc((sizeof(*cmd_suffix) * i) + 1);
	if (!cmd_suffix)
		return (2);
	j = 0;
	while (j < i)
	{
		cmd_suffix[j] = str[j];
		++j;
	}
	cmd_suffix[j] = '\0';
	cmd_suffix_splited = ft_split(cmd_suffix, ' ');
	free(cmd_suffix);
	if (cmd_suffix_splited == NULL)
		return (2);
	i = 0;
	while (cmd_suffix_splited[i])
	{
		ret = ft_elem_pushback(head, ft_create_elem(cmd_suffix_splited[i], CMD_SUFFIX));
		if (ret == 2)
			{
				free_tab(cmd_suffix_splited);
				return (2);
			}
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