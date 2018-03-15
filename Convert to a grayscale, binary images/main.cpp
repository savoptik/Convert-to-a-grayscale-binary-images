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
#include <binarizationEstablishedBoundaries.hpp>
using namespace std;

int main(int argc, const char * argv[]) {
    string filePath = "/Users/artemsemenov/Documents/projects/xcode/Convert to a grayscale, binary images/images/апельсин.png"; // путь к файлу.
    grayScale pic(filePath); // создание объекта
    pic.showCurrentVersion(); // вывод преобразованного изображения.
    binarysationSetthreshold bst(filePath, 130); // создание объекта преобразованного изображения и задание порога.
    bst.showCurrentVersion(); // вывод бинаризованного изображения.
    binarizationEstablishedBoundaries beb(filePath, 50, 50); // создание объекта бинаризации с заданными верхней и нижней границей.
    beb.showCurrentVersion(); // вывод изображения.
    return 0;
}
