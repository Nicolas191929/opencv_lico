#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
int main()
{
	Mat image;
	image = imread("img.jpg", IMREAD_COLOR);
	namedWindow("Оригінал", 1); imshow("Оригінал", image);

	CascadeClassifier face_cascade;
	face_cascade.load("haarcascade_frontalface_alt2.xml");

	std::vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(image, center, Size(faces[i].width*0.6, faces[i].height*0.6), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
	}
	imshow("Результат", image);

	waitKey(0);
	return 0;
}