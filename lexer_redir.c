#include "minishell.h"

t_redir *create_redir(int type, char *filename)
{
    t_redir *new;
    new = malloc(sizeof(t_redir));
    if (!new)
        return NULL;
    new->filename = ft_strdup(filename);
    new->type = type;
    new->next = NULL;
    return new;
}

void add_redir(t_redir **redirliste, t_redir *new_redir)
{
    t_redir *temp;

    if (!*redirliste)
    {
        *redirliste = new_redir;
        return;
    }
    temp = *redirliste;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_redir;
}

