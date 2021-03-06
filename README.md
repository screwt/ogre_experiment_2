# A Blender scene loader

Tool to load scene exported from blender with the blender2ogre export addon:

 * https://github.com/screwt/blender2ogre

## Roadmap

 - [x] : Load a simple scene exported from blender
 - [x] : Allow switching to camera defined in blender
 - [ ] : Allow multiple scene loading (switchable scene)
 - [ ] : Allow character loading from blender (Blender Custom attribute make it a character)
 - [ ] : Allow character controlling
 - [ ] : Add joypad support

## Startup calls graph
![call graph](https://raw.githubusercontent.com/screwt/ogre_experiment_2/develop/doc/media/uml_startup_calls.png)

## Setting up ogre2.1

https://forums.ogre3d.org/viewtopic.php?t=84572

Two links need to be made manualy:

 * %OGRE_GIT_ROOT%/Dependencies/inlude => %OGRE_GIT_ROOT%/Dependencies/build/ogredeps/include
 * %OGRE_GIT_ROOT%/Dependencies/lib => %OGRE_GIT_ROOT%/Dependencies/build/ogredeps/lib


### ogre deps

https://bitbucket.org/cabalistic/ogredeps/overview

Be sure to use: 
```
> hg clone https://bitbucket.org/cabalistic/ogredeps
```
A manual download wont work

### ogre sources

https://github.com/OGRECave/ogre

## Starting an Ogre3D 2.1 App

Don t forget the the tow links inlude & lib

https://ogrecave.github.io/ogre/api/2.1/UsingOgreInYourApp.html

