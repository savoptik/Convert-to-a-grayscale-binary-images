//
//  BinarizationManualWelectionThreshold.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "BinarizationManualWelectionThreshold.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void binarizationManualWelectionThreshold::conversionToBinary(ushort threshold) {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] > threshold? 255: 0;
            image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] > threshold? 255: 0;
            image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] > threshold? 255: 0;
        }
    }
}

void binarizationManualWelectionThreshold::outBinaryImages() {
    imshow("Binary image", image);
    waitKey();
    destroyWindow("Binary image");
}

binarizationManualWelectionThreshold::binarizationManualWelectionThreshold(std::string filePash, ushort threshold) {
    ;
    conversionToBinary(threshold);
}
