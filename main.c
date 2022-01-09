#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
    char name[50];
    int salary;
    int age;
    int id;
};
struct employee e;

long int size = sizeof(e);
FILE *fp, *ft;
void addrecord()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char choice = 'y';
    while (choice == 'y') {

        printf("\nEnter Name : ");
        scanf("%s", e.name);

        printf("\nEnter Age : ");
        scanf("%d", &e.age);

        printf("\nEnter Salary : ");
        scanf("%d", &e.salary);

        printf("\nEnter Employee ID : ");
        scanf("%d", &e.id);

        fwrite(&e, size, 1, fp);

        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);

        scanf("%c", &choice);
    }
}

void deleterecord()
{
    system("cls");
    int empID;
    char choice = 'y';

    while (choice == 'y') {
        printf("\nEnter employee ID to delete : ");
        scanf("%d",&empID);

        ft = fopen("temp.txt", "wb");
        rewind(fp);

        while (fread(&e, size,1, fp)== 1)
            if (e.id!=empID)
                fwrite(&e, size, 1, ft);
                fclose(fp);
                fclose(ft);
                remove("data.txt");
                rename("temp.txt", "data.txt");
                fp = fopen("data.txt", "rb+");
                printf("\nDeleted the record successfully!!");
        printf("\nDo you want to delete another record (Y/N) :");
        fflush(stdin);
        scanf("%c", &choice);}
}
void modifyrecord()
{
    system("cls");
    int empID;
    char choice = 'y';

    while (choice == 'y') {
        printf("\nEnter employee ID to modify : ");
        scanf("%d",&empID);

        rewind(fp);

        while (fread(&e, size, 1, fp) == 1) {

            if (e.id==empID){
                printf("\nEnter new name:");
                scanf("%s", e.name);
                printf("\nEnter new age :");
                scanf("%d", &e.age);
                printf("\nEnter new salary :");
                scanf("%d", &e.salary);
                printf("\nEnter new EMP-ID :");
                scanf("%d", &e.id);

                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }

        printf("\nWant to modify another record (Y/N) :");
        fflush(stdin);
        scanf("%c", &choice);
    }
}
void displayrecord()
{
    system("cls");
    rewind(fp);

    printf("\n==============================================================");
    printf("\n\tNAME\t\tAGE\t\tSALARY\t\tID\n");
    printf("==============================================================\n");

    while (fread(&e, size, 1, fp) == 1)
        printf("\n\t%s\t\t%d\t\t%d\t%10d",e.name, e.age, e.salary, e.id);

    printf("\n\n\n\t");
}
int main()
{

    int choice;
    char pword[50]={"admin"};
    char pass[50];
    fp = fopen("data.txt", "rb+");

    if (fp == NULL) {
        fp = fopen("data.txt", "wb+");
        if (fp == NULL) {
            printf("\nCannot open file...");
            exit(1);
        }
    }
    printf("=====================================================");
    printf("\n=====================================================");
    printf("\n\t\t EMPLOYEE RECORD  \t");
    printf("\n=====================================================");
    printf("\n=====================================================\n");
    printf("\nEnter the password:");
    scanf("%s",pass);
    if(strcmp(pword,pass)==0){
        while (1){

                printf("\n 1. ADD RECORDS\n");

                printf("\n 2. DELETE RECORDS\n");

                printf("\n 3. MODIFY RECORDS\n");

                printf("\n 4. DISPLAY RECORDS\n");

                printf("\n 5. EXIT\n");

                printf("\nENTER YOUR CHOICE...\n");
                fflush(stdin);
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    addrecord();
                    break;

                case 2:
                    deleterecord();
                    break;

                case 3:
                    modifyrecord();
                    break;

                case 4:
                    displayrecord();
                    break;

                case 5:
                    fclose(fp);
                    exit(0);
                    break;

                default:
                    printf("\nINVALID CHOICE...\n");
}
}
    }
    else{
        printf("Wrong Password....Access Denied");
    }
    return 0;
}

