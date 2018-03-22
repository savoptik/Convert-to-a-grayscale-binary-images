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
#include <cmath>
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
    for (int i = 0; i < image.rows; i+=scaleLocalization) { // едем по строкам с шагом в длинну квадратика.
        for (int j = 0; j < image.cols; j+=scaleLocalization) { // Едем по столбцам изображения с шакгом в размер квадратика.
            Mat timeMatrix(scaleLocalization, scaleLocalization, Vec3b); // временная матрица.
            int ri = 0, cj = 0; // бегунки для второй матрицы.
            for (int r = i; r < i + scaleLocalization; r++) { // едем по строчкам квадратика
                cj = 0; // обнуляем щётчик столбиков временной матрицы.
                for (int c = j; c < j + scaleLocalization; c++) { // едем по столбикам квадратика.
                    timeMatrix.at<Vec3b>(ri, cj) = image.at<Vec3b>(r, c); // переписываем пиксель
                    cj++; // сдвигаем пишущий индекс.
                }
                ri++; // сдвигаем строчный пишущий индекс.
            }
            Squares.push_back(timeMatrix); // засовываем клеточку в вектор.
            numberOfSquaresInRow = i == 0? numberOfSquaresInRow++; // счетаем количество квадратиков в строке.
        }
    }
}

void binarisationOfOtsaLocal::collectImageOfSquares() { 
    <#code#>;
}
