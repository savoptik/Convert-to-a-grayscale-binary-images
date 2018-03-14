//
//  binarysationSetthreshold.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 14.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarysationSetthreshold.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

binarysationSetthreshold::binarysationSetthreshold(std::string filePash, ushort threshold) {
    image = imread(filePash);
    conversionTOGrayScale();
    conversionToBinary(threshold);
}

binarysationSetthreshold:: ~binarysationSetthreshold() {
    image.deallocate();
}

void binarysationSetthreshold::showCurrentVersion() {
    imshow("Binary version", image);
    waitKey();
    destroyWindow("Binary version");
}

void binarysationSetthreshold::conversionToBinary(ushort threshold) {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] < threshold? 0: 255;
            image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] < threshold? 0: 255;
            image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] < threshold? 0: 255;
        }
    }
}
