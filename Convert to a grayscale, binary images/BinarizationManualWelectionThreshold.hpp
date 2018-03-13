//
//  BinarizationManualWelectionThreshold.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef BinarizationManualWelectionThreshold_hpp
#define BinarizationManualWelectionThreshold_hpp

#include <stdio.h>
#include "grayScale.hpp"

class binarizationManualWelectionThreshold: grayScale {
public:
    virtual void conversionToBinary(ushort); // метод выполняет бираризацию изображения.
    void outBinaryImages(); // метод выводит бинарное изображение.
};

#endif /* BinarizationManualWelectionThreshold_hpp */
