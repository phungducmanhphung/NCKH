#include "arduinoFFT.h"
const uint16_t samples = 256; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 0.6;
const double samplingFrequency = 40;
const uint8_t amplitude = 2;
const double filterFrequency = 0.8;

double vReal[samples];
double vImag[samples];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, samples, samplingFrequency);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Ready");

}

void loop() {

  createFakeData();
  double x = caculatePeak(vReal,vImag,samples,samplingFrequency);
  Serial.println(x,6);
  // delay(500);
}

void createFakeData()
{
  double ratio = twoPi * signalFrequency / samplingFrequency; // Fraction of a complete cycle stored at each sample (in radians)
  for (uint16_t i = 0; i < samples; i++)
  {
    delay(100);
    vReal[i] = int8_t(amplitude * sin(i * ratio));/* Build data with positive and negative values*/
    vImag[i] = 0.0; //Imaginary part must be zeroed in case of looping to avoid wrong calculations and overflows
  }
}

double caculatePeak(double vReal[samples],double vImag[samples],uint16_t samples, double samplingFrequency )
{
  FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);	/* Weigh data */
  FFT.compute(FFTDirection::Forward); /* Compute FFT */
  FFT.complexToMagnitude(); /* Compute magnitudes */
  int filter_cutoff = filterFrequency * samples / samplingFrequency;
  // for (uint16_t i = 0; i < samples; i++)
  // {
  //   Serial.println(vImag[i] * 10);
  // }
  for(int i=filter_cutoff; i<samples/2; i++){
    vReal[i] = 0;
    vImag[i] = 0;
    vReal[samples-i] = 0;
    vImag[samples-i] = 0;
  }
  // delay(3000);

  double x = FFT.majorPeak();
  return x;
}

