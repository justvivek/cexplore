//vfs_open
#include <stdio.h>
#include <string.h>
#include "vfs_info.h"

void vfs_open(char *vfs_n)
{
		//FILE *fptr;
	#ifdef DEBUG
	printf("\n\n vfs_open called tt%stt\n",vfs_n);
	#endif
	fptr = fopen(vfs_n, "rb+");
	if(fptr == NULL) //if file does not exist, create it
	{
		printf("No such Virtual File System exists");
		//return -1;
	}
	else
	{
		//check the status of file system-CLOSED or OPEN
		if(vs.vfs_status==VFS_OPEN)
		{
			//load the details of header in struct
			printf("The VFS is in OPEN mode\n");
			fread(&vhi,sizeof(struct vfs_header_info),1,fptr);
			//pointer now points to the first file
			#ifdef DEBUG
			printf("VFS name is: %s\nnumber of file currently present: %d\nsize of Header is: %dB\n",vhi.vinfo.vfs_name, vhi.vinfo.num_of_files, vhi.vinfo.size_of_vfs);
			printf("Size of Complete File Sys: %d",vhi.vinfo.size_of_vfs);
			#endif
		}
		else
		{
			printf("The VFS was in CLOSE mode\n");
			fptr = fopen(vfs_n, "rb+");
			vs.header = &vhi;
      		vs.vfs_fp=fptr;
      		vs.vfs_status=VFS_OPEN;
      		printf("The VFS is in OPEN mode now\n");
			fread(&vhi,sizeof(struct vfs_header_info),1,fptr);
				//pointer now points to the first file
			#ifdef DEBUG
			printf("VFS name is: %s\nnumber of file currently present: %d\nsize of Header is: %dB\n",vhi.vinfo.vfs_name, vhi.vinfo.num_of_files, vhi.vinfo.size_of_vfs);
   			printf("Size of Complete File Sys: %d\n",vhi.vinfo.size_of_vfs);
   				#endif
		}
	}
}
void vfs_save(char *vfs_n)
{
	//vfs_open(vfs_n);
	char file_name[MAXLEN],choice,a;
	//FILE *fptr;
	int file_size,no_of_files_in_vfs,current_file_no;
	//check the status of file system-CLOSED or OPEN
	if(vs.vfs_status==VFS_OPEN)
	{
		//fseek(fptr,sizeof(struct vfs_header_info),SEEK_SET);
		if(vhi.vinfo.num_of_files>=MAX_FILES)
		{
			printf("The VFS already contains MAX_FILES allowed no more files can be added\n");
			//return -1;
		}
		else
		{
			printf("Enter the exixting file name :");
			scanf("%s",file_name);
			
			//update file into struct
			no_of_files_in_vfs=vhi.vinfo.num_of_files;
			current_file_no=no_of_files_in_vfs+1;
			//strcpy(fi[current_file_no].file_name,file_name);
			//fi[current_file_no].offset=fseek(fptr,0L,SEEK_END);
			#ifdef DEBUG
			fseek(fptr,0L,SEEK_END);
			printf("currently fseek end is %d\n",ftell(fptr));
			#endif
			FILE *new_file;
			new_file = fopen(file_name, "rb");
			if(new_file!=NULL)
			{
				fseek(new_file,0L,SEEK_END);
				long int new_file_size=ftell(new_file);
				printf("File size of the filw to be saved: %ld\n",new_file_size);
				strcpy(vhi.finfo[current_file_no].file_name,file_name);
				vhi.finfo[current_file_no].file_size=new_file_size;
	
				if(vhi.vinfo.num_of_files==0)
					vhi.finfo[current_file_no].offset=sizeof(struct vfs_header_info);
				else{
					vhi.finfo[current_file_no].offset=vhi.finfo[vhi.vinfo.num_of_files-1].offset+vhi.finfo[vhi.vinfo.num_of_files-1].file_size;
					}
				fseek(new_file,0L,SEEK_SET);
				fseek(fptr,vhi.finfo[current_file_no].offset,SEEK_SET);
				do {
					a = fgetc(new_file);
					fputc(a, fptr);
				} while (a != EOF);
				fclose(new_file);
				new_file=NULL;
				//fi[current_file_no].file_size=fseek(new_file,0L,SEEK_END);
				//update vfs_info
				//strcpy(vi.vfs_name,vi.vfs_name);
				vhi.vinfo.num_of_files=current_file_no;
				vhi.vinfo.size_of_vfs=vhi.vinfo.size_of_vfs+new_file_size;
				printf("TOtal number of files :%d\n",vhi.vinfo.num_of_files);
				fseek(fptr,0L,SEEK_SET);
				fwrite(&vhi,sizeof(struct vfs_header_info),1,fptr);
				//fflush(fptr);
				#ifdef DEBUG
				printf("earlier size is %d, new file size is%d",vhi.vinfo.size_of_vfs,new_file_size);
				#endif
				

				//update vfs_header_info
				//vhi.vinfo=vi;
				//vhi.finfo[current_file_no]=fi[current_file_no];

				#ifdef DEBUG
				printf("\n\nafter saving\n");
				printf("VFS name is: %s\nnumber of file currently present: %d\nsize of Header is: %uB\n",vhi.vinfo.vfs_name, vhi.vinfo.num_of_files, sizeof(struct vfs_header_info));
				printf("Size of Complete File Sys: %d",vhi.vinfo.size_of_vfs);
				#endif
			}
		}
	}
	else//else of checking VFS_OPEN
	{
		printf("The file is not open\n");
	}
}
