//
//  Dependency.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Dependency_hpp
#define Dependency_hpp

#include <string>
#include <json/json.hpp>

namespace DataModel {
    
    struct Dependency {
        std::string pluginId;
        std::string version;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Dependency &o);
    
    void to_json(json &j, const Dependency &o);
}

#endif /* Dependency_hpp */
