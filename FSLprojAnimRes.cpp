//============================================================================
// Name        : FSLprojAnimRes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : AnimalRes.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : animalReserve.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;

class reserve{
public: char name[50],state[30],nearestCity[30],buffer[300],areaInKm[20],num[15],estYear[20];

};
reserve r[100];

class species{
public: char rrn[5],name[50],list[100],buffer[500];
};
species sp[100];


void insert();
void search();
void display();
void modify();
int getNumRecords();
void insertSpecies();
void dispSpecies();
void searchSpecies();
void adminMenu();
void userMenu();
void admin();


int main() {
	int choice;

				{
				cout<<"************************WELCOME TO ANIMAL RESERVE MANAGEMENT SYSTEM*****************************\n";
				cout<<"CAUTION: The system is 'CASE SENSITIVE'.Enter inputs accordingly.\n";
				inv:
				cout<<"CHOOSE YOUR VIEW:\n";
				cout<<"1.Admin view\n2.User view\n3.Exit application\n";
				cout<<"Enter your choice:";
				cin>>choice;

				switch(choice)
				{
				case 1:admin();
					   break;

				case 2:userMenu();
				       break;

				case 3:cout<<"\n\nTHANK YOU FOR USING THE RESERVE MANAGEMENT SYSTEM";
					exit(0);

				default:cout<<"Enter a valid choice!!!\n\n";
						goto inv;
				}
				}
	return 0;
}

void admin(){
	string pass="adminpass",pwd;
	int i=3;
	password:
	cout<<"Enter administrator password:";
	cin>>pwd;
	if(pwd=="adminpass")
	{
		adminMenu();
	}
	else
	{
		i--;
		if(i==0)
		{
			cout<<"\nToo many attempts.....Please login later.\n\n";
			main();
		}
		else
		{
			cout<<"WARNING:Invalid password...Only "<<i<<" attempt(s) left!!"<<"\n\n";
			goto password;
		}
	}

}

void adminMenu()
{
	int choice;
	cout<<"\n\n**********Administrator page**************\n";

	for(;;){
		adminInv:
	cout<<"\n1.Insert new Reserve record\n2.Search reserve details\n3.Display reserve details\n4.Modify details\n5.Insert species\n6.Display species file\n7.Search species\n8.Back to main page\n";
	cout<<"Enter your choice:";
	cin>>choice;
	cout<<"\n\n";

	switch(choice)
	{
	case 1:insert();
		break;

	case 2:search();
		break;

	case 3:display();
		break;

	case 4:modify();
		break;

	case 5:insertSpecies();
		break;

	case 6:dispSpecies();
		break;

	case 7:searchSpecies();
		break;

	case 8:main();
	break;

	default:cout<<"Invalid choice.....Try again!!\n\n";
			goto adminInv;
	}
	}
}

void userMenu()
{
	int uChoice;
	cout<<"\n\n***********WELCOME TO THE USER VIEW****************\n\n";

	for(;;){
		userInv:
	cout<<"1.View the reserves list\n2.View the species in each reserve\n3.Search reserve\n4.Back to main page\n\n";
	cout<<"Enter your choice:";
	cin>>uChoice;

	switch(uChoice)
	{
	case 1:display();
		break;

	case 2:dispSpecies();
		break;

	case 3:search();
		break;

	case 4:cout<<"\n";main();
		break;

	default:cout<<"Invalid choice.....Enter again\n\n";
			goto userInv;
	}

	}
}

void insert()
{

	fstream res;
	reserve r;
	res.open("reserve.txt",ios::out|ios::app);
	if(!res)
	{

	cout<<"cannot open the file in output mode";
	exit(0);

	}
	cout<<"WARNING:Please use appropriate format while entering data and avoid whitespaces";
	cout<<"\nEnter the Reserve name = ";
	cin>>r.name;
	cout<<"\nEnter the State = ";
	cin>>r.state;
	cout<<"\nEnter the Nearest city= ";
	cin>>r.nearestCity;
	cout<<"\nEnter the Area of the reserve in km^2= ";
	cin>>r.areaInKm;
	cout<<"\nEnter the number of species in the reserve = ";
	cin>>r.num;
	cout<<"\nEnter the year of establishment = ";
	cin>>r.estYear;
	strcpy(r.buffer,r.name);
	strcat(r.buffer,"|");
	strcat(r.buffer,r.state);
	strcat(r.buffer,"|");
	strcat(r.buffer,r.nearestCity);
	strcat(r.buffer,"|");
	strcat(r.buffer,r.areaInKm);
	strcat(r.buffer,"|");
	strcat(r.buffer,r.num);
	strcat(r.buffer,"|");
	strcat(r.buffer,r.estYear);
	strcat(r.buffer,"\n");
	res<<r.buffer;
	res.close();
	cout<<"\n";
}

void search()
{

	fstream in;
	char name[50];
	in.open("reserve.txt",ios::in);
	if(!in)
	{

	cout<<"\nUnable to open the file in input mode";
	exit(0);

	}
	cout<<"\nCAUTION: The system is 'CASE SENSITIVE'.Enter inputs accordingly.\n";
	cout<<"\nEnter the Reserve's name you want to search = ";
	cin>>name;
	reserve r;
	while(!in.eof())
	{
	in.getline(r.name,50,'|');
	in.getline(r.state,30,'|');
	in.getline(r.nearestCity,30,'|');
	in.getline(r.areaInKm,20,'|');
	in.getline(r.num,15,'|');
	in.getline(r.estYear,20,'\n');
	if(strcmp(r.name,name)==0)
	{
	cout<<"\nRecord found";
	cout<<"\n Name\t\t State \t\t NearestCity\t Area in KM^2\t Species count\t Est. Year\n";
	printf("------------------------------------------------------------------------------------------\n");

	cout<<r.name<<"\t"<<r.state<<"\t  "<<r.nearestCity<<"\t\t"<<r.areaInKm<<"\t\t"<<r.num<<"\t    "<<r.estYear<<"\n\n";

	return;
	}
	}
	cout<<"\nRecord not found\n\n";
	return;


}

void modify()
{

	fstream in;
	char name[50];
	int I,j;
	reserve r1[100];
	in.open("reserve.txt",ios::in);
	if(!in)
	{

	cout<<"\nUnable to open the file in input mode";
	exit(0);

	}

	cout<<"\nCAUTION: The system is 'CASE SENSITIVE'.Enter inputs accordingly.\n";
	cout<<"\nEnter the Name:";
	cin>>name;
	I=0;
	while(!in.eof())
	{

	in.getline(r1[I].name,50,'|');
	in.getline(r1[I].state,30,'|');
	in.getline(r1[I].nearestCity,30,'|');
	in.getline(r1[I].areaInKm,20,'|');
	in.getline(r1[I].num,15,'|');
	in.getline(r1[I].estYear,20,'\n');
	I++;

	}
	I--;
	for(j=0;j<I;j++)
	{
	if(strcmp(name,r1[j].name)==0)

	{

	cout<<"\nThe old values of the record with name '"<<name<<"' are: ";
	cout<<"\nName = "<<r1[j].name;
	cout<<"\nState = "<<r1[j].state;
	cout<<"\nNearest city = "<<r1[j].nearestCity;
	cout<<"\nArea in KM^2= "<<r1[j].areaInKm;
	cout<<"\nSpecies count = "<<r1[j].num;
	cout<<"\nEstablished year = "<<r1[j].estYear;
	cout<<"\n\nEnter the new values:";
	cout<<"\nWARNING:Please use appropriate format while entering data and avoid whitespaces";
	cout<<"\nName = ";
	cin>>r1[j].name;
	cout<<"\nState = ";
	cin>>r1[j].state;
	cout<<"\nNearest city = ";
	cin>>r1[j].nearestCity;

	cout<<"\nArea in KM^2 = ";
	cin>>r1[j].areaInKm;
	cout<<"\nSpecies count = ";
	cin>>r1[j].num;
	cout<<"\nEstablished year = ";
	cin>>r1[j].estYear;
	break;

	}
	}
	if(j==I)
	{
	cout<<"\nThe record with name '"<<name<<"' is not present\n";
	return;
	}
	in.close();
	fstream out1;
	out1.open("reserve.txt",ios::out);
	if(!out1)
	{

	cout<<"\nUnable to open the file in output mode";
	return;

	}
	for(j=0;j<I;j++)
	{
	out1<<r1[j].name<<'|'<<r1[j].state<<'|'<<r1[j].nearestCity<<'|'<<r1[j].areaInKm<<'|'<<r1[j].num<<'|'<<r1[j].estYear<<'\n';
	}
	out1.close();
	cout<<"\n";

}

void display()
{

	reserve r;

	fstream in;
	in.open("reserve.txt",ios::in);
	if(!in)
	{

	cout<<"\nCannot open the file in output mode";
	exit(0);

	}
	//I=0;
	printf("Name\t\tState\t\tNearestCity\t\tArea in KM^2\t\tSpecies count\t\tEst Year\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	while(!in.eof())
	{

	in.getline(r.name,50,'|');

	in.getline(r.state,30,'|');
	in.getline(r.nearestCity,30,'|');
	in.getline(r.areaInKm,20,'|');
	in.getline(r.num,15,'|');
	in.getline(r.estYear,20,'\n');

	cout<<r.name<<"\t"<<r.state<<"\t"<<r.nearestCity<<"\t\t\t"<<r.areaInKm<<"\t\t\t"<<r.num<<"\t\t\t"<<r.estYear<<endl;
	}
	in.close();

}

int getNumRecords()
{
fstream f;
int  cnt=0;
f.open("species.txt",ios::in);

if(!f)
 {
cout<<"\nCannot open the file in output mode";
return 0;
 }

while(!f.eof())
 {
f.getline(sp[cnt].rrn,5,'|');
f.getline(sp[cnt].name,50,'|');
f.getline(sp[cnt].list,100,'\n');

cnt++;
//cout<<cnt<<"\n";
 }

        cnt--;
f.close();
//returning number of records

return cnt;
}

void insertSpecies()
{

	fstream app;
	species s;
	char rcnt[5];
	int cnt;

	app.open("species.txt",ios::out|ios::app);
	if(!app)
	 {
	cout<<"cannot open the file in output mode";
	exit(0);
	            }
	cout<<"WARNING:Please use appropriate format while entering data and avoid whitespaces";
	cout<<"\nEnter the Reserve name= ";
	cin>>s.name;

	cout<<"\nEnter the species list in a comma-separated manner(species1,species2,species3,.....)= ";
	cin>>s.list;

	cnt = getNumRecords();
	//cout<<cnt<<"\n";
cnt++;

	sprintf(rcnt,"%d",cnt);
	strcpy(s.buffer,rcnt);
	strcat(s.buffer,"|");

	strcat(s.buffer,s.name);
	strcat(s.buffer,"|");

	strcat(s.buffer,s.list);
	strcat(s.buffer,"\n");

	app<<s.buffer;
	app.close();
	cout<<"\n";
}

void searchSpecies()
{

	char rrn[5];
	int  cnt=0;
	cout<<"\nEnter the RRN to be searched ";
	cin>>rrn;

	cnt=getNumRecords();

	printf("Name\t\t\tList of species\n");
	printf("-------------------------------\n");
	for(int j=0; j < cnt; j++)
	 {
	if(strcmp(rrn,sp[j].rrn)==0)
	   {
	printf("\n%s\t\t%s\n",sp[j].name,sp[j].list);
	printf("\nRecord found");

	return;
	   }

}
	cout<<"\nRecord not found\n";

	return;
}


void dispSpecies()
{

	species s;
	fstream in;
	in.open("species.txt",ios::in);
	if(!in)
	{

	cout<<"\nCannot open the file in output mode";
	exit(0);

	}
	//int I=0;
	printf("RRN\t\tName\t\t\tList of species\n");
	printf("----------------------------------------------------------\n");
	while(!in.eof())
	{

	in.getline(s.rrn,5,'|');

	in.getline(s.name,50,'|');

	in.getline(s.list,100,'\n');

	cout<<s.rrn<<"\t\t"<<s.name<<"\t\t"<<s.list<<endl;
	}
	in.close();

}



