#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main() {
	char* line;
	int	fd;
    	int i = 1;
    
    if (!(fd = open("test.txt", O_RDONLY)))	// 1
    {
    	printf("\nError in open");
        return (0);
    }
    while ((line = get_next_line(fd)) > 0)// 2
    {
    	printf("Gnl %d line : %s", i++, line);	
        free(line);				// 6	
    }
    printf("\n");
    
    free(line);					// 4
	close(fd);				// 5
	system("leaks a.out");
    return (0);
}