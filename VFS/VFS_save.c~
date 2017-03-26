#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOAD_SUCCESS 0 
#define LOAD_FAIL 1
#define SAVE_SUCCESS 0 
#define SAVE_FAIL 1
#define CREATE_SUCCESS 0 
#define CREATE_FAIL 1
#define EXTRACT_SUCCESS 0 
#define EXTRACT_FAIL 1
#define UNLOAD_SUCCESS 0 
#define UNLOAD_FAIL 1

#define MAX_FILE 10

struct VFS_INFO{
	char vfs_name[30];
	int vfs_files;
};

struct VFS_FILE_INFO{
        char vfs_file_name[30];
	int file_offset;
	int file_size;
};

struct VFS_HEADER_INFO{
	struct VFS_INFO vfs_info;
	struct VFS_FILE_INFO vfs_file_info[MAX_FILE];
};
struct VFS_HEADER_INFO *v_head;
FILE *fp;
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
int main(int argc,char *argv[]){
	VFS_create("VFS");
	int flag=VFS_load("VFS");
	if(flag==LOAD_SUCCESS)
		printf("Load successful\n");
	else 
		printf("Could not load vfs\n");

	flag=VFS_save("JsonObject.txt");
	if(flag==SAVE_SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");

	flag=VFS_save("sum.c");
	if(flag==SAVE_SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");


	flag=VFS_extract("JsonObject.txt","NEW_JsonObject.txt");
	if(flag==EXTRACT_SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");

	flag=VFS_extract("sum.c","NEW_sum.c");
	if(flag==EXTRACT_SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");


	return 0;
}



