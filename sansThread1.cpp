#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <thread>
#include <semaphore.h> 
#include <pthread.h> 
#include <sys/time.h>
using namespace std;
using namespace cv;
Mat mtrc;
 
 #define V 4
 #define ITER 300
 #define HEIGHT 600
 #define WIDTH 500
RNG rng( 0xFFFFFFFF );
double R=100;
double G=80;
double B=150;
 int i;



std::complex<long double> c(  -0.772691322542185 ,0.124281466072787);

void clr();
int main( int argc, char** argv )
{
struct timeval temps_avant, temps_apres;
  gettimeofday (&temps_avant, NULL);
 
  mtrc=cv::Mat(WIDTH, HEIGHT, CV_8UC3);
   		 clr();
  gettimeofday (&temps_apres, NULL);
  printf("temps en us: %ld us\n", ((temps_apres.tv_sec - temps_avant.tv_sec) * 1000000 + temps_apres.tv_usec) -          temps_avant.tv_usec);
     while( true )
     {
       
     imshow("julia frame", mtrc ); 
 if(cvWaitKey(5) > 0){
  
     }

}
  return 0;

}

 void clr(){
  
for(int x=0;x<WIDTH;x++){
      for(int y=0;y<HEIGHT;y++){
        long double newX=((long double)((long double)x-((long double)WIDTH/2))/
((long double)WIDTH/2));
        long double newY=((long double)((long double)y-((long double)HEIGHT/2))/
((long double)HEIGHT/2));
        std::complex<long double> z(newY,newX);
        int i=0;
        long double norm = std::norm(z);
                while(i<ITER && norm<V){
          z=(z*z)+c;
          norm = std::norm(z);
          i++;
        }
        if(i==ITER && norm<V){
          mtrc.at<Vec3b>(x,y)[0]=rng.uniform(255,0)+R; 
          mtrc.at<Vec3b>(x,y)[1]=rng.uniform(0,250)+G; 
          mtrc.at<Vec3b>(x,y)[2]=rng.uniform(150,400)+B;
        }
        else{
          int couleur=(int)((float)i/(float)ITER*360);
          mtrc.at<Vec3b>(x,y)[0]=10;
          mtrc.at<Vec3b>(x,y)[1]=couleur;
          mtrc.at<Vec3b>(x,y)[2]=255;
      }
    } 


}}
