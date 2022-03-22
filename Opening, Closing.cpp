#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat Image;
Mat open;
Mat close;

int main()
{
	Image = imread("garden.png");

	imshow("Orginal", Image);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));

	morphologyEx(Image, open, MORPH_OPEN, element, Point(-1, -1),2);

	imshow("Open", open);


	morphologyEx(Image, close, MORPH_CLOSE, element, Point(-1, -1), 2);

	imshow("CLose", close);






	waitKey(0);
	return 0;





}