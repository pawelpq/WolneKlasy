#ifndef HISTOGRAMOPENCV_H
#define HISTOGRAMOPENCV_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
/*
  Autor : pawelpq
  Data: lipiec 2011

  Warto�ci pocz�tkowe:
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
    //wywo�anie funkcji cv::calcHisto
    void liczHistogram();
    //wyswietlenie wykresu histogramu
    void wyswietlHistogram();
   //ustawienie i odswierzanie warto�ci sta�ych
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
  //obraz z kt�rego wyliczamy histogram- musi by� w ocieniach szaro�ci
  Mat grayFrame;
  //histogram
  MatND hist;
  //liczba bin�w- przedzia��w histogramu
  int grayBins;
  //to samo co liczba bin�w - potrzebna inna posta� do funkcji cv:::calcHisto
  int histSize[1];
  //zakres odcieni szaro�ci -sta�y, od 0 do 255
  float grayRange[2];
  //to samo co grayRange- inna reprezentacja, potrzebne do cv::calcHisto
  const float* ranges[1];
  //kana� z kt�rego liczony jest histogram.
  //w przypadku odcieni szaro�i jeden kana� - numer kana�u 0
  int channel[1];

  //max/min warto�� na histogrami
  double maxValue;
  double minValue;
  //numere binu max/min
  int indexMin;
  int indexMax;

  //skala - d�ugo�� paska dla jednostkowej warto�ci binu
  double scale;
  //szerokosc binu
  int weightBin;
  /*
   Skalowanie wykresu chistogramu polega na okre�lenie d�ugo�ci paska binu w funkcji
   wysoko�ci okna wykresu.
   skala jest opisana zalezno�cia
   scale=wysokoscOkna/maxValue
   Otrzymana warto�c skaluje wysoko�c bin�w w przedzia� 0-wysokosc okna
   �atwo zauwa�y� �e, dla bin posiadaj�cy warto�c maxValu zajmie ca�e okno
    */
  //parametry okna
  int heightHistImage;
  int weightHistImage;
  //obraz z wykresem histogramu
  Mat histImage;
};

#endif // HISTOGRAMOPENCV_H
