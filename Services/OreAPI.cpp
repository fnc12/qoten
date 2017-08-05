//
//  OreAPI.cpp
//  Qoten
//
//  Created by John Zakharov on 05.08.17.
//  Copyright © 2017 Outlaw. All rights reserved.
//

#include "OreAPI.hpp"

#include <curl/curl.h>
#include <sstream>

struct CurlCleaner {
    CURL *handle = nullptr;
    
    CurlCleaner(decltype(handle) h):handle(h){}
    
    ~CurlCleaner() {
        if(this->handle) {
            curl_easy_cleanup(this->handle);
            this->handle = nullptr;
        }
    }
};

struct FileCloser {
    FILE *handle = nullptr;
    
    FileCloser(decltype(handle) h):handle(h){}
    
    ~FileCloser(){
        if(this->handle){
            fclose(this->handle);
            this->handle = nullptr;
        }
    }
};

using namespace DataModel;

/*namespace Uri {
//    const std::string listProjects = "/api/projects";
    const std::string getProject = "/api/projects/";
}*/

Services::OreAPI::OreAPI(const std::string &proto_, const std::string &host_):proto(proto_),host(host_){
    
}

Services::OreAPI::~OreAPI() {
    
}

std::vector<Project> Services::OreAPI::listProjects() {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    auto url = this->createUrl("/api/projects");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    std::stringstream ss;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ss);
    auto res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        auto data = ss.str();
        auto j = json::parse(data);
        return j;
    }else{
        auto errorText = curl_easy_strerror(res);
        throw std::runtime_error(errorText);
    }
}

std::shared_ptr<Download> Services::OreAPI::downloadProjectVersion(const std::string &pluginId, const std::string &versionName) {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    auto url = this->createUrl("/api/projects/" + pluginId + "/versions/" + versionName + "/download");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    std::stringstream ss;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ss);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    auto res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if(http_code == 300) {
            auto data = ss.str();
            auto j = json::parse(data);
            return j;
        }else{
            return {};
        }
    }else{
        auto errorText = curl_easy_strerror(res);
        throw std::runtime_error(errorText);
    }
}

std::shared_ptr<Version> Services::OreAPI::getVersion(const std::string &pluginId, const std::string &versionName) {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    auto url = this->createUrl("/api/projects/" + pluginId + "/versions/" + versionName);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    std::stringstream ss;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ss);
    auto res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if(http_code == 200) {
            auto data = ss.str();
            auto j = json::parse(data);
            return j;
        }else{
            return {};
        }
    }else{
        auto errorText = curl_easy_strerror(res);
        throw std::runtime_error(errorText);
    }
}

bool Services::OreAPI::downloadFile(const std::string &url, const std::string &filename) {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFileCallback);
    if(auto fp = fopen(filename.c_str(), "wb")){
        FileCloser fileCloser(fp);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)fp);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        auto res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if(http_code == 200) {
                return true;
            }else{
                return false;
            }
        }else{
            auto errorText = curl_easy_strerror(res);
            throw std::runtime_error(errorText);
        }
//        fclose(fp);
        return true;
    }else{
        return false;
    }
}

size_t Services::OreAPI::writeFileCallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

std::shared_ptr<std::vector<Version>> Services::OreAPI::getProjectVersions(const std::string &pluginId) {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    auto url = this->createUrl("/api/projects/" + pluginId + "/versions");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    std::stringstream ss;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ss);
    auto res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if(http_code == 200) {
            auto data = ss.str();
            auto j = json::parse(data);
            return j;
        }else{
            return {};
        }
    }else{
        auto errorText = curl_easy_strerror(res);
        throw std::runtime_error(errorText);
    }
}

std::shared_ptr<Project> Services::OreAPI::getProject(const std::string &pluginId) {
    auto curl = curl_easy_init();
    CurlCleaner cleaner(curl);
    auto url = this->createUrl("/api/projects/" + pluginId);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
    std::stringstream ss;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&ss);
    auto res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if(http_code == 200) {
            auto data = ss.str();
            auto j = json::parse(data);
            return j;
        }else{
            return {};
        }
    }else{
        auto errorText = curl_easy_strerror(res);
        throw std::runtime_error(errorText);
    }
}

size_t Services::OreAPI::writeMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    auto &mem = *(std::stringstream *)userp;
    char dataString[realsize + 1];
    memcpy((void *)dataString, (const void *)contents, realsize);
    dataString[realsize] = '\0';
    mem << std::string(dataString);
    /*if(verboseOutput) {
        cout << "dataString = *" << dataString << "*" << endl;
        for(auto i = 0; i < realsize; ++i) {
            cout << "dataString[" << i << "] = " << int(dataString[i]) << endl;
        }
    }*/
    
    return realsize;
}

std::string Services::OreAPI::createUrl(const std::string &uri, std::map<std::string, std::string> arguments) const {
    auto res = this->proto + "://" + this->host + uri;
    if(arguments.size()) {
        std::stringstream ss;
        ss << "?";
        size_t i = 0;
        for(auto &p : arguments) {
            ss << p.first << "=" << p.second;
            if(i < arguments.size() - 1) {
                ss << "&";
            }
        }
        res += ss.str();
    }
    return res;
}
