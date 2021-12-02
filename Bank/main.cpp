#include <iostream>
#include "header.h"
int choice,choice2;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	bank data;
	data.menu();
	cin>>choice;
	switch(choice)
	{
    case 1:
     data.new_acc();
     main();
    break;
   case 2:
     data.update();
     if(data.choice1 == 1)
     main(); 
	break;
    case 3:
     data.transiction();
     if(data.choice1==1)
     main();
    break;
    case 4:
	data.detail();
    if(data.choice1==1)
     main();
	break;
    case 5:
	data.erase();
	if(data.choice1==1)
     main();
    break;
    case 6:
	data.dis_record();
	if(data.choice1==1)
     main();
    break;
    case 7:
	data.end();
    break;
    }
    
	return 0;
}

