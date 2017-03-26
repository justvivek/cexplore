#include "header.h"

int VFS_load(char name[30]){
	
	fp=fopen(name,"r+b");
	if(!fp){
		printf("VFS could not be loaded!!\n");
		return LOAD_FAIL;
	}

	v_head=(struct VFS_HEADER_INFO*)malloc(sizeof(struct VFS_HEADER_INFO));
	//to bring to RAM
	fread(v_head,sizeof(struct VFS_HEADER_INFO),1,fp);
	//printf("%s\n",v_head->vfs_info.vfs_name);
	return LOAD_SUCCESS;
}
