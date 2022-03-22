#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

Mat orgim;
Mat dst;
Mat cdst;

int main()

{
	orgim = imread("detection.jpg");



	Canny(orgim, dst, 50, 200, 3);
	cvtColor(dst, cdst, COLOR_GRAY2BGR);


	vector<Vec2f>lines;

	HoughLines(dst, lines, 1, CV_PI / 180, 150);

	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;


		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(x0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(x0 - 1000 * (a));

		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);







	}
	imshow("Picture", orgim);
	imshow("Detection_Image", cdst);
	





	waitKey(0);
	return (0);
}