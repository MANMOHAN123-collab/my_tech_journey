# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<string.h>

struct student{

  int roll;
  char name[50];
  char branch[30];
  float marks;

};
void addstudent();
void deletestudent();
void updatestudent();
void searchstudent();
void displaystudent();


 
int main() { 
  int choice;
           printf("\n");
           printf("**==========Student Record system==========**\n");
           printf("1.Add new student\n");
           printf("2.Delete student record\n");
           printf("3.Update student record\n");
           printf("4.Search student by roll no\n");
           printf("5.Display All students\n");
           printf("6.Exit\n");
           printf("________________________________________________\n");
           printf("\n");
           printf("Enter your choice no.: ");
           scanf("%d",&choice);
           switch (choice){
            case 1:
            addstudent();
            printf("\nThanks for using this management system\n ");
            break;
            case 2:
            deletestudent();
            break;
            case 3:
            updatestudent();
            break;
            case 4:
            printf("You can search student by roll no!!\n");
            searchstudent();
            break;
            case 5:
            displaystudent();
            break;
            case 6:
            printf("\n");
            printf("!! Thanks for using this management system!!\n");
            break;
            default:
            printf("Invalid choice!! Please enter correct values\n");
          }
          
          printf("\nDesigned by @ MANMOHAN SINGH\n");
          printf("\n");
    return 0;   
}
// add new student 
void addstudent(){
  char record;
  while(1){
    printf("Do you want to add any student record(press y/n): ");
    scanf(" %c",&record);
    if (record=='y'|| record=='Y'){
      struct student s;
  FILE *fptr;
  fptr=fopen("Student.txt","a");
  
  printf("Enter the student name: ");
  scanf("%s",s.name);
  printf("Enter student roll no: ");
  scanf("%d",&s.roll);
  printf("Enter student branch: ");
  scanf("%s",s.branch);
  printf("Enter student marks: ");
  scanf("%f",&s.marks);
  fprintf(fptr,"\nRoll: %d\t Name: %s\t Branch: %s\t Marks: %f",s.roll,s.name,s.branch,s.marks);
  printf("Student record added successfully\n");

  fclose(fptr);
  break;

    } else if(record=='n'|| record=='N'){
      printf("Thanks for using this management system\n ");
      break;
      
    }
  else 
printf("Enter valid choice!!\n");
}}
void searchstudent(){
  char line[200];
  int found=0;
  while (1){
    int rollno;
  printf("\nEnter the student roll no: ");
  if(scanf("%d",&rollno)!=1);
  FILE *fptr;
  fptr=fopen("Student.txt","r");
  struct student s;
  while(fgets(line,sizeof(line),fptr)!=NULL){
  if (sscanf(line,"Roll: %d Name: %s Branch: %s Marks: %f",&s.roll,s.name,s.branch,&s.marks)==4){
  if (s.roll==rollno){
    printf("\nYes!! Student found!!\n");
    printf("\n");
    printf("Student name: %s\t",s.name);
    printf("Stduent roll no: %d\t",s.roll);
    printf("Student branch: %s\t",s.branch);
    printf("Student marks: %f\n",s.marks);
    found=1;
    break;}
  }}
if (!found){
  printf("\n Student Not found\n");
}}}
void deletestudent(){
  int roll_no;
  
FILE *fptr;
FILE *temp;

struct student s;
int found=0;
char line[200];
fptr=fopen("Student.txt","r");
temp=fopen("temp.txt","w");
if(fptr==NULL || temp==NULL){
  printf("File opening error\n");
  return;}
printf("Enter roll no of that student you want to delete the record: ");
scanf("%d",&roll_no);
while(fgets(line,sizeof(line),fptr)!=NULL){
  if (sscanf(line,"Roll: %d Name: %s Branch: %s Marks: %f",&s.roll,s.name,s.branch,&s.marks)==4){
if (roll_no==s.roll){
  found=1;
  continue;
}

fprintf(temp,"Roll: %d\t Name: %s\t Branch: %s\t Marks: %f\n",s.roll,s.name,s.branch,s.marks);}}
fclose(fptr);
fclose(temp);

if (found){
  remove("Student.txt");
rename("temp.txt","Student.txt");
  printf("\nStudent deleted successfully\n ");
  }
  else{
printf("\nStudent not found\n");
printf("PLease Try Again!!\n");}
printf("\n");
}
void updatestudent(){
  int sroll;
  char line[200];
  printf("Enter student roll no for update :");
  scanf("%d",&sroll);
  FILE *fptr;
  FILE *tempr;
  fptr=fopen("Student.txt","r");
  tempr=fopen("tempr.txt","w");
  struct student s;
  int fnd=0;
while(fgets(line,sizeof(line),fptr)!=NULL){
  if(sscanf(line,"Roll: %d Name: %s Branch: %s Marks: %f",&s.roll,s.name,s.branch,&s.marks)==4){
  if (s.roll==sroll){
    fnd=1;
    printf("Enter new name:");
    scanf("%s",s.name);
    printf("Enter new roll no: ");
    scanf("%d",&s.roll);
    printf("Enter new branch: ");
    scanf("%s",s.branch);
    printf("Enetr new marks: ");
    scanf("%f",&s.marks);
    
  }
  fprintf(tempr,"Roll: %d\t Name: %s\t Branch: %s\t Marks: %f\n",s.roll,s.name,s.branch,s.marks);
}}
fclose(fptr);
fclose(tempr);

if (fnd){
  remove("Student.txt");
  rename("tempr.txt","Student.txt");
  printf("\n sdtudent updated successfully\n");
}
else
printf("\n !!student not found!! \n Try Again \n");
}
void displaystudent(){
  FILE *fptr;
   char line[200];
  fptr=fopen("Student.txt","r");
  struct student s;
  while(fgets(line,sizeof(line),fptr)!=NULL){
    if (sscanf(line,"Roll: %d Name: %s Branch: %s Marks: %f",&s.roll,s.name,s.branch,&s.marks)==4)
    printf("Student name: %s\t",s.name);
    printf("Student roll no: %d\t",s.roll);
    printf("Student branch: %s\t",s.branch);
    printf("Student marks: %f\n",s.marks);

  }fclose(fptr);
}