#include <complex>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
ifstream inFile;
// Reading file
int sum = 0;
float x = 0;
extern "C"
{
    vector<complex<double>> DFT(vector<complex<double>> data);
}
//DFT function
vector<complex<double>> DFT(vector<complex<double>> data)
{
    int N = data.size();
    int K = N;
    complex<double> intsum;
    vector<complex<double>> dft;
    dft.reserve(K);

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
        dft.push_back(intsum);
    }
    
    return dft;

}


int main(){
    
    inFile.open("wave.txt");
    string line;

 
    if (!inFile) {
        cout<< "Unable to open file datafile.txt";
    }
    else{
        // cout << typeid(inFile).name() << '\n';
        cout<<"file readed successfully"<<'\n'; // call system to stop
    }

    vector<complex<double>> signal;
    vector<complex<double>> Fourier;

    for (int i = 0; i < 11; i++)
    {
        
        getline(inFile, line);
        double linedata = stod (line);
        signal.push_back(linedata);
        
        cout << "Data: " << line <<'\n' ;
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    Fourier=DFT(signal);

    for (int z = 0; z < 11; z++)
    {
        cout << "Fourier: " << Fourier[z] <<'\n' ;
    }
    

    inFile.clear();
    inFile.seekg(0, std::ios::beg);


    while (inFile >> x) 
    {
        sum++;
    }
 
    cout<<sum<<'\n';

    // for (int i = 0; i < 5; i++)
    // {
    //  cout << i << "\n";
    // }  
    
    }
