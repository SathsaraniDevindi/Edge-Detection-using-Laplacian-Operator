# Edge-Detection-using-Laplacian-Operator
Step by step process to detect the edges in the image using the Laplacian operator.
Laplacian operator is a second order derivative mask which has two further classifications as positive Laplacian operator and negative Laplacian operator. 

1.	Load the image using the function Mat img = imread(argv[1], 1);
2.	Check whether the image is found or not if (!img.data) {
3.	If image is not found it will display an error message.
4.	After loading the image convert it to a gray image.
       Mat gray(height, width, CV_8UC1, Scalar(0));
	     cvtColor(img, gray, COLOR_BGR2GRAY);
5.	Take a copy of the gray image and further procees.
      Mat output = gray.clone();

6.	Initialize G as G=0
7.	As this is a 3x3 kernel we have to ignore first two rows, first two columns, last two rows, and last two columns as well.
Therefore we have to start from x=2 , y=2  and end with height-2, width-2.
for (int x = 2; x < height - 2; x++) {
		for (int y = 2; y < width - 2; y++) {

8.	Here I have tested with both Laplacian operators in the below and chose the second one as it gives better quality.
 
9.	Then we need to multiply kernal with relevant mask.
    Mask = [1,1,1,1,-8,1,1,1,1]
    
10.	Then check the values using if else condition to determine whether the pixel lies on light side or dark side. 
        if (G < 0) {G = 0;}
            else if (G > 255) {G = 255;}
11.	Finally output the image which applied Laplacian operator.
        output.at<uchar>(x, y) = G;
