#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

string toAlphabetString(int n);
int fromAlphabetString(string s);

int main(){
	string s;
	int ch, n;
	while(1){
		cout<<endl<<"Enter choice (1 - toName, 2 - fromName, 0 - Exit): ";
		cin>>ch;

		if(ch == 1){
			cout<<endl<<"Enter column number: ";
			cin>>n;
			cout<<"Column name: "<<toAlphabetString(n)<<endl;
		} else if (ch == 2){
			cout<<endl<<"Enter column name: ";
			cin>>s;
			cout<<"Column no.: "<<fromAlphabetString(s)<<endl;
		}
		else
			break;
	}
	return 0;
}

string toAlphabetString(int n){
	string s;
	while(n>0){
		s+=(n%26) + 64;
		n/=26;
	}
	s+='\0';
	reverse(s.begin(), s.end()); 
	return s;
}

int fromAlphabetString(string s){
	reverse(s.begin(), s.end()); 
	int n = 0;
	for(int i=0 ; s[i]!='\0' ; i++)
		n += pow(26, i) * (s[i] - 64);
	return n;
}