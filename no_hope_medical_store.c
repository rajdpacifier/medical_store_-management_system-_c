#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
 
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void customer();
void start();
void Supplier();
void bill();
void search_cname();
//void About();
//void fexit();
void medicine();

void start()
{
     system("cls");
      int i=5,j=0;
     gotoxy(i,j);
     printf("Press 1 for customer information");
     gotoxy(i,j+2);
     printf("Press 2 for supplier information");
     gotoxy(i,j+4);
     printf("Press 3 for Bill");
     gotoxy(i,j+6);
     printf("Press 4 for medicine information");
     gotoxy(i,j+8);
     printf("Press 5 for About");
     gotoxy(i,j+10);
     printf("Press 6 for exit\n");
     char option;
     scanf(" %c",&option);
     switch(option){
                    case '1': customer();
                    break;
              /*      case '2':supplier();
                    break;
                    case '3': bill();
                    break;
                    case '4': medicine();
                    break;
                   // case '5': about();
                    //break;
                  //  case '6': fexit();
         //           break;
                */    default: printf("\nInvalid Input");
                             printf("\nPress correct input\n");
                             sleep(1000);
                             start();
                             
                             }
     
     
     
     }
struct customer
{
 int cust_id;
 char cust_name[30];
 char cust_mob_no[11];
};
struct customer custom;
//**********Customer update*******
void cust_update(){
     int i=5,j=8,p;
     char ch;
     int cid;
     FILE *fp;
     system("cls");
     gotoxy(i,j);
     printf("Modifying customer");
     gotoxy(i,++j);
     printf("Enter the customer ID");
     scanf("%d",&cid);
     gotoxy(i,++j);
     fp=fopen("custom.txt","rb+");
    
     while(fscanf(fp,"%d%s%s",&custom.cust_id,custom.cust_name,custom.cust_mob_no)!=EOF)
     
{

      if(custom.cust_id==cid){
      	int w=(sizeof(custom.cust_name)+sizeof(custom.cust_mob_no));
                            fseek(fp,-w,SEEK_CUR);
                              gotoxy(i,++j);
                              printf("Existing record");
                              gotoxy(i,++j);
                              printf("%d\t%s\t%s",custom.cust_id,custom.cust_name,custom.cust_mob_no);
                              gotoxy(i,++j);
                              printf("Enter new name   ;");
                              scanf("%s",custom.cust_name);
                              gotoxy(i,++j);
                              printf("Enter new mobile no.");
                              scanf("%s",custom.cust_mob_no);
                              gotoxy(i,++j);
                              printf("Press 1 for update the details and 2 for cancel the updates");
                              scanf("%d",&p);
                              if(p==1){
                                       FILE *op;
                                       
                                       op=fopen("custom.txt","a");
                                       fprintf(op,"%d %s %s\n",custom.cust_id,custom.cust_name,custom.cust_mob_no);
                                       gotoxy(i,j);
                                       printf("\nCustomer updated successfully\n\n");
                                       fclose(op);
                                       }
                              else
                              {
                                  printf("\nNo updation done");
                                  sleep(1500);
                              
                              customer();
                              
                                 }                 
								 }
		
						 }}
//***********End of customer update*************
//***********Customer Entry*************
void cust_entry()
{
     char ch;
     int id,m,i=6,j=7;
     FILE *fp;
     fp=fopen("custom.txt","a");
     system("cls");
     gotoxy(i,++j);
     printf("Customer Entry");
     gotoxy(i,++j);
     printf("Enter Customer ID");
     scanf("%d",&custom.cust_id);
   //  printf("Customer ID = %d",custom.cust_id);
     gotoxy(i,++j);
     printf("Customer Name");
     gotoxy(i,++j);
     scanf("%s",custom.cust_name);
     gotoxy(i,++j);
     printf("Customer Mobile Number");
     scanf("%s",custom.cust_mob_no);
     printf("\nPress 1 to save changes and 2 to cancel changes");
     scanf("%d",&m);
     if(m==1){
              fprintf(fp,"%d %s %s ",custom.cust_id,custom.cust_name,custom.cust_mob_no);
              system("cls");
              gotoxy(i,j);
              printf("Customer added successfully");
              }
                                  else
                              {
                                  printf("\nNo entry done");
                                  sleep(1500);
                              
                              customer();
                              
                                 }        }
//**********End of customer entry**********
//**********Customer List************
void cust_list()
{int i=5,j=10;
     char ch;
     FILE *fp;
     printf("\nCustomer List");
     gotoxy(i,j);
     int k=10;
     printf(" ID        Customer Name    Mobile No.");
     gotoxy(i,j);
     printf("================================================");
     while(fscanf(fp,"%d %s %s",&custom.cust_id,custom.cust_name,custom.cust_mob_no)!=EOF)
     {
     gotoxy(i,++k);
     printf("%d",custom.cust_id);
     gotoxy(i+10,k);
     printf("%s",custom.cust_name);
     gotoxy(i+20,k);
     printf("%s",custom.cust_mob_no);
     k=k+2;
     
     }
}
//*******************End of Customer List**********
//*******************Customer Search***************
void cust_search()
{
     int ch;
     int i=5,j=8;
         system("cls");
         gotoxy(i,j);
         printf("Searching of customer is available by mame");
         search_cname();}
         
//************Search by customer name***************
void search_cname(){
   int i=5,j=8;   char name[50];
     system("cls");
     FILE *fp;
     fp=fopen("custom.txt","a");
     gotoxy(i,++j);
     printf("Enter customer name to be searched");
     gets(name);
     int l;
     gotoxy(i,++j);
     printf("ID    Customer Name      Mobile No");
     gotoxy(i,++j);
     printf("====================================");
     int a=0;
     while(fscanf(fp,"%d%s%s",&custom.cust_id,custom.cust_name,custom.cust_mob_no)!=EOF && a==0);
     {
       if(strcmp(custom.cust_name,name)==0)
       {
                                           gotoxy(i,l);
                                           printf("%d",custom.cust_id);
                                           gotoxy(i,l);
                                           printf("%s",custom.cust_name);
                                           gotoxy(i,l);
                                           printf("%s",custom.cust_mob_no);
                                           a=1;
                                   //        break;
                                           }}
                                           if(a=0)
                                           {
                                                                               gotoxy(i,j);
                                                                               printf("Record not found");
                                                                               }
                                                                               }
     //*************************End of customer search*********************
                                                                                                                                                            
         
              
     void customer(){
     int i,j;
     gotoxy(i,j);
     printf("\nPress 1 for adding new customer\n\n");
     gotoxy(i,j+2);
     printf("\nPress 2 for updating customer\n\n");
     gotoxy(i,j+4);
     printf("\nPress 3 for Searching customer\n\n");
     gotoxy(i,j+6);
     printf("\nPress 4 for getting list of existing customers\n\n ");
     gotoxy(i,j+8);
     printf("\nPress 5 to return to the  menu\n\n");
     gotoxy(i,j+10);
     
     char option;
     scanf(" %c",&option);
     switch(option){
                    case '1': cust_entry();
                    break;
                    case '2':cust_update();
                    break;
                    case '3': cust_search();
                    break;
                    case '4': cust_list();
                    break;
                    case 5: start();
                    break;         
                    default:printf("\nInvalid Input");
                            printf("\nEnter correct input\n");
                            sleep(1000);
                            customer();
                            break;                         }
     
     
     
     };


int main()
{
     
 start();      
     getch();
     return 0;
     
     }
