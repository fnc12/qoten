//
//  Recommended.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Recommended_hpp
#define Recommended_hpp

#include <string>
#include <vector>

#include "Dependency.hpp"
#include "Channel.hpp"

namespace DataModel {
    
    struct Recommended {
        int id;
        std::string createdAt;
        std::string name;
        std::vector<Dependency> dependencies;
        std::string pluginId;
        Channel channel;
        long fileSize;
        std::string md5;
        bool staffApproved;
        std::string href;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Recommended &o);
    
    void to_json(json &j, const Recommended &o);
}

#endif /* Recommended_hpp */
