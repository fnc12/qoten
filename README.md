# qoten

Package manager for [Sponge minecraft server](https://www.spongepowered.org)

# Usage

`qoten` is a simple CLI tool that allows you to view plugins, search plugins, view versions, install and remove plugins from your sponge server.

```
qoten list - Returns a list of projects based on given criteria
qoten view $(pluginId) - Shows raw project info in JSON format
qoten versions $(pluginId) - Shows versions of plugin
qoten add $(pluginId) - Install recommended version of specified plugin into 'mods' dir
qoten remove $(pluginId) - Remove installed plugin from 'mods' dir
qoten search $(text) - Search for plugins
```

# Compilation

```c++
clang++ -std=c++11 -o qoten_ qoten/main.cpp qoten/DataModel/*.cpp qoten/Services/*.cpp -I qoten/ -I qoten/libs/ -lcurl
```

Next rename `qoten_` to `qoten` and move to a place where you will be able to call it from just like any CLI command.
