#include "header.h"

int VFS_unload(){
	if(!v_head){
		printf("load vfs and continue");
		return UNLOAD_FAIL;
	}
	fclose(fp);
	free(v_head);
	v_head=NULL;
	fp=NULL;
	return UNLOAD_SUCCESS;
}