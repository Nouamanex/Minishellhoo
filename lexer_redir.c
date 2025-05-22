#include "minishell.h"

t_redir *create_redir(int type, char *filename)
{
    t_redir *new;
    new = malloc(sizeof(t_redir));
    new->filename = ft_strdup(filename);
    new->type = type;
    new->next = NULL;
    return new;
}

// void add_redir()
// {

// }