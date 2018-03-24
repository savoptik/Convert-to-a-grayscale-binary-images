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
    imshow("Binarisation of Otso local", image); // вывод результирующего изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Binarisation of Otso local"); // уничтожение окна.
}

void binarisationOfOtsaLocal::cutImageIntoSquares() {
    Mat timeMatrix(scaleLocalization, scaleLocalization, CV_8UC3, Scalar(126, 0, 255)); // временная матрица.
    for (int i = 0; i < image.rows; i+=scaleLocalization) { // едем по строкам с шагом в длинну квадратика.
        for (int j = 0; j < image.cols; j+=scaleLocalization) { // Едем по столбцам изображения с шакгом в размер квадратика.
            int ri = 0, cj = 0; // бегунки для второй матрицы.
            for (int r = i; ((r < i + scaleLocalization) && (r < image.rows)); r++) { // едем по строчкам квадратика
                cj = 0; // обнуляем щётчик столбиков временной матрицы.
                for (int c = j; ((c < j + scaleLocalization) && (c < image.cols)); c++) { // едем по столбикам квадратика.
                    timeMatrix.at<Vec3b>(ri, cj) = image.at<Vec3b>(r, c); // переписываем пиксель
                    cj++; // сдвигаем пишущий индекс.
                }
                ri++; // сдвигаем строчный пишущий индекс.
            }
            Squares.push_back(timeMatrix); // засовываем клеточку в вектор.
            numberOfSquaresInRow = i == 0? numberOfSquaresInRow++: numberOfSquaresInRow; // счетаем количество квадратиков в строке.
        }
    }
    timeMatrix.deallocate(); // уничтожаем временную матрицу, она отработала и больше не нужна.
}

void binarisationOfOtsaLocal::collectImageOfSquares() {
    int indexSVector = 0; // бегунок по вектору квадратиков.
    for (int i = 0; i < image.rows; i+=scaleLocalization) { // проход по строкам результирующего изображения.
        for (int j = 0; j < image.cols; j+=scaleLocalization) { // проход по столбцам результирующего изображения.
            int ri = 0, cj = 0; // вспомогательные бегунки.
            for (int r = i; ((r < i + scaleLocalization) && (r < image.rows)); r++) { // проход по строкам квадратика изображения.
                cj = 0; // обнуление бегунка столбцов записуемого квадратика.
                for (int c = j; ((c < j + scaleLocalization) && (c < image.cols)); j++) { // проход по столбцам квадратика изображения.
                    image.at<Vec3b>(r, c) = Squares[indexSVector].at<Vec3b>(ri, cj); // переписывание пикселя
                    cj++; // прирощение бегунка столбцов записуемого квадратика.
                }
                ri++; // прирощение бегунка строк записуемого квадратика.
            }
            indexSVector++; // прирощение индекса вектора с квадратиками.
        }
    }
    Squares.clear();
}
