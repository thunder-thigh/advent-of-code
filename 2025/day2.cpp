#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void check_for_invalid_IDs(long long int start_ID, long long int end_ID, int& invalid_IDs, long long int& summation_of_invalid_IDs){
		while(start_ID<=end_ID){
				string current_num=to_string(start_ID);
				short int num_length=current_num.length();
				if(num_length%2==0){
						if(current_num.substr(0, num_length/2)==current_num.substr(num_length/2, num_length/2)){
								invalid_IDs++;
								summation_of_invalid_IDs+=start_ID;
						}
				}
				start_ID++;
		}
		cout<<"\n"<<"Invalid IDs: "<<invalid_IDs<<"\n";
		cout<<"Summation: "<<summation_of_invalid_IDs<<"\n\n";
}

void get_start_and_end(stringstream& token_ss, int& invalid_IDs, long long int& summation_of_invalid_IDs){
		string start, end;
		getline(token_ss, start, '-');
		getline(token_ss, end, '-');
		long long int start_ID, end_ID;
		start_ID=stoll(start, NULL, 10);
		end_ID=stoll(end, NULL, 10);
		cout<<start_ID<<" "<<end_ID;
		check_for_invalid_IDs(start_ID, end_ID, invalid_IDs, summation_of_invalid_IDs);
}
int main(){
		ifstream inputs("inputs/day2_input.txt");
		if(!inputs){
				cout<<"Error opening file";
				exit(0);
		}
		string complete_input;
		getline(inputs, complete_input);
		stringstream ss(complete_input);
		string token;
		int invalid_IDs=0;
		long long int summation_of_invalid_IDs=0;
		while (getline(ss, token, ',')){
				cout<<token<<": ";
				stringstream token_ss(token);
				get_start_and_end(token_ss, invalid_IDs, summation_of_invalid_IDs);
				token_ss.str("");
				token_ss.clear();
		}
}
