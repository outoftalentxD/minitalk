/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:58:06 by melaena           #+#    #+#             */
/*   Updated: 2021/06/21 18:14:10 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int binary(unsigned char b) 
{
  for (int i = 0; i < 8; i++) 
  {
    printf("%c", (b & 0x80) ? '1' : '0');
    b <<= 1;
  }
  printf("\n");
  return 0;
}

static char byte;
static int size;



void handler(int sig_recieved)
{
	int bit;

	bit = sig_recieved == SIGUSR1; 
	byte += bit;
	size++;
	if (size < 8)
		byte <<= 1;
	if (size > 7)
	{
		write(1, &byte, 1);
		if (!byte)
			write(1, "\n", 1);
		byte = 0;
		size = 0;
	}
}

int main(int argc, char **argv)
{
	printf("SERVER PID: %d\n", getpid());
	byte = 0;
	size = 0;
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return(0);
}
