//
//  Download.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef Download_hpp
#define Download_hpp

#include <string>
#include <vector>
#include <json/json.hpp>

namespace DataModel {
    
    struct Download {
        std::vector<std::string> message;
        std::string post;
    };
    
    using nlohmann::json;
    
    void from_json(const json &j, Download &o);
    
    void to_json(json &j, const Download &o);
}

#endif /* Download_hpp */
