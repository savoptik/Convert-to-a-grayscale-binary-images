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

grayScale::grayScale(string filePath) { // принимаем строку с путём к файлу.
    image = imread(filePath); // читаем в матрицу изображение.
    conversionTOGrayScale(); // преобразуем изображение к полутоновому.
}

grayScale::~grayScale() {
    image.deallocate(); // уничтожаем изображение.
}

void grayScale::showGrayImage() {
    imshow("Gray image", image); // отображаем изображение.
    waitKey(); // ждём нажатия клавиши.
    destroyWindow("Gray image"); // уничтожаем окно.
}
