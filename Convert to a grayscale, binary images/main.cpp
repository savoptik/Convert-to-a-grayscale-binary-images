//
//  main.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "grayScale.hpp"
#include <string>
#include "binarysationSetthreshold.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    string filePath = "/Users/artemsemenov/Documents/projects/xcode/Convert to a grayscale, binary images/images/апельсин.png"; // путь к файлу.
    grayScale pic(filePath); // создание объекта
    pic.showCurrentVersion(); // вывод преобразованного изображения.
    binarysationSetthreshold bst1(filePath); // создание объекта преобразованного изображения
    bst1.conversionToBinaryUpBound(130); // преобразование с верхней границей.
    binarysationSetthreshold bst2(filePath); // создание ещё одного объекта.
    bst2.conversionToBinaryDownBound(130); // преобразование с верхней границей.
    bst1.showCurrentVersion(); // вывод изображения бинаризованого с верхней границей.
    bst2.showCurrentVersion(); // вывод изображения, бинаризованного с нижней границей.
    return 0;
}
