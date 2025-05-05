#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Helper: get the length of the variable name
int var_name_len(const char *s)
{
    int i = 0;
    while (s[i] && (isalnum(s[i]) || s[i] == '_'))
        i++;
    return i;
}

// Main function
void replace_dollar_variables(char **token_str)
{
    char *str = *token_str;
    char *new_str = calloc(1, 1);
    int i = 0;

    while (str[i])
    {
        if (str[i] == '$' && str[i + 1])
        {
            i++; // skip $
            int len = var_name_len(&str[i]);
            char *var_name = strndup(&str[i], len);
            char *value = getenv(var_name);
            free(var_name);

            if (value)
            {
                char *tmp = new_str;
                new_str = realloc(new_str, strlen(tmp) + strlen(value) + 1);
                strcat(new_str, value);
                free(tmp);
            }
            i += len;
        }
        else
        {
            char letter[2] = {str[i], 0};
            char *tmp = new_str;
            new_str = realloc(new_str, strlen(tmp) + 2);
            strcat(new_str, letter);
            free(tmp);
            i++;
        }
    }

    free(*token_str);
    *token_str = new_str;
}
