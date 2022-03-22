#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat tophat;
Mat gradient;


int main()

{
	Mat Image = imread("gargen.png");
	Mat tophatIm = imread("moon.png");


	imshow("Orginal" , tophatIm);
	imshow("Orginal1", Image);

	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	morphologyEx(tophatIm, tophat, MORPH_TOPHAT, element, Point(-1, -1), 6);

	imshow("tophat", tophat);
	
	morphologyEx(Image, gradient, MORPH_GRADIENT, element, Point(-1, -1), 3);

	imshow("gradient", gradient);





	waitKey(0);
	return 0;

}