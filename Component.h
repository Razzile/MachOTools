//
//  Component.h
//  MachOTools
//
//  Created by callum taylor on 07/07/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef Component_h
#define Component_h

class Component {
public:
    virtual std::string Description() = 0;
    virtual bool TryLoad() = 0;
};

#endif /* Component_h */
