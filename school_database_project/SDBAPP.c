#include"STD.h"
#include"SDB.h"
student list[10];

void SDB_APP()/*this function is our program start up to help the user to choose which action
 he wants by choosing a number from 1 to 7 or 0 to exit*/
{
  Int8 choice=1;
  while(choice!=0)
  {
      printf("To add entry, enter 1\n");
      printf("To get used size in database, enter 2\n");
      printf("To read student data, enter 3\n");
      printf("To get the list of all student IDs, enter 4\n");
      printf("To check is ID is existed, enter 5\n");
      printf("To delete student data, enter 6\n");
      printf("To check if database is full, enter 7\n");
      printf("To exit enter 0\n");
      printf("----------------------------------------------------------\n");
      scanf("%d",&choice);
      SDB_action(choice);
  }
}


void SDB_action (uint8 choice)/*this function is our key function that send the user by
the number he chose 1-7 to the function that fulfill their needs */
{
    uint32 id=0;
    if(choice==1)
    {
        SDB_AddEntry();
    }
    else if(choice==2)
    {
    uint8 UsedSize=SDB_GetUsedSize();
    printf("Number of students Stored = [%d]\n",UsedSize);
    }
    else if(choice==3)
    {
        printf("Please Enter the Student's ID :\n");
        scanf("%u",&id);
        SDB_ReadEntry(id);
        printf("-----------------------\n");
    }
    else if(choice==4)
    {
    SDB_GetList();
    }
    else if(choice==5)
    {
        printf("Please Enter the ID to Check :\n");
        scanf("%u",&id);
        SDB_IsIdExist (id);
    }
    else if(choice==6)
    {
        printf("Please Enter the ID you want to (DELETE) :\n");
        scanf("%u",&id);
        SDB_DeletEntry (id);
    }
    else if(choice==7)
    {
        SDB_IsFull();
    }

}
