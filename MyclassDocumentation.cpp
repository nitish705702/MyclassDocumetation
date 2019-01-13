/*
*****************************************************************************************************
               Working in this project(December 2018--jan2019) B.tech 2nd Year
.
.       WELCOME                                                                                               .
.                                                                                                      
....................................................................................
                  Nitish Kumar Arya
                  B.Tech Computer Science and Engineering
                  From Madan mohan Malaviya University of Technology ,Gorakhpur
....................................................................................
                *****  ****** *****************  ****** *******  *******  ******  *******  **************  ********
              ******  ******  ****************  ****** *******  *******  ******  *******  ******  ********  ********
            ******* ******  ******* *******  ******  *******  *******  ******  ******* *******    *********  ******** 
.
.*******************************************************************************************************
*/
//#include<bits/stdc++.h>
//we can use this header file But my compiler does not take
#include<iostream>
//conio.h use for gotoxy method
#include<conio.h>
//fstream header file use for file input/output
#include<fstream>
//iomanip  header file use for setw(),precision() function
#include<iomanip>
#include <windows.h>
#include<cstdio>
#include<cstring>
using namespace std;
//create a class Student name
class student{
	//variable declare student roll number
	int rollno;
	//variable Student name
	string name_student;
	// mark of the cse b.tech student like as mark1 ,mark2,mark3,mark4,mark5 and mark6 
	int mark1,mark2,mark3,mark4,mark5,mark6,mark7;
	//percentage parameter
	float per;
	//grade of each subject
	char grade;
	//Grade calculate
	void grade_calculate()
	{
		per=(mark1+mark2+mark3+mark4+mark5+mark6)/6;
	//per>=90 the student will get A+ Grade
	 if(per>=90)
	 {
        grade='A+';
	 }
	 //per>=80 and per<=89 the student will get A+ Grade
    else if(per>=80 && per<89)
    {
        grade='A';
	}
	//per>=70 and per<=79 the student will get B+ Grade
     else if(per>=70 && per<79)
    {
        grade='B+';
	}
	//per>=60 && per<69 the student will get B Grade
	 else if(per>=60 && per<69)
    {
        grade='B';
	}
    //(per>=50 && per<59 the student will get C Grade
	 else if(per>=50 && per<59)
    {
        grade='C';
	}
	//per>=60 && per<69 the student will get D Grade
	else if(per>=40 && per<49)
    {
        grade='D';
	}
    	//per>=40 && per<49 the student will get F Grade
	else
    {
            grade='F';
	}
    }
	public :
		void getdata()
		{
			//Enter the Marks of the subject,name and roonumber of the student
		  cout<<"Enter the rollnumber"<<endl;
		  cin>>rollno;
		  cout<<endl;
		  cout<<"Enter the name of Student :"<<endl;
		  //student name
		  cin>>	name_student;
		  cout<<endl;
		  //these are all bachaler of technology computer science and engineering  subjects
		  //Subject1
		  cout<<"Data Base Management System "<<endl;
		  cin>>mark1;
		  cout<<endl;
		  //Subject2
		  cout<<"Theory of computation   :"<<endl;
          cin>>mark2;
		  cout<<endl;
		  //Subject3
		  cout<<"Management information System :"<<endl;
		  cin>>mark3;
		  cout<<endl;
		  //Subject4
		  cout<<"optimization technique :"<<endl;
		  cin>>mark4;
		  cout<<endl;
		  //Subject5
		  cout<<"Computer Organization and Design :"<<endl;
		  cin>>mark5;
		  cout<<endl;
		  //Subject7
		  cout<<"Microprocessor and its application :(Ac)"<<endl;
		  cin>>mark7;
		  cout<<endl;
		  //Subject6
		  cout<<"Softwere Lab :"<<endl;
		  cin>>mark6;
		  cout<<endl;
		  //grade_calculate functiomn called
		  grade_calculate();
		}
		void showdata()
		{
		  cout<<"Rollnumber of the Student :"<<endl;
		  cout<<rollno;
		  cout<<endl;
		  cout<<"Name of Student :"<<endl;
		  //student name
		  cout<<name_student;
		  cout<<endl;
		  //these are all bachaler of technology computer science and engineering  subjects
		  //Enter Subject1 marks
		  cout<<"Data Base Management System ";
		  cout<<mark1;
		  cout<<endl;
		  //Subject2 marks
		  cout<<"Theory of computation   :";
          cout<<mark2;
		  cout<<endl;
		  //Subject3 marks
		  cout<<"Management information System :";
		  cout<<mark3;
		  cout<<endl;
		  //Subject4 maeks
		  cout<<"optimization technique :";
		  cout<<mark4;
		  cout<<endl;
		  //Subject5 marks
		  cout<<"Computer Organization and Design :";
		  cout<<mark5;
		  cout<<endl;
		  //Subject7 marks
		  cout<<"Microprocessor and its application :(Ac)";
		  cout<<mark7;
		  cout<<endl;
		  //Subject6 marks
		  cout<<"Softwere Lab :";
		  cout<<mark6;
		  cout<<endl;
		}
		void show_tabular()
		{
			//Showing all result marks wise
			cout<<rollno<<setw(15);
			cout<<name_student<<setw(10);
			cout<<mark1<<setw(5);
			cout<<mark2<<setw(5);
			cout<<mark3<<setw(5);
			cout<<mark4<<setw(5);
			cout<<mark5<<setw(5);
			cout<<mark6<<setw(5);
			cout<<mark7<<setw(5)<<endl;
			cout<<setw(6)<<endl;
			cout<<setprecision(3)<<per;
			cout<<"   "<<grade<<endl;
		}
		
        int  retrollno()
         {
            return rollno;
         }
};
//End the Student class
//Global declaration of stream class obj
fstream fp;
//student class object
student obj;
void write_student()
{
	//file open in append mode
    fp.open("student.dat",ios::out|ios::app);
    //getdata function call
    obj.getdata();
    fp.write((char*)&obj,sizeof(student));
    //student file close function
    fp.close();
    cout<<endl;
	cout<<endl;
	//Showing that function is called or not
	cout<<"Student file record has Been Created ";
    cout<<endl;
    //takes input/output fron keyboard
    getch();
}
/***************************************************************
 ****************************************************************
 **       function to read file record                         **
 ****************************************************************                                                              
 ***************************************************************
 */
void display_all()
{
    fflush(stdin);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    //to use for showing display text
	cout<<"\t\tDisplay all record !!!";
	cout<<endl;
	cout<<endl;
	//file opening
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&obj,sizeof(student)))
    {
        obj.showdata();
        cout<<endl;
        cout<<endl;
		cout<<"====================================";
        cout<<endl;
        getch();
    }
    //file close
    fp.close();
	getch();
}
/***************************************************************
 ****************************************************************
 **    function to read some perticular task from file         **
 ****************************************************************                                                              
 ***************************************************************
*/
void display_sp(int n)
{
	//intialise flag variable which is working like as bool variable
    int flag=0;
    //file opening
    fp.open("student.dat",ios::in);
    //read method work
    while(fp.read((char*)&obj,sizeof(student)))
    {
    	//retrollno() function is called which is define student class 
        if(obj.retrollno()==n)
        {
            fflush(stdin);
          //shodata function is called
		    obj.showdata();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
    {
    	cout<<endl;
    	cout<<endl;
    	//if record is not availble in the student file ,the show "Record is not exit"
        cout<<"record not exist";
    	cout<<endl;
	}
    getch();
}

//***************************************************************
//      function to modify record of file
//      to modify the student record
//****************************************************************
void modify_student()
{
    int rollno,found=0;
    cout<<endl;
    cout<<endl;
    cout<<"\tTo Modify ";
    cout<<endl<<endl;
	cout<<"\tPlease Enter The roll number of student";
    cin>>rollno;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&obj,sizeof(student))&&found==0)
    {
        if(obj.retrollno()==rollno)
        {

        	//shodata function is called
            obj.showdata();
            cout<<endl;
            cout<<"Please Enter The New Details of student";
			cout<<endl;
			//get data function is called
            obj.getdata();
            int pos=-1*sizeof(obj);
            //current position of the file to use seekp methop 
            fp.seekp(pos,ios::cur);
            fp.write((char*)&obj,sizeof(student));
            cout<<endl;
            cout<<endl;
			cout<<"\tUpdated";
            found=1;
        }
    }
    //file closed
    fp.close();
    if(found==0)
        cout<<"Record is not found ::";
    getch();
}
//function use for deleting the perticular student record
void delete_student()
{
    int rollno;
    cout<<"\tDelete Record";
    cout<<endl;
    cout<<"Please Enter The roll number of student You Want To Delete";
    cin>>rollno;
    //student file open
    cout<<endl;
    //file open in input or output mode
    fp.open("student.dat",ios::in|ios::out);
    //fstream class object created
    fstream fp2;
    //temp file create
    fp2.open("temp.dat",ios::out);
    //pointer location at the beginning
	fp.seekg(0,ios::beg);
    while(fp.read((char*)&obj,sizeof(student)))
    {
    	//check roll number are right or wrong
        if(obj.retrollno()!=rollno)
        {
            fp2.write((char*)&obj,sizeof(student));
        }
    }
    fp2.close();
    fp.close();
    //remove method to use for remove the file
    remove("student.dat");
    //rename method to use for renaming b
    rename("temp.dat","student.dat");
    cout<<endl;
	cout<<"\tRecord Deleted ..";
    getch();
}

//***************************************************************
//      function to display all students grade report
//****************************************************************
void class_result()
{
    fp.open("student.dat",ios::in);
    if(!fp)
    {
        cout<<"file could not open"<<endl;
        cout<<"Program is closing ...."<<endl;;
        getch();
        exit(0);
    }
    cout<<endl;
    cout<<endl;
    cout<<"\t\tALL STUDENTS RESULT"<<endl;
    cout<<"===================================================="<<endl;
    cout<<"Roll No. Name         DBMS TOC MIS OT COD MIS  %age Grade"<<endl;
    cout<<"===================================================="<<endl;
    while(fp.read((char*)&obj,sizeof(student)))
    {
    	//show_tabular method call for result print a tabular form
        obj.show_tabular();
    }
    fp.close();
    getch();
}
//***************************************************************
//      function to display result menu
//****************************************************************

void result()
{
    int choice,rollno;
    char ch;
    cout<<endl;
    cout<<endl;
    cout<<"RESULT"<<endl<<endl;
    cout<<"1. Class Result"<<endl;
	cout<<"2. Student Report Card"<<endl;
	cout<<"3.Back to Main Menu"<<endl<<endl;
    cout<<"Enter Choice (1/2)? "<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1 :
        class_result();
        break;
    case 2 :
    {
        do
        {
            fflush(stdin);
            char choice;
            cout<<endl;
            cout<<"Enter Roll Number Of Student : ";
            cin>>rollno;
            display_sp(rollno);
            cout<<endl;
            cout<<"Do you want to See More Result (M/n)"<<endl;
            cin>>choice;
        }
        while(choice=='M'||choice=='m');
        break;
    }
    case 3:
        break;
    default:
        cout<<"\a";
    }
}
/***************************************************************
      Entry 
/****************************************************************/

void entry_menu()
{
    char ch2;
    cout<<endl;
    cout<<"Entry menu"<<endl;
    cout<<"1.Create Student Record"<<endl;
    cout<<"2.Display all Student records"<<endl;
    cout<<"3.Search Student record "<<endl;
    cout<<"4.Modify Student record"<<endl;
    cout<<"5.Delete Student record"<<endl;
    cout<<"6.Back to the main"<<endl;
    cout<<"Please Enter Your Choice (1-6)"<<endl;
    //choice input  "getche()" from keyboard
    ch2=getche();
    switch(ch2)
    {
    case '1':
    	//write method call
        write_student();
        break;
    case '2':
    	//Display method call
        display_all();
        break;
    case '3':
        int rollno;
        fflush(stdin);
        cout<<endl;
        cout<<"Please Enter The roll number ";
        cin>>rollno;
        //display
        display_sp(rollno);
        break;
    case '4':
    	//data modification
        modify_student();
        break;
    case '5':
    	//delete data from file
        delete_student();
        break;
    case '6':
        break;
    default:
        cout<<"Default"<<endl;
        //let us called entry_menu method
        entry_menu();
    }
}
/***************************************************************
//      INTRODUCTION FUNCTION
//****************************************************************
*/
void intro()
{
	/*The gotoxy() funtion is used to simply move the cursor on your monitor screen wherever desired.
      It is declared in the "conio.h" header file.
      gotoxy(int x,int y)
      print like as:
                    STUDENT
                    Report Card
                    Project
                    Nitish Kumar Arya
                    Computer Science and Engineering
                    From : Madan Mohan malaviya University of Technology ,Gorakhpur
    */
    gotoxy(35,11);
    cout<<"STUDENT";
    gotoxy(33,14);
    cout<<"Report Card";
    gotoxy(35,17);
    cout<<"Project"<<endl;
    cout<<"Made by : Nitish Kumar Arya"<<endl;
    cout<<"Computer Science and Engineering"<<endl<<endl;
    cout<<"From : Madan Mohan malaviya University of Technology ,Gorakhpur";
    getch();

}
/***************************************************************
 ****************************************************************
 **    THE MAIN function of this Project                       **
 ****************************************************************                                                              
 ***************************************************************
 */

int main()
{
  char ch;
  intro();
  do{
  	fflush(stdin);
  	//i am try to showing attractive after running my project
	cout<<"                  WELOCOME                    "<<" "<<endl;
	cout<<"*******  ******  ******* *******  ******  *******  *******  ******  ******* *******  ******  ******* "<<endl;
	cout<<" *****    ****    *****   *****    ****    *****   *****    ****    *****   *****    ****    ***** "<<endl;
	cout<<"  ***      **      ***     ***      **      ***     ***      **      ***     ***      **      ***  "<<endl;
	cout<<"   ******************       ******************       ******************       ******************   "<<endl;
	cout<<"    *****************************************         *****************************************    "<<endl;
    cout<<"*******  ******  ******* *******  ******  *******  *******  ******  ******* *******  ******  ******* "<<endl;
  	cout<<"Result"<<endl;
  	cout<<"Entry / Edit Menu"<<endl;
  	cout<<"Exit"<<endl;
  	cout<<endl;
  	cout<<"please select 1-3"<<endl;
  	ch=getche();
  	//select your choice
    switch(ch)
        {
        case '1':
        	fflush(stdin);
            //Result function is called
			result();
            break;
        case '2':
        	//fflush(stdion) used for buffering 
        	fflush(stdin);
        	//enty_menu method are called
            entry_menu();
            break;
        case '3':
        	fflush(stdin);
            exit(0);
        default :
        	fflush(stdin);
            cout<<"\a";
        }
        //end of switch function
    }
    //ending of do while loop
    while(ch!='3'); 	
    cout<<endl;
	return 0;
} 
/* complete project
   workind Dates 10-12-2018 To 13-01-2019
  Dairy
       i follow book name : ANSI C++
      10-12-2018 :
	             i am create a project structure
                 like as a parameter are required for this project
      13-12-2018 to 18-12-2018:
                  Student class create and think about the which type function are use
                  and some code code on dev c++
      25-12-2018 to 31-12-2018:
	              Some function Defination 
      13-12-2019 :
                 finally i hava completed my project 
                 Its project taken more time because i am not able to regularily work on this project
	  Thank you so much
*/
