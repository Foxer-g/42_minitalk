/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:23:24 by toespino          #+#    #+#             */
/*   Updated: 2026/02/16 22:11:33 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ackn_handle(int32_t signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signal;
}

void	send_caracter(int32_t serv_id, unsigned char caracter)
{
	int32_t	to_send;
	int32_t	i;
	
	i = 0;
	while (i <= 7)
	{
		to_send = ((caracter & 1) << i);
		kill(serv_id, to_send);
		i++;
	}
}

int32_t	main(int32_t ac, char **av)
{
	struct	sigaction	sig_action;
	int32_t				serv_id;
	uint64_t			i;

	if (ac != 3)
		return (0);
	serv_id = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_caracter(serv_id , (unsigned char)av[2][i]);
		i++;
	}
	sig_action.sa_sigaction = ackn_handle;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	sigaction(SIGUSR1, &sig_action, NULL);
	while (true)
		pause();
}
