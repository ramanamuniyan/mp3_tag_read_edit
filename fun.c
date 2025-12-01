#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"

static long unsigned int n;

int filecheck(char str[])
{
  char *dot=strstr(str,".mp3");

  if(dot==NULL)
  return 1;

  return 0;
  
    
}


void file_read(char* filename,meta_data *mdata)
{
    
FILE *fptr=fopen(filename,"rb");
if(fptr == NULL)
{
perror("");
return;
}

char buffer[4];
fread(buffer,3,1,fptr);
if(strcmp(buffer,"ID3")!=0)
{
  printf("version should be ID3\n");
  exit(EXIT_FAILURE);
}

fseek(fptr,10,SEEK_SET);
//printf("%lu ",ftell(fptr));//10
for(int i=0;i<6;i++)

{
fread(mdata[i].tag_name,4,1,fptr);
mdata[i].tag_name[4]='\0';

//printf("--%lu-- ",ftell(fptr));//14
unsigned char buf[4];
fread(buf, 1, 4, fptr);

int size = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];

mdata[i].tag_size=size;
fseek(fptr,3,SEEK_CUR);

fread(mdata[i].tag_data,size,1,fptr);
mdata[i].tag_data[size-1]='\0';

//printf("--%lu-- \n",ftell(fptr));
fseek(fptr,-1,SEEK_CUR);// -1

n=ftell(fptr);
}


fclose(fptr);

}


void file_edit(char* filename,meta_data *mdata)
{



  printf("Editing..\n");
  printf("1.Title\n");
  printf("2.Artist\n");
  printf("3.Album\n");
  printf("4.Year\n");
  printf("5.Genre\n");
  printf("6.Comment\n");
  printf("Enter the choice : ");
  int edit_value;
  scanf("%d",&edit_value);
  char tag[5];

  switch(edit_value)
  {
    case 1:
    strcpy(tag,"TIT2");
    break;

    case 2:
    strcpy(tag,"TPE1");
    break;

    case 3:
    strcpy(tag,"TALB");
    break;

    case 4:
    strcpy(tag,"TYER");
    break;

    case 5:
    strcpy(tag,"TCON");
    break;

    case 6:
    strcpy(tag,"COMM");
    break;
    default:
    puts("Invalid");

  }
  char tag_content[100];
  int tag_contentsize;
scanf(" %[^\n]",tag_content);
tag_contentsize=strlen(tag_content);


FILE *fptr1=fopen(filename,"rb+");
//FILE *fptr1=fopen("new.mp3","wb");

if(fptr1 == NULL)
{
perror("");
return;
}

for(int i=0;i<6;i++)
{
  if(strcmp(mdata[i].tag_name,tag)==0)
  {
   // puts("found");
    strcpy(mdata[i].tag_data,tag_content);
    mdata[i].tag_size = tag_contentsize;

  }
}
char buf[1000];
// fread(buf,10,1,fptr);
// fwrite(buf,10,1,fptr1);
int arr[6];

for(int i=0;i<6;i++)
{
  arr[i]= mdata[i].tag_size;
}

for(int i=0;i<6;i++)
{
  
  mdata[i].tag_size=(__builtin_bswap32(++mdata[i].tag_size));
} 
fseek(fptr1,10,SEEK_SET);

for(int i=0;i<6;i++)
{

  fwrite(mdata[i].tag_name,4,1,fptr1);
  fwrite(&mdata[i].tag_size,4,1,fptr1);
  fwrite("\0",1,2,fptr1);
  fwrite("\0",1,1,fptr1);
  fwrite(mdata[i].tag_data,(arr[i]),1,fptr1);

}

//fseek(fptr,n,SEEK_SET);

//  while(!feof(fptr))
//  {

//  char bf;
//    fread(&bf,1,1,fptr);
//    fwrite(&bf,1,1,fptr1);

//  }



//fclose(fptr);
fclose(fptr1);


}
