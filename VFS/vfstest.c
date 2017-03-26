//#include "VFSH.h"

#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 30
#define MAX_FILES 10
#define VFS_OPEN 0
#define VFS_CLOSE 1
#define SUCCESS 0
#define FAIL 1

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
	vhi *header;
	FILE *vfs_fptr;
	int vfs_status;
}vs;

vs vs_stat;
vhi *header;
FILE *fp;


int VFS_create(char name[MAXLEN]){
	vs vs_stat;
	header=(vhi *)malloc(sizeof(vhi));
	strcpy(header->vfs_info.name,name);
	header->vfs_info.num_files=0;
	header->vfs_info.size=sizeof(vhi);
	if((fp=fopen(name,"rb+")) == NULL) {
		printf("VFS File cannot be Created\n");
		return 0;
	}
	else{	
	//	vs_stat.header=header;
	//	vs_stat.vfs_fptr=fp;
	//	vs_stat.vfs_status=VFS_OPEN;	
		fwrite(header,sizeof(vhi),1,fp);
		printf("VFS created successfuly\n");
		fclose(fp);
	//	vs_stat.vfs_status=VFS_CLOSE;
	//	fp=NULL;
		return SUCCESS;
	}
}

int VFS_open(char name[MAXLEN]){
	if((fp=fopen(name,"rb+")) == NULL) {
		printf("VFS File cannot be Created\n");
		return 0;
	}
	else{
		header=(vhi *)malloc(sizeof(vhi));
		fread(header,sizeof(vhi),1,fp);
		vs_stat.header=header;
		vs_stat.vfs_fptr=fp;
		vs_stat.vfs_status=VFS_OPEN;
		return SUCCESS;
	}
}

int VFS_save(char name[MAXLEN]){
	if(vs_stat.vfs_status != VFS_OPEN){
		printf("VFS is not open, Exiting.... \n");
		return FAIL;
	}
	else{
		if(header->vfs_info.num_files < MAX_FILES){
			FILE *temp=fopen(name,"rb+");
			if((temp=fopen(name,"rb+"))== NULL){printf("file cannot be created, exiting..."); return FAIL;}
			else{
				char c;
				int n=header->vfs_info.num_files;
				strcpy(header->vfs_file[n].name,name);
				fseek(temp, 0L, SEEK_END);
				header->vfs_file[n].file_size=ftell(temp);
				if(n==0){
					header->vfs_file[n].offset=sizeof(vhi);
				}
				else{
					header->vfs_file[n].offset=header->vfs_file[n-1].file_size + header->vfs_file[n-1].offset;
				}
				fseek(temp,0L,SEEK_SET);
				fseek(fp,0L,SEEK_END);
				while(!feof(temp)){
					fread(&c,sizeof(char),1,temp);
					fwrite(&c,sizeof(char),1,fp);
				}
				header->vfs_info.num_files+=1;
				fseek(fp,0L,SEEK_SET);
				fwrite(header,sizeof(vhi),1,fp);
				fclose(temp);
			}
		}
	}
	return SUCCESS;
}

int VFS_extract(char name[MAXLEN], char newfile[MAXLEN]){
	int i=0,j=0,k=0,foffset,fsize;
	char c;
	FILE *newfp;
	if(!header){
		printf("VFS is not open, Exiting.... \n");
		return FAIL;
	}
	else{
		for(i; i< header->vfs_info.num_files; i++){
			if((strcmp(header->vfs_file[i].name,name)) ==0){ k=1; break;}
		}
		if(k){
			foffset=header->vfs_file[i].offset;
			fsize=header->vfs_file[i].file_size;
			if((newfp= fopen(newfile,"wb"))  ==NULL){
				printf("New File cannot be opened, Exiting... ");
				return FAIL;
			}
			fseek(newfp,foffset, SEEK_SET);
			for(j;j<fsize;j++){
				fread(&c,sizeof(char),1,fp);
				fwrite(&c,sizeof(char),1,newfp);
			}
			fclose(fp);
			return SUCCESS;
		}
		else{
			printf("File cannot be extracted\n");
			return FAIL;
		}
	}
}	


int VFS_unload(){
	if(!header){
		printf("VFS not loaded, Exiting....");
		return FAIL;
	}
	fclose(fp);
	free(header);
	header=NULL;
	fp=NULL;
	return SUCCESS;
}



int main(){

	VFS_create("VFSfile");
	int flag=VFS_open("VFSfile");
	if(flag==SUCCESS)
		printf("Load successful\n");
	else 
		printf("Could not load vfs\n");

	flag=VFS_save("sample1.txt");
	if(flag==SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");

	flag=VFS_save("sample2.txt");
	if(flag==SUCCESS)
		printf("Save successful\n");
	else 
		printf("Could not be saved\n");


	flag=VFS_extract("sample1.txt","newsample1.txt");
	if(flag==SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");

	flag=VFS_extract("sample2.txt","newsample2.txt");
	if(flag==SUCCESS)
		printf("extract successful\n");
	else 
		printf("Could not be extracted\n");
	return 0;
}
