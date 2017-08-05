//
//  Recommended.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Recommended.hpp"

namespace Keys {
    const std::string id = "id";
    const std::string createdAt = "createdAt";
    const std::string name = "name";
    const std::string dependencies = "dependencies";
    const std::string pluginId = "pluginId";
    const std::string channel = "channel";
    const std::string fileSize = "fileSize";
    const std::string md5 = "md5";
    const std::string staffApproved = "staffApproved";
    const std::string href = "href";
}

void DataModel::from_json(const json &j, Recommended &o) {
    using namespace Keys;
    o.id = j[id];
    o.createdAt = j[createdAt];
    o.name = j[name];
    o.dependencies = j[dependencies].get<decltype(o.dependencies)>();
    o.pluginId = j[pluginId];
    o.channel = j[channel];
    o.fileSize = j[fileSize];
    o.md5 = j[md5];
    o.staffApproved = j[staffApproved];
    o.href = j[href];
}

void DataModel::to_json(json &j, const Recommended &o) {
    using namespace Keys;
    j = {
        { id, o.id },
        { createdAt, o.createdAt },
        { name, o.name },
        { dependencies, o.dependencies },
        { pluginId, o.pluginId },
        { channel, o.channel },
        { fileSize, o.fileSize },
        { md5, o.md5 },
        { staffApproved, o.staffApproved },
        { href, o.href },
    };
}
