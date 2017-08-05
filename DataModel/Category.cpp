//
//  Category.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "Category.hpp"

namespace Keys {
    const std::string title = "title";
    const std::string icon = "icon";
}

void DataModel::from_json(const json &j, Category &o) {
    using namespace Keys;
    o.title = j[title];
    o.icon = j[icon];
}

void DataModel::to_json(json &j, const Category &o) {
    using namespace Keys;
    j = {
        { title, o.title },
        { icon, o.icon },
    };
}
