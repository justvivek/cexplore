#include "header.h"

int VFS_save(char name[30]){
	if(!v_head){
		printf("load vfs and continue");
		return SAVE_FAIL;
	}
	else{
		if(v_head->vfs_info.vfs_files < MAX_FILE){
			FILE * temp_fp = fopen(name,"rb");
			if(temp_fp==NULL){
					printf("File to be saved is not present!\n");
					return SAVE_FAIL;
			}
			else{
				char c;	
				int n=v_head->vfs_info.vfs_files;
				strcpy(v_head->vfs_file_info[n].vfs_file_name,name);
				fseek(temp_fp,0L,SEEK_END);
				v_head->vfs_file_info[n].file_size=ftell(temp_fp);
				if(n == 0){
					v_head->vfs_file_info[n].file_offset=sizeof(struct VFS_HEADER_INFO);
				}
				else{
					v_head->vfs_file_info[n].file_offset = v_head->vfs_file_info[n-1].file_offset + v_head->vfs_file_info[n-1].file_size;
				}
				fseek(temp_fp,0L,SEEK_SET);
				fseek(fp,0L,SEEK_END);
				while(!feof(temp_fp)){
					fread(&c,sizeof(char),1,temp_fp);
					fwrite(&c,sizeof(char),1,fp);
				}
				
				v_head->vfs_info.vfs_files+=1;

				fseek(fp,0L,SEEK_SET);
				fwrite(v_head,sizeof(struct VFS_HEADER_INFO),1,fp);
				fclose(temp_fp);

			}
		}
	}
	return SAVE_SUCCESS;
}