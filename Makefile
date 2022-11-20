build: clean
	gcc -c pam.c -o pam.o -I. -fPIC
	gcc -c ssh.c -o ssh.o -I. -fPIC
	gcc pam.o ssh.o -o libpam_ssh.so -lpam -lssh -shared -fPIC
clean:
	rm -f *.o *.so
