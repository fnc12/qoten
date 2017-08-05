//
//  Version.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Version_hpp
#define Version_hpp

#include <string>
#include <vector>
#include <json/json.hpp>

#include "Dependency.hpp"
#include "Channel.hpp"

namespace DataModel {
    
    struct Version {
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
    
    void from_json(const json &j, Version &o);
    
    void to_json(json &j, const Version &o);
}

#endif /* Version_hpp */
