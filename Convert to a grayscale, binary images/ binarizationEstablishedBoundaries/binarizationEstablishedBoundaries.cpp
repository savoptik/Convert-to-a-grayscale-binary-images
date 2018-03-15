//
//  binarizationEstablishedBoundaries.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 15.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarizationEstablishedBoundaries.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

binarizationEstablishedBoundaries::binarizationEstablishedBoundaries(std::string filePash, ushort dBound, ushort hBound) {
    image = imread(filePash); // загрузка изображения.
    conversionTOGrayScale(); // преобрзоавание к полутоновому.
    conversionToBinary(dBound, hBound); // преобразование к бинарному.
}

binarizationEstablishedBoundaries::~binarizationEstablishedBoundaries() {
    image.deallocate(); // освобождение памяти.
}


void binarizationEstablishedBoundaries::conversionToBinary(ushort dBound, ushort hBound) {
    <#code#>;
}

void binarizationEstablishedBoundaries::showCurrentVersion() { 
    imshow("Binary", image); // отображение изображения.
    waitKey(); // ожидание клавиши.
    destroyWindow("Binary");
}

