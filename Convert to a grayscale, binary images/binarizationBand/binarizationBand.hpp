//
//  binarizationBand.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 15.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binarizationBand_hpp
#define binarizationBand_hpp

#include <stdio.h>
#include "binaryConversions.hpp"

class binarizationBand: binaryConversions {
public:
    binarizationBand(std::string filePash, ushort dBound, ushort uBound); // Конструктор загрузит изображение, преобразует его в к полутоновому, потом к бинарному.
    ~binarizationBand(); // деструктор освободит память.
    virtual void showCurrentVersion(); // метод отобразит текущее состояние картинки.
    
private:
    void conversionToBinary(ushort dBound, ushort uBound); // метод выполняет приобразование к бинарному изображению.
};

#endif /* binarizationBand_hpp */
