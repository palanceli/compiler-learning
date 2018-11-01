#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int token;	// current token
char *src, *old_src;	// pointer to source code string
int poolsize; 	// default size of text/ data/ stack
int line;	// line number

void next(){
	token = *src++;
	return;
}

void expression(int level){
	// do nothing
}

void program(){
	next();		// get next token
	while(token > 0){
		printf("token is: %c\n", token);
		next();
	}
}

int eval(){
	// do nothing yet
	return 0;
}

int main(int argc, char **argv){
	int i;
	argc--;
	argv++;
  
  char* srcfilePath = *argv;

	poolsize = 256 * 1024;	// arbitrary size
	line = 1;
  
  FILE *fd = fopen(srcfilePath, "rb");
	if(fd == NULL){
		printf("could not open(%s)\n", srcfilePath);
		return -1;
	}
  fseek(fd, 0L, SEEK_END);
  int cbFilesize = ftell(fd);
  fseek(fd, 0L, SEEK_SET);

	if(!(src = old_src = malloc(cbFilesize))){
		printf("could not malloc(%d) for source area\n", poolsize);
		return -1;
	}
  memset(src, 0, cbFilesize);

	// read the source file
  if(fread(src, cbFilesize, 1, fd) <= 0){
		printf("read() returned %d\n", 1);
		return -1;
	}
	fclose(fd);

	program();
	return eval();
}
