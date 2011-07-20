#include "histogramopencv.h"

HistogramOpenCV::HistogramOpenCV()
{
    initValue();
}
HistogramOpenCV::HistogramOpenCV(Mat gray){
    grayFrame=gray;
    initValue();
}

void HistogramOpenCV::setGrayFrame(Mat gray){
    grayFrame=gray;
}

void HistogramOpenCV::liczHistogram(){
     calcHist(&grayFrame,1,channel,Mat(),hist,
             1,histSize,ranges);
     minMaxLoc(hist,&minValue,&maxValue,&indexMin,&indexMax);
     scale=(double)heightHistImage/maxValue;
 }
void HistogramOpenCV::wyswietlHistogram(){
     histImage=Mat::zeros(heightHistImage,weightHistImage,CV_8UC3);
     for(int i=0;i<grayBins;i++){
         float binVal=hist.at<float>(i);
         int w=binVal*scale;
         /*
           Uk³ad wspó³rzednych obrazu ma poczatek w lewym górnym rogu
           Sk³adowa Y pierwszego punktu jest wylicza poprzez odjecia wysokoœci binu
           od wysokoœi okna by prostok¹ty by³y rysowane w góre
           */
         rectangle(histImage,
                   Point((i+1)*(int)(weightBin),heightHistImage-w),
                   Point(i*(int)(weightBin),heightHistImage),
                   Scalar::all(150));

     }
     imshow("hist",histImage);
}
void initValue();

  void HistogramOpenCV::setBinCount(int bin){
      grayBins=bin;
      initValue();
  }

  void HistogramOpenCV::setHeightHistImage(int h){
      heightHistImage=h;
      initValue();
  }

  void  HistogramOpenCV::setWeightHistImage(int w){
      weightHistImage=w;
      initValue();
  }

  int HistogramOpenCV::getBinCount(){return grayBins; }
  int HistogramOpenCV::getMaxValue(){return maxValue; }
  int HistogramOpenCV::getMinValue(){return minValue; }
  int HistogramOpenCV::getMaxIndex(){return indexMax; }
  int HistogramOpenCV::getMinIndex(){return indexMin; }

void HistogramOpenCV::initValue(){
    grayBins=255;
    histSize[0]=grayBins;
    grayRange[0] =0;
    grayRange[1]=255;
    ranges[0]=grayRange;
    channel[0]=0;
    heightHistImage=500;
    weightHistImage=255*2;
    weightBin=weightHistImage/grayBins;

}
