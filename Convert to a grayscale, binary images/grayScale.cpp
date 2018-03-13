//
//  grayScale.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "grayScale.hpp"
using namespace std;
using namespace cv;

grayScale::grayScale(string filePath) {
    image = imread(filePath);
    conversionTOGrayScale();
}

grayScale::~grayScale() {
    image.deallocate();
    destroyAllWindows();
}

void grayScale::showGrayImage() {
    imshow("Gray image", image);
    waitKey();
}
