/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:27:37 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 21:17:10 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signum, siginfo_t *siginfo, void *context)
{
	static char	byte;
	static int	len;
	int			bit;
	
	(void)context;
	bit = (signum == SIGUSR1);
	byte <<= 1;
	byte += bit;
	len++;
	if (len == 7)
	{
		if (!byte)
			kill(siginfo->si_pid, SIGUSR2);
		ft_putchar_fd(byte, 1);
		len = 0;
		byte = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
	return ;
}

int main()
{
	struct sigaction action;

	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
