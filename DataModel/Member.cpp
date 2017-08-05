//
//  Member.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Member.hpp"

namespace Keys {
    const std::string userId = "userId";
    const std::string name = "name";
    const std::string roles = "roles";
    const std::string headRole = "headRole";
}

void DataModel::from_json(const json &j, Member &o) {
    using namespace Keys;
    o.userId = j[userId];
    o.name = j[name];
    o.roles = j[roles].get<decltype(o.roles)>();
    o.headRole = j[headRole];
}

void DataModel::to_json(json &j, const Member &o) {
    using namespace Keys;
    j = {
        { userId, o.userId },
        { name, o.name },
        { roles, o.roles },
        { headRole, o.headRole },
    };
}
