/* The Linux "driver" for my EEPROM programmer */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define DEVICE "/dev/usb/lp0"

int lptw(const char);

int main (int argc, char **argv)
{
	/*if (argc != 2)
	{
		fprintf(stderr, "Usage: lpt <hexadecimal data>\n");
		return -1;
	}

	unsigned char data = strtol(argv[1], NULL, 16); */

	lptw(btoi("01110000"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
		
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA

	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
   	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA

	lptw(btoi("01110100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110111"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA

	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110101"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("01110100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
   	lptw(btoi("01110110"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA

	//write
	lptw(btoi("01111100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("00101100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA

	int i, x;
	for (i = 0; i<1000000000; i++)
		x=0;

	//read
	lptw(btoi("11111100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
	lptw(btoi("10011100"));//nDE, nCE, nOE, nWE, nECLK, nCLR, ADDR, DATA
		
	return 0;
}

int btoi (char* bin)
{
	int i;
	int dec = 0;
	
	for (i = 0; i < 8; i++)
	{
		dec = dec * 2 + (bin[i] == '1' ? 1 : 0);
	}
	
	return dec;
}

int lptw(const char data)
{
	static int errors = 0;
	int fd = open(DEVICE, O_WRONLY);
	
	if (fd < 0)
	{
		errors++;
		fprintf(stderr, "Could not communicate with port. Errno %i\n", errors);
		return -1;
	}
	
	write(fd, &data, 1);

	#ifdef _DEBUG
	printf("Data written to the port was %X\n", data);
	#endif
	
	close(fd);

}
