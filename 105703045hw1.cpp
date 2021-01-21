#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>    //cv::Canny()

using namespace cv;
using namespace std;
int main(int argc, char const *argv[]) {
	Mat input(2, 2, CV_8U),dst(2, 2, CV_8U);
	Mat img(2,2,CV_8U);
	Mat image1(2, 2, CV_8U);
	fstream file;
	file.open("hw1test.txt");
	string strLine;
	int height1 = 0;
	int width1 = 0;
	float save = 0.0;
	vector<vector<float>> data2D;
	if (!file) {
		cout << "error\n";
		system("pause");
		return 0;
	}
	while (getline(file, strLine)) {
		stringstream ss(strLine);
		vector<float> row;
		float data;
		while (ss >> data) {
			row.push_back(data);
		}
		data2D.push_back(row);
	}
	
	file.close();
	cout << data2D.size();

	input = imread("Lenna.jpg", 0);
//	image1 = imread("C:\\Users\\USER\\Documents\\電腦視覺\\Lenna_sharpen.jpg",0);
	if (input.empty()) {
		cout << "error\n";
		system("pause");
		return 0;
	}
	img.create(input.size().width, input.size().height, CV_8U);
//	dst.create(input.size().width, input.size().height, CV_8U);

	
	for (int height = 0; height < input.rows; height++){
		uchar *data = input.ptr<uchar>(height);
		uchar *data1 = img.ptr<uchar>(height);
		for (int width = 0; width < input.cols; width++) {
		data1[width] = 0;
		save = 0.0;
			for (int valuer = 0; valuer < (int)data2D.size(); valuer++) {
				height1 = height + (valuer - (int)data2D.size() / 2);
				for (int valuec = 0; valuec < (int)data2D.size(); valuec++) {
					width1 = width + (valuec - (int)data2D.size() / 2);

					if (height1 < 0 || height1 >= input.rows || width1<0 || width1>=input.cols) {
						data1[width] = 0;
					}
					else {
						save += (float)input.ptr<uchar>(height1)[width1] * data2D[valuer][valuec];
						if (valuer == (int)data2D.size() - 1 && valuec == (int)data2D.size() - 1) {
							if (save< 0.0) {
								save= 0.0;
							}
							data1[width] = save;
						}				
					}
				}
			}
		}
	}
//	absdiff(img, image1, dst);
	namedWindow("showImage1", WINDOW_AUTOSIZE);
	namedWindow("showImage2", WINDOW_AUTOSIZE);
//	namedWindow("2Dsharpen", WINDOW_AUTOSIZE);
//	namedWindow("Result_sharpen_diff", WINDOW_AUTOSIZE);
	imshow("showImage1",input);
	imshow("showImage2",img);
//	imshow("2Dsharpen", image1);
//	imshow("Result_sharpen_diff", dst);
	waitKey(0);
	destroyAllWindows();
	input.release();
	img.release();
	
		return 0;
}