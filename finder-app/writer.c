#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main (int argc, char** argv)
{
    int fd;
    int numWrite = 0;

    openlog(NULL,0, LOG_USER);
    if (argc != 3)
    {
        syslog(LOG_ERR, "The filepath or write string was not specifed.\n");
        return 1;
    }

    fd = open (argv[1], O_WRONLY | O_CREAT | O_SYNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (fd < 0)
    {
        syslog(LOG_ERR, "Cannot open file.\n");
        return 1;
    }

    numWrite = write(fd, argv[2], strlen(argv[2]));
    if(numWrite == strlen(argv[2]))
    {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    }
    else
    {
        syslog(LOG_DEBUG, "Error. Just write %d character of %s to %s", numWrite, argv[2], argv[1]);
    }

    closelog();

    return 0;
}