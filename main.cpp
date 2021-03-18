#include <iostream> // input-output library
#include <cmath>  // library for sin function
#include "wav.hpp" // make sure to include this helper library
// " " instead of <> means that library is in the same folder as your program

using namespace std;

int main(){
    WavSound sound1; // helper
    int sample_rate = 44100; // samples per second
    // your code goes here
    double dt = 1.0/sample_rate;
    int duration = 5.0;
    int n_samples = duration / dt;
    int* waveform = new int[n_samples]; // creates the array
    double freq = 500.0;
    // and here
    for ( int i = 0; i < n_samples ; i++){
        //and here
        double time = i * dt;
        waveform[i]=6000.0*sin(2*M_PI*freq* time);
    }
    // generates sound file from waveform array, writes n_samples numbers
    // into sound wav file
    // should know sample_rate for sound timing
    sound1.MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav
    delete[](waveform);
    return 0;
}