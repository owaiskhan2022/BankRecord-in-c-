#include<iostream>
#include"conio.h"
#include"stdio.h"
#include"header.h"
#include"string.h"
using namespace std;
void bank::menu()

    { 
 		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\tWelcome to bank management system\n";
 		cout<<"\n\n\n\t\t\t\t\t1. Create new account.\n";
 		cout<<"\t\t\t\t\t2. Update account.\n";
 		cout<<"\t\t\t\t\t3. For transictio.\n";
 		cout<<"\t\t\t\t\t4. Detail of existing account\n";
 		cout<<"\t\t\t\t\t5. Remove existing account.\n";
 		cout<<"\t\t\t\t\t6. List of all the existing accounts.\n";
 		cout<<"\t\t\t\t\t7. Exit.\n";
 		cout<<"\n\n\t\t\t\t\tEnter your choice: ";
     }
     
void bank::new_acc(){
	int type,loop=0;
  	FILE *ptr;
  	char dash;
   ptr = fopen("bankrecord.txt","a+");
   cout<<"---------------------------ADD RECORD---------------------------";
   cout<<"\n\n\n\t\t\t\t\tEnter today date (mm / dd / yyyy): ";
   cin>>add.deposit.month>>dash>>add.deposit.day>>dash>>add.deposit.year;
   exist_acc:
   	loop = 0;
   cout<<"\n\t\t\t\t\tEnter the account no: ";
	cin>>check.acc_no;
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)	
	{
     if(check.acc_no == add.acc_no )
     {
    	loop = 1;
  //    fclose(ptr);
     already();
     goto exist_acc;
     break;
     }
   
	 }
	 
	 if(loop ==0 )
     {
	add.acc_no = check.acc_no;
	
  // add.acc_no = check.acc_no;
  // ptr=fopen("bankrecord.txt","a+");
   cout<<"\n\t\t\t\t\tEnter the name: ";
   fflush(stdin);
   gets(add.name);
   cout<<"\n\t\t\t\t\tEnter the date of birth (mm/dd/yyyy): ";
   cin>>add.dob.month>>dash>>add.dob.day>>dash>>add.dob.year;
   cout<<"\n\t\t\t\t\tEnter the age: ";
   cin>>add.age;
   cout<<"\n\t\t\t\t\tEnter the address: ";
   fflush(stdin);
   gets(add.address);
   cout<<"\n\t\t\t\t\tEnter the citizenship: ";
   fflush(stdin);
   gets(add.citizenship);
   cout<<"\n\t\t\t\t\tEnter the phone no: ";
   cin>>add.phone;
   cout<<"\n\t\t\t\t\tEnter the amount of deposit: ";
   cin>>add.amt;
   cout<<"\t\t\t\t\tType of account:\n";
   cout<<"\t\t\t\t\t\t\t\t1. #saving\n";
   cout<<"\t\t\t\t\t\t\t\t2. #current\n";
   cout<<"\t\t\t\t\t\t\t\t3. #fixed1 (for one year)\n";
   cout<<"\t\t\t\t\t\t\t\t4. #fixed2 (for two year)\n";
   cout<<"\t\t\t\t\t\t\t\t5. #fixed3 (for three year)\n";
   cout<<"\t\t\t\t\t\t\tEnter your account type: ";
   cin>>add.acc_type;

	fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

   fclose(ptr);
   cout<<"\n\t\t\t\t\t\t\tAccount created successfully!:";
   getch();
}
   }

////////////////////////////////////////////////////////////////////////////////
void bank::already()
{
    cout<<"\n\t\t\t\t\tAccount no already in use";
 }
////////////////////////////////////////////////////////////////////////////////

void bank::update()
  {
    FILE *old,*now;
    int choice,test=0,back,main_exit;
    old = fopen("bankrecord.txt","r");
    now = fopen("bankupdate.txt","w");
    cout<<"\n\t\t\t\t\tEnter the account no. of the customer whose info you want to change: ";
    cin>>upd.acc_no;
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)

	{
	    if(add.acc_no == upd.acc_no)
			{
						test=1;
					cout<<"\n\t\t\t\t\tWhich information do you want to change?\n";
					cout<<"\n\t\t\t\t\t\t\t1. Address.";
					cout<<"\n\t\t\t\t\t\t\t2. Phone.";
					cout<<"\n\t\t\t\t\tEnter your choice: ";
					cin>>choice;
				if(choice == 1)
				{
					cout<<"\t\t\t\t\tEnter the new Address: ";
					fflush(stdin);
					cin>>upd.address;
				fprintf(now,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
					cout<<"\t\t\t\t\tChanges saved!";
				}
				else if (choice == 2)
					{
						cout<<"\t\t\t\t\tEnter the new Phone No: ";
						cin>>upd.phone;
				fprintf(now,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
						cout<<"\t\t\t\t\tChanges saved successfully!";
					}
			}
		else
	    fprintf(now,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	}
			fclose(old);
		fclose(now);
			remove("bankrecord.txt");
			rename("bankupdate.txt","bankrecord.txt");
    if(test == 0)
    {
	    cout<<"\t\t\t\t\tNo such account exist: ";
	    choice1 == 0;
	}
	 /////////////////////////////////////////////////////////////////////////////////
	    else
{		label:
		cout<<"\n\t\t\t\t\tEnter 0 to try again 1 to go to main menu";
	    cin>>back;
	    if(back==0)
		{
	    fclose(old);
	    fclose(now);
	    update();
		}
		if(back != 1)
		goto label;
	    else if(back == 1)
	    choice1=1;
	}

}
void bank::transiction(){
 	int choice,back,test=0;
 	FILE *old,*newrec;
 	old = fopen("bankrecord.txt","r");
 	newrec = fopen("new.txt","w");
 	cout<<"\t\t\t\t\tEnter the account no of customer: ";
 	cin>>trans.acc_no;
 	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
   		if(trans.acc_no==add.acc_no){
   			test=1;
   			if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0){
   				cout<<"\n\t\t\t\t\tYou cannot deposit or withdraw ammount from fixed accounts: ";
   				choice1==1;					///////////////////////////////////////////////////////////////////////////////////////////////
				   //main();/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			   }
			   cout<<"\t\t\t\t\tDo you want to\n";
			   cout<<"\t\t\t\t\t\t\t1. Deposit\n\t\t\t\t\t\t\t2. Withdraw";
			   cout<<"\n\n\t\t\t\t\tEnter your choice: ";
			   cin>>choice;
			   if(choice==1){
			   	cout<<"\t\t\t\t\tEnter the amount you want to deposit: ";
			   	cin>>trans.amt;
			   	add.amt+= trans.amt;
			   	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				cout<<"\n\t\t\t\t\tDeposited Successfully: ";
			   }
			   if(choice==2){
			   	printf("\t\t\t\t\tEnter the amount you want to Withdraw: ");
			   	cin>>trans.amt;
			   	add.amt-= trans.amt;
			   	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				cout<<"\n\t\t\t\t\tWithdrawn Successfully: ";
			   }
		   }
		   else
		   fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
           }
           fclose(old);
           fclose(newrec);
           remove("bankrecord.txt");
           rename("new.txt","bankrecord.txt");
           
		   //program_bc1();
		   if(test!=1){
		   //getch();
           cout<<"\t\t\t\t\tRecord not found!...";
       		label2:
		cout<<"\n\t\t\t\t\tEnter 0 to try again 1 to go to main menu";
	    cin>>back;
	    if(back==0)
		{
	    fclose(old);
	    fclose(newrec);
	    transiction();
		}
		if(back != 1)
		goto label2;
	    else if(back == 1)
	    choice1=1;
	   }
 }
 
 ///////////////////////////////////////////////////////////////////////////////
 void bank::detail()
{
    FILE *ptr;
    int choice,back,test=0;
    ptr = fopen("bankrecord.txt","r");
    cout<<"\t\t\t\t\tEnter the account no of customer:";
    cin>>check.acc_no;
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)

       {
	  if(check.acc_no == add.acc_no)
	     {
		  cout<<"\n\t\t\t\t\tAccount NO.:"<<add.acc_no<<"\n\t\t\t\t\tName:%s "<<add.name<<"\n\t\t\t\t\tDOB:"<<add.dob.month<<"/"<<add.dob.day<<"/"<<add.dob.year<<"\n\t\t\t\t\tAge: "<<add.age<<"\n\t\t\t\t\tAddress: "<<add.address<<"\n\t\t\t\t\tCitizenship No: "<<add.citizenship<<"\n\t\t\t\t\tPhone number:"<<add.phone<<"\n\t\t\t\t\tType Of Account: "
		  <<add.acc_type<<"\n\t\t\t\t\tAmount deposited: $"<<add.amt<<"\n\t\t\t\t\tDate Of Deposit: "<<add.deposit.month<<"/"<<add.deposit.day<<"/"<<add.deposit.year<<"\n\n";
	  test++;
	  getch();
	     }
       }
    if(test == 0)
       {
	    cout<<"\n\t\t\t\t\tNo record found!";
	    cout<<"\t\t\t\t\tEnter 0 to try again 1 to go to main menu";
	    cin>>back;
	    if(back==0)
		detail();
		else if (back == 1)
		{
			test = 7;
			fclose(ptr);
			choice1==1;
		}
       }
    if(test > 0)
    {
    	back = 3;
		if(back == 3)
	    choice1=1;
	}
			
  }
  
  
  //////////////////////////////////////////////////////////////////////////////////////////
  void bank::erase()
  {
    FILE *old,*now;
    int choice,testt,invalid,test=0,back;
    old = fopen("bankrecord.txt","r");
    now = fopen("newbankrecord.txt","w");
    cout<<"\n\t\t\t\t\tEnter the account no. you want to delet: ";
    cin>>rem.acc_no;
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
		{
	if(add.acc_no != rem.acc_no)
		{
			 fprintf(now,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
			}
	else
		{
			test++;
			cout<<"\n\t\t\t\t\tRecord deleted successfully:";
				getch();
			 	testt==0;
			 	choice1=1;
			 }
	}
	fclose(old);
   fclose(now);
   remove("bankrecord.txt");
   rename("newbankrecord.txt","bankrecord.txt");
       if (test== 0)
	{
			cout<<"\t\t\t\t\tRecord not found:";
			cout<<"\t\t\t\t\tEnter 0 to try again and 1 to go to main menu:";
			cin>>invalid;
			if(invalid == 0)
				erase();
			else if(invalid == 1)
				choice1=1;
	}
  }
//////////////////////////////////////////////////////////////////////////////////////
void bank::dis_record()
  {
  FILE *display;
  int test = 0;
  display = fopen("bankrecord.txt","r");
  printf("\n\t\t\t\t\tACC.N0\t\tNAME\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(display,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)

     {
       cout<<"\n\t\t\t\t\t"<<add.acc_no<<"\t"<<add.name<<"\t\t\t"<<add.address<<"\t\t"<<add.phone;
       test++;
       choice1 = 1;
     }
  fclose(display);
  if(test==0)
    {
      printf("\n\n\t\t\t\t\t\t\t\tNo Record saved!!\n");
      choice1=1;
	 // program_bc1();
    }
    getch();
    choice1=1;
//    program_bc1();
  }
  
  //////////////////////////////////////////////////////////////////////////////////
  void bank::end()
   {
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tTHANKS FOR VISITING OUR BANK";
   }
