//
//  Project.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Project.hpp"

namespace Keys {
    const std::string pluginId = "pluginId";
    const std::string createdAt = "createdAt";
    const std::string name = "name";
    const std::string owner = "owner";
    const std::string description = "description";
    const std::string href = "href";
    const std::string members = "members";
    const std::string channels = "channels";
    const std::string recommended = "recommended";
    const std::string category = "category";
    const std::string views = "views";
    const std::string downloads = "downloads";
    const std::string stars = "stars";
}

void DataModel::from_json(const json &j, Project &o) {
    using namespace Keys;
    o.pluginId = j[pluginId];
    o.createdAt = j[createdAt];
    o.name = j[name];
    o.owner = j[owner];
    o.description = j[description];
    o.href = j[href];
    o.members = j[members].get<decltype(o.members)>();
    o.channels = j[channels].get<decltype(o.channels)>();
    o.recommended = j[recommended];
    o.category = j[category];
    o.views = j[views];
    o.downloads = j[downloads];
    o.stars = j[stars];
}

void DataModel::to_json(json &j, const Project &o) {
    using namespace Keys;
    j = {
        { pluginId, o.pluginId },
        { createdAt, o.createdAt },
        { name, o.name },
        { owner, o.owner },
        { description, o.description },
        { href, o.href },
        { members, o.members },
        { channels, o.channels },
        { recommended, o.recommended },
        { category, o.category },
        { views, o.views },
        { downloads, o.downloads },
        { stars, o.stars },
    };
}
