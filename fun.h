#ifndef FUN_H
#define FUN_H

typedef struct 
{ 
    char tag_name[5];
    char tag_data[100];
   unsigned int  tag_size;


}meta_data;




int filecheck(char str[]);
void file_read(char* filename,meta_data *mdata);
void file_edit(char* filename,meta_data *mdata,int,char*);
void errorfun();



#endif
