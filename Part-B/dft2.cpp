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

extern "C"
{
    complex<double> * DFT(complex<double> data[]);
    // vector<complex<double>> DFT(vector<complex<double>> data);
    // vector<complex<double>> FFT(vector<complex<double>> &sampels);
    // int addition(int a,int b);
}

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
            // cout<<intsum<<"\n";
            // cout<<"\n";
            
        }
        //cout<<intsum<<"\n";
        data_arr[k]=intsum;
    }
    // cout<<"sum"<<intsum<<"\n";
    return data_arr;

}



int main(){
    
    inFile.open("test");
    while (inFile >> x) 
    {
        sum++;
    }
 
    cout<<sum<<'\n';

    inFile.clear();
    inFile.seekg(0, std::ios::beg);


    //int size = inFile.tellg();
    //cout << "size: " << size <<'\n' ;
    complex<double> Data[sum];
    string line;
    int z;
    //complex<double> output[size];


    for (int i = 0; i < sum; i++)
    {
        
        getline(inFile, line);
        complex<double> linedata = stod (line);
        Data[i]= linedata;
        cout << "Data" << i << ": "<< Data[i] <<'\n' ;
        cout << '\n';
    }

    int arrsize= sizeof(Data)/sizeof(Data[0]);;
    cout << "Data size: " << arrsize<<'\n' ;
    cout << '\n';
    cout << '\n';
    inFile.clear();
    inFile.seekg(0, std::ios::beg);


    complex<double> *output;
    output=DFT(Data);
    // cout << "dft: " << output<<'\n' ;
    for ( int i = 0; i < 10; i++ ) 
    {
      cout << "*(output + " << i << ") : ";
      cout << *(output + i) << endl;
    }

    // int opsize= sizeof(output)/sizeof(output[0]);
    // for (int s; s<opsize; s++)
    // {
    //     cout << "dft: " << output[s] <<'\n' ;
    // }
    
    


//     Data[21]= {complex<double> (0.0,0), complex<double> (0.0006713867,0)
// ,complex<double>(0.001373291,0)
// ,complex<double>(0.0020751953,0)
// ,complex<double>(0.0027770996,0)
// ,complex<double>(0.0034484863,0)
// ,complex<double>(0.0041503906,0)
// ,complex<double>(0.004852295,0)
// ,complex<double>(0.005554199,0)
// ,complex<double>(0.0062561035,0)
// ,complex<double>(0.0069274902,0)
// ,complex<double>(0.0076293945,0)
// ,complex<double>(0.008331299,0)
// ,complex<double>(0.009033203,0)
// ,complex<double>(0.00970459,0)
// ,complex<double>(0.010406494,0)
// ,complex<double>(0.011108398,0)
// ,complex<double>(0.011779785,0)
// ,complex<double>(0.012481689,0)
// ,complex<double>(0.013183594,0)
// ,complex<double>(0.0138549805,0)};


}


