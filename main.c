#include <stdio.h>
#include <string.h>
#include "fun.h"




int main(int argc,char **argv)

{
    meta_data mdata[6];

    // printf("1.Read mp3 tag\n");
    // printf("2.Edit mp3 tag\n");
    // printf("Enter the choice\n");


    char *res=argv[1];

    

    int choice;
    if(strcmp(res,"-v")==0)
    {
      if(argc != 3)
      {
      errorfun();
      return 0;
      }

      choice=1;

    }


    else if(strcmp(res,"-e")==0)
    choice =2;

    else
    {
    errorfun();
    return 0;
    }

    if(argc <3 && argc >5)
    {
      errorfun();
      return 0;
    }


    



    //filename:
    //printf("Enter File Name: \n");
     
    char *filename=argv[2];
    //scanf("%s",filename);
    if(filecheck(filename))
    {
    printf("File is not valid\n");
    return 1;
    //goto filename;
    }

    char tag_name[6][15]={"TITLE","ALBUM","ARTIST","YEAR","GENRE","COMMENT" };

file_read( filename,mdata);
switch(choice)
{

  case 1:
  
  
  for(int i=0;i<6;i++)
  {
    printf("%d.",i+1);
    printf("%-7s :",tag_name[i]);
    printf(" %s",mdata[i].tag_data);
    printf("\n");
  }
  


  break;

  case 2:
  int choice;

  char *res1=argv[3];

  if(strcmp(res1,"-t")==0)
  choice=1;

  else if(strcmp(res1,"-T")==0)
  choice=2;

  else if(strcmp(res1,"-A")==0)
  choice=3;

  else if(strcmp(res1,"-y")==0)
  choice=4;

  else if(strcmp(res1,"-c")==0)
  choice=5;

  else if(strcmp(res1,"-C")==0)
  choice=6;

  else
  printf("BAD");
  // errorfun();


  file_edit(filename,mdata,choice,argv[4]);
  remove(filename);
  rename("new.mp3",filename);

  break;

  default:
  printf("Enter Valid Choice");

}



}



