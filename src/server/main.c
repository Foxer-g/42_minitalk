/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 07:58:17 by toespino          #+#    #+#             */
/*   Updated: 2026/02/16 19:33:46 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handle(int32_t signal, siginfo_t *info, void *context)
{
	static int32_t	i = 0;
	static char		caracter = 0;

	(void)context;
	if (i <= 7)
	{
		caracter |= ((signal & 1) << i);
		i++;
	}
	else
	{
		ft_printf("%c", caracter);
		if (caracter == 0)
			kill(info->si_pid, SIGUSR1);
		i = 0;
		caracter = 0;
	}
}

int32_t	main(void)
{
	struct	sigaction	sig_action;
	int32_t				id;

	id = getpid();
	ft_printf("%d\n", id);
	sig_action.sa_sigaction = sig_handle;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (true)
		pause();
}
