#include<iostream>
#include<fstream>
#include<iomanip>                   
using namespace std;
int chooseMain();
void getPatientDatabase();
void getDoctorDatabase();
void blood_bank();
void getDoctor();
class blood
{
	protected:
		int OP,ON,AP,AN,BP,BN,ABP,ABN;
	public:
		blood()                         //constructor
		{
			OP=100;
			ON=25;
			AP=30;
			AN=25;
			BP=30;
			BN=10;
			ABP=15;
			ABN=10;
		}
		void donate()
		{
			string s;
			cout<<"Enter blood group: ";
			cin>>s;
			if(s=="O+")
			{
				OP++;
			}
			else if(s=="O-")
			{
				ON++;
			}
			else if(s=="A+")
			{
				AP++;
			}
			else if(s=="A-")
			{
				AN++;
			}
			else if(s=="B+")
			{
				BP++;
			}
			else if(s=="B-")
			{
				BN++;
			}
			else if(s=="AB+")
			{
				ABP++;
			}
			else if(s=="AB-")
			{
				ABN++;
			}
			cout<<"Thank You for Donating Blood. You have Successfully Donated the Blood and It has been Added to our Blood Bank.\n";
		}
			void need()
		{
			string s;
			cout<<"Enter blood group: ";
			cin>>s;
			if(s=="O+")
			{
				OP--;
			}
			else if(s=="O-")
			{
				ON--;
			}
			else if(s=="A+")
			{
				AP--;
			}
			else if(s=="A-")
			{
				AN--;
			}
			else if(s=="B+")
			{
				BP--;
			}
			else if(s=="B-")
			{
				BN--;
			}
			else if(s=="AB+")
			{
				ABP--;
			}
			else if(s=="AB-")
			{
				ABN--;
			}
			cout<<"Successfully provided "<<s<<" blood from Blood Bank\n";
		}
	void display();
	~blood()
	{
		cout<<"\n Destructor of class blood";
	}
};
	void blood::display()
		{
			cout<<"Updated Blood Bank Details\n";
			cout<<"--------------------------\n";
			cout<<"A+ve "<<AP;
			cout<<"\nA-ve "<<AN;
			cout<<"\nB+ve "<<BP;
			cout<<"\nB-ve "<<BN;
			cout<<"\nO+ve "<<OP;
			cout<<"\nO-ve "<<ON;
			cout<<"\nAB+ve "<<ABP;
			cout<<"\nAB-ve "<<ABN;
					}
class hospital
{
	public:
		string name,gender,phone,city,disease,adm_Date,dept;
		int age,id;
		string getDept(){
	        string sp;
	        cout<<"1.GENERAL_MEDICINE"<<endl;
	        cout<<"2.NEUROLOGY"<<endl;
	        cout<<"3.CARDIOLOGY"<<endl;
	        cout<<"4.NEPHROLOGY"<<endl;
	        cout<<"5.GASTROENTEROLOGY"<<endl;
	        cout<<"6.GYNAECOLOGY"<<endl<<endl;
           	int s;
	        cin>>s;
	        switch(s){
            	case 1:{
		         	sp= "GENERAL_MEDICINE";
		        	break;
		        }
		        case 2:{
			        sp="NEUROLOGY";
			        break;
		        }
	         	case 3:{
		            sp="CARDIOLOGY";
		         	break;
	        	}
	          	case 4:{
			        sp= "NEPHROLOGY";
		         	break;
	         	}
	         	case 5:{
		         	sp= "GASTROENTEROLOGY";
		        	break;
		        }
	           	case 6:{
		          	sp= "GYNAECOLOGY";
		        	break;
		        }
		        default:{
	            	cout<<"\nCome on!Enter a valid option."<<endl;
                }
			}
	    	return sp;
        }
		virtual void displayPat()
        {
        	cout<<"Patients";
		}    
};
class doctor:public hospital
{
	string d_fname,qual,d_city;
	int d_ID,d_age,experience;
	public:
		void addDoc(){
	    doctor d;
	    cout<<"Fill up the following details"<<endl;
	    cout<<"ID:"<<endl;
	    cin>>d.d_ID;
   		cout<<"Name:"<<endl;
   		cin>>d.d_fname;
   		cout<<"Age:"<<endl;
   		cin>>d.d_age;
   		cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
   		int q;
   		cin>>q;
   		if(q==1)
   			d.qual="MBBS";
		else d.qual="MD";
		cout<<"Choose Specialization among the following:"<<endl;
		string spec=d.getDept();
		cout<<"Experience (in Years):"<<endl;
		cin>>d.experience;
		cout<<"City:"<<endl;
		cin>>d.d_city;
		system("cls");


		fstream fileObj;
		fileObj.open("doctor.txt",ios::app );
        fileObj.seekp (0, ios::end);
		fileObj<<d.d_ID<<endl<<d.d_fname<<endl<<d.d_age<<endl<<d.qual<<endl<<spec<<endl<<d.experience<<endl<<d.d_city<<endl;
		fileObj.close();
	cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getDoctorDatabase();
	}
	else
	  exit(0);
	}
	void dispDatabase(){
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<right<<setw(70)<<setfill(' ')<<"DOCTOR DATABASE"<<endl<<endl;
	int age,exp,count=0;
	string ID,fname,ci,qua,spe;
	while(fileObj>>ID>>fname>>age>>qua>>spe>>exp>>ci)
	{	count++;
		cout<<right<<setw(50)<<setfill(' ')<<"Doctor Profile:"<<count<<endl;
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.Name:"<<fname<<endl<<"3.Age:"<<age<<endl<<"4.Qualification:"<<qua<<endl<<"5.Specialization:"<<spe<<endl<<"6.Experience:"<<exp<<endl<<"7.City:"<<ci<<endl;
	}
	if(count==0)
	{cout<<"\nNo matching records found!"<<endl;
 	 exit(0);
	}

	cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1)
	{
	  system("cls");
	  getDoctorDatabase();
	}
	else
	  exit(0);
}
};

class patient:public hospital
{
	public:
		void addPat(){
	    patient p;									
	    cout<<"Fill up the following details"<<endl;
	    cout<<"ID:";
	    cin>>p.id;
   		cout<<"Name:"<<endl;
   		cin>>p.name;
   		cout<<"Gender M/F: "<<endl;
   		cin>>p.gender;
   		cout<<"Age:"<<endl;
   		cin>>p.age;
		cout<<"Phone No.:"<<endl;
   		cin>>p.phone;
		cout<<"City:"<<endl;
		cin>>p.city;
   		cout<<"Disease/Symptoms:"<<endl;
   		cin>>p.disease;
   		cout<<"Admission date  (DD/MM/YYYY):"<<endl;
   		cin>>p.adm_Date;
		cout<<"Kind of Specialization required:"<<endl;
		string dept=p.getDept();
		system("cls");

        fstream patObj;
		patObj.open("patient.txt",ios::app );
        patObj.seekp (0, ios::end);
		patObj<<p.id<<endl<<p.name<<endl<<p.gender<<endl<<p.age<<endl<<p.phone<<endl<<p.city<<endl<<p.disease<<endl<<p.adm_Date<<endl<<dept<<endl;
		patObj.close();

	cout<<"\n\t\tNew Patient profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}

	else
	  exit(0);
}
//the displayPat function
void displayPat(){
	int x;
	cout<<"\nEnter the ID of the Patient whose profile you want to Display:"<<endl;
	cin>>x;
	fstream patObj("patient.txt");
	patObj.seekg(0);
									
	//string name,gender,city,disease,adm_Date,dept,phone;
	//int age,id,
	int count=0;
	while(patObj>>id>>name>>gender>>age>>phone>>city>>disease>>adm_Date>>dept)
	{
		if(id==x){
		cout<<"1.ID:"<<id<<endl<<"2.Name:"<<name<<endl<<"3.Gender:"<<gender<<endl<<"4.Age"<<age<<endl<<"5.Phone No.:"<<phone<<endl<<"6.City:"<<city<<endl<<"7.Disease/Symptoms:"<<disease<<endl<<"8.Admission date(DD/MM/YYYY):"<<adm_Date<<endl<<"9.Kind of Specialization required:"<<dept<<endl;
		count++;
		break;
		}
	}

	patObj.close();
	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}

cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}

	else
	  exit(0);
}


//the dispPatDatabase function
void dispPatDatabase(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	cout<<right<<setw(70)<<setfill(' ')<<"PATIENT DATABASE"<<endl<<endl;
	int count=0;
	while(Obj>>id>>name>>gender>>age>>phone>>city>>disease>>adm_Date>>dept)
	{   count++;
		cout<<right<<setw(50)<<setfill(' ')<<"Patient Profile:"<<count<<endl;
		cout<<"1.ID:"<<id<<endl<<"2.Name:"<<name<<endl<<"3.Gender:"<<gender<<endl<<"4.Age:"<<age<<endl<<"5.Phone No.:"<<phone<<endl<<"6.City:"<<city<<endl<<"7.Disease/Symptoms:"<<disease<<endl<<"8.Admission date(DD/MM/YYYY):"<<adm_Date<<endl<<"9.Kind of Specialization required:"<<dept<<endl;
		}

	Obj.close();

	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}

cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}

	else
	  exit(0);

}

//the numberofPats function
void numberofPats(){
	fstream Obj("patient.txt");
	Obj.seekg(0);
	//int age,id;
	//string name,gender,phone,city,disease,adm_Date,dept;
	int count1=0;
	while(Obj>>id>>name>>gender>>age>>phone>>city>>disease>>adm_Date>>dept)
	{
	 count1++;
	}

	Obj.close();
	cout<<"\n\n\tThe number of patients in the hospital="<<count1<<endl;

cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}

	else
	  exit(0);

}
};
class appointment:public doctor
{	
	public:
		int n;
		int bookAppointment()
{ cout<<"\n ----- Book Your Appointment ---- \n";	
    cout<<"\n ----- Available slots ---- \n";	 

    //check if record already exist..
    cout<<"Enter the doctor's id: ";
	cin>>n;
	ifstream read;
	switch(n)
	{
	
		case 1:
			{
			read.open("shanmathi.txt");
			break;
			}
     	case 2:
			{
			read.open("shrinidhi.txt");
			break;
			}
		case 3:
			{
			read.open("anitha.txt");
			break;
			}
		case 4:
			{
			read.open("dhanya.txt");
			break;
			}
		case 5:
			{
			read.open("arjun.txt");
			break;
			}
		case 6:
			{
			read.open("prithvi.txt");
			break;
			}
		case 7:
			{
			read.open("karthik.txt");
			break;
			}
		case 8:
			{
			read.open("saindhavi.txt");
			break;
			}
		case 9:
			{
			read.open("ram.txt");
			break;
			}
		case 10:
			{
			read.open("shanaya.txt");
			break;
			}
		case 11:
			{
			read.open("prasad.txt");
			break;
			}
		case 12:
			{
			read.open("punith.txt");
			break;
			}
		}
    int hoursbook = 8;
    int arr[13] = {0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n Appointment Summary by hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=10; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}
	
	else
	{								           	
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}            
	}	
	read.close();
    }
	if(recordFound == 0){
	cout<<"\n Appointment Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=18; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}		
	}
   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<<"\n Error : Invalid Selection";
	cout<<"\n Please selection correct value from menu A- Z";
	cout<<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	bookAppointment();
   }
   
   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0) 
      isBooked = 0;
      
   if(isBooked ==1)
   {
   	cout<<"\n Error : Appointment is already booked for this Hour";
   	cout<<"\n Please select different time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	bookAppointment();
   }
   
   string name;
   cout<<"\n Enter your first name:";
   cin>>name;  
   
   ofstream out;
   switch(n)
	{
	    case 1:
			{
			out.open("shanmathi.txt",ios::app);
			break;
			}
		 case 2:
			{
			out.open("shri.txt",ios::app);
			break;
			}
		 case 3:
			{
			out.open("anitha.txt",ios::app);
			break;
			}
		case 4:
			{
			out.open("dhanya.txt",ios::app);
			break;
			}
		 case 5:
			{
			out.open("arjun.txt",ios::app);
			break;
			}
		 case 6:
			{
			out.open("prithvi.txt",ios::app);
			break;
			}
		 case 7:
			{
			out.open("karthik.txt",ios::app);
			break;
			}
		 case 8:
			{
			out.open("saindhavi.txt",ios::app);
			break;
			}
		 case 9:
			{
			out.open("ram.txt",ios::app);
			break;
			}
		 case 10:
			{
			out.open("shanaya.txt",ios::app);
			break;
			}
		 case 11:
			{
			out.open("prasad.txt",ios::app);
			break;
			}
		 case 12:
			{
			out.open("punith.txt",ios::app);
			break;
			}
			
	}
	
   if(out){
	   out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}
	
};
main()
{
	 system("cls");
	cout<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"WELCOME TO SAYONORA HOSPITAL MANAGEMENT SYSTEM "<<endl;
	cout<<endl<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"------------------------------------------------"<<endl;
    cout<<right<<setw(40)<<setfill(' ')<<"1.Main Menu"<<endl;
	cout<<right<<setw(35)<<setfill(' ')<<"2.Exit"<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"------------------------------------------------"<<endl<<endl;
	cout<<"Enter your choice:"<<endl<<endl;
	int choice1;
	cin>>choice1;
    if (choice1==1){
		 system("cls");
		 int var=chooseMain();
		 system("cls");
		 	switch(var){
	
			case 1:{
			    
				system("cls");
				blood_bank();
				break;
			}

			case 2:{
				system("cls");
		    	getPatientDatabase();
				break;
			}

			case 3:
				{
				system("cls");
		    	getDoctorDatabase();
				break;
			case 4:{
		        system("cls");
		        getDoctor();
		        break;
			    }
	    	case 5:{
	            return 0;
				break;
				}
			default:
				cout<<"\nCome on!Enter a valid option."<<endl;
		}

	}
}
	else if(choice1==2){
		return 0;
	}
	else
	 cout<<"\nCome on!Enter a valid option."<<endl;
}

//the chooseMain function
int chooseMain(){

	int choice2;
	cout<<right<<setw(40)<<setfill(' ')<<"\nMAIN MENU"<<endl<<endl<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
	cout<<"			"<<"1.Enter Into BloodBank details"<<endl;
	cout<<"			"<<"2.Enter Into Patients' Database"<<endl;
	cout<<"			"<<"3.Enter Into Doctors' Database"<<endl;
	cout<<"			"<<"4.Appointment"<<endl;
	cout<<"			"<<"5.Exit"<<endl<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;

	cout<<"\nEnter the number corresponding to your choice:"<<endl;
	cin>>choice2;
	return choice2;

}
void blood_bank()
{
		int a;
    cout<<"\n                         "<<"WELCOME TO BLOOD BANK DATABASE"<<endl<<endl;
	cout<<"\n1.Donate \n2.Need blood \n3.Availability\nEnter your choice :";
	cin>>a;
	blood b;
	switch(a)
	{
		case 1:
			{
				b.donate();
				b.display();
				break;
			}
		case 2:
			{
				b.need();
				b.display();
				break;
			}
		case 3:
			{
				b.display();
				break;
			}
	}
}
void getDoctorDatabase(){
	int choice_doc;
	cout<<"\n                         " <<"WELCOME TO DOCTOR'S DATABASE"<<endl<<endl;
	cout<<"			"<<"1.Add New Doctor's Information"<<endl;
	cout<<"			"<<"2.Display Entire Doctor Database"<<endl;
	cout<<"			"<<"3.Exit"<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;
    cout<<right<<setw(60)<<setfill(' ')<<"\nEnter the number corresponding to your choice:"<<endl<<endl;
	cin>>choice_doc;
	system("cls");
	doctor d;
	switch(choice_doc){
		case 1:{

		    d.addDoc();
			break;
		}
		case 2:{
        	d.dispDatabase();
			break;
		}
		case 3:{
			exit(0);
			break;
		}
}
}
void getDoctor()
{
	patient p;
	string dept;
	int idarr[2],n,i=0;
	cout<<"\nEnter the kind of specialization you are looking for:"<<endl<<endl;
	dept=p.getDept();
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<"------------------------------------------------------------------";
	cout<<"\nThe Doctors Available With  "<<dept<<" Specialization are:"<<endl;
    cout<<"------------------------------------------------------------------";
	int ID,age,exp,count=0;
	string fname,gender,ci,qua,spe;
	while(fileObj>>ID>>fname>>age>>qua>>spe>>exp>>ci)
	{
		if(spe==dept){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.Name:"<<fname<<endl<<"3.Age:"<<age<<endl<<"4.Qualification:"<<qua<<endl<<"5.Specialization:"<<spe<<endl<<"6.Experience:"<<exp<<endl<<"7.City:"<<ci<<endl;
		count++;
		}
	}
	fileObj.close();
	int c;
	if(count==0){
		cout<<"\nNo doctors with this specialization found!"<<endl;
		cout<<"--------------------------------------------";
		exit(0);
	}
	else
	{
		cout<<"\nNumber of Doctors with "<<dept<<" Specialization:"<<count<<endl;
		cout<<"-----------------------------------------------------------";
	cout<<"\n ----- Book Your Appointment ---- \n";
    int i=0;
	appointment a;
	a.bookAppointment();
	i++;
    cout<<"\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Get back to appointment \n enter 3 to Exit."<<endl;
	cin>>c;
}
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}
	else if(c==2)
	{
		getDoctor();
	}

	else
	  exit(0);
}

void getPatientDatabase(){
	int choice_pat;
	cout<<"\n                         "<<"WELCOME TO PATIENT'S DATABASE"<<endl<<endl;
	cout<<"			"<<"1.Add New Patient's Information"<<endl;
	cout<<"			"<<"2.Display a Patient's Information"<<endl;
	cout<<"			"<<"3.Display Entire Patient Database"<<endl;
	cout<<"			"<<"4.Total Number of Patients"<<endl;
	cout<<"			"<<"5.Exit"<<endl;
	cout<<right<<setw(80)<<setfill('-')<<"----------"<<endl;

	cout<<right<<setw(60)<<setfill(' ')<<"\nEnter the number corresponding to your choice:"<<endl<<endl;
	cin>>choice_pat;
	system("cls");
	patient p;
	switch(choice_pat){
		case 1:{
		    p.addPat();
			break;
		}
		case 2:{
			hospital *h;
			h=&p;
			h->displayPat();
			break;
		}
		case 3:{
			p.dispPatDatabase();
			break;
		}
		case 4:{
			p.numberofPats();
			break;
	}
	    case 5:{
			exit(0);
			break;
		}
}
}
