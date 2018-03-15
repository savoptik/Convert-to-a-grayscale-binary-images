//
//  binarizationEstablishedBoundaries.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 15.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binarizationEstablishedBoundaries_hpp
#define binarizationEstablishedBoundaries_hpp

#include <stdio.h>
#include "binaryConversions.hpp"
#include <string>

class  binarizationEstablishedBoundaries: binaryConversions {
public:
     binarizationEstablishedBoundaries(std::string, ushort, ushort); // конструктор читает изображение, преобразует его к полутоновому, затем к бинарному.
    ~ binarizationEstablishedBoundaries(); // деструктор освобождает память.
    virtual void showCurrentVersion(); // отображает изображение.
    
private:
    void conversionToBinary(ushort, ushort); // метод выполняет приведение полутонового изображения к чёрнобелому.
};

#endif /* binarizationEstablishedBoundaries_hpp */
