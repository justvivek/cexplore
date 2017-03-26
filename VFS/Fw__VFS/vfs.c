#include <stdio.h>
#include <string.h>
#include "vfs_info.h"

int main()
{
	char choice,choice2, *vfs_name;
	printf("Creating a VIRTUAL FILE SYSTEM\n");
	vfs_create();
	vfs_open(vhi.vinfo.vfs_name);

	while(1)
	{
		printf("\nEnter choices for VFS\n\n3-save\n4-extract\n5-close\n");
		scanf("\n%c",&choice);
		switch(choice)
		{
			case '3':do
						{
							vfs_save(vfs_name);
							printf("\nsave more files ??\nyes-y\n");
							scanf("\n%c",&choice2);
							if(choice2!='y'&&choice2!='Y')
								break;
						}while(1);
			break;
			case '4':do
						{
							vfs_extract(vfs_name);
							printf("\nExtract more files and save in another file??\nyes-y\n");
							scanf("%c",&choice2);
							if(choice2!='y'&&choice2!='Y')
								break;
						}while(1);
			break;
			case '5':vfs_close();
			break;
			default:printf("thank you\n");return 0;
		}
	}
	return 0;
}
