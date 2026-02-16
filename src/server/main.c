/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 07:58:17 by toespino          #+#    #+#             */
/*   Updated: 2026/02/16 17:18:33 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int32_t	main(void)
{
	struct	sigaction	sig_action;
	int32_t				id;

	id = get_pid();
	ft_printf("%d\n", id);
	sig_action.sa_sigaction = ;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (true)
		pause();
}
