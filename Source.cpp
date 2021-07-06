#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp" 

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	Mat img = imread(argv[1], 1);
	if (!img.data) {
		cout << "Could not find the image!" << endl;
		return -1;
	}

	int height = img.rows;
	int width = img.cols;
	int  widthstep = img.step;
	int ch = img.channels();

	Mat gray(height, width, CV_8UC1, Scalar(0));
	cvtColor(img, gray, COLOR_BGR2GRAY);

	
	Mat output = gray.clone();
	
	int G = 0;
	
	for (int x = 2; x < height - 2; x++) {
		for (int y = 2; y < width - 2; y++) {
			
			//Laplacian operator
			G = -gray.at<uchar>(x - 1, y - 1) - gray.at<uchar>(x, y - 1) - gray.at<uchar>(x + 1, y - 1)- gray.at<uchar>(x - 1, y) - gray.at<uchar>(x + 1, y) - gray.at<uchar>(x - 1, y + 1) - 
				gray.at<uchar>(x, y + 1) - gray.at<uchar>(x + 1, y + 1) + 
				8 * (gray.at<uchar>(x, y));

			if (G < 0) {
				G = 0;
			}
			else if (G > 255) {
				G = 255;
			}

			output.at<uchar>(x, y) = G;

			/////////////////////zero crossing/////////////////////////////////////////////////////
			/*GXY = abs(gr.at<uchar>(x + 1, y) + gr.at<uchar>(x - 1, y) + gr.at<uchar>(x, y + 1) + gr.at<uchar>(x, y - 1)- 4 *(gr.at<uchar>(x, y)));
			GUR = gr.at<uchar>(x - 1, y - 2) + gr.at<uchar>(x - 1, y) + gr.at<uchar>(x - 2, y - 1) + gr.at<uchar>(x, y - 1) - 4 * (gr.at<uchar>(x - 1, y - 1));
			GU = gr.at<uchar>(x, y - 2) + gr.at<uchar>(x, y) + gr.at<uchar>(x - 1, y - 1) + gr.at<uchar>(x + 1, y - 1) - 4 * (gr.at<uchar>(x, y - 1));
			GUL = gr.at<uchar>(x + 1, y - 2) + gr.at<uchar>(x + 1, y) + gr.at<uchar>(x, y - 1) + gr.at<uchar>(x + 2, y - 1) - 4 * (gr.at<uchar>(x + 1, y - 1));
			GR = gr.at<uchar>(x - 1, y - 1) + gr.at<uchar>(x - 1, y + 1) + gr.at<uchar>(x - 2, y) + gr.at<uchar>(x, y) - 4 * (gr.at<uchar>(x - 1, y));
			GL = gr.at<uchar>(x + 1, y - 1) + gr.at<uchar>(x + 1, y + 1) + gr.at<uchar>(x , y) + gr.at<uchar>(x + 2, y) - 4 * (gr.at<uchar>(x + 1, y));
			GDR = gr.at<uchar>(x - 1, y ) + gr.at<uchar>(x - 1, y + 2) + gr.at<uchar>(x - 2, y + 1) + gr.at<uchar>(x, y + 1) - 4 * (gr.at<uchar>(x - 1, y + 1));
			GD = gr.at<uchar>(x, y) + gr.at<uchar>(x, y + 2) + gr.at<uchar>(x - 1, y + 1) + gr.at<uchar>(x + 1, y + 1) - 4 * (gr.at<uchar>(x, y + 1));
			GDL = gr.at<uchar>(x + 1, y) + gr.at<uchar>(x + 1, y + 2) + gr.at<uchar>(x, y + 1) + gr.at<uchar>(x + 2, y + 1) - 4 * (gr.at<uchar>(x + 1, y + 1));


			xnt GA = GUR * GDL;
			xnt GB = GU * GD;
			xnt GC = GUL * GDR;
			xnt GE = GL * GR;

			xf (GA < 0 || GB < 0 || GC < 0 || GE < 0) {
				xf (GXY >= T)
					output.at<uchar>(x, y) = 255;
				else
					output.at<uchar>(x, y) = 0;
			}

			else {
				output.at<uchar>(x, y) = 0;
			}*/


			//////////////////laplacian of gaussian//////////////////////////////////////
			/*G = 2 * gr.at<uchar>(x, y + 1) +
				2 * gr.at<uchar>(x, y - 1) +
				2 * gr.at<uchar>(x + 1, y) +
				2 * gr.at<uchar>(x - 1, y) +
				gr.at<uchar>(x, y + 2) +
				gr.at<uchar>(x, y - 2) +
				gr.at<uchar>(x + 2, y) +
				gr.at<uchar>(x - 2, y) +
				gr.at<uchar>(x - 1, y + 1) +
				gr.at<uchar>(x + 1, y + 1) +
				gr.at<uchar>(x + 1, y - 1) +
				gr.at<uchar>(x - 1, y - 1) -
				16 * gr.at<uchar>(x, y);
		
			

			if (G < 0) {
				G = 0;
			}
			else if (G > 255) {
				G = 255;
			}
			
				output.at<uchar>(x, y) = G;*/
		

		}
	}


	namedWindow("Image");
	imshow("Image", img);
	namedWindow("Output Image");
	imshow("Output Image", output);
	imwrite("file1.jpg", output);
	waitKey(0);
	return 0;

}
