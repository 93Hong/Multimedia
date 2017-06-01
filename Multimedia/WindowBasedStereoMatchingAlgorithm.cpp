/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	String leftImageName = "left.png";
	String rightImageName = "right.png";

	Mat image = imread(leftImageName, IMREAD_GRAYSCALE);
	Mat image2 = imread(rightImageName, IMREAD_GRAYSCALE);
	Mat dst(image.rows, image.cols, CV_8UC1);

	if (image.empty() || image2.empty()) {
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}

	int fromX, fromY, width, height, distance;
	double tmp, min;

	for (int y = 0; y < image2.size().height; y++) {
		for (int x = 0; x < image2.size().width; x++) {
			fromX = x - 2;
			fromY = y - 2;
			width = x + 3;
			height = y + 3;

			if (width > image2.cols - 1)
				width = image2.cols - 1;
			if (height > image2.rows - 1)
				height = image2.rows - 1;
			if (fromX < 0)
				fromX = 0;
			if (fromY < 0)
				fromY = 0;

			width = width - fromX;
			height = height - fromY;

			Mat rightWindow(image2, Rect(fromX, fromY, width, height));

			min = 10000;
			distance = x;

			for (int i = fromX; i < fromX + 16; i++) {
				if (i + width > image2.cols - 1)
					break;
				Mat leftWindow(image, Rect(i, fromY, width, height));
				tmp = 0;

				for (int y1 = 0; y1 < height; y1++)
					for (int x1 = 0; x1 < width; x1++)
						tmp += pow((double)leftWindow.at<uchar>(y1, x1) - (double)rightWindow.at<uchar>(y1, x1), 2);
				if (min > tmp) {
					distance = i;
					min = tmp;
				}
			}
			dst.at<uchar>(y, x) = saturate_cast<uchar>((distance - x) * 16);
		}
	}

	namedWindow("Left", WINDOW_AUTOSIZE);
	imshow("Left", image);
	namedWindow("Right", WINDOW_AUTOSIZE);
	imshow("Right", image2);
	namedWindow("Result", WINDOW_AUTOSIZE);
	imshow("Result", dst);

	waitKey(0);
	return 0;
}*/