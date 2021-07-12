# Ultimate Spider-Man Debug menu for PC 

**Recreation** of the PS2 version's debug menu for the PC version.

## Download

Get the menu from [here](https://github.com/krystalgamer/usm-debug-menu/releases)

## Installation

* Rename `binkw32.dll` in the game's folder to `binkw32_.dll`
* Copy the `binkw32.dll` in the zip file to the game's folder

## Usage

* **INSERT** - opens and closes the menu
* **UP/DOWN Arrows** - moves the current select option up and down
* **ENTER** - executes the selected option
* **ESCAPE** - go to previous menu

## Current implemented options

### Warp

Allows to teleport to any in-game region

### Char Select

Allows to switch between *all* available characters

**NOTE**: `peter_parker` and `peter_hooded` are versions of peter without powers, used in the first missions of the game

## Extending functionality

If you desire to add any new option(s) to the menu, it's very simple.
`create_menu` is used to create a new menu.
`add_debug_menu_entry` is used to add entries to a menu.


## License

This project is MIT licensed
