//
//  OreAPI.hpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#ifndef OreAPI_hpp
#define OreAPI_hpp

#include <string>
#include <stdexcept>
#include <memory>
#include <map>

#include "DataModel/Project.hpp"
#include "DataModel/Version.hpp"
#include "DataModel/Download.hpp"

namespace Services {
    
    using DataModel::Project;
    using DataModel::Version;
    using DataModel::Download;
    
    struct OreAPI {
        
        const std::string proto;
        const std::string host;
        
        OreAPI(const std::string &proto, const std::string &host);
        
        ~OreAPI();
        
        std::vector<Project> listProjects();
        
        std::shared_ptr<Project> getProject(const std::string &pluginId);
        
        std::shared_ptr<std::vector<Version>> getProjectVersions(const std::string &pluginId);
        
        std::shared_ptr<Version> getVersion(const std::string &pluginId, const std::string &versionName);
        
        std::shared_ptr<Download> downloadProjectVersion(const std::string &pluginId, const std::string &versionName);
        
        bool downloadFile(const std::string &url, const std::string &filename);
        
        std::string createUrl(const std::string &uri, std::map<std::string, std::string> arguments = {}) const;
        
    protected:
        
        static size_t writeMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
        
        static size_t writeFileCallback(void *ptr, size_t size, size_t nmemb, FILE *stream);
    };
}

#endif /* OreAPI_hpp */
