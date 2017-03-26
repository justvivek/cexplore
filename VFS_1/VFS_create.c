#include "header.h"

int VFS_create(char name[30]){
	struct VFS_HEADER_INFO *v_head=(struct VFS_HEADER_INFO*)malloc(sizeof(struct VFS_HEADER_INFO));
	strcpy(v_head->vfs_info.vfs_name,name);
	v_head->vfs_info.vfs_files=0;


	// writing the struct variable to file
	FILE *fp = fopen(name,"wb");
	if(fp==NULL){
		printf("VFS could not be created!!\n");
		return CREATE_FAIL;
	}
	fwrite(v_head,sizeof(struct VFS_HEADER_INFO),1,fp);
	printf("VFS created \n");
	fclose(fp);
	return CREATE_SUCCESS;
}
