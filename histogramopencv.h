#ifndef HISTOGRAMOPENCV_H
#define HISTOGRAMOPENCV_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
/*
  Autor : pawelpq
  Data: lipiec 2011

  Wartoœci pocz¹tkowe:
    grayBins=255;
    heightHistImage=500;
    weightHistImage=255*2;


  */
class HistogramOpenCV
{
public:
    HistogramOpenCV();
        HistogramOpenCV(Mat gray);
    void setGrayFrame(Mat gray);
    //wywo³anie funkcji cv::calcHisto
    void liczHistogram();
    //wyswietlenie wykresu histogramu
    void wyswietlHistogram();
   //ustawienie i odswierzanie wartoœci sta³ych
  void initValue();

    void setBinCount(int bin);
    void setHeightHistImage(int h);
    void  setWeightHistImage(int w);

    int getBinCount();
    int getMaxValue();
    int getMinValue();
    int getMaxIndex();
    int getMinIndex();


private:
  //obraz z którego wyliczamy histogram- musi byæ w ocieniach szaroœci
  Mat grayFrame;
  //histogram
  MatND hist;
  //liczba binów- przedzia³ów histogramu
  int grayBins;
  //to samo co liczba binów - potrzebna inna postaæ do funkcji cv:::calcHisto
  int histSize[1];
  //zakres odcieni szaroœci -sta³y, od 0 do 255
  float grayRange[2];
  //to samo co grayRange- inna reprezentacja, potrzebne do cv::calcHisto
  const float* ranges[1];
  //kana³ z którego liczony jest histogram.
  //w przypadku odcieni szaroœi jeden kana³ - numer kana³u 0
  int channel[1];

  //max/min wartoœæ na histogrami
  double maxValue;
  double minValue;
  //numere binu max/min
  int indexMin;
  int indexMax;

  //skala - d³ugoœæ paska dla jednostkowej wartoœci binu
  double scale;
  //szerokosc binu
  int weightBin;
  /*
   Skalowanie wykresu chistogramu polega na okreœlenie d³ugoœci paska binu w funkcji
   wysokoœci okna wykresu.
   skala jest opisana zaleznoœcia
   scale=wysokoscOkna/maxValue
   Otrzymana wartoœc skaluje wysokoœc binów w przedzia³ 0-wysokosc okna
   ³atwo zauwa¿yæ ¿e, dla bin posiadaj¹cy wartoœc maxValu zajmie ca³e okno
    */
  //parametry okna
  int heightHistImage;
  int weightHistImage;
  //obraz z wykresem histogramu
  Mat histImage;
};

#endif // HISTOGRAMOPENCV_H
