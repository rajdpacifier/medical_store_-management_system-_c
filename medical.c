#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<math.h>

#include<time.h>
#include<ctype.h>

#include<stdlib.h>
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct supplier
{
char supp_id[20];
char supp_name[25];
char mob_no[11];
};
struct supplier temp1;
void supp_entry();
void customer();
void supp_list();
void search();
void start();
void medsearch();
void medentry();
void supplier();
void bill();
void stock();
void search_cname();
void medicine();
void box(char q){
int r;
for(r=16;r<68;r++)
{
gotoxy(r,15);
printf("%c",q);}
for(r=16;r<45;r++)
{
gotoxy(16,r);
printf("%c",q);}
for(r=16;r<68;r++)
{
gotoxy(r,45);
printf("%c",q);}
for(r=15;r<46;r++)
{gotoxy(68,r);
printf("%c",q);}
}
void start()
{
system("cls");
char q='#';
box(q);
gotoxy(30,20);
printf("Main Menu");
gotoxy(25,22);
printf("=====================");
int i=25,j=25;
gotoxy(i,j);
printf("Press 1 for customer information");
gotoxy(i,++j+2);
printf("Press 2 for supplier information");
gotoxy(i,++j+4);
printf("Press 3 for Bill");
gotoxy(i,++j+6);
printf("Press 4 for medicine information");
gotoxy(i,++j+8);
printf("Press 5 for exit");
gotoxy(i,++j+10);
char option;
scanf(" %c",&option);
switch(option){
case '1': customer();
break;
case '2':supplier();
break;
case '3': bill();
break;
case '4': medicine();
break;
case '5': exit(0);
break;
default: printf("\nInvalid Input");
printf("\nPress correct input\n");
Sleep(1000);
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
///***********Customer Entry*************void cust_entry()
{
char ch;
int id,m,i=6,j=7;
FILE *fp;
fp=fopen("custom.txt","a");
system("cls");
gotoxy(i,++j);
printf("Customer Entry");
gotoxy(i,++j+2);
printf("Enter Customer ID\t");
scanf("%d",&custom.cust_id);
gotoxy(i,++j+4);
printf("Customer Name\t");
scanf("%s",custom.cust_name);
gotoxy(i,++j+6);
printf("Customer Mobile Number\t");
scanf("%s",custom.cust_mob_no);
printf("\nPress 1 to save changes and 2 to cancel changes\t");
scanf("%d",&m);
if(m==1){
fprintf(fp,"%d %s %s ",custom.cust_id,custom.cust_name,custom.cust_mob_no);
system("cls");
gotoxy(i,j);
printf("Customer added successfully");
Sleep(1000);
fclose(fp);
customer();
}
else
{
printf("\nNo entry done");
Sleep(1500);
customer();
}
}
//**********End of customer entry**********
//**********Customer List************
void cust_list()
{int i=15,j=10;
system("cls");
char ch;
FILE *fp;
fp=fopen("custom.txt","rb");
gotoxy(i,j-2);
printf("Customer List");
gotoxy(i,j);
int k=14;
printf(" ID
Customer Name Mobile No.");
gotoxy(i,++j);
printf("================================================");
while(fscanf(fp,"%d %s %s",&custom.cust_id,custom.cust_name,custom.cust_mob_no)!=EOF)
{
gotoxy(i,++k);printf("%d",custom.cust_id);
gotoxy(i+15,k);
printf("%s",custom.cust_name);
gotoxy(i+30,k);
printf("%s",custom.cust_mob_no);
k=k+2;
}
fclose(fp);
printf("\n\n\n\n\n\t\tPress any key to return to the customer menu\t");
getche();
customer();
}
//*******************End of Customer List**********
//*******************Customer Search***************
void cust_search()
{
int ch;
int i=5,j=8;
system("cls");
gotoxy(i,j);
printf("Searching of customer is available by name");
search_cname();}
//************Search by customer name***************
void search_cname(){
int i=5,j=8; char name[50];
system("cls");
FILE *fp;
fp=fopen("custom.txt","rb");
gotoxy(i,++j);
printf("Enter customer name to be searched: ");
scanf("%s",&name);
int l=j+3;
gotoxy(i,j+4);
printf("ID Customer Name
Mobile No\n\n");
gotoxy(i,j+5);
printf("====================================");
int a=0;
while(fscanf(fp,"%d%s%s",&custom.cust_id,custom.cust_name,custom.cust_mob_no)!=EOF)
{
if(strcmp(custom.cust_name,name)==0)
{
gotoxy(i,j+7);
printf("%d",custom.cust_id);
gotoxy(i+6,j+7);
printf("%s",custom.cust_name);
gotoxy(i+25,j+7);
printf("%s",custom.cust_mob_no);
a=1;
gotoxy(i,j+15);
int d;
printf("press 1 to go back.");
scanf("%d",& d);
if(d==1)
customer();//
break;
}}
if(a==0)
{
gotoxy(i,j);
printf("Record not found");
Sleep(1000);
customer();
}
}
//*************************End of customer search*********************
void customer(){
system("cls");
gotoxy(30,20);
printf("Customer Menu");
gotoxy(25,22);
printf("=====================");
box('*');
int i=25,j=25;
gotoxy(i,j);
printf("Press 1 for adding new customer\n\n");
gotoxy(i,j+2);
printf("Press 2 for Searching customer\n\n");
gotoxy(i,j+4);
printf("Press 3 for exixting list of customers\n\n ");
gotoxy(i,j+6);
printf("Press 4 to return to the menu\n\n ");
gotoxy(i,j+10);
char option;
scanf(" %c",&option);
switch(option){
case '1': cust_entry();
break;
case '2':cust_search();
break;
case '3': cust_list() ;
break;
case '4': start();
break;
default:printf("\nInvalid Input");
printf("\nEnter correct input\n");
Sleep(1000);
customer();
break;
}
};//---------for supplier------
void supplier()
{
char ch;
system("cls");
box('o');
int i=18,j=25;
gotoxy(25,25);
printf("------------SUPPLIER MENU------------");
gotoxy(i+6,j+5);
printf("Press 1 To Add new supplier.");
gotoxy(i+6,j+7);
printf("Press 2 To Search Supplier.");
gotoxy(i+6,j+9);
printf("Press 3 For the list of existing suppliers.");
gotoxy(i+6,j+11);
printf("Press 4 for main menu.");
gotoxy(i+6,j+13);
printf("-------Please enter your choice-------");
gotoxy(i+6,j+16);
scanf("%d",&ch);
switch(ch)
{
case 1:supp_entry();
break;
case 2:search();
break;
case 3:supp_list();
break;
case 4:start();
break;
default:
gotoxy(i+6,j+17);
printf("Invalid input..\n /Please enter correct input.");
Sleep(1000);
supplier();
}
}
//-----------for supplier entry------------
void supp_entry()
{
FILE *fp;
system("cls");
fp=fopen("supplier.txt","a");
int i=5,j=7;
gotoxy(i+5,j-5);
printf("Supplier Entry....");
gotoxy(i+4,j-4);
printf("--------------------");
gotoxy(i,j);printf("Enter supplier id\t\t");
scanf("%s",temp1.supp_id);
gotoxy(i,j+2);
printf("Enter supplier name\t");
scanf("%s",temp1.supp_name);
gotoxy(i,j+4);
printf("Enter mobile number\t");
scanf("%s",temp1.mob_no);
fprintf(fp,"%s %s %s ",&temp1.supp_id,temp1.supp_name,temp1.mob_no);
fclose(fp);
gotoxy(i,j+10);
printf("Data successfully entered");
Sleep(2200);
supplier();
}
//----------supplier list-----------
void supp_list()
{
char ch;
int i=5,j=8,q=15;
system("cls");
FILE *ptr1;
ptr1=fopen("supplier.txt","r");
system("cls");
gotoxy(i,j);
printf("supplier list");
gotoxy(i,j+2);
printf("ID.
SUPPLIER NAME.
PH.NO.");
gotoxy(i,j+3);
printf("===============================================");
while(fscanf(ptr1,"%s %s %s ",temp1.supp_id,temp1.supp_name,temp1.mob_no)!=EOF)
{
gotoxy(i,q);
printf("%s",temp1.supp_id);
gotoxy(i+15,q);
printf("%s",temp1.supp_name);
gotoxy(i+35,q);
printf("%s\n\n",temp1.mob_no);
q=q+2;
}
printf("Press any key to go back.\n");
getche();
supplier();
}
//=========search supplier=========
void search()
{
system("cls");
char name[20];
FILE *fp;
fp=fopen("supplier.txt","rb");
gotoxy(13,8);
printf("Enter Supplier Name to be searched :\t");scanf("%s",name);
gotoxy(20,35);
printf("Press any key to return to Back menu.....");
gotoxy(12,14);
printf("ID
SUPPLIER NAME.
PH NO.");
gotoxy(12,16);
int i=18;
printf("======================================");
while(fscanf(fp,"%s %s %s",temp1.supp_id,temp1.supp_name,temp1.mob_no)!
=EOF)
{
if(strcmp(temp1.supp_name,name)==0)
{
gotoxy(11,++i);
printf("%s",temp1.supp_id);
gotoxy(22,i);
printf("%s",temp1.supp_name);
gotoxy(40,i);
printf("%s",temp1.mob_no);
i++;
break;
}
}
if(strcmp(temp1.supp_name,name)!=0)
{
gotoxy(20,30);
printf("Record not found!!!");
}
fclose(fp);
getche();
supplier();
}
//======END OF SUPPLIER FUNCTION============
struct medical
{
char id[6];
char medi_name[20];
int rack;
int cabinet;
int quantity;
float unit;
char pur_date[15];
char exp_date[15];
char comp_name[20];
char supp_name[30];
};
struct medical temp;
void medicine()
{
system("cls");
box('+');int i=20,j=25;
gotoxy(28,25);
printf("Medicine Menu");
gotoxy(25,26);
printf("=======================");
gotoxy(i,j+6);
printf("Enter 1 to know about purchase of new medicines");
gotoxy(i,j+8);
printf("Enter 2 to know about medicine stock");
gotoxy(i,j+10);
printf("Enter 3 to search a medicine");
gotoxy(i,j+12);
printf("Enter 4 to return to the main menu\n\n");
gotoxy(i,j+14);
int option;
scanf("%d",&option);
switch(option)
{
case 1:medentry();
break;
case 2:stock();
break;
case 3:medsearch();
break;
case 4:start();
break;
default:
printf("Invalid Input.\nPlease enter correct Input");
Sleep(1000);
medicine();
break;
}
}
void medentry()
{
system("cls");
char id[6];
gotoxy(5,10);
printf("Enter Medicine ID\t");
scanf(" %s",id);
FILE *fp;
fp=fopen("medicines.txt","r");
while((fread(&temp,sizeof(temp),1,fp))==!EOF)
{
if(id==temp.id)
{
printf("\nAlready Exists ");
Sleep(1000);
medicine();
}
}
fclose(fp);
fp=fopen("medicines.txt","a");strcpy(temp.id,id);
gotoxy(5,12);
printf("Enter the name of medicine\t");
scanf("%s",temp.medi_name);
gotoxy(5,14);
printf("Enter the rack number where it is kept\t");
scanf(" %d",&temp.rack);
gotoxy(5,16);
printf("Enter cabinet number\t");
scanf(" %d",&temp.cabinet);
gotoxy(5,18);
printf("Enter quantity of medicine available\t");
scanf("%d",&temp.quantity);
gotoxy(5,20);
printf("Enter price of each unit\t");
scanf("%f",&temp.unit);
gotoxy(5,22);
printf("Enter purchase date\t");
scanf("%s",temp.pur_date);
gotoxy(5,24);
printf("Enter expiry date\t");
scanf("%s",temp.exp_date);
gotoxy(5,26);
printf("Enter name of Supplier\t");
scanf("%s",temp.supp_name);
gotoxy(5,28);
printf("Enter company name\t");
scanf("%s",temp.comp_name);
fprintf(fp,"%s %s %d %d %d %f %s %s %s %s
",temp.id,temp.medi_name,temp.rack,temp.cabinet,temp.quantity,temp.unit,temp.pur_date,temp.ex
p_date,temp.supp_name,temp.comp_name);
fclose(fp);
gotoxy(25,35);
printf("Medicine data added");
Sleep(2000);
medicine();
}
struct bill
{
char billno[6];
char cname[30];
char mediname[30];
int medi_qty;
float medi_rate;
float total;
int day;
int month;
int year;
};
void stock()
{
system("cls");FILE *ms;
ms=fopen("medicines.txt","rb");
gotoxy(5,8);
printf("================== MEDICINES AVAILABLE IN THE STORE
====================");
int i=19;
gotoxy(9,10);
printf("ID.
MEDICINE NAME.
QTY.
supplier name
Exp. date");
gotoxy(5,12);
printf("======================================================================
===\n");
while(fscanf(ms,"%s %s %d %d %d %f %s %s %s %s
",temp.id,temp.medi_name,&temp.rack,&temp.cabinet,&temp.quantity,&temp.unit,temp.pur_date,te
mp.exp_date,temp.supp_name,temp.comp_name)!=EOF)
{
gotoxy(9,++i);
printf(" %s",temp.id);
gotoxy(19,i);
printf(" %s",temp.medi_name);
gotoxy(37,i);
printf(" %d",temp.quantity);
gotoxy(49,i);
printf(" %s",temp.supp_name);
gotoxy(67,i);
printf(" %s\n\n\n\n\n",temp.exp_date);
i++;
}
printf("Press any key to return to medicines menu");
getche();
medicine();
}
void medsearch()
{
char mid[6];
int i,c;
system("cls");
FILE *mse;
mse=fopen("medicines.txt","r");
printf(" \n\n\n\t\t\tEnter MEDICINE id\t");
scanf("%s",mid);
i=14;
gotoxy(9,10);
printf("ID. MEDICINE NAME. QTY Supplier Name Exp.Date");
gotoxy(9,12);
printf("==================================================================
\n");
while(fscanf(mse,"%s %s %d %d %d %f %s %s %s %s
",temp.id,temp.medi_name,&temp.rack,&temp.cabinet,&temp.quantity,&temp.unit,temp.pur_date,te
mp.exp_date,temp.supp_name,temp.comp_name)!=EOF)
{
if(strcmp(mid,temp.id)==0)
{
gotoxy(9,i);printf(" %s",temp.id);
gotoxy(15,i);
printf(" %s",temp.medi_name);
gotoxy(32,i);
printf(" %d",temp.quantity);
gotoxy(43,i);
printf(" %s",temp.supp_name);
gotoxy(60,i);
printf(" %s",temp.exp_date);
i++;
break;
}
}
if(strcmp(mid,temp.id)!=0)
{
gotoxy(20,20);
printf("Not in Stock.....");
}
gotoxy(20,20);
printf("Press any key to return to medicine menu");
getche();
medicine();
}
//============for bill=============
void bill()
{
float netamt=0.0;
FILE *ptrbill;
char id[6];
int j=1;
char bill_no[6];
float total=0.0;
system("cls");
gotoxy(1,4);
printf("Enter bill no : ");
scanf("%s",bill_no);
char cus_name[30];
printf("Customer Name: ");
scanf("%s",cus_name);
char date[10];
printf("Date : ");
scanf("%s",date);
int a=1;
char medicine[200][10];
int quantity[10];
int w=0;
while(a==1)
{
printf("Enter the id of the medicine : ");
scanf("%s",medicine[w]);printf("Enter it's quantity : ");
scanf("%d",&quantity[w]);
w++;
printf("For adding more medicines enter 1 else enter 0 to prepare bill.");
scanf("%d",&a);
}
system("cls");
gotoxy(25,3);
printf("***** Jivan Jyoti Medico *****");
gotoxy(7,7);
printf("Bill No: ");
printf(" %s",bill_no);
gotoxy(7,9);
printf("Customer Name: %s",cus_name);
gotoxy(50,7);
printf("Date : %s",date);
gotoxy(7,12);
printf("Sr.No Medicine Name
Qty
Rate
Total ");
gotoxy(6,14);
int p=0;
printf("---------------------------------------------------------------------");
int i=15;
while(w>0)
{
ptrbill=fopen("medicines.txt","r");
while(fscanf(ptrbill,"%s %s %d %d %d %f %s %s %s
%s",temp.id,temp.medi_name,&temp.rack,&temp.cabinet,&temp.quantity,&temp.unit,temp.pur_dat
e,temp.exp_date,temp.comp_name,temp.supp_name)!=EOF)
{
if(strcmp(medicine[p],temp.id)==0)
{
gotoxy(7,i);
printf(" %d",j);
gotoxy(14,i);
printf(" %s",temp.medi_name);
gotoxy(34,i);
printf(" %d",quantity[p]);
gotoxy(47,i);
printf(" %.2f",temp.unit);
gotoxy(60,i);
float total=(quantity[p]*temp.unit);
printf(" %.2f",total);
printf("%d",w);
}
netamt=total+netamt;
i++;
j++;
}
fclose(ptrbill);p++;w--;}
gotoxy(6,35);
printf("---------------------------------------------------------------------");
gotoxy(50,37);printf("Total : ");
printf("%.2f\n\n\n",netamt);
fclose(ptrbill);
printf("Press enter for main menu.....");
getch();
start();
}
int main()
{
start();
getch();
return 0;
}
