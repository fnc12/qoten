//
//  JsonExtension.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef JsonExtension_hpp
#define JsonExtension_hpp

#include <memory>
#include <json/json.hpp>

namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json& j, const std::shared_ptr<T>& v) {
            if(v){
                j = *v;
            }else{
                j = nullptr;
            }
        }
        
        static void from_json(const json& j, std::shared_ptr<T>& v) {
            if (j.is_null()) {
                v = {};
            } else {
                v = std::make_shared<T>(j.get<T>());
            }
        }
    };
}

#endif /* JsonExtension_hpp */
