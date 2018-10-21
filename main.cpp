#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "main.h"
#include "sha.h"

int main(int argc, char *argv[])
{
	unsigned char a[32] = {0};
	CSHA256 *My_sha = new CSHA256();
	My_sha->Write((unsigned char *)"caixianzhang", 12);
	My_sha->Finalize(a);
	for(int i = 0;i < 32; i++)
	{
		printf("%02x",a[i]);
	}
	printf("\n");
    return 0;
}


