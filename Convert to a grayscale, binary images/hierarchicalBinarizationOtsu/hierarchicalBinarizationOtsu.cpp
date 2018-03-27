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

void hierarchicalBinarizationOtsu::binarisationHO(cv::Mat &mask) {
    <#code#>;
}

cv::Mat hierarchicalBinarizationOtsu::generaitMask(std::vector<int> &hist) { 
    <#code#>;
}

std::vector<int> hierarchicalBinarizationOtsu::plotingHistUnit(cv::Mat &mask) { 
    <#code#>;
}

std::vector<int> hierarchicalBinarizationOtsu::plotingHistZero(cv::Mat &mask) { 
    <#code#>;
}

