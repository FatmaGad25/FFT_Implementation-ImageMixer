
#include <iostream>
// #include <fstream>
#include <complex>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include<pybind11/complex.h>
using namespace std;
namespace py = pybind11;
//You can read information from files into your C++ program. This is possible using stream extraction operator (>>). You use the operator in the same way you use it to read user input from the keyboard. However, instead of using the cin object, you use the ifstream/ fstream object.
// ifstream inFile;
// // Reading file

// //float x = 0;
// double x = 0;


///////////////////DFT function
vector<complex<double>> DFT(vector<complex<double>> data)
{
    int NumberOfSamples = data.size();
    int CopyOfNumberOfSampels = NumberOfSamples;
    complex<double> Frequency;
    vector<complex<double>> Frequencies;
    Frequencies.reserve(CopyOfNumberOfSampels);

    for (int k = 0; k < CopyOfNumberOfSampels; k++)
    {
       Frequency=(0);

        for (int n = 0; n < NumberOfSamples; n++)
        {
        double real = cos(((2 * M_PI) / NumberOfSamples) * k * n);
            double img = sin(((2 * M_PI) / NumberOfSamples) * k * n);
            complex<double> cotec(real, -img);
            Frequency += data[n] * cotec;
        }
        Frequencies.push_back(Frequency);
    }

    return Frequencies;
}

/////////////////////////FFT////////////////

vector<complex<double>> FFT(vector<complex<double>> &sampels)
{
    double pi = 3.14159265358979323846;
    // find the number of samples we have
    int NumberOfSampels = sampels.size();
    // Executr the end of the recursive even/odd splits once we only have one sample
    if (NumberOfSampels == 1)
    {
        return sampels;
    }

    /* Split the sampels into even and odd subsums */
    // Find half the total number of samples
    int M = NumberOfSampels / 2;

    // Declare an even and odd complex vector
    vector<complex<double>> SampelsEven(M, 0);
    vector<complex<double>> SampelsOdd(M, 0);

    // Input the even and odd sampels into recursive vectors
    for (int i = 0; i != M; i++)
    {
        SampelsEven[i] = sampels[2 * i];
        SampelsOdd[i] = sampels[2 * i + 1];
    }
    // Perform the recursive FFT operation on the odd and even sides
    vector<complex<double>> FrequenciesEven(M, 0);
    FrequenciesEven = FFT(SampelsEven);
    vector<complex<double>> FrequenciesOdd(M, 0);
    FrequenciesOdd = FFT(SampelsOdd);
    /*------ END RECURSION ______ */

    // Declare vector of frequency bins
    vector<complex<double>> Frequencies(NumberOfSampels, 0);
    // Combine the values found
    for (int k = 0; k != NumberOfSampels / 2; k++)
    {
        // For each split set, we need to multiply a k-dependent comlpex
        //number by the odd sunsum
        complex<double> ComplexExponential = polar(1.0, -2 * pi * k / NumberOfSampels) * FrequenciesOdd[k];
        Frequencies[k] = FrequenciesEven[k] + ComplexExponential;
        // Everytime you add pi, exponential changes sign
        Frequencies[k + NumberOfSampels / 2] = FrequenciesEven[k] - ComplexExponential;
    }
    return Frequencies;
}

PYBIND11_MODULE(Fourier, pass) {
  
    pass.def("FFT", &FFT, "A function which adds two numbers");
    pass.def("DFT", &DFT, "A function which adds two numbers");
}




























// int main()
// {
//     inFile.open("test");

//     vector<complex<double>> Data; // Create vector of complex numbers
//                                   // Place 1 + j2 in vector

//     vector<complex<double>> TransformedData;

//     vector<complex<double>> dft;

//     while (inFile >> x)
//     {
//         Data.push_back(complex<double>(x));
//     }

//     dft = DFT(Data);
//     TransformedData = FFT(Data);

//     //for (int z =0 ;z<TransformedData.size();z++)
//     for (int z = 0; z < TransformedData.size(); z++)
//     {
//         cout << "DFT: " << dft[z] << '\n';
//         cout << "FFT: " << TransformedData[z] << '\n';
//         cout << '\n';
//         // cout<<TransformedData[i].real()+TransformedData[i].imag()*1i;
//     }

//     inFile.clear();
//     inFile.seekg(0, std::ios::beg);

//     while (inFile >> x)
//     {
//         sum++;
//     }

//     cout << sum << '\n';
// }