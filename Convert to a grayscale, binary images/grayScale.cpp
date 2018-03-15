//
//  grayScale.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "grayScale.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

grayScale::grayScale(std::string filePash) {
    image = imread(filePash); // чтение.
    conversionTOGrayScale(); // преобразование к полутоновому.
}

grayScale::~grayScale() {
    image.deallocate(); // освобождение памяти.
}

void grayScale::showCurrentVersion() {
    imshow("Gray scale", image); // отображение изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Gray scale"); // уничтожение окна.
}
