//
//  Category.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Category_hpp
#define Category_hpp

#include <string>
#include <json/json.hpp>

namespace DataModel {
    
    struct Category {
        std::string title;
        std::string icon;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Category &o);
    
    void to_json(json &j, const Category &o);
}

#endif /* Category_hpp */
