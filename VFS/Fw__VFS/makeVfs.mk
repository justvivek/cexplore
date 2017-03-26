all: vfs_run
vfs_run: vfs.o vfs_open.o vfs_create.o
	gcc -o vfs vfs.c vfs_open.c vfs_create.c
