#include <complex>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
ifstream inFile;
// Reading file
int sum = 0;
float x = 0;
// extern "C"
// {
//     vector<complex<double>> DFT(vector<complex<double>> data);
// }
//DFT function
complex<double> * DFT(complex<double> data[])
{
    int N = sizeof(data);
    int K = N;
    complex<double> data_arr[K];
    complex<double> intsum;
    // vector<complex<double>> dft;
    // dft.reserve(K);

    for (int k=0; k<K; k++)
    {
        intsum= (0,0);

        for (int n=0; n<N; n++)
        {
            double real= cos(((2*M_PI)/N)*k*n);
            double img= sin(((2*M_PI)/N)*k*n);
            complex<double> cotec (real, -img);
            intsum+= data[n]*cotec;
        }
        data_arr[k]=intsum;
    }
    
    return data_arr;

}



int main(){
    
    inFile.open("test");

    int size = inFile.tellg();
    cout << "size: " << size <<'\n' ;
    complex<double> Data[1000];
    string line;
    int z;
    complex<double> output[size];


    for (int i = 0; i < 20; i++)
    {
        
        getline(inFile, line);
        complex<double> linedata = stod (line);
        Data[i]= linedata;
        
        cout << "Data: " << line <<'\n' ;
    }

    complex<double> * output;
    // output=DFT(Data);




}


