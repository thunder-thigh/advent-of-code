#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//def SIZE 99

void rotate(int &starting, string rotation, int& counter){
		int value = stoi(rotation.substr(1, rotation.length()-1), NULL, 10);
		//std::cout <<value<<"\n";
		char direction=rotation[0];
		if (direction=='R'){
				starting+=value;
				if (starting%100==0) counter++;
		}
		else {
				starting-=value;
				if (starting%100==0) counter++;
		}
}
int main(){
		int start_pos=50;
		int counter=0;
		string current_rotation;
		ifstream inputs("inputs/day1_input.txt");
		if(!inputs){
				std::cout<<"Error opening file";
				exit(0);
		}
		while(!inputs.eof()){
				getline(inputs, current_rotation, '\n');
				rotate(start_pos, current_rotation, counter);
		}
		std::cout<<"Total zeroes matched: "<<counter<<"\n";
		inputs.close();
}
