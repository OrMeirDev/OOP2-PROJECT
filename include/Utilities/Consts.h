#pragma once 

#include <string>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 680;
const int MARGIN = 100;

const int BIRD_OBJECT_SPEED = 250;
const int SQUARE_BATMAN_SPEED = 150;
const int SQUARE_EAGLE_SPEED = 100;
const float FLYING_OBJECT_GRAVITY = 0;
const float GRAVITY = 1.3;
const int EFFECT_TIME = 3;
const int INITIAL_COINS_NUMBER = 0;
const int BLOCK_OFFSET = 60;
const int BIRD_OFFSET = 60;

const int VIEWXMARGIN = 100 - WINDOW_WIDTH / 2;


const float DARKNESS_ANIMATION_START_VAL = 730.f;
const float DARKNESS_ANIMATION_END_VAL = 270.f;

const int LIVES = 3;

const int YBORDER = 590;

const float HEIGHT = 500;
const int JUMPHEIGHT = 70;
const int TOP_HEIGHT = 72 + 85;

const int TEXTURESIZE = 32;
const int FONTSINZE = 30;

const int COIN_SCORE = 5;


// ============ Textures ============

const std::string NEWGAME_TEXTURE = "startbutton.png";
const std::string HELP_TEXTURE = "helpbutton.png";
const std::string EXIT_TEXTURE = "exitbutton.png";
const std::string BACKGROUND_TEXTURE = "background.png";
const std::string FREEZE_TEXTURE = "freezepresent.png";
const std::string LIFE_TEXTURE = "lifepresent.png";
const std::string HELPSCREEN_TEXTURE = "helpscreen.png";
const std::string ENDGAME_TEXTURE = "endgame.png";
const std::string BACKTOMENU_TEXTURE = "backtomenu.png";
const std::string PARALLAX_TEXTURE = "parallax.png";
const std::string FLOOR_TEXTURE = "floor.png";
const std::string BIRD_TEXTURE = "squarebird.png";
const std::string BLOCK_TEXTURE = "block.png";
const std::string WALL_TEXTURE = "wall.png";
const std::string COIN_TEXTURE = "coin.png";
const std::string SNAKE_TEXTURE = "snake.png";
const std::string GAMEOVER_TEXTURE = "gameoverscreen.png";
const std::string CEILING_TEXTURE = "ceiling.png";
const std::string HOUSE_TEXTURE = "house.png";
const std::string DARKNESS_TEXTURE = "darknesstrap.png";
const std::string MAGNIFIER_TEXTURE = "magnifiertrap.png";
const std::string ENLARGED_BIRD_TEXTURE = "enlargedBird.png";
const std::string DISTANCE_TEXTURE = "distance.png";
const std::string LIVES_TEXTURE = "lives.png";
const std::string COIN2_TEXTURE = "coin2.png";
const std::string FONT = "font.ttf";
const std::string SQUAREBATMAN_TEXTURE = "squarebatman.png";
const std::string CEILINGSPIKES_TEXTURE = "ceilingspikes.png";
const std::string FLOORSPIKES_TEXTURE = "floorspikes.png";
const std::string SQUAREEAGLE_TEXTURE = "squareeagle.png";
const std::string WINNER_TEXTURE = "winnerscreen.png";
const std::string GHOST_SQUAREBIRD_TEXTURE = "GhostSquareBird.png";
const std::string GHOST_POWERUP_TEXTURE = "ghostpowerup.png";

// ============ Sounds ================
const std::string COIN_SOUND = "coinsound.ogg";
const std::string BLOCK_SOUND = "blocksound.ogg";
const std::string FAIL_SOUND = "failsound.ogg";
const std::string MENU_SOUND = "menusound.ogg";
const std::string POPBLOCK_SOUND = "popblocksound.ogg";
const std::string ENLARGE_SOUND = "enlargesound.ogg";
const std::string GHOST_SOUND = "ghostsound.ogg";
const std::string DARKNESS_SOUND = "darknesssound.ogg";




enum GameObjectNumber {
	BIRD,
	FLOOR,
	WALL,
	COIN,
	SNAKE,
	CEILING,
	HOUSE,
	DARKNESSTRAP,
	MAGNIFIERTRAP,
	SQUAREBATMAN,
	CEILINGSPIKES,
	FLOORSPIKES,
	SQUAREEAGLE,
	GHOSTPOWERUP
};