//
//  Download.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Download.hpp"

namespace Keys {
    const std::string message = "message";
    const std::string post = "post";
}

void DataModel::from_json(const json &j, Download &o) {
    using namespace Keys;
    o.message = j[message].get<decltype(o.message)>();
    o.post = j[post];
}

void DataModel::to_json(json &j, const Download &o) {
    using namespace Keys;
    j = {
        { message, o.message },
        { post, o.post },
    };
}
