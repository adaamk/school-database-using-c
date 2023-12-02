#include"STD.h"
#include"SDB.h"
#include <stdio.h>
student list[10];
Int8 count=0;

bool SDB_IsFull ()/*this func. is checking if the data base full or not by using
if statement asking if the count equal 10 or not if yes print data base is full if
    not print data base is not full yet*/
{
    if(count==10)
    {
        printf("The Data base is now FULL\n");
        return true;
    }
    else
        printf("The Data base is NOT full yet\n");
        return false;
}

uint8 SDB_GetUsedSize()/*this func is returning the "count" that is the number of students the data base have*/
{
return count;
}

bool SDB_AddEntry(void)/*this function is adding a student to the data base by checking first if
data base is full or not (<10) then ask the user about the information required to add a student
,every information is stored in our struct that called list and in the area that made for it
by adding 1 to the count after every information, else
(count=10) the program print the failure message*/
{
    if(count<10)
    {
    printf("Please Enter student ID:\n");
    scanf("%hhu",&list[count].Student_ID);
    printf("Please Enter the student year:\n");
    scanf("%hhu",&list[count].Student_year);
    printf("Please Enter course1 ID:\n");
    scanf("%hhu",&list[count].Course1_ID);
    printf("Please Enter course1 grade:\n");
    scanf("%hhu",&list[count].Course1_grade);
    printf("Please Enter course2 ID:\n");
    scanf("%hhu",&list[count].Course2_ID);
    printf("Please Enter course2 grade:\n");
    scanf("%hhu",&list[count].Course2_grade);
    printf("Please Enter course3 ID:\n");
    scanf("%hhu",&list[count].Course3_ID);
    printf("Please Enter course3 grade:\n");
    scanf("%hhu",&list[count].Course3_grade);
    count++;
    printf("----------------------\n");
    return true;
    }
    else
    {
        printf("Failed to add entry!\n Please check your inputs and try again\n");
        return false;
    }
}

void SDB_DeletEntry(uint32 id)
{
    int i, delete_index = -1;

    for (i = 0; i < count; i++)
    {
        if (id == list[i].Student_ID)
        {
            delete_index = i;
            break;
        }
    }

    if (delete_index != -1)
    {
        for (i = delete_index; i < count - 1; i++)
        {
            list[i] = list[i + 1];
        }

        // Clear the data of the last element
        list[count - 1].Student_ID = 0;
        list[count - 1].Student_year = 0;
        list[count - 1].Course1_ID = 0;
        list[count - 1].Course1_grade = 0;
        list[count - 1].Course2_ID = 0;
        list[count - 1].Course2_grade = 0;
        list[count - 1].Course3_ID = 0;
        list[count - 1].Course3_grade = 0;

        count--;

        printf("Entry with ID %u Deleted\n", id);
    }
    else
    {
        printf("ID %u Not found\n", id);
    }
}


bool SDB_ReadEntry (uint32 id)
{
    int16 i,flag=0;
    for(i=0;i<10;i++)
    {
        if(id==list[i].Student_ID)
        {
            printf("Student ID is: [%d]\n",list[i].Student_ID);
            printf("Student year is: [%d]\n",list[i].Student_year);
            printf("Student course1 ID is: [%d]\n",list[i].Course1_ID);
            printf("Student course1 grade is: [%d]\n",list[i].Course1_grade);
            printf("Student course2 ID is: [%d]\n",list[i].Course2_ID);
            printf("Student course2 grade is: [%d]\n",list[i].Course2_grade);
            printf("Student course3 ID is: [%d]\n",list[i].Course3_ID);
            printf("Student course3 grade: [%d]\n",list[i].Course3_grade);
            flag=1;
            return true;
        }
    }
    if(flag==0)
    {
        printf("Student does NOT exist!!\n");
        return false;
    }
}

void SDB_GetList ()
{
 printf("Number of Students in list = [%d]\n",count);
 int i;
 for(i=0;i<count;i++)
 {
    printf("[%d]\n",list[i].Student_ID);
 }
}

bool SDB_IsIdExist(uint32 id)
{
  int i;
  for (i = 0; i < count; i++)
  {
    if (id == list[i].Student_ID)
    {
      printf("Student Exist\n");
      return true;
    }
  }
  printf("Student does NOT exist\n");
  return false;
}

