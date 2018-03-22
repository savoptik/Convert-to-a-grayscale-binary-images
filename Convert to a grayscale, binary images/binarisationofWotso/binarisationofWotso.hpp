//
//  binarisationofWotso.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 20.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binarisationofWotso_hpp
#define binarisationofWotso_hpp

#include <stdio.h>
#include "histogramEqualization.hpp"
#include <string>

class binarisationofWotso: public histogramEqualization {
protected:
    binarisationofWotso(std::string filePash); // конструктор загрузит изображение, запустит приведение изображения к полутоновому, запустит построение гистограммы.
    binarisationofWotso(cv::Mat& exImage); // альтернативный конструктор.
    binarisationofWotso() {}; // Конструктор без переменных для классов наследников.
    ~binarisationofWotso(); // деструктор освободит память.
    virtual void showCurrantStat(); // вывод изображения.
    void conversionToBinaryOfVocoGlobale(); // глобальная бинаризация Оцо
    void exportToDisk(std::string filePash); // метод записывает полученное изображение на диск.
protected:
    ushort findThreshold(); // метод вычисление порога.
};

#endif /* binarisationofWotso_hpp */
