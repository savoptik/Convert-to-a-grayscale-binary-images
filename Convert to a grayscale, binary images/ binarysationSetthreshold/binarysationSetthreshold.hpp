//
//  binarysationSetthreshold.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 14.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binarysationSetthreshold_hpp
#define binarysationSetthreshold_hpp

#include "binaryConversions.hpp"
#include <stdio.h>

class binarysationSetthreshold: binaryConversions{
public:
    binarysationSetthreshold(std::string); // конструктор выполняет чтение файла, и преобразование к полутоновому.
    ~binarysationSetthreshold(); // деструктор освобождает память.
    virtual void showCurrentVersion(); // метод выводит изменённое изображение.
    void conversionToBinaryUpBound(ushort); // метод выполняет приведение полутонового изображения к чёрнобелому с верхней границей.
    void conversionToBinaryDownBound(ushort); // метод приводит изображение к бинарному с нижней грацицей
};

#endif /* binarysationSetthreshold_hpp */
