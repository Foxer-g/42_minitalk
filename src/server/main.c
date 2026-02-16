/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 07:58:17 by toespino          #+#    #+#             */
/*   Updated: 2026/02/16 09:12:14 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int32_t	main(void)
{
	struct	sigaction	sa;
	pid_t				id;

	id = get_pid;
	sa.sa_sigaction = display;
	sigemptyset()
	while (true)
		pause();
}
