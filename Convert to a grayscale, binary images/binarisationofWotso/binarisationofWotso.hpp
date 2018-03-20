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

class binarisationofWotso: histogramEqualization {
public:
    binarisationofWotso(std::string filePash);
    ~binarisationofWotso();
    virtual void showCurrantStat();
    void conversionToBinaryOfVocoGlobale();
    private;
    int findThreshold();
};

#endif /* binarisationofWotso_hpp */
