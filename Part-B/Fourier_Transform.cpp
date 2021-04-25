#include<iostream>
#include <fstream>
using namespace std;
ifstream inFile;
// Reading file
int sum = 0;
float x=0;
int main(){
    
    inFile.open("wave.txt");
 
    if (!inFile) {
        cout<< "Unable to open file datafile.txt";
    }
    else{
        cout<<"file readed successfully"<<'\n'; // call system to stop
    }
         while (inFile >> x) {
        sum++;
                }
        cout<<sum<<'\n';
    
    }