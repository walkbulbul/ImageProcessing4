#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


Mat image;
Mat dst;

int main()

{
	image = imread("garden.png");
	
	dilate(image, dst, getStructuringElement(MORPH_RECT, Size(3, 3)));

	imshow("Original", image);
	imshow("Dilation", dst);






	waitKey(0);
	return 0;
}