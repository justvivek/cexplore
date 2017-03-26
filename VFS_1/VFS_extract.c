#include "header.h"

int VFS_extract(char name[30],char new_name[30]){
	
	if(!v_head){
		printf("load vfs and continue");
		return EXTRACT_FAIL;
	}
	else{
		int i=0;
		int file_found=0;

		for(i=0;i<v_head->vfs_info.vfs_files;i++){
			if(strcmp(v_head->vfs_file_info[i].vfs_file_name,name) == 0){
				file_found=1;
				break;
			}
		}
		if(file_found){
			int offset=v_head->vfs_file_info[i].file_offset;
			int size=v_head->vfs_file_info[i].file_size;
			FILE *new_fp = fopen(new_name,"wb");
			if(!new_fp){
				return EXTRACT_FAIL;
			}
			char c;
			fseek(fp,offset,SEEK_SET);
			int i;
			for(i=0;i<size;i++){
				fread(&c,sizeof(char),1,fp);
				fwrite(&c,sizeof(char),1,new_fp);	
			}
			fclose(new_fp);
			return EXTRACT_SUCCESS;
		}
		else{
			return EXTRACT_FAIL;
		}
	}

}