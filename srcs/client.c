/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:41:32 by melaena           #+#    #+#             */
/*   Updated: 2021/06/21 18:14:53 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int send_byte(int pid, char c)
{
	int offset;

	offset = 7;
	while (offset > -1)
	{
		if ((c >> offset) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		offset--;
	}
	return (0);
}

int send_message(int pid, char *message)
{
	int len;
	int i;
	int offset;
	
	offset = 0;
	i = -1;
	len = strlen(message);
	while (++i <= len)
		send_byte(pid, message[i]);			
	return (0);
}

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

int main(int argc, char **argv)
{
	char *message;
	int	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message = argv[2];
		send_message(pid, message);
	}
	else
	{
		printf("TEST_MODE:\n");
		char byte;
		int bit;
		byte = '1';
		char newbyte = 0;
		
		for (int offset = 7; offset > -1; offset--)
		{
			bit = (byte >> offset) & 1;
			printf("%d", bit);
			newbyte += bit;
			if (offset > 0)
				newbyte <<= 1;
		}	
		printf("\nnewbyte: ");
		binary(newbyte);
		printf("\nbyte: ");
		binary(byte);
		printf("%c\n", byte);
		printf("%c\n", newbyte);
	}	
}
