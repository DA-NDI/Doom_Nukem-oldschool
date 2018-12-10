
# Doom_Nukem
Educational group project at 42 school, UnitFactory, Kyiv. C, graphical library SDL2. Doom like game

I was inspired by Kung_fury, some oldschool, doom, and duke nukem.

Some images i used are under copyright, no commercial interest was involved

You can shoot, jump, fly, crouch, sit, teleport, run, kill, die and so on

To compile and run programm in terminal:
```bash
make
./doom_nukem <level_number or your custom map name>
```
To run game, enter valid arguments, one of the valid levels

1 - 5 or map, created with map editor

Last level is labyrinth, its hard to escape,
even for guy who created it

For example to run level 1:
```bash
./doom_nukem 1
```
Some useful keys:

* `^ < > v` move player
* `l_shift` speed up 
* `1 2 3 4` change weapon
* `w e r` change skybox background
* `p` pause
* `space` jump
* `t` tv-mode (interlacing, thus fps increased * 2)
* `left_click` shoot
* `l_ctrl` sit
* `f` fly_mode
* `enter` interact with objects
* `z` remove wall black on level 3
* `g` on/off shadows (or press enter on light trigger)

To run map_editor:

```bash
cd map_editor
./map <grid_size> <-n for new map or -e for edit> <map name>
```

For example to create map 10x10 (another one option is 50x50) with filename rakamakafo:
```bash
./map 10 -n rakamakafo
```
 now you can go back to root folder and run your created map:
 
 ```bash
 cd ..
 ./doom_nukem rakamakafo
 ```
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/map_1.png)

## Have fun!

![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/1.jpg)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/3.png)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/6.png)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/7.png)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/8.png)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/11.png)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/gif_1.gif)
![alt text](https://github.com/DA-NDI/Doom_Nukem-oldschool/blob/master/screenshots/gif_2.gif)
## WOLF3d gif (older version of this game):
![alt text](https://github.com/DA-NDI/Wolf3d/blob/master/wolf1.gif)
