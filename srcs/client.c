/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:27:38 by melaena           #+#    #+#             */
/*   Updated: 2021/07/31 18:41:14 by melaen	a          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_error(char *message, int code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(code);
}

void handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGUSR2)
	{
		ft_putendl_fd("Message was delivered successfully!", 1);
		exit(0);
	}
}

int send_byte(int byte, int pid)
{
	int counter;
	int error;

	counter = 1 << 6;
	while (counter)
	{
		if (counter & byte)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		if (error)
			handle_error("Server is not responding", -1);
		counter >>= 1;
		usleep(10000);
	}
	return (1);
}

int send_message(char *message, int pid)
{
	while (*message)
	{
		send_byte(*message, pid);
		message++;
	}
	send_byte(0, pid);
	return (1);
}

int main(int argc, char **argv)
{
	struct sigaction	action;
	int					pid;
	char				*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
	}
	else 
	{
		ft_putstr_fd("usage: ./client [SERVER_PID] [MESSAGE]\n", 1);
		exit(0);
	}
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_message(message, pid);	
 	return (0);
}
