#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat getSecondImage(Mat image);
Mat getThirdImage(Mat image);
Mat getFourthImage(Mat image);
Mat getSeventhImage(Mat image);
int parse(int value);
int main()
{
    Mat firstImage(800,800,CV_8U,Scalar(0));
    Mat secondImage(800,800,CV_8U,Scalar(0));
    Mat thirdImage(800,800,CV_8U,Scalar(0));
    Mat fourthImage(800,800,CV_8U,Scalar(0));
    Mat seventhImage(250,250,CV_8U,Scalar(0));

    imwrite("./first.png",firstImage);
    imwrite("./second.png",getSecondImage(secondImage));
    imwrite("./third.png",getThirdImage(thirdImage));
    imwrite("./fourth.png",getFourthImage(fourthImage));  
    imwrite("./seventh.png",getSeventhImage(seventhImage));      

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}

int parse(int value){
    if(value > 255)return 255;
    if(value < 0) return 0;
    return value;
}
Mat getSecondImage(Mat image){
  
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            if(y > image.rows/2 && x < image.cols/2){
                image.at<uchar>(y,x) = (uchar)(255);
            }
            else if(y < image.rows/2 && x > image.cols/2){
                image.at<uchar>(y,x) = (uchar)(255);
            }
            
        }
        
    }
    return image;
}
Mat getThirdImage(Mat image){
    
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            if(x%5 == 0){
                image.at<uchar>(y,x) = (uchar)(255);
            }
            
            
        }
        
    }
    return image;
}

Mat getFourthImage(Mat image){
    
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            if(y%5 == 0){
                image.at<uchar>(y,x) = (uchar)(255);
            }
            
            
        }
        
    }
    return image;
}

Mat getSeventhImage(Mat image){
     for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            
                image.at<uchar>(y,x) = (uchar)(parse(x - 25));
           
            
            
        }
        
    }
    return image;
}