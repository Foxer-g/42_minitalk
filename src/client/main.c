/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:23:24 by toespino          #+#    #+#             */
/*   Updated: 2026/02/19 16:21:08 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

bool	ft_isfulldigit(char *string)
{
	int32_t	i;
	bool	res;

	res = true;
	i = 0;
	while (string[i])
		if (!ft_isdigit(string[i++]))
			res &= false;
	return (res);
}

void	ackn_handle(int32_t signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signal;
	g_ack = 1;
}

void	send_caracter(int32_t serv_id, unsigned char caracter)
{
	int32_t	to_send;
	int32_t	i;

	i = 0;
	while (i < 8)
	{
		if (caracter & 1)
			to_send = SIGUSR1;
		else
			to_send = SIGUSR2;
		g_ack = 0;
		kill(serv_id, to_send);
		while (!g_ack)
			pause();
		caracter >>= 1;
		i++;
	}
}

int32_t	main(int32_t ac, char **av)
{
	struct sigaction	sig_action;
	int32_t				serv_id;
	uint64_t			i;

	if (ac != 3)
	{
		ft_printf("client take two parameters : ./client <serv_id> <message>");
		return (0);
	}
	serv_id = ft_atoi(av[1]);
	if (serv_id <= 1 || !ft_isfulldigit(av[1]))
	{
		ft_printf("ERROR : Invalid pid");
		return (0);
	}
	sig_action.sa_sigaction = ackn_handle;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	sigaction(SIGUSR1, &sig_action, NULL);
	i = 0;
	while (av[2][i])
		send_caracter(serv_id, (unsigned char)av[2][i++]);
	send_caracter(serv_id, 0);
	ft_printf("[SYS] message succesfully received\n");
}
