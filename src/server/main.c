/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 07:58:17 by toespino          #+#    #+#             */
/*   Updated: 2026/02/16 15:11:42 by f0xer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int32_t	main(void)
{
	struct	sigaction	sa;
	pid_t				id;

	id = get_pid;
	ft_printf("%d\n", id);
	sa.sa_sigaction = display;
	sigemptyset()
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
}
