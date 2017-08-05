//
//  Member.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Member_hpp
#define Member_hpp

#include <string>
#include <vector>
#include <json/json.hpp>

namespace DataModel {
    
    struct Member {
        int userId;
        std::string name;
        std::vector<std::string> roles;
        std::string headRole;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Member &o);
    
    void to_json(json &j, const Member &o);
}

#endif /* Member_hpp */
