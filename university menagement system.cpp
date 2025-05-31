#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
 static const int maxStudent = 50;  // ? Correct static constant
    int studentIndex=0;
    string sName[maxStudent];
    string sID[maxStudent];
    string sEnrolmentDate[maxStudent];
    string sMajor[maxStudent];
    int sCreditHour[maxStudent];
    char sGradepoints[maxStudent];
    string sn,sId[maxStudent],sEn;
public:
    char choice;
    // void sUpdateInfo(){
    //	bool found = false;
    ////	cout>>"Enter the number you want to update:";
    //	cin>> sn;}
    void sRemoveInfo(){
    	cout<<"==============Deleting Information============"<<endl;
    		cout<<"Please enter the id number that's information you want to delete:"<<endl;
    		cin>> sId[maxStudent];
			if(studentIndex>0){
				  bool found = false;
			   for(int i=0; i<studentIndex ; i++){
				 if(sId[maxStudent]==sID[i]){
					found = true;
						for(int j=i; j<studentIndex-1; j++){
					     sName[j]=sName[j+1];
                         sID[j]= sID[j+1];
                         sEnrolmentDate[j]=sEnrolmentDate[j+1];
                         sMajor[j]=sMajor[j+1];
                         sCreditHour[j]=sCreditHour[j+1];
                         sGradepoints[j]=sGradepoints[j+1 ];
                         }
					studentIndex--;
					cout<<"Record Information on " << sId << "has been deleted successfully."<<endl;
					break;
				}
				if(!found){
					cout<<"Student Enrollement Number not Enrolled till now!";
				}
			}
		} 
		else{
			cout<<"NO RECORD Information for deleting!";
		} 
			}
    void sAddInformation() {
        int newStudents;
        cout << "============= ADDING INFORMATION ===========" << endl;
        cout << "Enter the number of students you want to add: ";
        cin >> newStudents;

        if (studentIndex + newStudents > maxStudent) {
            cout << "Error: Cannot add more than " << maxStudent << " students.\n";
            return;
        }

        cin.ignore();  // Ignore newline character

        for (int i = 0; i < newStudents; i++) {
            cout << "\nEnter details for student " << studentIndex + 1 << ":" << endl;
            cout << "Enter student name: ";
            getline(cin, sName[studentIndex]);
            cout << "Enter student ID: ";
            getline(cin, sID[studentIndex]);
            cout << "Enter enrolment date: ";
            getline(cin, sEnrolmentDate[studentIndex]);
            cout << "Enter major: ";
            getline(cin, sMajor[studentIndex]);

            studentIndex++;  // Move to next student
        }

        // Ask for GPA calculation
        cout << "\nDo you want to calculate GPA? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
    }
    
		float getGradePoints(char grade){
			switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
         default:
            cout << "Invalid grade entered. Using 0.0" << endl;
            return 0.0;
    }
}
    void getGpa() {
        int numCourses;
        cout << "\nEnter the number of courses: " << endl;
        cin >> numCourses;

        float totalWeightedGP = 0, totalCredits = 0;

        for (int i = 0; i < numCourses; i++) {
            char grade;
            int creditHours;

            cout << "Enter grade (A, B, C, D, F) for course " << i + 1 << ": ";
            cin >> grade;
            grade = toupper(grade);
            cout << "Enter credit hours for course " << i + 1 << ": ";
            cin >> creditHours;

            float gradePoint = getGradePoints(grade);

            totalWeightedGP += (gradePoint * creditHours);
            totalCredits += creditHours;
        }

        if (totalCredits == 0) {
            cout << "No courses entered. GPA calculation not possible." << endl;
        } else {
            float GPA = totalWeightedGP / totalCredits;
            cout << "Your Semester GPA is: " << GPA << endl;
        }
    }
   
    void sDisplayInformation() {
        if (studentIndex == 0) {
            cout << "No students available.\n";
            return;
        }

        cout << "\n========= Student Information =========\n";
        for (int i = 0; i < studentIndex; i++) {
            cout << "Student " << i + 1 << ":\n";
            cout << "Name: " << sName[i] << "\n";
            cout << "ID: " << sID[i] << "\n";
            cout << "Enrolment Date: " << sEnrolmentDate[i] << "\n";
            cout << "Major: " << sMajor[i] << "\n";
            cout << "---------------------------------\n";
        }
    }
};

// Continue fixing other classes similarly...

class Employee{
	private:
		static const int maxEmployee=30;
		int employeeIndex=0;
		string eName[maxEmployee];
		int empID[maxEmployee];
		string eDepartment[maxEmployee];
		string ePosition[maxEmployee];
		double eAnnualSalary[maxEmployee];
        double eBonusPercentage[maxEmployee];
        int monthsWorked[maxEmployee];
        char choice;
        int eId;
        public:
        void eRemoveInfo(){
        	cout<<"Enter number you want to delete id:"<<endl;
        	cin>> eId;
        	if(employeeIndex>0){
        		bool found=false;
        		for(int i=0;i<employeeIndex;i++){
        	if(eId == empID[i]){
        		found=true;
        		for(int j=i;j<employeeIndex-1;j++){
        eName[j]=eName[j+1];
        empID[j]=empID[j+1];
		eDepartment[j]=eDepartment[j+1];
	    ePosition[j]=ePosition[j+1];
		eAnnualSalary[j]=eAnnualSalary[j+1];
        eBonusPercentage[j]=eBonusPercentage[j+1];
        monthsWorked[j]=monthsWorked[j+1];	
				}
				employeeIndex--;
				cout<<"Record information on " << eId << " has been deleted"<<endl;
				break;
			}
			if(!found){
				cout<<"Employee enrolment number not enrolled till now";
			}
              }
    }
	else{
          	cout<<"No record found for deletng!";
		  }
		}
		void eAddInformation() {
			 int newEmployee;
        cout << "============= ADDING INFORMATION ===========" << endl;
        cout << "Enter the number of employees you want to add: ";
        cin >> newEmployee;

        if (employeeIndex + newEmployee > maxEmployee) {
            cout << "Error: Cannot add more than " << maxEmployee << " students.\n";
            return;
        }

        cin.ignore();  // Ignore newline character

        for (int i = 0; i < newEmployee; i++) {
        	cout<<"Enter the information of employee: "<<i+1<<endl;
            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, eName[employeeIndex]);

            cout << "Enter employee ID: ";
            cin >> empID[employeeIndex];
            cin.ignore();
            cout << "Enter employee department: ";
            getline(cin, eDepartment[employeeIndex]);

            cout << "Enter employee position: ";
            getline(cin, ePosition[employeeIndex]);
            cout << "\nDo you want to calculate yearly bonus? (Y/N): ";
            cin >> choice;
            choice = toupper(choice);
		
            cout << "Enter employee salary: ";
            cin>>eAnnualSalary[employeeIndex];
			cout<<"Enter employe bonus percentage on salary: ";
			cin>> eBonusPercentage[employeeIndex];
			cout<<"Enter employee moths worked in a year(1-12): ";
			cin>> monthsWorked[employeeIndex];
			if(monthsWorked[employeeIndex]<1 || monthsWorked[employeeIndex]>12){
				cout << "Invalid months entered. Setting to 12 (full year)." << endl;
                monthsWorked[employeeIndex]= 12;
            }
        employeeIndex++;
    }
}
    
     double eDisplayInformation() {
     	for (int i = 0; i < employeeIndex; i++) {
        
         cout<<"===========Information of employee: "<<i+1<<endl;
       cout<<"Employee name: " <<eName[i]<<endl; 
       cout<<"Employee Id: "<<empID[i]<<endl;
       cout<<"Employe department: "<<eDepartment[i]<<endl;
       cout<<"Employe position: "<<ePosition[i]<<endl;
	   cout<<"Employe salary: $"<<eAnnualSalary[i]<<endl; 
	   cout<<"employee moths worked: "<<monthsWorked[i]<<endl;
	   cout<<"employee bonus percentage: "<<eBonusPercentage[i]<< "%"<<endl;
	    if (choice == 'Y') {
            double yearlyBonus = (eAnnualSalary[i] * eBonusPercentage[i] / 100) * (monthsWorked[i] / 12.0);
            cout << "Employee yearly bonus: $" << yearlyBonus << endl;
        } else {
            cout << "Yearly bonus calculation skipped.\n";
        }
        cout << "---------------------------------\n";
        }
    }
};
class course{
	private:
		string courseName;
		string courseCode;
		string cInstructor;
		int cCredits;
		public:
		void cAddInformation(){
			cout<<"Enter the course Name: ";
			cin>> courseName;
			cout<<"Enter the course code: ";
			cin>> courseCode;
			cout<<"Enter the name of course instructor: ";
			cin>> cInstructor;
			cout<<"Enter the course credit: ";
			cin>> cCredits; 
		}
		void cDisplayInformation(){
			cout<<"Course Name: "<<courseName<<endl;
			cout<<"Course Code: "<<courseCode<<endl;
			cout<<"Course Instructor: "<<cInstructor<<endl;
			cout<<"Course Credits: "<<cCredits<< " hours"<<endl;
		}
};
class Grade{
	private:
		string studentName;
		int studentId;
		string courseCode;
		char grade;
		public:
			void assignGradeInformation(){
				cout<<"Enter Student Name: ";
				cin>> studentName;
				cout<<"Enter Student ID: ";
				cin>> studentId;
				cout<<"Enter couse code: ";
				cin>> courseCode;
				cout<<"Enter the grade: ";
				cin>> grade;
					}
			void displayGradeInformation(){
				cout<<"Student Name: "<<studentName<<endl;
				cout<<"Student Id: "<<studentId<<endl;
				cout<<"Course Code: "<<courseCode<<endl;
				cout<<"Enter grade: "<<grade<<endl;
			}
};
void studentOper(){
    	cout<<"=============STUDENT INFORMATION=================="<<endl;
	Student s1;
	int choice;
	do{
		cout<<"Enter a number you want to perform operation between(1-5):"<<endl;
		cout<<"1.Add a new student: \n";
       	cout<<"2.Display information for a specific student: \n"; 
        cout<<"3.Update student information: \n";
      	cout<<"4.Remove a student: \n";
      	cout<<"5.exit: \n";
      	cin>>choice;
      	switch(choice){
      		case 1:
      			s1.sAddInformation();
      			 if (s1.choice == 'Y') {
        s1.getGpa();
    } else { 
        cout << "\nGPA calculation skipped." << endl;
    }
      			break;
      		case 2:
      	cout<<"======= Displaying Student detail==== "<<endl;
		  s1.sDisplayInformation();
				break;
			case 3:
				
				break;
			case 4:
				s1.sRemoveInfo();	
		      	break;
		   case 5:
			   cout << "Exiting...\n";
                break;
           default:
          cout << "Invalid choice!\n";
         }
           } while (true);
}
void employeeOper(){
     cout<<"==============EMPLOYE INFORMATION==================="<<endl;
    Employee emp;
	int choice;
	do{
		cout<<"Enter a number you want to perform operation between(1-5):\n";
		cout<<"1.Add a new employee: \n";
       	cout<<"2.Display information for a specific employee: \n"; 
        cout<<"3.Update employee information: \n";
      	cout<<"4.Remove a employee: \n";
      	cout<<"5.exit: \n";
      	cin>>choice;
      	switch(choice){
      		case 1:
      			emp.eAddInformation();
      			break;
      		case 2:
      				cout<<"======= Displaying employee detail==== "<<endl;
	                emp.eDisplayInformation();
				break;
			case 3:
				
				break;
			case 4:
				emp.eRemoveInfo();	
		      	break;
		   case 5:
		  cout << "Exiting...\n";
        break;
        default:
        cout << "Invalid choice!\n";
    }
       } while (true);
}
void courseOper(){
    cout<<"==================COURSE INFORMATION=================="<<endl;
    course c1;
	int choice;
	do{
		cout<<"Enter a number you want to perform operation between(1-5):\n";
		cout<<"1.Add a new course: \n";
       	cout<<"2.Display information for a specific course: \n"; 
        cout<<"3.Update course information: \n";
      	cout<<"4.Remove a course: \n";
      	cout<<"5.exit: \n";
      	cin>>choice;
      	switch(choice){
      		case 1:
      			c1.cAddInformation();
      			break;
      		case 2:
      cout<<"========Displaying course detail=========="<<endl;
      c1.cDisplayInformation();
		
				break;
			case 3:
				
				break;
			case 4:
					
		      	break;
		   case 5:
		  cout << "Exiting...\n";
        break;
        default:
        cout << "Invalid choice!\n";
    }
       } while (true);
}
void gradeOper(){
    	cout<<"=================GRADE INFORMATION=============="<<endl;
	Grade g1;
	
	int choice;
	do{
		cout<<"Enter a number you want to perform operation between(1-5):\n";
		cout<<"1. Assign a grade to a student for a course: \n";
       	cout<<"2.Display information for a specific student: \n"; 
        cout<<"3.Update grade information: \n";
      	cout<<"4.Remove a grade: \n";
      	cout<<"5.exit: \n";
      	cin>>choice;
      	switch(choice){
      		case 1:
      		g1.assignGradeInformation();	
      			break;
      		case 2:
      			
	cout<<"========Displaing Grade Information========="<<endl;
	g1.displayGradeInformation();
				break;
			case 3:
				
				break;
			case 4:
					
		      	break;
		   case 5:
		  cout << "Exiting...\n";
        break;
        default:
        cout << "Invalid choice!\n";
    }
       } while (true);
}
int main(){
	int choice;
	string uName,uPassword;
	string logId="1122",logPassword="kaka";
    cout<<"============WELCOME TO UNIVERSITY MENAGEMENT SYSTEM============"<<endl;
    cout<<"===========ADMINISTRATION PORTION========="<<endl;
    cin.ignore();
    cout<<"=====Sign in first to login=========please enter user name:";
	getline(cin,uName);
	cout<<"Enter user login password: ";
	cin>> uPassword;
	if (uName==logId && uPassword==logPassword ){
		cout<<"====login successfully====="<<endl;

	do{ 
	    cout<<"-----------------------------------------"<<endl;
		cout<<"|Welcome to university menagement system|"<<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"Enter a number you want to perform operation between 1 to 5: "<<endl;
		cout<<"1.Student-related operations: \n";
	    cout<<"2.Employee-related operations: \n";
		cout<<"3.Course-related operations: \n";
		cout<<"4.Grade-related operations: \n";
		cout<<"5.exit: \n";
		cin>> choice;
		switch(choice){
			case 1:
			studentOper();
			break;	
			case 2:
			employeeOper();
			break;
			case 3:
			courseOper();
			break;
			case 4:
			gradeOper();
			break;
			case5:
			 exit(0);
        default:
            cout << "Invalid choice! Please try again\n";	
		}
	}while (choice != 5);
}else{
	cout<<"Incorrect login,please try again!"<<endl;
}
    return 0;
	}
