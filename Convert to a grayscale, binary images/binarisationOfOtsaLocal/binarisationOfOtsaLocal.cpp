//
//  binarisationOfOtsaLocal.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 20.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarisationOfOtsaLocal.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

binarisationOfOtsaLocal::binarisationOfOtsaLocal(std::string filepash, const int SL) {
    image = imread(filepash); // загрузка изображения.
    scaleLocalization = SL; // записываем размер квадратиков.
    cutImageIntoSquares(); // режем изображение на квадратики.
    for (int i = 0; i < Squares.size(); i++) { // идём по массиву квадратиков.
        binarisationofWotso bo(Squares[i]); // готовимся к преобразованию квадратика к Отсу
        bo.conversionToBinaryOfVocoGlobale(); // выполняем бинаризацию.
        Squares[i] = bo.getImageMatrix(); // забираем изображение обратно в вектор.
    }
    collectImageOfSquares(); // собираем изображение.
}

void binarisationOfOtsaLocal::showCurrentVersion() { 
    imshow("Binarisation of Otso local", resultImage); // вывод результирующего изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Binarisation of Otso local"); // уничтожение окна.
}

void binarisationOfOtsaLocal::cutImageIntoSquares() { 
    <#code#>;
}

void binarisationOfOtsaLocal::collectImageOfSquares() { 
    <#code#>;
}
