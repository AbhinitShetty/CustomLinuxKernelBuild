#include<stdio.h>
#include<string.h>
#include<stdlib.h>		//Required for exit()
#include<sys/types.h>		//Required for creat()
#include<sys/stat.h>		//Required for creat()
#include<fcntl.h>		//Required for creat()
#include<unistd.h>		//Required for write()
#include<syslog.h>		//Required for syslog()

int main(int argc, char **argv){

	if (argc <= 2){
		exit(EXIT_FAILURE);
	}
		
	int fd;
	fd = creat(argv[1], 0644);			//Create a file with all possible permissions for User/Group/Others
	if (fd == -1)
		printf("Error while creating file");
	
	ssize_t nr;
	size_t count;
	count = strlen(argv[2]);
	nr = write(fd, argv[2], count);			//Write string to the file
	if (nr == -1)					//Check for errno errors
		printf("Check errno");
	else if (nr != count)
		printf("Some Error!!");
		
	openlog( "", LOG_PID, LOG_USER);		//"userlog"
	openlog( "", LOG_PERROR, LOG_ERR);		//"errorlog"
	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	
	return 0;
}
	

	
