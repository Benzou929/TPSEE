#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
        const char dem[2] = ":";
	FILE *fcpu;
        int buffSize = 1024;
	char buffer [buffSize];
        char *line;
	char *mychar;
	
	fcpu = fopen("/proc/cpuinfo","r");
 	if(fcpu == NULL)
		exit(EXIT_FAILURE);
        while(line = fgets(buffer,1024,fcpu)) {
        	mychar =  strtok(line,dem);
    		if(strcmp(mychar,"model name	") == 0 || 
                   strcmp(mychar,"cpu MHz	") == 0 ||
                   strcmp(mychar,"address sizes	") == 0 ||
                   strcmp(mychar,"cache size	") == 0) {
                
                 while( mychar != NULL ) {
                     printf( "%s\n", mychar );
                         
                     mychar = strtok(NULL, dem);
                 }
	}
}
	fcpu = fopen("/proc/meminfo","r");
 	if(fcpu == NULL)
		exit(EXIT_FAILURE);
        while(line = fgets(buffer,1024,fcpu)) {
        	mychar =  strtok(line,dem);
    		if(strcmp(mychar,"MemTotal") == 0 || 
                   strcmp(mychar,"MemFree") == 0) {
                
                 while( mychar != NULL ) {
                     printf( "%s\n", mychar );
                         
                     mychar = strtok(NULL, dem);
                 }
	}       
}
	fcpu = fopen("/proc/partitions","r");
	int mem;
	//int taille;
	char namemem[1024];
 	if(fcpu == NULL)
		exit(EXIT_FAILURE);
	while(fgets(buffer,1024,fcpu)) {
	   if(sscanf(buffer,"%*d %*d %d %s", &mem, namemem) == 2){
	      mem = mem / 1024;
	      printf("Mémoire %s Taille %d MO \n",namemem,mem);
	   }
	}
	char version[256];
	fcpu = fopen("/proc/version","r");
	if(fcpu == NULL)
		exit(EXIT_FAILURE);
	if(fgets(buffer,1024,fcpu)) {
	if(sscanf(buffer,"%*s %*s %s", version) == 1)
	      printf("Linux Version %s \n", version);
	}

return 0;
}


