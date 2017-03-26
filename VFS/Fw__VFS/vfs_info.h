//vfs_info.h

#define VFS_OPEN 0
#define VFS_CLOSE 1
#define MAX_FILES 10
#define MAXLEN 100

FILE *fptr;

struct file_info
{
	char file_name[MAXLEN];
	int offset;//start offset of file
	int file_size;
}fi[MAX_FILES];
struct vfs_info
{
	char vfs_name[MAXLEN];
	int num_of_files;
	int size_of_vfs;
}vi;
struct vfs_header_info
{
	struct vfs_info vinfo;
	struct file_info finfo[MAX_FILES];
}vhi;
struct vfs_status
{
	struct vfs_header_info * header;
	FILE *vfs_fp;
	int vfs_status;
}vs;

int calculate_size();
char * vfs_create(void);
void vfs_open(char *vfs_n);
void vfs_save(char *vfs_n);
void vfs_close();