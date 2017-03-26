//vfs_create.c
#include <stdio.h>
#include <string.h>
#include "vfs_info.h"

char * vfs_create()
{
	char vfs_n[MAXLEN],c;
	printf("Enter the name of VFS: ");
	scanf("%s",vfs_n);
	int * temp,i;
	#ifdef DEBUG
	printf("%s",vfs_n);
	#endif
	fptr = fopen(vfs_n, "rb+");
	if(fptr == NULL) //if file does not exist, create it
	{
   		fptr = fopen(vfs_n, "wb+");
       //updating status of vfs
      vs.header = &vhi;
      vs.vfs_fp=fptr;
      vs.vfs_status=VFS_OPEN;
   		printf("New File System Created with name: %s\n",vfs_n);
      //update vfs_info
      strcpy(vi.vfs_name,vfs_n);
      vi.num_of_files=0;
      vi.size_of_vfs=sizeof(struct vfs_header_info);

      //update vfs_header_info
   		vhi.vinfo=vi;

     // vhi.file_info[0]=NULL;
   		#ifdef DEBUG
   		printf("size of everything in VFS is \n");
   		printf("size of vfs_name in VFS is %zuB\n",sizeof(vhi.vinfo.vfs_name));
   		printf("size of num_of_files in VFS is %zuB\n",sizeof(vhi.vinfo.num_of_files));
   		printf("size of size_of_vfs valriable in VFS is %zuB\n",sizeof(vhi.vinfo.size_of_vfs));
   		#endif

   		printf("VFS name is: %s\nnumber of file currently present: %d\nsize of Header is: %dB\n",vhi.vinfo.vfs_name, vhi.vinfo.num_of_files, vhi.vinfo.size_of_vfs);
   		fseek(fptr,0,SEEK_SET);
      fwrite(&vhi,sizeof(struct vfs_header_info),1,fptr);
      printf("Header info stored successfully in the File\n");
      //return vhi.vinfo.vfs_name;
      fclose(fptr);
      vs.vfs_status=VFS_CLOSE;
      fptr=NULL;
	}
	else
	{
		printf("file already present\n");
    //return 0;
	}
  return &vfs_n;
}
void vfs_extract(char *vfs_n)
{
  //vfs_open(vfs_n);
 char existing_file_name[30];
  char new_file_name[30];
  int i,j;
  printf("\nEnter the name of the file you want to extract from the VFS: ");
  scanf("%s",existing_file_name);
  if(vs.vfs_status==VFS_CLOSE){
    printf("VFS CLOSED.\n");
    return;
  }
  fseek(fptr,0L,SEEK_SET);
  fread(&vhi,sizeof(struct vfs_header_info),1,fptr);
  #ifdef DEBUG
  printf("\n\ninsideVFS_EXTRACT\n");
  printf("VFS name is: %s\nnumber of file currently present: %d\nsize of Header is: %uB\n",vhi.vinfo.vfs_name, vhi.vinfo.num_of_files, sizeof(struct vfs_header_info));
  printf("Size of Complete File Sys: %d",vhi.vinfo.size_of_vfs);
  #endif
  if(vhi.vinfo.num_of_files==0){
    printf("Zero files in VFS\n");
    return;
  }
  for (i = 1; i <=vhi.vinfo.num_of_files ; i++)
  {
    #ifdef DEBUG
    printf("file name at i %d is tt%stt and existing_file_name is tt%stt",i,vhi.finfo[i].file_name,existing_file_name);
    #endif
    if(strcmp(vhi.finfo[i].file_name,existing_file_name)==0)
    {
      printf("Enter a new name for copying the content to: ");
      scanf("%s",new_file_name);

      long int start_point =vhi.finfo[i].offset;
      fseek(fptr,start_point,SEEK_SET);
      int new_file_size=vhi.finfo[i].file_size;
      FILE *fp = fopen(new_file_name,"wb");
      char c;
      for(j=0;j<new_file_size;j++){
      fread(&c,sizeof(char),1,fptr);
      fwrite(&c,sizeof(char),1,fp);
      }
      printf("contents succesfully stored in the new file : %s\n",new_file_name);
      fclose(fp);
      fp=NULL;
      break;
    }
  }
}
void vfs_close()
{
  fclose(fptr);
  fptr=NULL;
  vs.vfs_status=VFS_CLOSE;
  vs.header=NULL;
  vs.vfs_fp=NULL; 
}