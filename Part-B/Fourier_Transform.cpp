#include <complex>
#include <vector>
#include <iostream>
#include <fstream>
#include<complex>
#include<vector>
using namespace std;
//You can read information from files into your C++ program. This is possible using stream extraction operator (>>). You use the operator in the same way you use it to read user input from the keyboard. However, instead of using the cin object, you use the ifstream/ fstream object.
ifstream inFile;
// Reading file
int sum = 0;
//float x = 0;
double x=0;
double pi = 3.14159265358979323846;
extern "C"
{
    vector<complex<double>> DFT(vector<complex<double>> data);
    vector<complex<double>> FFT(vector<complex<double>> &sampels);
    int addition(int a,int b);
}


int addition(int a,int b);

int addition(int a,int b)
{
	return (a+b);
}
///////////////////DFT function
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

/////////////////////////FFT////////////////

vector<complex<double>> FFT(vector<complex<double>> &sampels)
{

    // find the number of samples we have
        int N = sampels.size();
    // Executr the end of the recursive even/odd splits once we only have one sample
        if(N==1){return sampels;}

/* Split the sampels into even and odd subsums */
    // Find half the total number of samples
        int M = N/2;

    // Declare an even and odd complex vector
    vector<complex<double>> Xeven(M,0);
    vector<complex<double>> Xodd(M,0);

    // Input the even and odd sampels into recursive vectors
    for(int i=0;i!=M;i++)
    {
        Xeven[i]=sampels[2*i];
        Xodd[i]=sampels[2*i+1];
    }
    // Perform the recursive FFT operation on the odd and even sides
    vector<complex<double>> Feven(M,0);
    Feven = FFT(Xeven);
    vector<complex<double>> Fodd(M,0);
    Fodd = FFT(Xodd);
/*------ END RECURSION ______ */

    // Declare vector of frequency bins
    vector<complex<double>> freqbins(N,0);
    // Combine the values found
    for (int k=0;k!=N/2;k++)
    {
    // For each split set, we need to multiply a k-dependent comlpex
    //number by the odd sunsum
    complex<double> cmplxexponential =polar(1.0,-2*pi*k/N)*Fodd[k];
    freqbins[k]=Feven[k] + cmplxexponential;
    // Everytime you add pi, exponential changes sign
    freqbins[k+N/2]=Feven[k]-cmplxexponential;
    }
    return freqbins;
    }




int main()
{
    inFile.open("test");
    string line;

    vector<complex<double>> Data; // Create vector of complex numbers
 // Place 1 + j2 in vector

    vector< complex<double>> TransformedData;

    vector<complex<double>> dft;

    while (inFile >> x)
     {
        Data.push_back(complex<double>(x));
     }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    dft= DFT(Data);
    TransformedData= FFT(Data);

    //for (int z =0 ;z<TransformedData.size();z++)
    for (int z = 0; z < TransformedData.size(); z++)
    {
        cout << "DFT: " << dft[z] <<'\n' ;
        cout << "FFT: " << TransformedData[z] <<'\n' ;
        cout <<'\n' ;
        // cout<<TransformedData[i].real()+TransformedData[i].imag()*1i;
    }


    inFile.clear();
    inFile.seekg(0, std::ios::beg);


    while (inFile >> x)
    {
        sum++;
    }

    cout<<sum<<'\n';

    }


