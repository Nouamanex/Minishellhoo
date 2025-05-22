/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchagour <nchagour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:02:24 by nchagour          #+#    #+#             */
/*   Updated: 2025/05/22 23:23:19 by nchagour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {

    const char * path = getenv( "PATH" );
    printf( "PATH environment variable == %s\n", path );

    return 0;
}
