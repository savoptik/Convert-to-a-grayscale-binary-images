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

void grayScale::conversionTOGrayScale() {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j); // получаем пиксель, разложенный на каналы.
            int mid = (buf[0] + buf[1] + buf[2])/3; // вычисляем среднее.
            // записываем среднее в каналы.
            image.at<Vec3b>(i, j)[0] = mid;
            image.at<Vec3b>(i, j)[1] = mid;
            image.at<Vec3b>(i, j)[2] = mid;
        }
    }
}
