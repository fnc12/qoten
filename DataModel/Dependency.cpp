//
//  Dependency.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Dependency.hpp"

namespace Keys {
    const std::string pluginId = "pluginId";
    const std::string version = "version";
}

void DataModel::from_json(const json &j, Dependency &o) {
    using namespace Keys;
    o.pluginId = j[pluginId];
    o.version = j[version];
}

void DataModel::to_json(json &j, const Dependency &o) {
    using namespace Keys;
    j = {
        { pluginId, o.pluginId },
        { version, o.version },
    };
}
