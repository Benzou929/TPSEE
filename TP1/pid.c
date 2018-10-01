#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int arc,char** args) {
    char* pid;
    pid = args[1];
    char file[50];
    FILE *fcpu;
    int buffSize = 1024;
    char buffer [buffSize];
    const char dem[2] = ":";
    char cmdline[20];
    char *mychar;
    char *line;
    printf("Processus avec le pid : %s \n",pid);

    sprintf(file,"/proc/%s/cmdline",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    fgets(buffer,1024,fcpu);
    sscanf(buffer,"%s", cmdline);
    printf("Le nom de la commande : %s \n",cmdline);
    
    sprintf(file,"/proc/%s/status",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    while(line=fgets(buffer,1024,fcpu)){
	mychar =  strtok(line,dem);
    if(strcmp(mychar,"Tgid") == 0){
	//printf("Tgid : ");
	while( mychar != NULL ) {
           printf( "%s", mychar );      
           mychar = strtok(NULL, dem);
                 }
           }	
    }
    int flag = 1;
    int ppid;
	char *parentId;
	sprintf(file,"/proc/%s/status",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    while(line=fgets(buffer,1024,fcpu)){
	mychar =  strtok(line,dem);
    if(strcmp(mychar,"PPid") == 0){	    
	while( mychar != NULL ) {
           printf("%s", mychar );
           if(flag == 2){parentId = mychar;} 
           flag++;         
           mychar = strtok(NULL, dem);
           
              }  
              break;
           }
          
    }
    
    sscanf(parentId,"%d",&ppid);    
	sprintf(file,"/proc/%d/cmdline",ppid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    fgets(buffer,1024,fcpu);
    sscanf(buffer,"%s", cmdline);
    printf("Le nom de la commande PPid: %s \n",cmdline);	

    sprintf(file,"/proc/%s/status",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    while(line=fgets(buffer,1024,fcpu)){
	mychar =  strtok(line,dem);
    if(strcmp(mychar,"Threads") == 0){
	//printf("Tgid : ");
	while( mychar != NULL ) {
           printf( "%s", mychar );      
           mychar = strtok(NULL, dem);
                 }
           }	
    }

    sprintf(file,"/proc/%s/status",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    while(line=fgets(buffer,1024,fcpu)){
	mychar =  strtok(line,dem);
    if(strcmp(mychar,"Uid") == 0){
	//printf("Tgid : ");
	while( mychar != NULL ) {
           printf( "%s", mychar );      
           mychar = strtok(NULL, dem);
                 }
           }	
    }

    sprintf(file,"/proc/%s/status",pid);
    fcpu = fopen(file,"r");
    if(fcpu == NULL)
	exit(EXIT_FAILURE);
    while(line=fgets(buffer,1024,fcpu)){
	mychar =  strtok(line,dem);
    if(strcmp(mychar,"Gid") == 0){
	//printf("Tgid : ");
	while( mychar != NULL ) {
           printf( "%s", mychar );      
           mychar = strtok(NULL, dem);
                 }
           }	
    }
}

