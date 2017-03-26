VFS: VFS.o VFS_create.o VFS_extract.o VFS_load.c VFS_save.o VFS_unload.o
	gcc VFS.o VFS_create.o VFS_extract.o VFS_load.c VFS_save.o VFS_unload.o
VFS.o: VFS.c
	gcc -c VFS.c
VFS_create.o: VFS_create.c
	gcc -c VFS_create.c
VFS_extract.o: VFS_extract.c
	gcc -c VFS_extract.c
VFS_load.o: VFS_load.c
	gcc -c VFS_load.c
VFS_save.o: VFS_save.c
	gcc -c VFS_save.c
VFS_unload.o: VFS_unload.c
	gcc -c VFS_unload.c
clean:
	rm -rf *.o VFS
