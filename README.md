[![license](https://img.shields.io/github/license/npruehs/ue4-rts.svg?maxAge=2592000)](https://github.com/npruehs/ue4-rts/blob/develop/LICENSE)

# Real-Time Strategy Plugin for Unreal Engine 4

Open-Source Real-Time Strategy Plugin for Unreal Engine 4 developed by the original creators of [Hostile Worlds](http://www.indiedb.com/games/hostile-worlds/) for Unreal Engine 3.

We really love the spirit of Unreal 4 moving to open-source, and we'd love to give something back.

Note that we're still in heavy development. Some things are already in place, such as

* Camera Movement & Bounds
* Initial Unit Placement
* Single- and Multi-Unit Selection
* Movement Orders
* Stop Orders
* Attack Orders
* Health, Damage (and Healing), Cooldown, Range
* Victory Conditions
* Projectiles
* Unit Target Acquisition
* Control Groups
* Health Bars
* Minimap
* Teams
* Constructions
* Unit Production/Tech Research
* Resource Gathering
* Fog of War

All of this is already completely working in multiplayer as well, and has been fully exposed to scripting, enabling you to update UI and play animations and sounds.

We're going to add all of this to the Unreal Marketplace for free as well soon (tm).

For a quick look, just open RTSSampleGame/Maps/RTSGameSampleMap.umap in the editor and hit Play. We recommend taking a closer look at that map as reference for your own ones as well.

## Adding The Plugin

Note that the plugin currently requires a C++ Unreal project, which in turn requires a working compiler.

1. Clone the repository.
1. Close the Unreal Editor.
1. Copy the RTSPlugin folder to Plugins folder next to your .uproject file.
1. Right-click your .uproject file and select Re-generate Visual Studio project files.
1. Build the resulting solution in Visual Studio.
1. Start the Unreal Editor.
1. Enable the plugin in Edit > Plugins > RTS.

## Bugs & Feature Requests

We are sorry that you've experienced issues or are missing a feature! After verifying that you are using the latest version and having checked whether a [similar issue](https://github.com/npruehs/ue4-rts/issues) has already been reported, feel free to [open a new issue](https://github.com/npruehs/ue4-rts/issues/new). In order to help us resolving your problem as fast as possible, please include the following details in your report:

* Steps to reproduce
* What happened?
* What did you expect to happen?

After being able to reproduce the issue, we'll look into fixing it immediately.


## Contributing

You'd like to help make this plugin even more awesome? Seems like today's our lucky day! In order to maintain stability of the tool and its code base, please adhere to the following steps, and we'll be pleased to include your additions in our next release.

Note that this plugin is distributed under the [MIT License](https://github.com/npruehs/ue4-rts/blob/develop/LICENSE). So will be your code.

### Step 1: Choose what to do

If you've got no idea how to help, head over to our [issue tracker](https://github.com/npruehs/ue4-rts/issues) and see what you'd like to do most. You can basically pick anything you want to, as long as it's not already assigned to anyone.

If you know exactly what you're missing, [open a new issue](https://github.com/npruehs/ue4-rts/issues/new) to begin a short discussion about your idea and how it fits the project. If we all agree, you're good to go!

### Step 2: Fork the project and check out the code

Real-Time Strategy Plugin for Unreal Engine 4 is developed using the [GitFlow branching model](http://nvie.com/posts/a-successful-git-branching-model/). In order to contribute, you should check out the latest develop branch, and create a new feature or hotfix branch to be merged back.

### Step 3: Implement your feature or bugfix

Real-Time Strategy Plugin for Unreal Engine 4 is based on [Unreal Engine 4.16.1](https://www.unrealengine.com/).

### Step 4: Open a pull request

Finally, [open a pull request](https://help.github.com/articles/creating-a-pull-request/) so we can review your changes together, and finally integrate it into the next release.


## License

Real-Time Strategy Plugin for Unreal Engine 4 is dual-licensed:

* everything beneath Source\RTS\Content\StarterContent is governed by the [Unreal® Engine End User License Agreement](https://www.unrealengine.com/eula) 
* everything else is released under the [MIT License](https://github.com/npruehs/ue4-rts/blob/develop/LICENSE)
