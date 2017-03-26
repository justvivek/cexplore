#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define MAXLEN 20
#define MAXFILES 10
#define VFS_OPEN 1
#define VFS_CLOSE 0
#define CREATE_ERROR 11

struct vfs_file_info{
	char fname[MAXLEN];
	long f_offset;
	long f_size;
};

struct vfs_info{
	char vfs_name[MAXLEN];
	long size;
	int num_files;
};

struct vfs_header_info{
	struct vfs_info v_info;
	struct vfs_file_info files[MAXFILES];
};

struct vfs{
	struct vfs_header_info header;
	FILE* fp;
	int vfs_status;	
};

int vfs_create(char* );

int extract(char*, char*);

int save_vfs(char*, char*);

int load_vfs(char*);

int vfs_close();

