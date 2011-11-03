#include "project.h"


int read_parameter_file(const char* filename, PARA_P file)
{
    FILE* id;
    int ret ;
    id = fopen(filename , "r") ;
    if(id)
    {
		ret = fread((void*)file,  1 ,sizeof(PARA) , id) ;
		fclose(id);
		if(ret !=  sizeof(PARA))  return -1 ;
    }
    else
    {
        return -1 ;
    }
    return 0 ;
}


int write_parameter_file(const char* filename, PARA_P file)
{
    FILE* id;
    int ret ;
    id = fopen(filename , "w") ;
    if(id)
    {
        ret = fwrite((void*)file, 1 , sizeof(PARA) , id) ;
	    fclose(id) ;
	    if (ret != sizeof(PARA))  return -1 ;
    }
    else
    {
        return -1 ;
    }
    return 0 ;
}
