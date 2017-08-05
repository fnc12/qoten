//
//  main.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "Services/OreAPI.hpp"

using std::cout;
using std::endl;

using namespace Services;

using nlohmann::json;

OreAPI api("https", "ore.spongepowered.org");

std::string getPluginFilename(const std::string &pluginId) {
    return "mods/" + pluginId + ".jar";
}

void printUsage() {
    cout << "qoten list - Returns a list of projects based on given criteria" << endl;
    cout << "qoten view $(pluginId) - Shows raw project info in JSON format" << endl;
    cout << "qoten versions $(pluginId) - Shows versions of plugin" << endl;
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::string> args;
    args.reserve(argc);
    for(auto i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    
    if(args.size() > 1){
        if(args[1] == "list") {
            auto projects = api.listProjects();
            cout << "projects count = " << projects.size() << endl;
            for(size_t i = 0; i < projects.size(); ++i) {
                auto &project = projects[i];
                cout << i << ") " << project.name << " ( pluginId: '" << project.pluginId << "')" << endl;
            }
        }else if(args[1] == "view") {
            if(args.size() > 2){
                auto &pluginId = args[2];
                if(auto project = api.getProject(pluginId)){
                    cout << json(*project).dump(4) << endl;
                }else{
                    cout << "Plugin with id '" << pluginId << "' not found :(" << endl;
                    return 1;
                }
            }else{
                cout << "pluginId expected right after 'view' word" << endl;
                return 1;
            }
        }else if(args[1] == "versions") {
            if(args.size() > 2) {
                auto &pluginId = args[2];
                if(auto versions = api.getProjectVersions(pluginId)){
                    cout << pluginId << " versions count = " << versions->size() << endl;
                    for(auto i = 0; i < versions->size(); ++i) {
                        auto &version = versions->at(i);
                        cout << i << ") " << version.name << ", url: " << api.createUrl(version.href) << endl;
                    }
                }else{
                    cout << "Plugin with id '" << pluginId << "' not found :(" << endl;
                    return 1;
                }
            }else{
                cout << "pluginId expected right after 'versions' word" << endl;
                return 1;
            }
        }else if(args[1] == "version") {
            if(args.size() > 2) {
                auto &pluginId = args[2];
                if(args.size() > 3) {
                    auto &versionName = args[3];
                    if(auto version = api.getVersion(pluginId, versionName)){
                        cout << json(version).dump(4) << endl;
                    }else{
                        cout << "Plugin with id '" << pluginId << "' not found or version with name '" << versionName << "' not found :(" << endl;
                        return 1;
                    }
                }else{
                    cout << "plusing version name expected right after plugin name" << endl;
                    return 1;
                }
            }else{
                cout << "pluginId expected right after 'version' word" << endl;
                return 1;
            }
        }else if(args[1] == "add") {
            if(args.size() > 2) {
                auto &pluginId = args[2];
                if(auto download = api.downloadProjectVersion(pluginId, "recommended")){
                    auto tempFilename =  getPluginFilename(pluginId);
                    if(api.downloadFile(download->post, tempFilename)){
//                        cout << "File downloaded!" << endl;
                        cout << "Plugin '" << pluginId << "' installed successfully!" << endl;
                    }else{
                        cout << "unable to download the file :(" << endl;
                    }
                }else{
                    cout << "Plugin with id '" << pluginId << "' not found :(" << endl;
                    return 1;
                }
            }else{
                cout << "pluginId expected right after 'add' word" << endl;
                return 1;
            }
        }else if(args[1] == "remove") {
            if(args.size() > 2) {
                auto &pluginId = args[2];
                auto filename = getPluginFilename(pluginId);
                ::remove(filename.c_str());
                cout << "Plugin '" << pluginId << "' removed." << endl;
            }else{
                cout << "pluginId expected right after 'add' word" << endl;
                return 1;
            }
        }
    }else{
        printUsage();
    }
    
    return 0;
}
