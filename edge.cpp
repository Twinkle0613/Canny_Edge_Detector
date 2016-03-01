#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <stdio.h>

using namespace cv;
using namespace std;

int edgeThresh = 1;
Mat image, gray, edge, cedge;
    VideoCapture cap(0);

// define a trackbar callback
static void updateImage(int, void*)
{    
    static int i = 0; 
    // Transfer the image from webcam to "image"
    cap >> image;
    // Converting the colour of image to become gray
    cvtColor(image, gray, COLOR_BGR2GRAY);
    // Make the image smoothly 
    blur(gray, edge, Size(3,3));
    // Run the edge detector on grayscale
    Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
    cedge = Scalar::all(0);
    image.copyTo(cedge, edge);
    imshow("Edge map", cedge);
    printf("%d\n",i++);
    waitKey(1);
}



int main()
{
    // Reserve same size of sapce in cedge and the type of space is same with image
    cedge.create(image.size(), image.type());

    // Create a window
    namedWindow("Edge map", 1);

    // Create a toolbar
    createTrackbar("Canny threshold", "Edge map", &edgeThresh, 100, updateImage);

  while(1){

    // Update the image that captured by webcap
    updateImage(0, 0);

 }
    return 0;
}
