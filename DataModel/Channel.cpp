//
//  Channel.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Channel.hpp"

namespace Keys {
    const std::string name = "name";
    const std::string color = "color";
}

void DataModel::from_json(const json &j, Channel &o) {
    using namespace Keys;
    o.name = j[name];
    o.color = j[color];
}

void DataModel::to_json(json &j, const Channel &o) {
    using namespace Keys;
    j = {
        { name, o.name },
        { color, o.color },
    };
}
