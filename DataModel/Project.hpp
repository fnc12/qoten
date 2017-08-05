//
//  Project.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Project_hpp
#define Project_hpp

#include <string>
#include <json/json.hpp>
#include <vector>
#include <memory>
#include "Services/JsonExtension.hpp"

#include "Member.hpp"
#include "Channel.hpp"
#include "Recommended.hpp"
#include "Category.hpp"

namespace DataModel {
    
    struct Project {
        
        std::string pluginId;
        std::string createdAt;
        std::string name;
        std::string owner;
        std::shared_ptr<std::string> description;
        std::string href;
        std::vector<Member> members;
        std::vector<Channel> channels;
        Recommended recommended;
        Category category;
        int views;
        int downloads;
        int stars;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Project &o);
    
    void to_json(json &j, const Project &o);
}

#endif /* Project_hpp */
