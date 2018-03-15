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
#include <string>

class binarysationSetthreshold: binaryConversions{
public:
    binarysationSetthreshold(std::string, ushort); // конструктор выполняет чтение файла, и преобразование с начала к полутоновому, а потом к бинаризованному.
    ~binarysationSetthreshold(); // деструктор освобождает память.
    virtual void showCurrentVersion(); // метод выводит изменённое изображение.
    
private:
    void conversionToBinary(ushort); // метод выполняет приведение полутонового изображения к чёрнобелому.
};

#endif /* binarysationSetthreshold_hpp */
