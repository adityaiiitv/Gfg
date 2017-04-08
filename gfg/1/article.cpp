// Author: Aditya Prakash
// Title: OpenCV C++ Program to blur an image.
#include <opencv2/core/core.hpp>		//	Import the core header file
// core - a compact module defining basic data structures, including the dense multi-dimensional array Mat and basic functions used by all other modules.
#include <opencv2/highgui/highgui.hpp>
// highgui - an easy-to-use interface to video capturing, image and video codecs, as well as simple UI capabilities.
#include <opencv2/imgproc/imgproc.hpp>
// imgproc - an image processing module that includes linear and non-linear image filtering
//, geometrical image transformations (resize, affine and perspective warping, generic table-based remapping)
//, color space conversion, histograms, and so on.
#include <stdio.h>
#include <iostream>
//The stdio.h header defines three variable types, several macros, and various functions for performing input and output.
// Namespace where all the C++ OpenCV functionality resides 
using namespace cv;
using namespace std;
//We can also use 'namespace std' if need be.
int main()		// Main function
{ 
 Mat image = imread("bat.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
// Mat object is a basic image container.
// imread: first argument denotes the image to be loaded
// the second arguments specifies the image format.
// CV_LOAD_IMAGE_UNCHANGED (<0) loads the image as is
// CV_LOAD_IMAGE_GRAYSCALE ( 0) loads the image as an intensity one
// CV_LOAD_IMAGE_COLOR (>0) loads the image in the BGR format
// If the second argument is not specified, it is implied CV_LOAD_IMAGE_COLOR 

    if(! image.data )                              // Check for no data
    {
        cout <<  "Could not open or find the image.\n";
        return -1;					// unsuccessful
    }
 blur(image,image,Size(10,10));			// Function to blur the image
 // first argument: input source
 // second argument: output source
 // third argument: blurring kernel size
 
 namedWindow( "bat", CV_WINDOW_AUTOSIZE );	// Create a window
 // first argument: name of the window
 // second argument: flag- types: 
 // WINDOW_NORMAL If this is set, the user can resize the window.
 // WINDOW_AUTOSIZE If this is set, the window size is automatically adjusted to fit the displayed image() ), and you cannot change the window size manually.
 // WINDOW_OPENGL If this is set, the window will be created with OpenGL support.

 imshow( "bat", image );			// Displays an image in the specified window.
 // first argument: name of the window
 // second argument: image to be shown(Mat object)
 waitKey(0);							// Wait infinite time for a keypress
 return 0;								// Return from the main function
}
