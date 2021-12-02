#include<iostream>
#include<conio.h>
class bank{
	private:
	struct date{
    	int month,day,year;
    	};

	struct str{
    	char name[60];
    	int acc_no,age;
    	char address[100];
    	char citizenship[15];
    	double phone;
    	char acc_type[10];
    	float amt;
    	struct date dob;
    	struct date deposit;
    	struct date withdraw;
    	}add,upd,check,rem,trans;
	
	
	
	public:
		int choice1;
		void menu();
		void new_acc();
		void already();
		void dis_record();
		void update();
		void erase();
		void detail();
		void select();
		void end();
		void transiction();
		void program_bc2();
		void mani();
};
