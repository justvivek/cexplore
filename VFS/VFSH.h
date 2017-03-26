#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 30
#define MAX_FILES 10
#define VFS_OPEN 1
#define VFS_CLOSE 0 

typedef struct VFS_File_Info{
	char name[MAXLEN];
	int offset;
	int file_size;
}vfi;

typedef struct VFS_Info{
	char name[MAXLEN];
	int num_files;
	int size;
}vi;

typedef struct VFS_Header_Info{
	vfi vfs_file[MAX_FILES];
	vi vfs_info;
}vhi;

typedef struct VFS_Status{
	vhi header;
	FILE *vfs_fptr;
	int vfs_status;
}vs;

vs vs_stat;
vhi *header;
FILE *fp;

int VFS_create(char name[MAXLEN]);
int VFS_open(char *name);
int VFS_save(char name[MAXLEN]);
int VFS_extract(char name[MAXLEN], char newfile[MAXLEN]);
int VFS_unload();

