/* Just for fun -- testing the LPT interface */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int lptw(const char*, const char);

int main (int argc, char **argv)
{
	/*if (argc != 2)
	{
		fprintf(stderr, "Usage: lpt <hexadecimal data>\n");
		return -1;
	}

	unsigned char data = strtol(argv[1], NULL, 16); */

	int i;
	for (i=0; i<500;i++)
		lptw("/dev/usb/lp0", 0x01);

	while (1) {
			
	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x01);
		lptw("/dev/usb/lp0", 0x02);
	}
	
	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x01);
		lptw("/dev/usb/lp0", 0x02);
		lptw("/dev/usb/lp0", 0x04);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x02);
		lptw("/dev/usb/lp0", 0x04);
		lptw("/dev/usb/lp0", 0x08);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x04);
		lptw("/dev/usb/lp0", 0x08);
		lptw("/dev/usb/lp0", 0x10);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x08);
		lptw("/dev/usb/lp0", 0x10);
		lptw("/dev/usb/lp0", 0x20);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x10);
		lptw("/dev/usb/lp0", 0x20);
		lptw("/dev/usb/lp0", 0x40);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x20);
		lptw("/dev/usb/lp0", 0x40);
		lptw("/dev/usb/lp0", 0x80);
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x80);
		lptw("/dev/usb/lp0", 0x40);		
	}
	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x20);
		lptw("/dev/usb/lp0", 0x40);
		lptw("/dev/usb/lp0", 0x80);
	}
	
	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x40);
		lptw("/dev/usb/lp0", 0x20);
		lptw("/dev/usb/lp0", 0x10);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x20);
		lptw("/dev/usb/lp0", 0x10);
		lptw("/dev/usb/lp0", 0x08);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x10);
		lptw("/dev/usb/lp0", 0x08);
		lptw("/dev/usb/lp0", 0x04);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x08);
		lptw("/dev/usb/lp0", 0x04);
		lptw("/dev/usb/lp0", 0x02);		
	}

	for (i=0; i<200;i++) {
		lptw("/dev/usb/lp0", 0x04);
		lptw("/dev/usb/lp0", 0x02);
		lptw("/dev/usb/lp0", 0x01);		
	}

	}
	
	return 0;
}

int lptw(const char* dev, const char data)
{
	static int errors=0;
	int fd = open(dev, O_WRONLY);
	if (fd < 0)
	{
		errors++;
		fprintf(stderr, "Could not communicate with port. Errno %i\n", errors);
		return -1;
	}
	
	write(fd, &data, 1);

	#ifdef _debug
	printf("Data written to the port was %X\n", data);
	#endif
	
	close(fd);

}
