//
//  Channel.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Channel_hpp
#define Channel_hpp

#include <string>
#include <json/json.hpp>

namespace DataModel {
    
    struct Channel {
        std::string name;
        std::string color;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Channel &o);
    
    void to_json(json &j, const Channel &o);
}

#endif /* Channel_hpp */
