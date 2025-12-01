#include <stdio.h>
#include <string.h>
#include "fun.h"




int main(int argc,char **argv)

{
    meta_data mdata[6];

    // printf("1.Read mp3 tag\n");
    // printf("2.Edit mp3 tag\n");
    // printf("Enter the choice\n");

    if(argc !=3)
    {
      
      printf("Command should be : Toview ./a.out -v filename ,Toedit ./a.out -e filename\n");
      return 0;
    }

    char *res=argv[1];

    

    int choice;
    if(strcmp(res,"-v")==0)
    choice=1;

    else if(strcmp(res,"-e")==0)
    choice =2;

    else
    {

    printf("Command should be : Toview ./a.out -v filename ,Toedit ./a.out -e filename\n");
    return 1;
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

file_read( filename,mdata);
switch(choice)
{

  case 0:

  break;
  case 1:
  
  
  for(int i=0;i<6;i++)
  {
    printf("%d.",i+1);
    printf("%s ",mdata[i].tag_name);
    printf("%s",mdata[i].tag_data);
    printf("\n");
  }
  


  break;

  case 2:
  
  file_edit(filename,mdata);
  //remove(filename);
  //rename("new.mp3",filename);

  break;

  default:
  printf("Enter Valid Choice");

}



}



