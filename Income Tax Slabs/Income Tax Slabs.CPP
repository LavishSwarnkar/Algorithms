#include<iostream>
using namespace std;

long long int table[7][10], x, rebate;

void slabsInputAndLogic();
void taxInputAndCalc();
void salInputAndCalc();
int getSlabS(long long int sal);
int getSlabT(long long int sal);
long long int calcTax(long long int sal);
long long int calcSal(long long int tax);
void pTable();

int main(){
 	slabsInputAndLogic();
	//pTable();

	int ch;
	while(1){
		cout<<endl<<"Enter choice (1 - calcTax, 2 - calcSal, 0 - Exit): ";
		cin>>ch;

		if(ch == 1)
			taxInputAndCalc();
		else if (ch == 2)
			salInputAndCalc();
		else
			break;
	}
	
	return 0;
}

void slabsInputAndLogic(){
	long long int i, j, t, z;

	cout<<"Enter no. of slabs: ";
	cin>>x;

	t = table[0][0] = table[1][x-1] = 0;
	for(i=0 ; i<x-1 ; i++)
	{	cout<<"Enter UL of S"<<i+1<<": ";
		cin>>table[1][i];
		table[0][i+1] = table[1][i];

		table[3][i] = table[1][i] - t;
		t = table[1][i];
	}
	table[3][i] = 0;

	table[2][0] = 0;
	table[4][0] = table[3][0];
	for(i=1 ; i<x ; i++)
	{	cout<<"Enter tax p of S"<<i+1<<": ";
		cin>>table[2][i];

		table[4][i] = table[3][i] + table[4][i-1];
	}
	table[4][i-1] = 0;

	cout<<"Enter rebate amount: ";
	cin>>rebate;

	table[5][0] = table[6][0] = table[6][x-1] = 0;
	for(i=1 ; i<x ; i++)
	{	table[5][i] = table[6][i-1];
		table[6][i] = (((table[1][i] - table[4][i-1])*table[2][i])/100) + table[5][i];
	}
	table[6][i-1] = 0;
}

void taxInputAndCalc(){
	long long int z;

	cout<<"Enter salary: ";
	cin>>z;
	cout<<"Tax = "<<calcTax(z)<<endl;
}

void salInputAndCalc(){
	long long int z;

	cout<<"Enter Tax: ";
	cin>>z;
	cout<<"Salary = "<<calcSal(z)<<endl;
}

int getSlabS(long long int sal){
    int i;
	for(i=0 ; i<x ; i++)
		if(sal > table[0][i] && sal <= table[1][i])
			return i;
	return x-1;
}

int getSlabT(long long int sal){
	int i;
	for(i=0 ; i<x ; i++)
		if(sal > table[5][i] && sal <= table[6][i])
			return i;
	return x-1;
}

long long int calcTax(long long int sal){
    int slab;
	long long int tax=0;
	if(sal<=rebate) return 0;
	else sal-=rebate;
	slab=getSlabS(sal);
	if(slab>0)
	{	tax = table[6][slab-1];
		sal -= table[1][slab-1];
	}
	tax += (sal*table[2][slab])/100;
	return tax;
}

long long int calcSal(long long int tax){
    int slab=getSlabT(tax);
	long long int sal=0;
	if(slab>0)
	{	sal = table[1][slab-1];
		tax -= table[6][slab-1];
	}
	sal += (tax*100)/table[2][slab];
	return sal>0 ? sal+rebate : sal;
}

void pTable(){
    int i, j;
	for(i=0 ; i<7 ; i++)
	{	for(j=0 ; j<x ; j++)
			cout<<table[i][j]<<"\t";
		cout<<endl;
	}
}