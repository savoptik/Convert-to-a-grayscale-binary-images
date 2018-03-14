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
    binarysationSetthreshold(std::string, ushort);
    ~binarysationSetthreshold();
    virtual void showCurrentVersion();
    
private:
    void conversionToBinary(ushort);
    
};

#endif /* binarysationSetthreshold_hpp */
