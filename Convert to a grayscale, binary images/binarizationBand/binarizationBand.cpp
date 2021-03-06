//
//  binarizationBand.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 15.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarizationBand.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void binarizationBand::showCurrentVersion() { 
    imshow("Binarization band", image); // вывод изображения
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Binarization band"); // уничтожение окон.
}

binarizationBand::~binarizationBand() { 
    image.deallocate(); // освобождение памяти.
}

binarizationBand::binarizationBand(std::string filePash, ushort dBound, ushort uBound) { 
    image = imread(filePash); // загрузка изображения.
    conversionTOGrayScale(); // преобразование изображения к полутоновому.
    if (dBound < uBound) { // если значение нижней границы диапазона меньше верхней
        conversionToBinary(dBound, uBound); // запускаем преобразование.
    } else { // иначе
        conversionToBinary(uBound, dBound); // запускаем преобразование поменяв местами значение диапазона.
    }
}

void binarizationBand::conversionToBinary(ushort dBound, ushort uBound) { 
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j);
            image.at<Vec3b>(i, j)[0] = ((buf[0] > dBound) && (buf[0] < uBound))? 255: 0;
            image.at<Vec3b>(i, j)[1] = ((buf[1] > dBound) && (buf[1] < uBound))? 255: 0;
            image.at<Vec3b>(i, j)[2] = ((buf[2] > dBound) && (buf[2] < uBound))? 255: 0;
        }
    }
}
