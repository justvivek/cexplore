#include "header.h"

int main(int argc,char *argv[]){
	VFS_create("test_VFS");
	int flag=VFS_load("test_VFS");
	if(flag==LOAD_SUCCESS)
		printf("Load successful\n");
	else 
		printf("Could not load vfs\n");

	flag=VFS_save("sample1.txt");
	if(flag==SAVE_SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");

	flag=VFS_save("sample2.txt");
	if(flag==SAVE_SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");


	flag=VFS_extract("sample1.txt","NEW_sample1.txt");
	if(flag==EXTRACT_SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");

	flag=VFS_extract("sample2.txt","NEW_sample2.txt");
	if(flag==EXTRACT_SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");


	return 0;
}
