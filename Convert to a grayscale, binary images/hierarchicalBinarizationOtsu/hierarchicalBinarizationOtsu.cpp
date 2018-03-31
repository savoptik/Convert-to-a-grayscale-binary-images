//
//  hierarchicalBinarizationOtsu.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 25.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "hierarchicalBinarizationOtsu.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void hierarchicalBinarizationOtsu::showCurrentVersion() { 
    imshow("Hierarchical binarization Otsu", image);
    waitKey();
    destroyWindow("Hierarchical binarization Otsu");
}

hierarchicalBinarizationOtsu::~hierarchicalBinarizationOtsu() { 
    image.deallocate();
    masks.clear();
}

std::vector<int> hierarchicalBinarizationOtsu::plotingHistZero(cv::Mat &mask, int activPiks) { 
    std::vector<int> hist(256); // Гистограма
    for (int i = 0; i < image.rows; i++) {
        for (int j =0; j < image.cols; j++) {
            if (mask.at<Vec3b>(i, j)[0] == activPiks) {
                hist[image.at<Vec3b>(i, j)[0]]++;
            }
        }
    }
}

