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
    // vector< complex<double> > Data; // Create vector of complex numbers
 // Place 1 + j2 in vector
    // inFile.clear();
    // inFile.seekg(0, std::ios::beg);

    int size = inFile.tellg();
    cout << "size: " << size <<'\n' ;
    complex<double> Data[1000];
    string line;
    int z;
    complex<double> output[size];

    //  while (inFile >> x) 
    //  {

    //     getline(inFile, line);
    //     Data[x] = line;
    //     // Data.push_back(complex<double>(x));
    //  }

    // inFile.clear();
    // inFile.seekg(0, std::ios::beg);


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


    //    vector< complex<double>> TransformedData;
    //     TransformedData=DFT(Data);

    // for (int i =0 ;i<TransformedData.size();i++)
//     for (int i =0 ;i<10;i++)
//     {
//         cout<<TransformedData[i]<<"\n";
//         // cout<<TransformedData[i].real()+TransformedData[i].imag()*1i;
//     }

//return 0;



// int main(){
    
//     inFile.open("wave.txt");
//     string line;

 
//     if (!inFile) {
//         cout<< "Unable to open file datafile.txt";
//     }
//     else{
//         // cout << typeid(inFile).name() << '\n';
//         cout<<"file readed successfully"<<'\n'; // call system to stop
//     }

//     vector<complex<double>> signal;
//     vector<complex<double>> Fourier;

//     for (int i = 0; i < 11; i++)
//     {
        
//         getline(inFile, line);
//         double linedata = stod (line);
//         signal.push_back(linedata);
        
//         cout << "Data: " << line <<'\n' ;
//     }

//     inFile.clear();
//     inFile.seekg(0, std::ios::beg);

//     Fourier=DFT(signal);

//     for (int z = 0; z < 11; z++)
//     {
//         cout << "Fourier: " << Fourier[z] <<'\n' ;
//     }
    

//     inFile.clear();
//     inFile.seekg(0, std::ios::beg);


//     while (inFile >> x) 
//     {
//         sum++;
//     }
 
//     cout<<sum<<'\n';

//     // for (int i = 0; i < 5; i++)
//     // {
//     //  cout << i << "\n";
//     // }  
    
//     }


// int main(){

//     inFile.open("test");
//     vector< complex<double> > Data; // Create vector of complex numbers
//  // Place 1 + j2 in vector
//      while (inFile >> x)
//      {
//         Data.push_back(complex<double>(x));
//      }
       
        

//     for (int i =0 ;i<TransformedData.size();i++){


//     cout<<TransformedData[i].real()+TransformedData[i].imag()*1i;
//     }
// return 0;


//     }

    // if (!inFile) {
    //     cout<< "Unable to open file datafile.txt";
    // }
    // else{
    //     // cout << typeid(inFile).name() << '\n';
    //     cout<<"file readed successfully"<<'\n'; // call system to stop
    // }



    //     vector<complex<double>> signal;
    // for (int i = 0; i < 11; i++)
    // {

    //     getline(inFile, line);
    //     double linedata = stod (line);
    //     signal.push_back(linedata);

    //     cout << "Data: " << line <<'\n' ;
    // }



