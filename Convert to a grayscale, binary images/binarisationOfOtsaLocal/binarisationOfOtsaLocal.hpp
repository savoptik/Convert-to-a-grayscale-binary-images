//
//  binarisationOfOtsaLocal.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 20.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binarisationOfOtsaLocal_hpp
#define binarisationOfOtsaLocal_hpp

#include <stdio.h>
#include "binarisationofWotso.hpp"
#include <vector>

class binarisationOfOtsaLocal: binarisationofWotso {
public:
    binarisationOfOtsaLocal(std::string filepash, const int SL); // конструктор загружает изображение и задаёт масштаб локальной бинаризации.
    binarisationOfOtsaLocal() {} // пустой конструктор.
    virtual void showCurrentVersion(); // вывод изображения.
private:
    int scaleLocalization; // размер квадратиков.
    int numberOfSquaresInRow; // Количество квадратиков в строке.
    cv::Mat resultImage; // результирующее изображение.
    std::vector<cv::Mat> Squares; // вектор хранит все квадратики.
    void cutImageIntoSquares(); // метод нарезает изображение на квадратики.
    void collectImageOfSquares(); // Метод собирает изображение из нарезанных квадратиков.
};

#endif /* binarisationOfOtsaLocal_hpp */
