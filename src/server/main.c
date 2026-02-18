/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 07:58:17 by toespino          #+#    #+#             */
/*   Updated: 2026/02/18 06:46:25 by f0xer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*join_write(char *str, char c)
{
	char	*res;
	int32_t	i;
	int32_t	len;

	res = NULL;
	len = ft_strlen(str);
	if (c == '\0')
		ft_printf("%s\n", str);
	else
	{
		res = malloc(len + 2);
		if (!res)
			return (str);
		i = 0;
		while (i < len)
		{
			res[i] = str[i];
			i++;
		}
		res[i++] = c;
		res[i] = '\0';
	}
	free(str);
	str = NULL;
	return (res);
}

static void	sig_handle(int32_t signal, siginfo_t *info, void *context)
{
	static int32_t	i = 0;
	static char		character = 0;
	static char		*str = NULL;

	(void)context;
	if (!str)
		str = ft_strdup("");
	if (signal == SIGUSR1)
		character |= (1 << i);
	i++;
	if (i >= 8)
	{
		str = join_write(str, character);
		i = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int32_t	main(void)
{
	struct	sigaction	sig_action;
	const int32_t		id = getpid();

	ft_printf("[SYS] server pid : %d\n", id);
	sig_action.sa_sigaction = sig_handle;
	sig_action.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_action.sa_mask);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (true)
		pause();
}
