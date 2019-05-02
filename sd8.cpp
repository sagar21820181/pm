#include<iostream>
#include<string.h>
using namespace std;

struct table
{
	int roll_no;
	string name;
};

int overload(table t[],int size)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(t[i].roll_no > 0)
		{
			count++;
		}
	}
	if(count == size)
	{
		return 0;
	}
	else
		return 1;
}

int hash1(table t[],int size,int r_n)
{
	int index;
	index = r_n % size;
	if(t[index].roll_no > 0)
	{
		int j=1;
		while(t[index].roll_no >=0)
		{
			index = (r_n + j) % size;
			j++;
		}		
	}
	return index;
}

void display(table t[],int size)
{
	cout << "\n\tIndex" << "\t\t" << "Roll No." << "\t" << "Name of Student" << endl;
	for(int i=0;i<size;i++)
	{
		cout << "\n\t   " << i << "\t\t " << t[i].roll_no << " \t \t" << t[i].name << endl; 
	}
}

int search(table t[],int size,int search)
{
	int s_index;
	int j;
	s_index = search % size;
	if(t[s_index].roll_no == -1)
	{
		cout << "\nElement not found...!!!" << endl;
		return -1;
	}
	else if(t[s_index].roll_no  != search)
	{
		
		for(j=1;j<size;j++)
		{
			s_index = (search + j) % size;
			if(t[s_index].roll_no == search)
			{
				break;
			}
		}
		j=-1;
	}
	if(j == -1 && t[s_index].roll_no != search)
	{
		cout << "\nElement not found.." << endl;
		return -1;
	}
	else
	{
		return s_index;	 
	}	
}

void delete_value(table t[],int size)
{
	int del;
	cout << "\nEnter the roll no. to be deleted : ";
	cin >> del;
	int d_index;
	d_index = search(t,size,del);
	if(d_index == -1)
	{
		cout << "\nElement not present in the hash table hence cannot be deleted"<<endl;
	}
	else
	{
		t[d_index].roll_no = -2;
		t[d_index].name = " ";
	}
}

int main()
{
	int size;
	int r_n;
	char ch;
	int ind;
	int choice,s,s_index;
	cout << "\nEnter the size of hash table : ";
	cin >> size;
	table t[size];
	int count;
	for(int i=0;i<size;i++)
	{
		t[i].roll_no = -1;
	}
	do
	{
		cout << "\nMENU :- \n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT" <<endl;
		cout << "\nEnter ur choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1 : if(overload(t,size))
					 {
						 cout << "\n ---- INSERT AN ELEMENT ----";
						 cout << "\nEnter the roll no. : ";
						 cin >> r_n;
						 ind = hash1(t,size,r_n);
						 t[ind].roll_no = r_n;
						 cout << "\nEnter the name for roll no. " << r_n << " : ";
						 cin >> t[ind].name;
					 }
					 else
					 	cout << "\nOverload...!!" << endl;
					 break;
			case 2 : display(t,size);
					 break;
			case 3 : cout << "\nEnter the roll no. to be searched : ";
					 cin >> s;
					 s_index = search(t,size,s);
					 if(s_index != -1)
					 {
						 cout << "\nThe element is present at index " << s_index << endl;
						 cout << "\n------------------------------------\n";
						 cout << "\nStudent  Details : " <<endl;
						 cout << "\nName : " << t[s_index].name << "\tRoll no : " << t[s_index].roll_no << endl;
						 cout << "\n------------------------------------\n";
					 }
					 break;
			case 4 : delete_value(t,size);
					 break;
			case 5 : cout << "\nExiting the program....!!!!" << endl; break;
			default : cout << "\nPlease choose appropriate option...!!!" <<endl; break;
		}
	}while(choice != 5);
	return 0;
}

