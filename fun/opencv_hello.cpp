/**
 * 
 * @author: Matija Belec
 * @date: 05.01.2015
 * 
g++ opencv_hello.cpp -o opencv_hello.out \
-I/usr/include/opencv -I/usr/include/opencv2 \
-lm -lopencv_core -lopencv_imgproc -lopencv_highgui
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char** argv) {
    
    // create image
    int width = 400, height = 300;
    cv::Mat img = cv::Mat::zeros(width, height, CV_8UC3);
    
    // draw (almost) square
    cv::line(img, cv::Point(100, 120), cv::Point(100, 200), 
             cv::Scalar(255, 255, 255), 2);
    cv::line(img, cv::Point(100, 200), cv::Point(200, 200), 
             cv::Scalar(255, 255, 255), 3);
    cv::line(img, cv::Point(200, 200), cv::Point(200, 100), 
             cv::Scalar(255, 255, 255), 4);
    cv::line(img, cv::Point(200, 100), cv::Point(80, 100), 
             cv::Scalar(255, 255, 255), 5);
    cv::line(img, cv::Point(80, 100), cv::Point(80, 140), 
             cv::Scalar(255, 255, 255), 6);
    
    // prepare window
    cv::namedWindow("preview", CV_WINDOW_AUTOSIZE);
    
    // show image
    cv::imshow("preview", img);
    cv::waitKey(0);
    
    return 0;
}
