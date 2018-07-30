#include <stdio.h>
#include <stdlib.h>

typedef union {
	unsigned int ip;
	unsigned char octet[4];
} ip_addr_t, * ip_addr_tp; /* we have the normal type as well as the pointer type */

/* functions */
void afiseaza_ip(char *str, ip_addr_t ip);


int main()
{
	ip_addr_t ip, network, broadcast, netmask;
	unsigned char subnet, i;
	/* 192.168.0.35/24  */ 
	/* pt files: sscanf(), sprintf() */
	printf("Scrie IP de forma x.x.x.x/x: ");
	
	while ( 5 != scanf("%hhu.%hhu.%hhu.%hhu/%hhu", &ip.octet[3], &ip.octet[2], 
												   &ip.octet[1], &ip.octet[0], 
												   &subnet)
		  )
	{
		printf("Reincearca IP de forma x.x.x.x/x: ");
	}
	
	printf("Am citit ip-ul %hhu.%hhu.%hhu.%hhu/%hhu\n",
									  ip.octet[3], ip.octet[2], 
									  ip.octet[1], ip.octet[0], 
									  subnet);
	
	/* get netmask from subnet */
	netmask.ip = 0xFFFFFFFF;
	
	for (i=0; i<32-subnet; i++)
	{
		//netmask.ip &= ~(1<<(31-i));
		netmask.ip &= ~(1<<(i));
	}
	
	afiseaza_ip("Netmask este %hhu.%hhu.%hhu.%hhu\n", netmask);
	
	
	/* get network & broadcast */
	
	network.ip = ip.ip & netmask.ip;
	broadcast.ip = ip.ip | ~(netmask.ip);
	
	afiseaza_ip("Network address este %hhu.%hhu.%hhu.%hhu\n", network);
	afiseaza_ip("Broadcast address este %hhu.%hhu.%hhu.%hhu\n", broadcast);
	
	return 0;
}

void afiseaza_ip(char *str, ip_addr_t ip)
{
	printf(str, ip.octet[3], ip.octet[2], ip.octet[1], ip.octet[0]);
}
