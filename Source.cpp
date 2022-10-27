#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#define RED 1
#define BLUE 2 //int BulletType =1 , =2 , =3
#define GREEN 3
#define Out 999999

using namespace sf;
using namespace std;
const int Max_Menu = 50;

int UpOrDown = 1;//Aya
float endtimer = 0;//Eiad
float timero5 = 0;
float timero;
int chickenscore = 0;//Eiad
bool chick[33] = {};//Eiad
bool KeyPressed = 0;//Aya
bool Player2On = 0;//Paula
bool Escapebool = 0;//Aya
bool TableEnter = 0;
bool P_Pressed = 0;
short EnterYourNamebool = 0;
short GameOverbool = 0;
int EggCollision = 48;//Eiad
int FireLoop = 10;//Paula
int FireLoop2 = 10;
int ChicksCounter1 = 0, ChicksCounter2 = 0;
int ChickBegin = 1, ChickEnd = 32;
//			Anas    Anas    Paula            Aya          	
sf::Text Lifes, Lifes2, PowerText, PowerText2, ChicksText, ChicksText2, Score, AinShams, _MainMenu[Max_Menu],
SoundMenu,//Aya
MusicMenu;

RenderWindow window(VideoMode(1024, 768), "Chicken Invaders");

float CutSceneMenuMove = 0,//Paula
CutSceneGameMove = 0,
CutSceneGameTimer = 0,
WinTimer = 0;//Paula
bool WinBool = 0;
bool FlyingBool = 0;

//Constant
const float MovementSpeed = 0.3;
//Variables
float BossHealth = 100;//Eiad
float  alien_Health[50] = { 0 };//Eiad
float chicken_Health[100] = { 0 };//Eiad
float Rock_Health[100] = { 0 };//Eiad
float PowerTimer = 0;//Paula
float PowerTimer2 = 0;//Paula
float Player2TextTimer = 0;//Paula
float BackgroundSpeed = 2;//Paula

bool REDPowerTimerbool = 0;//Paula
bool BLUEPowerTimerbool = 0;//Paula
bool GREENPowerTimerbool = 0;//Paula
bool REDPowerTimerbool2 = 0;//Paula
bool BLUEPowerTimerbool2 = 0;//Paula
bool AtomPowerTimerbool = 0;//Paula
bool AtomPowerTimerbool2 = 0;//Paula
bool GREENPowerTimerbool2 = 0;//Paula
bool Winning = 0;//Paula

int xPlayer = 0, yPlayer = 0, xEnemy = 0, //Animation  //Paula
xPlayer2 = 0, yPlayer2 = 0,//Animation //Paula
MenuBackground_Loop = 0, //BackgroundMovement //Paula
WavesBackground_Loop = 0, //BackgroundMovement //Paula
PlayerPower = 1,//Paula
WavePosition = 1,//Paula
FireNumber = 1,//Paula
FireNumber2 = 1,//Paula
DeathNumber = 0,//Paula
SmokeStop[500] = {},//Paula
xDeath = 0, yDeath = 0,//Paula
xDeath2 = 0, yDeath2 = 0,//Paula
ViewPort,//Eiad
ScoreNumber = 0, //Anas
TotalScore = 0,//Anas
TargetScore = 50000,//Anas
LifePlayer1 = 3,//Anas
LifePlayer2 = 0,//Anas
ScorePosition = 10,
xScore = 50,

TotalChar = 0,
Waves = 0,
chickmove[200],
stoneNumber[70],
xmovestones[70],
ymovestones[70],
xStones[100] = {},
yStones[100] = {},

//Anton
StonesSpeed = 1 + rand() % 10,
StonesNumber = 1 + rand() % 60,
StonesRandom = 1 + rand() % 200,
Wave1Random = 1 + rand() % 32, //Wave 1
Wave1Random2 = 1 + rand() % 32, //Wave 1
Wave2Random = 33 + rand() % 16, //Wave 2
Wave3Random = 1 + rand() % 60, // Wave 3 Stones
Wave4Random = 1 + rand() % 15, // Wave 3 Stones

Gifts1Random = 1 + rand() % 4,
Gifts2Random = 1 + rand() % 4,
Gifts3Random = 1 + rand() % 4,
Gifts4Random = 1 + rand() % 4,
AtomsRandom = 1 + rand() % 4,

MealRandom1 = 1 + rand() % 16,
MealRandom2 = 17 + rand() % 16,
powerchick = 0,
powerchick2 = 0,
PowerLevel = 0,
PowerLevel2 = 0,
PowerType = BLUE,
PowerType2 = BLUE,
ActScore = 0,
xAtoms[50]{},
xAliens = 0;

string NameSave;


bool
Fire = 0,
Fire2 = 0,//timing fire for sound
Intro = 1,
Level1Theme = 0,
Level2Theme = 0,
BossThemebool = 0,
EnemyLastMove = 0,
Action = 0,
Deathbool[500],
PlayerDeathbool = 0,
PlayerDeathbool2 = 0,
PowerStop = 0,
PowerStop2 = 0,
DeathAnimation = 0,
DeathAnimation2 = 0,
WavesDeath[20 + 1] = {},
SoundGame = 1,
MusicGame = 1,
ShieldBool = 0,
ShieldBool2 = 0;

float MenuView_Number = 0, //for moving view with MenuBackground_Loop
Speed = 0,
Speed2 = 0,
WavesView_Number = 0,
xaxis = 0,
xaxis2 = 0,
Left = 0,//for animation when you move back to your main position
FireTimer = 0.1, //for every bullet get out from the player
FireTimer2 = 0.1, //for every bullet get out from the player
EnemyAnimationTimer = 0.01,
EnemySpeed = 6,
EnemySpeed2 = 6,
Actionesta1 = 1,
Actionesta2 = 1,
Actionesta3 = 1,
Actionesta4 = 1,
xSmoke[500] = {},
ySmoke[500] = {},
SmokeTimer = 0.1,
ShakeReverse = 1.5,
ShakeReverse2 = 1.5,
ShakeTimer = 2,
ShakeTimer2 = 2,
ShakeSpeed = 0.3,
ShakeSpeed2 = 0.3,
DeathTimer = 0.1,
DeathTimer2 = 0.1,
ScoreTimer = 0.1,
TextTimer = 0.1,
StonesTImer[50] = { 0.1 },
ShieldTimer = 0,
ShieldTimer2 = 0,
PlayerRecovery = 0,
PlayerRecovery2 = 0,
AliensTimer = 0,
WaveTimer = 0;

//View

View MenuView, WavesView;

//Sound
SoundBuffer
_REDFireSound,
_BLUEFireSound,
_ChickEat,
_EggSound,
_TakenGift,
_EnemyDeadSound,
_PlayerDeadSound,
_BossDeadSound,
_IntroMenu,
_Level1,
_Level2,
_BossTheme,
_WinMusic,
_GameOverMusic,
_Flying,
_SelectMenu,
_Enter,
_Escape,
_GREENFireSound,
_AlienShot,
_OneUp;

//Paula
Sound
REDFireSound,
BLUEFireSound,
GREENFireSound,
REDFireSound2,
BLUEFireSound2,
GREENFireSound2,
ChickEat,
ChickEat2,
EggSound,
TakenGift,
TakenGift2,
EnemyDeadSound,
PlayerDeadSound,
Player2DeadSound,
BossDeadSound,
IntroMenu,
Level1,
Level2,
BossTheme,
WinMusic,
GameOverMusic,
Flying,
SelectMenu,
EnterMenu,
EscapeMenu,
AlienShot,
AlienShots[20],
OneUp;


//	Texture	

Texture
_Background,
_Player,
_Player2,
_Enemy,
_Enemy2,
_Menu,
_REDFireBullet,
_Egg,
_EggBreak,
_TopBar,
_BottomBar,
_Lazer,
_REDGift,
_GREENGift_,
_BLUEGift,
_Smoke,
_PlayerDeath,
_Stones,
_Sign,
_REDGifts,
_BLUEGifts,
_GREENGifts,
_Shield,
_Atom,
_Alien,
_BLUEFireBullet,
_GREENFireBullet,
_AlienFIre,
_BossEnemy,
_AlienBullet,
_Chick,
_Meal,
_CutScene;


Font _Score, font,
font2, _Lifes;

//Main
int SelectionMenu = 0;

bool SoundOn = 1, MusicOn = 1;
Text Number[11];
string Playerinput;
Text PlayerName;
bool LeaderBoardMenu = 0;
Text text1;
Text text2;
Text text;
Text Player2Text,
QuitBack,
ResumeBack,
MuteBack;
Text GameOver;

float PowerSpeed = 3.4;
float PowerScale[1000 + 9] = { 1 };
int BLUEScale = 0;
int BLUEScale2 = 0;







//




	//CREDit
bool CREDitsbool = 1;
int TextStop = 768;
//Font font;


//
short Enter = 0;

RectangleShape Rec(Vector2f(2000, 20)),
BlackScreen(Vector2f(500, 1000)),
BlackScreen2(Vector2f(500, 1000)),
AlienBulletsBox[20];

RectangleShape BossHealthBorder(Vector2f(500, 45)),
BossHealthBar(Vector2f(500 * BossHealth / 100, 20));

RectangleShape FireBar(Vector2f(5, 30)),
FireBars[30];
RectangleShape FireBar2(Vector2f(5, 30)),
FireBars2[30];
bool FireBarsbool[30];
bool FireBarsbool2[30];
int BarCounter = 0;
int BarCounter2 = 0;
float BarTimer = 0;
float BarTimer2 = 0;
float GameOverTimer = 0;
Texture
_MenuSets,
_Quit,
_ClickMenuSets,
_Fork,
_Fork2;




RectangleShape PlayerBox(Vector2f(37, 37));
RectangleShape PlayerBox2(Vector2f(37, 37));
RectangleShape EnemyBox(Vector2f(68, 37));
RectangleShape EnemiesBox[500];
RectangleShape BossBox;
RectangleShape BossBox2;
RectangleShape BossBox3;
RectangleShape AliensBox[500];
RectangleShape RectangleSound;
RectangleShape RectangleMusic;



//Fonts


//Functions    

//
String AinShamsText = "Ain Shams";
int AinShamsCounter = 0;
float AinShamsTimer = 0.1;





Sprite Start(_MenuSets, IntRect(0, 0, 462, 68)),
Load(_MenuSets, IntRect(0, 0, 462, 68)),
Table(_MenuSets, IntRect(0, 0, 462, 68)),
Options(_MenuSets, IntRect(0, 0, 462, 68)),
CREDits(_MenuSets, IntRect(0, 0, 462, 68)),
Fork(_Fork, IntRect(0, 0, 40, 52)),
Fork2(_Fork2, IntRect(0, 0, 40, 50)),
Quit(_Quit, IntRect(0, 0, 462, 68)),
ClickStart(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickLoad(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickTable(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickOptions(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickCREDits(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickQuit(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickResumeBack(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickQuitBack(_ClickMenuSets, IntRect(0, 0, 500, 500)),
ClickMuteBack(_ClickMenuSets, IntRect(0, 0, 500, 500)),
SignMute(_Sign, IntRect(0, 0, 518, 482)),
OvalResume(_MenuSets, IntRect(0, 0, 462, 68)),
OvalQuit(_MenuSets, IntRect(0, 0, 462, 68)),
OvalMute(_MenuSets, IntRect(0, 0, 462, 68));
//{





//}
//Menu



RectangleShape StartBox(Vector2f(180, 40));//Menu
RectangleShape LoadBox(Vector2f(180, 40));//Menu
RectangleShape Escape(Vector2f(600, 400));
RectangleShape ResumeBackBox(Vector2f(230, 40));
RectangleShape QuitBackBox(Vector2f(230, 40));
RectangleShape MuteBackBox(Vector2f(80, 40));


//table



RectangleShape TableBox(Vector2f(180, 40));//Menu
RectangleShape OptionsBox(Vector2f(180, 40));//Menu
RectangleShape CREDitsBox(Vector2f(180, 40));//Menu
RectangleShape QuitBox(Vector2f(100, 40));//Menu


//Definition
//Definition

//Sprites
Sprite
Player(_Player, IntRect(xPlayer * 160.625, yPlayer * 165, 160.625, 165)),
Player2(_Player2, IntRect(xPlayer2 * 160.625, yPlayer2 * 165, 160.625, 165)),
Enemy(_Enemy, IntRect(0, 0, 46, 38)),
Enemy2(_Enemy2, IntRect(0, 0, 46, 38)), //IntRect for definition
BossEnemy(_BossEnemy, IntRect(0, 0, 3752 / 10, 304)),
Background1(_Background, IntRect(0, 0, 1024, 1024)),
Background2(_Background, IntRect(0, 0, 1024, 1024)),
Background3(_Background, IntRect(0, 0, 1024, 1024)),
Background4(_Background, IntRect(0, 0, 1024, 1024)),
Background5(_Background, IntRect(0, 0, 1024, 1024)),
Menu(_Menu, IntRect(0, 0, 800, 308)),
REDFireBullet(_REDFireBullet, IntRect(0, 0, 117, 418)),
Egg(_Egg, IntRect(0, 0, 10, 12)),
EggBreak(_EggBreak, IntRect(0, 0, 28, 24)),
BottomBar(_BottomBar, IntRect(0, 0, 306, 68)),
BottomBar2(_BottomBar, IntRect(0, 0, 306, 68)),
TopBar(_TopBar, IntRect(0, 0, 405, 57)),
TopBar2(_TopBar, IntRect(0, 0, 405, 57)),
Lazer(_Lazer, IntRect(0, 0, 300 / 3, 200)),
Smoke(_Smoke, IntRect(0, 0, 4000 / 12, 300)),
PlayerDeath(_PlayerDeath, IntRect(0, 0, 773 / 8, 272 / 3)),
PlayerDeath2(_PlayerDeath, IntRect(0, 0, 773 / 8, 272 / 3)),
Stone(_Stones, IntRect(0, 0, 62.625, 62.25)),
SignSound(_Sign, IntRect(0, 0, 518, 482)),
SoundSelection(_Sign, IntRect(0, 0, 518, 482)),
SignMusic(_Sign, IntRect(0, 0, 518, 482)),
MusicSelection(_Sign, IntRect(0, 0, 518, 482)),
Sign30(_Sign, IntRect(0, 0, 518, 482)),
Sign60(_Sign, IntRect(0, 0, 518, 482)),
Sign120(_Sign, IntRect(0, 0, 518, 482)),
REDGift(_REDGifts, IntRect(0, 0, 51, 59)),
BLUEGift(_BLUEGifts, IntRect(0, 0, 51, 59)),
GREENGift(_GREENGifts, IntRect(0, 0, 51, 59)),
Shield(_Shield, IntRect(0, 0, 556, 556)),
Shield2(_Shield, IntRect(0, 0, 556, 556)),
Atom(_Atom, IntRect(0, 0, 44, 37)),
Alien(_Alien, IntRect(0, 0, 176, 121)),
BLUEFireBullet(_BLUEFireBullet, IntRect(0, 0, 407, 614)),
GREENFireBullet(_GREENFireBullet, IntRect(0, 0, 42, 192)),
AlienBullet(_AlienBullet, IntRect(0, 0, 138, 51)),
Chick(_Chick, IntRect(0, 0, 408, 351)),
Meal(_Meal, IntRect(0, 0, 509, 280)),
CutSceneMenu(_CutScene, IntRect(0, 0, 3000, 3000)),
CutSceneGame(_CutScene, IntRect(0, 0, 3000, 3000));

//array
Sprite  Enemies[100 + 9],
REDFireBullets[100 + 9],
REDFireBullets2[100 + 9],
BLUEFireBullets[100 + 9],
BLUEFireBullets2[100 + 9],
GREENFireBullets[100 + 9],
GREENFireBullets2[100 + 9],
Eggs[200],
Smokes[500],
Stones[200],
REDGifts[200],
BLUEGifts[200],
GREENGifts[200],
Atoms[200],
Aliens[200],
AlienBullets[20],
Chicks[200],
Meals[200];





//

float testTimer = 0.0001;
float BossTimer = 0;

int EggNumber = 1 + rand() % 32;
int BossMoveX = -4 + rand() % 9;
int BossMoveY = -4 + rand() % 9;

//BackgroundMove



int Rotation_1 = 90;
int Rotation_2 = 90;
int Rotation_3 = -90;
int Rotation_4 = -90;
//Beshoy
int DeathExtra[10];
bool Extra[10];
bool ForkClick = 0;


//Aya
string HelloTest = "YES WE CAN";


Text Test10, Test11, Test12, Test13, nwave1;

Text Test6, Test7, nwave3;
Text Test3, Test4, Test5, nwave4;
Text Test, Test1, Test2, nwave5;

float TextCounter10 = 0, TextCounter11 = 0, TextCounter12 = 0, TextCounter13 = 0, TextCounter14 = 0, nwavecounter1 = 0;
string HelloTest1 = "LETS START THE ADVENTURE";
string Hello1 = "Wave 1";
Text Test8, Test9, nwave2;
float TextCounter8 = 0, TextCounter9 = 0, nwavecounter2 = 0;
string HelloTest2 = "WELL PLAYED";
string Hello2 = "Wave 2";

string HelloTest3 = "KEEP GOING";
string Hello3 = "Wave 3";
string HelloTest4 = "NEVER GIVE UP";
string Hello4 = "Wave 4";
string HelloTest5 = "YES WE CAN";
string Hello5 = "Wave 5";

string GG = "Game Over";

float TextCounter = 0, TextCounter1 = 0, TextCounter2 = 0, nwavecounter5 = 0;
float TextCounter3 = 0, TextCounter4 = 0, TextCounter5 = 0, nwavecounter4 = 0;
float TextCounter6 = 0, TextCounter7 = 0, nwavecounter3 = 0;


int Rotation = 90;
int Rotation2 = -90;


//Struct
//Bishoy
struct info { // LeaderBoard
	string name = "---";
	int level = 0;
	int score = 0;
	Text nameT, scoreT, levelsT;
}table[100], User[100], user;


//
//Bishoy

struct save_progress {//SaveProgress
	int WavesProgress;
	int PowerTypeProgress;
	int PowerLevelProgress;

	int PlayerHealthProgress;
	string LoadName;
};








//Bishoy
void save(info& user);
//Bishoy
bool compare(info& a, info& b);


void Definition(),//Loadfromfile //Paula
Settings(),//sets //Paula
TextGame(),//Score , Waves , //Anas + Asmaa
BackgroundMenu(),//Paula
BackgroundGame(),//Paula
PlayerMovement(),//Paula
PlayerMovement2(),//Paula
PlayerAnimation(),//Paula
PlayerAnimation2(),//Paula
EnemyMovement(),//Paula
EnemyAnimation(),//Paula
Power(),//Paula+Eiad
Power2(),//Paula+Eiad
Action1(),//Paula
Action2(),//Paula
Action4(),//Paula
Action5(),//Paula
ChickenEgg(),//Paula+Anton
PlayerDead(),//Paula
PlayerDead2(),//Paula
DeadAnimation(),//Paula
DeadAnimation2(),//Paula
ShieldFunction(),//Paula
Collision(),//Eiad
Wave1(),//Paula
Wave2(),//Paula
Wave2Extra(),//Paula
Action2Extra(),//Paula
Wave3(),//Paula
Wave4(),//Paula
Wave5(),//Paula
Gifts1(),//Anton
Gifts2(),//Anton
Gifts3(),//Anton
Gifts4(),//Anton
GiftsMovement(),//Anton
ChickMovement(),//Eyad
Life(),//Anas
Default();//Paula
int
System();//Anas
//Main


RectangleShape EndGame(Vector2f(700, 300));
Sprite OvalName(_MenuSets);
Text Name;




void main()
{
	//BossEnemy.setPosition(200, 200);


	Image Icon;//Icon
	Icon.loadFromFile("ChickenIcon.png");
	window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

	window.setMouseCursorVisible(false);//Aya
	save_progress data;
	ofstream file; ifstream otherFile;
	Definition();//Paula
	Settings();//Paula


			   //Eiad
	for (int i = 1; i <= 60; i++) {
		stoneNumber[i] = 1 + rand() % 60;
		xmovestones[i] = 1 + rand() % 5;
		ymovestones[i] = 1 + rand() % 3;
		chickmove[i] = -5 + rand() % 10;
	}
	for (int i = 61; i <= 102; i++) {
		chickmove[i] = -5 + rand() % 10;
	}

	while (window.isOpen())
	{

		window.setFramerateLimit(60); //FPS
		//cout << ViewPort << endl;

		//Event
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

			//Paula
			if (Fork.getGlobalBounds().intersects(SignSound.getGlobalBounds())) {
				SignSound.setColor(Color::White);
				if (Mouse::isButtonPressed(Mouse::Button::Left))
					if (SoundOn)
						SoundOn = 0;
					else
						SoundOn = 1;

			}

			else
				//Aya
				SignSound.setColor(Color(25, 25, 112, 150));
			//Aya
			if (Fork.getGlobalBounds().intersects(MuteBackBox.getGlobalBounds())) {
				if (Mouse::isButtonPressed(Mouse::Button::Left)) {

					if (SoundOn) {
						SoundOn = 0;
						MusicOn = 0;
						Level1.pause();
						BossTheme.pause();
					}
					else {
						SoundOn = 1;
						MusicOn = 1;
						if (Waves < 5)
							Level1.play();
						else
							BossTheme.play();
					}
				}
			}
			//Aya
			if (Fork.getGlobalBounds().intersects(SignMusic.getGlobalBounds())) {

				SignMusic.setColor(Color::White);

				if (Mouse::isButtonPressed(Mouse::Button::Left))

					if (MusicOn) {
						MusicOn = 0;
						IntroMenu.pause();
					}

					else
					{
						MusicOn = 1;
						IntroMenu.play();
					}
			}

			else
				//Aya
				SignMusic.setColor(Color(25, 25, 112, 150));

			{


				//Paula
				if (EnterYourNamebool == 1) {
					switch (event.type)
			case sf::Event::TextEntered:
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter) && Playerinput.size() > 2) {// char+"\0"
					//cout << Playerinput << endl;
					Enter = 1;
					if (SoundOn)
						EnterMenu.play();
					//data.NameProgress = Playerinput; Sedra
					SelectionMenu = 1;
					EnterYourNamebool = 2;
					//SelectionMenu = 1;
					Default();
					IntroMenu.stop();
					if (MusicOn) {
						Level1Theme = 1;
						BossThemebool = 1;
					}



				}
				else if (!Enter) {
					if (event.text.unicode < 128 && !Keyboard::isKeyPressed(Keyboard::Key::BackSpace) &&
						!Keyboard::isKeyPressed(Keyboard::Key::Escape))
					{
						if (Playerinput.size() < 18)
						{
							Playerinput += event.text.unicode;
							PlayerName.setString(Playerinput);
						}
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && !Playerinput.empty())
					{
						Playerinput.pop_back();
						PlayerName.setString(Playerinput);
					}
				}
				}
			}
		}




		//Background

		//Menu
		if (SelectionMenu == 0) {//menu
			CutSceneMenu.setOrigin(100, 100);
			CutSceneMenu.setScale(1 + CutSceneMenuMove, 1 + CutSceneMenuMove);
			CutSceneMenu.move(-6.7 * 4, -6.8 * 4);
			CutSceneMenuMove += 0.01 * 2;
			if (Intro == 1 && MusicOn)
			{
				IntroMenu.play();
				Intro = 0;
				if (IntroMenu.Stopped() && MusicOn)
					Intro = 1;
			}

			//


			//Paula
			if (MenuBackground_Loop >= MenuView_Number) {
				Background1.setPosition(0, MenuBackground_Loop);
				Background2.setPosition(0, MenuBackground_Loop - 1008);  //2BackGrounds
				MenuBackground_Loop -= 1008;
			}

			//



			Fork.setPosition(Mouse::getPosition().x - 500, Mouse::getPosition().y + MenuView_Number - 100); //Mouse


			BackgroundMenu();//Movement
				//window.setMouseCursorVisible(true);


				//window.setMouseCursorVisible(false);


			Event event;



			/*	if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					cout << "x: " << H.getPosition().x << endl;
					cout << "y: " << Fork.getPosition().y << endl;
				}*/



			window.setView(MenuView);
			window.clear();
			window.draw(Background1);//
			window.draw(Background2);//
			window.draw(Menu);
			window.draw(AinShams);
			window.draw(Start);
			window.draw(Load);
			window.draw(Table);
			window.draw(Options);
			window.draw(CREDits);
			window.draw(Quit);
			window.draw(CutSceneMenu);
			TextGame();
			/*	window.draw(StartBox);
				window.draw(TableBox);
				window.draw(OptionsBox);
				window.draw(CREDitsBox);
				window.draw(QuitBox);*/



				//window.draw(ClickStart);


				//Menu Draw
			for (int item = 0; item < Max_Menu; item++) 	//Menu Draw
			{
				window.draw(_MainMenu[item]);	//Menu Draw
			}
			window.draw(Fork);	//Menu Draw

			//Aya
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) { //MenuDraw and Selecting
				if (KeyPressed == 0) {
					UpOrDown++;
					if (SoundOn)
						SelectMenu.play();
				}
				if (UpOrDown > 6)
					UpOrDown = 1;//MenuDraw and Selecting
				KeyPressed = 1;

			}
			else
				if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
					if (KeyPressed == 0) {
						UpOrDown--;//MenuDraw and Selecting
						if (SoundOn)
							SelectMenu.play();
					}
					if (UpOrDown < 1)
						UpOrDown = 6;//MenuDraw and Selecting
					KeyPressed = 1;

				}
				else
					KeyPressed = 0;


			if (Fork.getGlobalBounds().intersects(StartBox.getGlobalBounds())) {
				PlayerName.setString("");
				Playerinput = "";
				Default();
				window.draw(ClickStart);//MenuDraw and Selecting

				UpOrDown = 1;
				for (int i = 0; i < Max_Menu; i++)
				{


					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else//MenuDraw and Selecting
						_MainMenu[i].setFillColor(Color(147, 112, 219));

				}

				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					Default();

					EnterYourNamebool = 1;
				}

			}//MenuDraw and Selecting

			else if (Fork.getGlobalBounds().intersects(LoadBox.getGlobalBounds())) {
				window.draw(ClickLoad);//MenuDraw and Selecting

				UpOrDown = 2;
				for (int i = 0; i < Max_Menu; i++)
				{


					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else//MenuDraw and Selecting
						_MainMenu[i].setFillColor(Color(147, 112, 219));
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{

						Default();

						if (SoundOn)
							EnterMenu.play();
						BossHealth = 100;
						SelectionMenu = 2;
						otherFile.open("progress.txt");
						otherFile >> data.WavesProgress >> data.PowerTypeProgress >>
							data.PowerLevelProgress >> data.PlayerHealthProgress;
						otherFile.close();
						Waves = data.WavesProgress;
						WavePosition = data.WavesProgress;
						PowerType = data.PowerTypeProgress;
						PowerLevel = data.PowerLevelProgress;
						powerchick = data.PowerLevelProgress;
						LifePlayer1 = data.PlayerHealthProgress;
						Playerinput = data.LoadName;
						user.name = Playerinput;
						user.name = data.LoadName;

						IntroMenu.stop();
						if (MusicOn)
							Intro = 1;
						if (MusicOn) {
							Level1Theme = 1;
							BossThemebool = 1;
						}

					}

				}



			}//MenuDraw and Selecting


			else if (Fork.getGlobalBounds().intersects(TableBox.getGlobalBounds())) {
				window.draw(ClickTable);
				UpOrDown = 3;//MenuDraw and Selecting

				for (int i = 0; i < Max_Menu; i++)

				{
					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);//MenuDraw and Selecting
					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));

				}
				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					SelectionMenu = 3;
					TableEnter = 1;
					LeaderBoardMenu = 1;
					if (SoundOn)
						EnterMenu.play();
				}


			}

			else if (Fork.getGlobalBounds().intersects(OptionsBox.getGlobalBounds())) {
				window.draw(ClickOptions);//MenuDraw and Selecting
				UpOrDown = 4;

				for (int i = 0; i < Max_Menu; i++)
				{

					if (i + 1 == UpOrDown)//MenuDraw and Selecting
						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}//MenuDraw and Selecting

				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					SelectionMenu = 4;
					if (SoundOn)
						EnterMenu.play();
				}
			}
			else if (Fork.getGlobalBounds().intersects(CREDitsBox.getGlobalBounds())) {
				window.draw(ClickCREDits);
				UpOrDown = 5;

				for (int i = 0; i < Max_Menu; i++)//MenuDraw and Selecting
				{
					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);//MenuDraw and Selecting

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}//MenuDraw and Selecting

				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					SelectionMenu = 5;
					if (SoundOn)
						EnterMenu.play();
				}
			}

			else if (Fork.getGlobalBounds().intersects(QuitBox.getGlobalBounds())) {
				window.draw(ClickQuit);

				if (Mouse::isButtonPressed(Mouse::Button::Left)) {
					if (SoundOn)
						EnterMenu.play();
					window.close();
				}//MenuDraw and Selecting
				UpOrDown = 6;

				for (int i = 0; i < Max_Menu; i++)
				{//MenuDraw and Selecting
					if (i + 1 == UpOrDown)

						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}//MenuDraw and Selecting
			}
			//KEYBOARD

			else if (UpOrDown == 1) {

				window.draw(ClickStart);

				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					Enter = 0;
					EnterYourNamebool = 0;
					PlayerName.setString("");
					Playerinput = "";
					Default();
					EnterYourNamebool = 1;

				}

				for (int i = 0; i < Max_Menu; i++)
				{

					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));//MenuDraw and Selecting
				}
			}
			else if (UpOrDown == 2) {

				window.draw(ClickLoad);



				for (int i = 0; i < Max_Menu; i++)
				{

					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));//MenuDraw and Selecting
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter))

				{


					Default();


					while (TotalScore > TargetScore)
					{
						TargetScore += 100000;
					}


					if (SoundOn)
						EnterMenu.play();

					BossHealth = 100;
					SelectionMenu = 2;
					otherFile.open("progress.txt");
					otherFile >> data.WavesProgress >> data.PowerTypeProgress >>
						data.PowerLevelProgress >> data.PlayerHealthProgress
						>> data.LoadName;
					otherFile.close();

					Waves = data.WavesProgress;
					WavePosition = data.WavesProgress;
					PowerType = data.PowerTypeProgress;
					PowerLevel = data.PowerLevelProgress;
					powerchick = data.PowerLevelProgress;
					LifePlayer1 = data.PlayerHealthProgress;

					Playerinput = data.LoadName;
					user.name = Playerinput;
					user.name = data.LoadName;
					ScoreNumber = ActScore;

					IntroMenu.stop();
					if (MusicOn)
						Intro = 1;
					if (MusicOn) {
						Level1Theme = 1;
						BossThemebool = 1;
					}

				}
			}

			else if (UpOrDown == 3) {//MenuDraw and Selecting
				window.draw(ClickTable);



				for (int i = 0; i < Max_Menu; i++)
				{

					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);//MenuDraw and Selecting

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}
				//MenuDraw and Selecting

				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					SelectionMenu = 3;//MenuDraw and Selecting
					user.name = Playerinput;
					user.level = Waves;
					user.score = TotalScore;
					TableEnter = 1;

					LeaderBoardMenu = 1;

					if (SoundOn)
						EnterMenu.play();
				}
			}

			else if (UpOrDown == 4) {
				window.draw(ClickOptions);

				for (int i = 0; i < Max_Menu; i++)
				{//MenuDraw and Selecting

					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));//MenuDraw and Selecting
				}

				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					SelectionMenu = 4;
					if (SoundOn)
						EnterMenu.play();
				}
			}

			else if (UpOrDown == 5) {
				window.draw(ClickCREDits);//MenuDraw and Selecting

				for (int i = 0; i < Max_Menu; i++)
				{//MenuDraw and Selecting

					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);

					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}//MenuDraw and Selecting

				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					SelectionMenu = 5;//MenuDraw and Selecting
					if (SoundOn)
						EnterMenu.play();
				}
			}

			else if (UpOrDown == 6) {
				window.draw(ClickQuit);//MenuDraw and Selecting

				for (int i = 0; i < Max_Menu; i++)
				{
					if (i + 1 == UpOrDown)
						_MainMenu[i].setFillColor(Color::White);//MenuDraw and Selecting
					else
						_MainMenu[i].setFillColor(Color(147, 112, 219));
				}
				if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
					if (SoundOn)
						EnterMenu.play();
					window.close(); //MenuDraw and Selecting
				}
			}


			// window.draw(hello);
			//window.draw(StartBox);
			//window.draw(TableBox);
			//window.draw(OptionsBox);
			//window.draw(CREDitsBox);
			//window.draw(QuitBox);


			if (Mouse::isButtonPressed(Mouse::Button::Left))
				Fork = Fork2;
			else
				Fork.setTexture(_Fork);

			if (EnterYourNamebool == 1 && !Enter) {
				window.draw(EndGame);
				window.draw(Name);
				//window.draw(Player);
				window.draw(OvalName);
				window.draw(PlayerName);

				//EnterYourNamebool = 2;
			}



			window.display();




		}




		if (SelectionMenu == 3) {//
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				SelectionMenu = 0;
				if (SoundOn)
					EscapeMenu.play();
			}
			if (MenuBackground_Loop >= MenuView_Number) {
				Background1.setPosition(0, MenuBackground_Loop);
				Background2.setPosition(0, MenuBackground_Loop - 1008);  //2BackGrounds
				MenuBackground_Loop -= 1008;

			}

			//


			Fork.setPosition(Mouse::getPosition().x - 500, Mouse::getPosition().y + MenuView_Number - 100); //Mouse


			BackgroundMenu();//Movement
				//window.setMouseCursorVisible(true);


				//window.setMouseCursorVisible(false);

			window.setView(MenuView);
			window.clear();
			window.draw(Background1);
			window.draw(Background2);

			if (LeaderBoardMenu) {

				//cin >> user.name >> user.level >> user.score;
				ifstream otherFile("LeaderBoard.txt");
				if (!TableEnter)
					save(user);
				int i = 0;
				while (otherFile.good()) {
					otherFile >> User[i].name >> User[i].level >> User[i].score;
					i++;
				}

				sort(User, User + 100, compare);
				font.loadFromFile("Lobster-Regular.ttf");
				for (int i = 0; i < 10; i++)
					Number[i].setFont(font);
				int Num = -89;

				for (int i = 0; 10 > i; i++) {
					table[i].nameT.setFont(font);
					table[i].nameT.setString(User[i].name);
					table[i].nameT.setPosition(100, (100 + (i * 90) + MenuView_Number));

					table[i].scoreT.setFont(font);
					int score = (10 - i) * 1000;
					table[i].scoreT.setString(to_string(User[i].score));
					table[i].scoreT.setPosition(800, (100 + (i * 90) + MenuView_Number));

					table[i].levelsT.setFont(font);
					int level = 1 + i;
					table[i].levelsT.setString(to_string(User[i].level));
					table[i].levelsT.setPosition(500, (100 + (i * 90) + MenuView_Number));

					for (int i = 0; i < 10; i++) {
						Number[i].setString(to_string(Num));
						Number[i].setPosition(0, (100 + (i * 90) + MenuView_Number));
						Num++;
					}
				}


				LeaderBoardMenu = 0;
			}






			//
			for (int i = 0; 10 > i; i++) {
				window.draw(table[i].nameT);
				window.draw(table[i].scoreT);
				window.draw(table[i].levelsT);
				window.draw(Number[i]);
			}


			window.display();
		}//end of the menu



		else	if (SelectionMenu == 4) {

			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				SelectionMenu = 0;
				if (SoundOn)
					EscapeMenu.play();
			}
			if (MenuBackground_Loop >= MenuView_Number) {
				Background1.setPosition(0, MenuBackground_Loop);
				Background2.setPosition(0, MenuBackground_Loop - 1008);  //2BackGrounds
				MenuBackground_Loop -= 1008;

			}

			//




			Fork.setPosition(Mouse::getPosition().x - 500, Mouse::getPosition().y + MenuView_Number - 100); //Mouse


			BackgroundMenu();//Movement
				//window.setMouseCursorVisible(true);


				//window.setMouseCursorVisible(false);


			window.setView(MenuView);
			window.clear();
			window.draw(Background1);
			window.draw(Background2);



			window.draw(RectangleSound);
			window.draw(RectangleMusic);
			window.draw(Fork);
			window.draw(SoundMenu);
			if (SoundOn) {
				window.draw(SignSound);
				SoundGame = 1;
			}
			else SoundGame = 0;

			window.draw(MusicMenu);
			if (MusicOn) {
				window.draw(SignMusic);
				MusicGame = 1;
			}
			else MusicGame = 0;

			//SignMusic.setColor(Color::White);



			window.display();
		}//end of the menu
		//

		//CREDits

		else	if (SelectionMenu == 5) {
			if (CREDitsbool == 1) {
				TextStop = 768;
				text1.setPosition(0, TextStop + 500 + MenuView_Number);
				text2.setPosition(700, TextStop + 1000 + MenuView_Number);
				CREDitsbool = 0;
			}
			if (MenuBackground_Loop >= MenuView_Number) {
				Background1.setPosition(0, MenuBackground_Loop);
				Background2.setPosition(0, MenuBackground_Loop - 1008);  //2BackGrounds
				MenuBackground_Loop -= 1008;
			}

			Fork.setPosition(Mouse::getPosition().x - 500, Mouse::getPosition().y + MenuView_Number - 100); //Mouse


			BackgroundMenu();//Movement

			if (TextStop >= 380) {
				text1.move(0, -3);
				text2.move(0, -3);
				TextStop--;
			}
			else {
				text1.move(0, 0);
				text2.move(0, 0);
			}
			//cout << x << endl;
			window.setView(MenuView);
			window.clear();
			window.draw(Background1);
			window.draw(Background2);
			window.draw(text1);
			window.draw(text2);
			window.display();
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				SelectionMenu = 0;
				CREDitsbool = 1;
				if (SoundOn)
					EscapeMenu.play();
			}
		}

		//

		//The Whole Game with all waves!!!!!
		else if (SelectionMenu == 1 || SelectionMenu == 2) {
			//The Whole Game with all waves!!!!! //The Whole Game with all waves!!!!!
			//System
			TableEnter = 0;
			if (Escapebool == true) {
				//Aya+Paula
				ResumeBackBox.setPosition(415, 190 + WavesView_Number);
				Escape.setPosition(230, 100 + WavesView_Number);
				ClickResumeBack.setPosition(335, WavesView_Number - 10);
				OvalQuit.setPosition(300, 300 + WavesView_Number);
				QuitBackBox.setPosition(410, 315 + WavesView_Number);
				ClickQuitBack.setPosition(335, 160 + WavesView_Number);
				OvalMute.setPosition(300, 400 + WavesView_Number);
				MuteBackBox.setPosition(320, 415 + WavesView_Number);
				ClickMuteBack.setPosition(310, 245 + WavesView_Number);
				MuteBack.setPosition(240, 410 + WavesView_Number);
				SignMute.setPosition(330, 415 + WavesView_Number);
				QuitBack.setPosition(500, 310 + WavesView_Number);
				OvalResume.setPosition(300, 130 + WavesView_Number);
				ResumeBack.setPosition(480, 150 + WavesView_Number);
				Fork.setPosition(Mouse::getPosition().x - 500, Mouse::getPosition().y + WavesView_Number - 100); //Mouse


				window.clear();

				window.draw(Background3);
				window.draw(Background4);
				window.draw(Background5);


				for (int i = 1; i <= FireLoop; i++) {
					if (PowerType == RED)
						window.draw(REDFireBullets[i]);
					if (PowerType == BLUE)
						window.draw(BLUEFireBullets[i]);
					if (PowerType == GREEN)
						window.draw(GREENFireBullets[i]);
				}
				for (int i = 1; i <= FireLoop2; i++) {
					if (PowerType2 == RED)
						window.draw(REDFireBullets2[i]);
					if (PowerType2 == BLUE)
						window.draw(BLUEFireBullets2[i]);
					if (PowerType2 == GREEN)
						window.draw(GREENFireBullets2[i]);
				}
				if (Waves == 1) {
					for (int i = 1; i <= 32; i++)
						window.draw(Eggs[i]);
					for (int i = 1; i <= 32; i++)
						if (!Deathbool[i])
							window.draw(Enemies[i]);
					for (int i = 1; i <= 32; i++) {
						window.draw(Chicks[i]);
					}
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);

				}
				if (Waves == 2) {
					for (int i = 33; i <= 64; i++)
						window.draw(Eggs[i]);
					for (int i = 33; i <= 64; i++)
						if (!Deathbool[i])
							window.draw(Enemies[i]);

					for (int i = 33; i <= 65; i++)
						window.draw(Chicks[i]);
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);
				}
				if (Waves == 3) {
					for (int i = 1; i <= 60; i++) {
						if (Deathbool[i + 64] == 0)
							window.draw(Stones[i]);
					}
				}
				if (Waves == 4) {

					for (int i = 1; i <= 15; i++)
						window.draw(AlienBullets[i]);

					for (int i = 1; i <= 15; i++)
						window.draw(Aliens[i]);

					for (int i = 1; i <= 15; i++) {
						if (Deathbool[i + 124] == 0)
							window.draw(Aliens[i]);
					}


				}
				//for (int i = 1; i <= 15; i++)
					//window.draw(AlienBullets[i]);

				for (int i = 10; i <= 18; i++) {
					window.draw(Atoms[i]);
				}

				window.draw(REDGifts[10]);
				window.draw(REDGifts[11]);
				window.draw(REDGifts[12]);
				window.draw(BLUEGifts[10]);
				window.draw(BLUEGifts[11]);
				window.draw(BLUEGifts[12]);
				window.draw(BLUEGifts[13]);
				window.draw(GREENGifts[10]);
				window.draw(GREENGifts[11]);
				window.draw(GREENGifts[12]);

				window.draw(REDGifts[Wave1Random]);
				window.draw(BLUEGifts[Wave1Random]);
				window.draw(GREENGifts[Wave1Random]);
				window.draw(Atoms[Wave1Random]);
				window.draw(REDGifts[Wave2Random]);
				window.draw(BLUEGifts[Wave2Random]);
				window.draw(GREENGifts[Wave2Random]);
				window.draw(Atoms[Wave2Random]);
				window.draw(REDGifts[Wave4Random]);
				window.draw(BLUEGifts[Wave4Random]);
				window.draw(GREENGifts[Wave4Random]);
				window.draw(Atoms[Wave4Random]);
				window.draw(REDGifts[Wave3Random]);
				window.draw(BLUEGifts[Wave3Random]);
				window.draw(GREENGifts[Wave3Random]);
				window.draw(Atoms[Wave3Random]);
				window.draw(Shield);
				window.draw(Shield2);
				window.draw(Player);
				window.draw(Player2);
				window.draw(TopBar);
				window.draw(BottomBar);
				if (Player2On) {
					window.draw(TopBar2);
					window.draw(BottomBar2);
					window.draw(Lifes2);
					window.draw(PowerText2);
					window.draw(ChicksText2);
				}
				if (Waves == 5) {
					for (int i = 65; i <= 67; i++)
						window.draw(Eggs[i]);
					if (Deathbool[140] == 0)
						window.draw(BossEnemy);
					if (!Deathbool[140]) {
						window.draw(BossHealthBorder);
						window.draw(BossHealthBar);
					}
					for (int i = 61; i <= 100; i++)
						window.draw(Chicks[i]);
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);

				}
				for (int i = 0; i < 29; i++)
					if (FireBarsbool[i])
						window.draw(FireBars[i]);
					else break;
				for (int i = 0; i < 29; i++)
					if (FireBarsbool2[i])
						window.draw(FireBars2[i]);
					else break;

				window.draw(PlayerDeath);
				window.draw(PlayerDeath2);
				window.draw(Score);
				window.draw(Lifes);
				window.draw(ChicksText);
				//window.draw(Test);
				//window.draw(Test2); paula
				//window.draw(Test3);
				window.draw(Shield);
				window.draw(Shield2);
				window.draw(GREENFireBullet);
				window.draw(PowerText);
				window.draw(Score);
				if (Waves == 1)
					window.draw(CutSceneGame);
				window.draw(Escape);
				window.draw(OvalResume);
				window.draw(ResumeBack);
				window.draw(OvalQuit);
				window.draw(QuitBack);
				window.draw(OvalMute);
				window.draw(MuteBack);
				if (Fork.getGlobalBounds().intersects(ResumeBackBox.getGlobalBounds())) {
					window.draw(ClickResumeBack);
					UpOrDown = 7;
					if (Mouse::isButtonPressed(Mouse::Button::Left)) {
						Escapebool = 0;
						if (SoundOn)
							EnterMenu.play();
					}
				}
				if (Fork.getGlobalBounds().intersects(QuitBackBox.getGlobalBounds())) {
					window.draw(ClickQuitBack);
					UpOrDown = 8;
					if (Mouse::isButtonPressed(Mouse::Button::Left)) {
						Escapebool = 0;
						SelectionMenu = 0;
						BossTheme.pause();
						Level1.pause();
						Enter = 0;
						EnterYourNamebool = 0;
						PlayerName.setString("");
						Playerinput = "";
						if (SoundOn)
							EnterMenu.play();
					}

				}

				if (SoundOn)
					window.draw(SignMute);


				if (Fork.getGlobalBounds().intersects(MuteBackBox.getGlobalBounds()))
					window.draw(ClickMuteBack);



				//SelectionMenu = 0;

				window.draw(Fork);
				window.display();

			}//Pause
			/// <summary>
			/// ////////////////
			/// </summary>
			else {//Game
				TextGame();//Anas+Asmaa
				System();//Anas
				if (Keyboard::isKeyPressed(Keyboard::Key::P) && !GameOverbool && !P_Pressed) {
					Player2.setPosition(600, ViewPort + 200);
					Player2On = 1;
					ShieldBool2 = 1;
					LifePlayer2 = 3;
					P_Pressed = 1;
				}
				BackgroundGame();

				if (WavesBackground_Loop >= WavesView_Number) {
					Background3.setPosition(0, WavesBackground_Loop);
					Background4.setPosition(0, WavesBackground_Loop - 1008); //2 Backgrounds moving
					Background5.setPosition(-1020, WavesBackground_Loop);
					WavesBackground_Loop -= 1008;
				}

				PlayerMovement();
				PlayerMovement2();

				PlayerAnimation();
				PlayerAnimation2();

				EnemyAnimation();

				ChickenEgg();

				;//Movement

				GiftsMovement();
				/*

				void Power(Sprite REDFireBullets[], bool& Fire, Sound& REDFireSound, int& FireNumber, Sprite& Player,
		float& FireTimer, bool& PowerStop, int& SelectionMenu





		Power2(Sprite REDFireBullets2[], bool& Fire2, Sound& REDFireSound, int& FireNumber2, Sprite& Player2,
		float& FireTimer2, bool& PowerStop2, int& SelectionMenu)
				*/
				Power();
				Power2();

				Collision();

				DeadAnimation();
				DeadAnimation2();

				//Animaion
				Player.setTextureRect(IntRect(abs(xPlayer * 170), yPlayer * 82.5, 89, 78));
				Player2.setTextureRect(IntRect(abs(xPlayer2 * 170), yPlayer2 * 82.5, 89, 78));

				PlayerBox.setPosition(Player.getPosition().x + 15, Player.getPosition().y + 5);
				PlayerBox2.setPosition(Player2.getPosition().x + 15, Player2.getPosition().y + 5);

				if (ScoreTimer == ScoreNumber)
					ScoreNumber++;
				ScoreTimer += 0.5;
				if (ActScore >= ScorePosition)
				{
					xScore -= 10;
					Score.move(-16, 0);
					ScorePosition *= 10;
				}

				//The Whole Game with all waves!!!!!

					//cout << CutSceneGameTimer << endl;
				if (Level1Theme && CutSceneGameTimer > 5 &&
					MusicOn) {
					Level1.play();
					Level1Theme = 0;
				}
				if (Waves == 1) {
					ChickBegin = 1, ChickEnd = 32;
					if (CutSceneGameTimer > 5) {
						if (MusicOn)
							Intro = 1;
						if (WaveTimer >= 2) {
							if (WavePosition == 1) { //SetPosition Inside loop and Enemies-per-wave

								Atoms[15].setPosition(200, Player.getPosition().y - 800);
								Atoms[16].setPosition(800, Player.getPosition().y - 800);

								Wave1();//Position
								EnemySpeed = 2;

								WavePosition++;
							}


							//Call

							//
							Action1();
						}
					}
					CutSceneGameTimer += 0.03;
					CutSceneGame.setOrigin(100, 100);
					CutSceneGame.setScale(1 + CutSceneGameMove, 1 + CutSceneGameMove);
					//cout << CutSceneGame.getScale().x << " xx " << CutSceneGame.getScale().y << "yy" << endl;
					if (CutSceneGameMove < 20) {
						CutSceneGameMove += 0.01 * 2;
						CutSceneGame.move(-6.7 * 4, -6.8 * 4);
					}
					//for(int i=1; i<=32; i++)

					WaveTimer += 0.01;

					//
					for (int i = 1; i <= 32; i++)
						if (!Deathbool[i])
							EnemiesBox[i].setPosition(Enemies[i].getPosition().x + 33, Enemies[i].getPosition().y + 20);

					window.setView(WavesView);
					window.clear();
					window.draw(Background3);
					window.draw(Background4);
					window.draw(Background5);
					//

					for (int i = 1; i <= FireLoop; i++) {
						if (PowerType == RED)
							window.draw(REDFireBullets[i]);
						if (PowerType == BLUE)
							window.draw(BLUEFireBullets[i]);
						if (PowerType == GREEN)
							window.draw(GREENFireBullets[i]);
					}
					for (int i = 1; i <= FireLoop2; i++) {
						if (PowerType2 == RED)
							window.draw(REDFireBullets2[i]);
						if (PowerType2 == BLUE)
							window.draw(BLUEFireBullets2[i]);
						if (PowerType2 == GREEN)
							window.draw(GREENFireBullets2[i]);
					}





					for (int i = 1; i <= 32; i++)
						window.draw(Eggs[i]);
					//cout<<
					//window.draw(Lazer);
					//window.draw(REDGift);

					//
					if (!ShieldBool)
						window.draw(Player);
					if (!ShieldBool2)
						window.draw(Player2);
					//window.draw(PlayerBox);
					//
					for (int i = 1; i <= 32; i++) {
						if (Deathbool[i] == 0)
							window.draw(Enemies[i]);
						else	if (!SmokeStop[i])
						{
							Smokes[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							Chicks[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							Meals[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							if (i == Wave1Random)
								Gifts1();
							//if (i == MealRandom1)
							if (i == MealRandom2)
								Meals[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							if (SoundOn)
								EnemyDeadSound.play();
							SmokeStop[i]++;

						}
						//

						if (SmokeStop[i]) {
							xSmoke[i]++;
							if (xSmoke[i] > 11) {
								ySmoke[i]++;
								xSmoke[i] = 0;
							}
							if (ySmoke[i] > 1) {
								xSmoke[i] = 12;
							}

							Smokes[i].setTextureRect(IntRect(xSmoke[i] * 340, ySmoke[i] * 300, 350, 290)); //0,0,4000/12,300
							window.draw(Smokes[i]);
						}

					}
					window.draw(Atoms[15]);
					window.draw(Atoms[16]);
					ChickMovement();
					/*window.draw(Enemy);*/
					//window.draw(Menu);
					window.draw(TopBar);
					window.draw(BottomBar);
					if (Player2On) {
						window.draw(TopBar2);
						window.draw(BottomBar2);
						window.draw(Lifes2);
						window.draw(PowerText2);
						window.draw(ChicksText2);
					}
					window.draw(PlayerDeath);
					window.draw(PlayerDeath2);
					window.draw(Score);
					window.draw(Lifes);
					window.draw(ChicksText);
					//window.draw(Test);
					//window.draw(Test2); paula
					//window.draw(Test3);
					window.draw(Shield);
					window.draw(Shield2);
					window.draw(GREENFireBullet);
					window.draw(PowerText);
					for (int i = 0; i < 29; i++)
						if (FireBarsbool[i])
							window.draw(FireBars[i]);
						else break;
					for (int i = 0; i < 29; i++)
						if (FireBarsbool2[i])
							window.draw(FireBars2[i]);
						else break;
					ShieldFunction();
					for (int i = 1; i <= 32; i++) {
						window.draw(Chicks[i]);
					}
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);
					//window.draw(Smoke);
				/*	for (int i = 1; i <= 32; i++)



						window.draw(EnemiesBox[i]);*/
					if (Player2TextTimer < 4 && !Player2On)
						window.draw(Player2Text);
					if (Player2TextTimer >= 6)
						Player2TextTimer = 0;
					Player2TextTimer += 0.1;
					window.draw(REDGifts[Wave1Random]);
					window.draw(BLUEGifts[Wave1Random]);
					window.draw(GREENGifts[Wave1Random]);
					window.draw(Atoms[Wave1Random]);
					window.draw(CutSceneGame);


					TextGame();

					//display
					window.display();


				}//
				if (chickenscore == 32000) {
					endtimer += 0.01;
					if (endtimer >= 3.5) {
						Waves++;
						Action = 0;
						EnemySpeed = 6;
						WaveTimer = 0;
						chickenscore = 0;
						if (LifePlayer1 > 0) {
							file.open("progress.txt");
							file << Waves << " " << PowerType << " " << PowerLevel << " " << LifePlayer1 << " " << Playerinput;
							file.close();
							otherFile.open("progress.txt");
							otherFile >> data.WavesProgress >> data.PowerTypeProgress >> data.PowerLevelProgress >>
								data.PlayerHealthProgress >> data.LoadName;
						}
					}
				}


				//Wave2
				if (Waves == 2) {

					Action2Extra();
					if (WavePosition == 2) { //SetPosition Inside loop and Enemies-per-wave
						endtimer = 0;
						Wave2();
						Atoms[10].setPosition(200, Player.getPosition().y - 800);
						Atoms[17].setPosition(800, Player.getPosition().y - 800);
						BLUEGifts[10].setPosition(100, Player.getPosition().y - 1000);
						GREENGifts[10].setPosition(900, Player.getPosition().y - 3000);


						WavePosition++;
					}
					ChickBegin = 33, ChickEnd = 65;

					/*cout <<"EBug" << Enemies[41 + 16].getPosition().x << endl;
					cout << Enemies[42 + 16].getPosition().x<<endl;
					cout << Enemies[43 + 16].getPosition().x<<endl;
					cout << Enemies[44 + 16].getPosition().x<<endl;

				*/

					if (DeathExtra[1] == 0)
						for (int i = 33; i <= 36; i++) {
							if (Deathbool[i] == 1)
								DeathExtra[1] = 1;
							else {
								DeathExtra[1] = 0;
								break;
							}
						}


					if (DeathExtra[2] == 0)
						for (int i = 37; i <= 40; i++) {
							if (Deathbool[i] == 1)
								DeathExtra[2] = 1;
							else {
								DeathExtra[2] = 0;
								break;
							}
						}


					if (DeathExtra[3] == 0)
						for (int i = 41; i <= 44; i++) {
							if (Deathbool[i] == 1)
								DeathExtra[3] = 1;
							else {
								DeathExtra[3] = 0;
								break;
							}
						}


					if (DeathExtra[4] == 0)
						for (int i = 45; i <= 48; i++) {
							if (Deathbool[i] == 1)
								DeathExtra[4] = 1;
							else {
								DeathExtra[4] = 0;
								break;
							}
						}
					//cout << "x1   " << Enemies[33+16].getPosition().x << endl;
					//cout << "x2   " << Enemies[37+16].getPosition().x << endl;
					//cout << "x3   " << Enemies[41+16].getPosition().x << endl;
					//cout << "x4   " << Enemies[45+16].getPosition().x << endl;
					Wave2Extra();
					Action2();
					ChickenEgg();
					ChickMovement();

					/*			cout << "x : " << Enemies[48].getPosition().x << endl;
								cout << "y : " << Enemies[48].getPosition().y << endl;
								cout << "xreal : " << Enemies[41].getPosition().x << endl;
								cout << "yreal : " << Enemies[41].getPosition().y << endl;*/

					for (int i = 33; i <= 64; i++)
						if (!Deathbool[i])
							EnemiesBox[i].setPosition(Enemies[i].getPosition().x + 33, Enemies[i].getPosition().y + 20);

					window.setView(WavesView);
					window.clear();
					window.draw(Background3);
					window.draw(Background4);
					window.draw(Background5);
					//

					for (int i = 1; i <= FireLoop; i++) {
						if (PowerType == RED)
							window.draw(REDFireBullets[i]);
						if (PowerType == BLUE)
							window.draw(BLUEFireBullets[i]);
						if (PowerType == GREEN)
							window.draw(GREENFireBullets[i]);
					}
					for (int i = 1; i <= FireLoop2; i++) {
						if (PowerType2 == RED)
							window.draw(REDFireBullets2[i]);
						if (PowerType2 == BLUE)
							window.draw(BLUEFireBullets2[i]);
						if (PowerType2 == GREEN)
							window.draw(GREENFireBullets2[i]);
					}

					for (int i = 33; i <= 48; i++)
						window.draw(Eggs[i]);
					if (DeathExtra[1] == 2 && DeathExtra[2] == 2) {
						for (int i = 33 + 16; i <= 40 + 16; i++)
							window.draw(Eggs[i]);
						EggCollision = 40 + 16;
					}
					if (DeathExtra[3] == 2 && DeathExtra[4] == 2) {
						for (int i = 41 + 16; i <= 48 + 16; i++)
							window.draw(Eggs[i]);
						EggCollision = 48 + 16;

					}
					//window.draw(Lazer);
					//window.draw(REDGift);
					ShieldFunction();
					if (!ShieldBool)
						window.draw(Player);
					if (!ShieldBool2)
						window.draw(Player2);
					//window.draw(PlayerBox);
					//
					for (int i = 33; i <= 64; i++) {
						if (Deathbool[i] == 0) {
							window.draw(Enemies[i]);
							//window.draw(EnemiesBox[i]);

						}
						else	if (!SmokeStop[i])
						{
							Smokes[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							Chicks[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							Meals[i].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							if (i == Wave2Random)
								Gifts2();
							if (i == MealRandom2 + 32)
								Meals[i - 32].setPosition(Enemies[i].getPosition().x, Enemies[i].getPosition().y);
							if (SoundOn)
								EnemyDeadSound.play();
							SmokeStop[i]++;

						}
						//
						if (SmokeStop[i]) {
							xSmoke[i]++;
							if (xSmoke[i] > 11) {
								ySmoke[i]++;
								xSmoke[i] = 0;
							}
							if (ySmoke[i] > 1) {
								xSmoke[i] = 12;
							}

							Smokes[i].setTextureRect(IntRect(xSmoke[i] * 340, ySmoke[i] * 300, 350, 290)); //0,0,4000/12,300
							window.draw(Smokes[i]);
						}

					}

					/*window.draw(Enemy);*/
					//window.draw(Menu);
					window.draw(TopBar);
					window.draw(BottomBar);
					if (Player2On) {
						window.draw(TopBar2);
						window.draw(BottomBar2);
						window.draw(Lifes2);
						window.draw(PowerText2);
						window.draw(ChicksText2);

					}
					window.draw(PlayerDeath);
					window.draw(PlayerDeath2);
					window.draw(Score);
					window.draw(ChicksText);
					window.draw(Lifes);

					window.draw(Atoms[10]);
					window.draw(Atoms[17]);

					window.draw(PowerText);

					//cout << ShieldTimer2 << endl;

					window.draw(Shield);
					window.draw(Shield2);
					window.draw(Shield);
					window.draw(Shield2);
					window.draw(BLUEGifts[10]);
					window.draw(GREENGifts[10]);


					window.draw(REDGifts[Wave2Random]);
					window.draw(BLUEGifts[Wave2Random]);
					window.draw(GREENGifts[Wave2Random]);
					window.draw(Atoms[Wave2Random]);
					window.draw(REDGifts[Wave1Random]);
					window.draw(BLUEGifts[Wave1Random]);
					window.draw(GREENGifts[Wave1Random]);
					window.draw(Atoms[Wave1Random]);
					for (int i = 0; i < 29; i++)
						if (FireBarsbool[i])
							window.draw(FireBars[i]);
						else break;

					for (int i = 0; i < 29; i++)
						if (FireBarsbool2[i])
							window.draw(FireBars2[i]);
						else break;




					TextGame();
					if (Player2TextTimer < 4 && !Player2On)
						window.draw(Player2Text);
					if (Player2TextTimer >= 6)
						Player2TextTimer = 0;
					Player2TextTimer += 0.1;
					for (int i = 33; i <= 65; i++)
						window.draw(Chicks[i]);
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);
					window.display();

					//window.draw(Smoke);
			/*		for (int i = 33; i <= 40; i++)
						window.draw(EnemiesBox[i]);*/


					WaveTimer = 0;



					for (int i = 33; i <= 64; i++) {
						if (Deathbool[i] == 1)
							WavesDeath[Waves] = 1;
						else {
							WavesDeath[Waves] = 0;
							break;
						}
					}



				}
				if (WavesDeath[Waves] == 1) {
					endtimer += 0.01;
					if (endtimer >= 4) {
						Waves++;
						Action = 0;
						EnemySpeed = 6;
						WaveTimer = 0;
						if (LifePlayer1 > 0) {
							file.open("progress.txt");
							file << Waves << " " << PowerType << " " << PowerLevel << " " << LifePlayer1 << " " << Playerinput;
							file.close();
							otherFile.open("progress.txt");
							otherFile >> data.WavesProgress >> data.PowerTypeProgress >> data.PowerLevelProgress >>
								data.PlayerHealthProgress >> data.LoadName;
						}
					}
				}



				if (Waves == 3) {
					window.setView(WavesView);
					window.clear();
					window.draw(Background3);
					window.draw(Background4);
					window.draw(Background5);
					WaveTimer += 0.01;
					if (WaveTimer >= 2) {
						if (WavePosition == 3) {
							endtimer = 0;
							Wave3();
							Atoms[11].setPosition(200, Player.getPosition().y - 800);
							Atoms[17].setPosition(800, Player.getPosition().y - 800);

							WavePosition++;
							REDGifts[10].setPosition(100, Player.getPosition().y - 1000);
							BLUEGifts[11].setPosition(900, Player.getPosition().y - 3000);
						}
						//cout << WaveTimer << endl;

						endtimer += 0.01;



						for (int i = 1; i <= 60; i++) {
							Stones[i].move(i * 0.07, i * 0.1);

						}

						for (int i = 1; i <= 60; i++) {

							Stones[stoneNumber[i]].move(xmovestones[i], ymovestones[i]);
							Stones[i].setTextureRect(IntRect(xStones[i] * 62.625, yStones[i] * 62.25, 62.625, 62.25));
							if (StonesTImer[i] > 2) {
								StonesTImer[i] = 0.1;
								if (xStones[i] < 7)
									xStones[i]++;
								else {
									xStones[i] = 0;
									if (yStones[i] < 7)
										yStones[i]++;
									else
										yStones[i] = 4;
								}
							}
							StonesTImer[i]++;
							window.draw(Stones[i]);
						}
						for (int i = 1; i <= 60; i++) {
							if (Deathbool[i + 64] == 0)
								window.draw(Stones[i]);
							else	if (!SmokeStop[i + 64])
							{
								Smokes[i + 64].setPosition(Stones[i].getPosition().x, Stones[i].getPosition().y);
								Stones[i].setPosition(Out, Out);
								if (i == Wave3Random)
									Gifts3();

								SmokeStop[i + 64]++;

							}
							//
							if (SmokeStop[i + 64]) {
								xSmoke[i + 64]++;
								if (xSmoke[i + 64] > 11) {
									ySmoke[i + 64]++;
									xSmoke[i + 64] = 0;
								}
								if (ySmoke[i + 64] > 1) {
									xSmoke[i + 64] = 12;
								}

								Smokes[i + 64].setTextureRect(IntRect(xSmoke[i + 64] * 340, ySmoke[i + 64] * 300, 350, 290)); //0,0,4000/12,300
								window.draw(Smokes[i + 64]);
							}

						}


					}

					for (int i = 1; i <= FireLoop; i++) {
						if (PowerType == RED)
							window.draw(REDFireBullets[i]);
						if (PowerType == BLUE)
							window.draw(BLUEFireBullets[i]);
						if (PowerType == GREEN)
							window.draw(GREENFireBullets[i]);
					}
					for (int i = 1; i <= FireLoop2; i++) {
						if (PowerType2 == RED)
							window.draw(REDFireBullets2[i]);
						if (PowerType2 == BLUE)
							window.draw(BLUEFireBullets2[i]);
						if (PowerType2 == GREEN)
							window.draw(GREENFireBullets2[i]);
					}

					ShieldFunction();


					if (!ShieldBool)
						window.draw(Player);
					if (!ShieldBool2)
						window.draw(Player2);
					window.draw(TopBar);
					window.draw(BottomBar);
					if (Player2On) {
						window.draw(TopBar2);
						window.draw(BottomBar2);
						window.draw(Lifes2);
						window.draw(PowerText2);
						window.draw(ChicksText2);


					}
					window.draw(Atoms[11]);
					window.draw(Atoms[17]);

					window.draw(PlayerDeath);
					window.draw(PlayerDeath2);
					window.draw(Score);
					window.draw(Lifes);
					window.draw(PowerText);
					window.draw(ChicksText);

					window.draw(REDGifts[10]);
					window.draw(BLUEGifts[11]);

					window.draw(Shield);
					window.draw(Shield2);

					window.draw(REDGifts[Wave2Random]);
					window.draw(BLUEGifts[Wave2Random]);
					window.draw(GREENGifts[Wave2Random]);
					window.draw(Atoms[Wave2Random]);

					for (int i = 0; i < 29; i++)
						if (FireBarsbool[i])
							window.draw(FireBars[i]);
						else break;

					for (int i = 0; i < 29; i++)
						if (FireBarsbool2[i])
							window.draw(FireBars2[i]);
						else break;


					TextGame();
					if (Player2TextTimer < 4 && !Player2On)
						window.draw(Player2Text);
					if (Player2TextTimer >= 6)
						Player2TextTimer = 0;
					Player2TextTimer += 0.1;

					window.display();

					if (endtimer >= 16) {
						Waves++;
						Action = 0;
						EnemySpeed = 6;
						WaveTimer = 0;
						if (LifePlayer1 > 0) {
							file.open("progress.txt");
							file << Waves << " " << PowerType << " " << PowerLevel << " " << LifePlayer1 << " " << Playerinput;
							file.close();
							otherFile.open("progress.txt");
							otherFile >> data.WavesProgress >> data.PowerTypeProgress >> data.PowerLevelProgress >>
								data.PlayerHealthProgress >> data.LoadName;
						}
					}

				}

				if (Waves == 4) {
					if (WaveTimer >= 2) {
						if (WavePosition == 4) {
							endtimer = 0;
							Wave4();
							Atoms[12].setPosition(200, Player.getPosition().y - 800);
							Atoms[18].setPosition(800, Player.getPosition().y - 800);
							WavePosition++;
							GREENGifts[11].setPosition(100, Player.getPosition().y - 1000);
							REDGifts[11].setPosition(900, Player.getPosition().y - 3000);

						}
						Action4();
					}
					//cout << Aliens[1].getPosition().x << endl;
					//cout << WavePosition << endl;

					/*		else for (int i = 1; i <= 15; i++)
								Aliens[i].setPosition(-Out, Out);*/

					WaveTimer += 0.01;
					//cout << WaveTimer << endl;
					for (int i = 1; i <= 15; i++) {
						if (AlienBullets[i].getPosition().y > WavesView_Number + (100 * i) + 1000 && WaveTimer >= 3) {
							AlienBullets[i].setPosition(Aliens[i].getPosition().x, Aliens[i].getPosition().y);
							if (!Deathbool[i + 124] && Aliens[i].getPosition().x <= 1000 && Aliens[i].getPosition().x >= 0)
								AlienShots[i].play();
						}
						AlienBulletsBox[i].setPosition(AlienBullets[i].getPosition().x + 65, AlienBullets[i].getPosition().y + 40);
						AlienBullets[i].move(0, 8);
						//AlienShots[i].play();

					}

					window.setView(WavesView);
					window.clear();
					window.draw(Background3);
					window.draw(Background4);
					window.draw(Background5);


					window.draw(Atoms[12]);
					window.draw(Atoms[18]);



					for (int i = 1; i <= FireLoop; i++) {
						if (PowerType == RED)
							window.draw(REDFireBullets[i]);
						if (PowerType == BLUE)
							window.draw(BLUEFireBullets[i]);
						if (PowerType == GREEN)
							window.draw(GREENFireBullets[i]);
					}
					for (int i = 1; i <= FireLoop2; i++) {
						if (PowerType2 == RED)
							window.draw(REDFireBullets2[i]);
						if (PowerType2 == BLUE)
							window.draw(BLUEFireBullets2[i]);
						if (PowerType2 == GREEN)
							window.draw(GREENFireBullets2[i]);
					}

					/*	for (int i = 1; i <= 48; i++)
							window.draw(Eggs[i]);*/


					ShieldFunction();
					for (int i = 1; i <= 15; i++)
						window.draw(AlienBullets[i]);

					if (!ShieldBool)
						window.draw(Player);
					if (!ShieldBool2)
						window.draw(Player2);


					window.draw(TopBar);
					window.draw(BottomBar);
					if (Player2On) {
						window.draw(TopBar2);
						window.draw(BottomBar2);
						window.draw(Lifes2);
						window.draw(PowerText2);
						window.draw(ChicksText2);


					}
					window.draw(PlayerDeath);
					window.draw(PlayerDeath2);
					window.draw(Score);
					window.draw(Lifes);
					window.draw(ChicksText);

					window.draw(PowerText);

					//cout << ShieldTimer2 << endl;

					window.draw(Shield);
					window.draw(Shield2);


					window.draw(GREENGifts[11]);
					window.draw(REDGifts[11]);

					window.draw(REDGifts[Wave4Random]);
					window.draw(BLUEGifts[Wave4Random]);
					window.draw(GREENGifts[Wave4Random]);
					window.draw(Atoms[Wave4Random]);

					for (int i = 1; i <= 15; i++)
						if (!Deathbool[i + 124]) {

							AliensBox[i].setPosition(Aliens[i].getPosition().x + 33, Aliens[i].getPosition().y + 20);
							//window.draw(AliensBox[i]);

						}

					if (Aliens[15].getPosition().x >= 1000 && Aliens[14].getPosition().x >= 5000 && Aliens[13].getPosition().x >= 5000 &&
						Aliens[12].getPosition().x >= 5000 && Aliens[11].getPosition().x >= 5000 && Aliens[10].getPosition().x >= 5000) {
						endtimer += 0.01; if (endtimer >= 0.5) {
							Waves++;
							Action = 0;
							EnemySpeed = 6;
							WaveTimer = 0;
							if (LifePlayer1 > 0) {
								file.open("progress.txt");
								file << Waves << " " << PowerType << " " << PowerLevel << " " << LifePlayer1 << " " << Playerinput;
								file.close();
								otherFile.open("progress.txt");
								otherFile >> data.WavesProgress >> data.PowerTypeProgress >> data.PowerLevelProgress >>
									data.PlayerHealthProgress >> data.LoadName;
							}
						}

					}

					for (int i = 1; i <= 15; i++)
						window.draw(Aliens[i]);

					for (int i = 1; i <= 15; i++) {
						if (Deathbool[i + 124] == 0)
							window.draw(Aliens[i]);
						else	if (!SmokeStop[i + 124])
						{
							Smokes[i + 124].setPosition(Aliens[i].getPosition().x, Aliens[i].getPosition().y);

							if (i == Wave4Random)
								Gifts4();

							Aliens[i].setPosition(Out, Out);
							AliensBox[i].setPosition(Out, Out);
							SmokeStop[i + 124]++;

						}
						//
						if (SmokeStop[i + 124]) {
							xSmoke[i + 124]++;
							if (xSmoke[i + 124] > 11) {
								ySmoke[i + 124]++;
								xSmoke[i + 124] = 0;
							}
							if (ySmoke[i + 124] > 1) {
								xSmoke[i + 124] = 12;
							}

							Smokes[i + 124].setTextureRect(IntRect(xSmoke[i + 124] * 340, ySmoke[i + 124] * 300, 350, 290)); //0,0,4000/12,300
							window.draw(Smokes[i + 124]);
						}

					}

					for (int i = 0; i < 29; i++)
						if (FireBarsbool[i])
							window.draw(FireBars[i]);
						else break;
					for (int i = 0; i < 29; i++)
						if (FireBarsbool2[i])
							window.draw(FireBars2[i]);
						else break;


					TextGame();
					if (Player2TextTimer < 4 && !Player2On)
						window.draw(Player2Text);
					if (Player2TextTimer >= 6)
						Player2TextTimer = 0;
					Player2TextTimer += 0.1;

					window.display();


				}

				if (Waves == 5) {
					//if (!PlayerDeathbool)
					//	WavesView.setRotation(0);
					Level1.stop();
					if (BossThemebool && MusicOn) {
						BossTheme.play();
						BossThemebool = 0;
					}
					ChickBegin = 61, ChickEnd = 100;
					if (WaveTimer >= 2) {
						if (WavePosition == 5) {
							Atoms[13].setPosition(200, Player.getPosition().y - 800);
							Atoms[14].setPosition(800, Player.getPosition().y - 800);
							BLUEGifts[12].setPosition(100, Player.getPosition().y - 1000);
							GREENGifts[12].setPosition(900, Player.getPosition().y - 4000);
							BLUEGifts[13].setPosition(200, Player.getPosition().y - 10000);
							REDGifts[12].setPosition(800, Player.getPosition().y - 15000);
							Wave5();//dq
							WavePosition++;
						}
						Action5();
					}
					BLUEGifts[12].move(0, 2);
					BossHealthBar.setSize(Vector2f(500 * BossHealth / 100, 20));
					if (BackgroundSpeed > 0)
						BackgroundSpeed -= 0.005;
					else BackgroundSpeed = 0;

					WaveTimer += 0.01;
					Atoms[13].move(0, 3);
					Atoms[14].move(0, 3);
					window.setView(WavesView);
					window.clear();
					window.draw(Background3);
					window.draw(Background4);
					window.draw(Background5);
					window.draw(Atoms[13]);
					window.draw(Atoms[14]);

					if (BossHealth <= 25)
						BossHealthBar.setFillColor(Color::Red);
					else
						BossHealthBar.setFillColor(Color::Green);


					for (int i = 1; i <= FireLoop; i++) {
						if (PowerType == RED)
							window.draw(REDFireBullets[i]);
						if (PowerType == BLUE)
							window.draw(BLUEFireBullets[i]);
						if (PowerType == GREEN)
							window.draw(GREENFireBullets[i]);
					}
					for (int i = 1; i <= FireLoop2; i++) {
						if (PowerType2 == RED)
							window.draw(REDFireBullets2[i]);
						if (PowerType2 == BLUE)
							window.draw(BLUEFireBullets2[i]);
						if (PowerType2 == GREEN)
							window.draw(GREENFireBullets2[i]);
					}
					ChickenEgg();
					for (int i = 65; i <= 67; i++)
						window.draw(Eggs[i]);


					ShieldFunction();

					if (!ShieldBool)
						window.draw(Player);
					if (!ShieldBool2)
						window.draw(Player2);



					window.draw(TopBar);
					window.draw(BottomBar);
					if (Player2On) {
						window.draw(TopBar2);
						window.draw(BottomBar2);
						window.draw(Lifes2);
						window.draw(PowerText2);
						window.draw(ChicksText2);

					}
					window.draw(PlayerDeath);
					window.draw(PlayerDeath2);
					window.draw(Score);
					window.draw(Lifes);
					window.draw(PowerText);
					window.draw(ChicksText);


					//cout << ShieldTimer2 << endl;

					window.draw(Shield);
					window.draw(Shield2);


					window.draw(REDGifts[Wave3Random]);
					window.draw(BLUEGifts[Wave3Random]);
					window.draw(GREENGifts[Wave3Random]);
					window.draw(Atoms[Wave3Random]);
					window.draw(REDGifts[Wave4Random]);
					window.draw(BLUEGifts[Wave4Random]);
					window.draw(GREENGifts[Wave4Random]);
					window.draw(Atoms[Wave4Random]);
					////


					if (Deathbool[140] == 0)
						window.draw(BossEnemy);
					else	if (!SmokeStop[140])
					{
						BossTheme.stop();
						BossDeadSound.play();
						for (int i = 61; i <= 100; i++)
							Chicks[i].setPosition(BossEnemy.getPosition().x + (i * 15) - 1000, BossEnemy.getPosition().y);
						Meals[MealRandom1].setPosition(BossEnemy.getPosition().x + (70 * 15) - 1000, BossEnemy.getPosition().y);
						Meals[MealRandom2].setPosition(BossEnemy.getPosition().x + (80 * 15) - 1000, BossEnemy.getPosition().y);
						Smokes[140].setPosition(BossEnemy.getPosition().x, BossEnemy.getPosition().y);
						BossEnemy.setPosition(Out, Out);
						BossBox.setPosition(Out, Out);
						BossBox2.setPosition(Out, Out);
						BossBox3.setPosition(Out, Out);
						SmokeStop[140]++;

						Winning = 1;


					}
					//dqo
					if (SmokeStop[140]) {
						xSmoke[140]++;
						if (xSmoke[140] > 11) {
							ySmoke[140]++;
							xSmoke[140] = 0;
						}
						if (ySmoke[140] > 1) {
							xSmoke[140] = 12;
						}

						Smokes[140].setTextureRect(IntRect(xSmoke[140] * 340, ySmoke[140] * 300, 350, 290)); //0,0,4000/12,300
						window.draw(Smokes[140]);
						if (!WinBool)
							WinTimer += 0.1;
						else WinTimer -= 0.1;
						if (ShakeTimer > 5 && Winning) { //Shake
							WavesView.rotate(-ShakeReverse);
							ShakeTimer = 1 - ShakeSpeed;

							ShakeReverse *= -1;
						}
						ShakeTimer += 2;



					}

					window.draw(BLUEGifts[12]);
					window.draw(GREENGifts[12]);
					window.draw(BLUEGifts[13]);
					window.draw(REDGifts[12]);

					if (!Deathbool[140]) {
						BossBox.setPosition(BossEnemy.getPosition().x + 90, BossEnemy.getPosition().y + 40);
						BossBox2.setPosition(BossEnemy.getPosition().x + 20, BossEnemy.getPosition().y + 90);
						BossBox3.setPosition(BossEnemy.getPosition().x + 240, BossEnemy.getPosition().y + 90);

					}

					/*	window.draw(BossBox);
						window.draw(BossBox2);
						window.draw(BossBox3);*/

						//window.draw(CutSceneGame);

					if (WinTimer > 10) {
						Winning = 0;
						WavesView.setRotation(0);
						WinMusic.play();
						WinTimer = 0;
						WinBool = 1;
					}//csgo
					if (WinTimer < -5)
						if (BackgroundSpeed < 120)
							BackgroundSpeed += 0.5;
						else {
							if (!FlyingBool) {
								Flying.play();
								FlyingBool = 1;
							}
							CutSceneGame.setScale(1 + CutSceneGameMove, 1 + CutSceneGameMove);

							if (CutSceneGameMove > 0.3 - 1) {

								CutSceneGameMove -= 0.01 * 4;
								CutSceneGame.move(6.7 * 8, 6.8 * 8);
							}

							else {
								otherFile.open("progress.txt");
								otherFile >> data.WavesProgress >> data.PowerTypeProgress >>
									data.PowerLevelProgress >> data.PlayerHealthProgress;
								otherFile.close();
								user.name = Playerinput;
								user.name = data.LoadName;
								ScoreNumber = ActScore;
								user.score = TotalScore;
								SelectionMenu = 3;
								user.level = Waves;
								LeaderBoardMenu = 1;
							}

						}
					if (!Deathbool[140]) {
						window.draw(BossHealthBorder);
						window.draw(BossHealthBar);
					}
					for (int i = 0; i < 29; i++)
						if (FireBarsbool[i])
							window.draw(FireBars[i]);
						else break;

					for (int i = 0; i < 29; i++)
						if (FireBarsbool2[i])
							window.draw(FireBars2[i]);
						else break;
					for (int i = 61; i <= 80; i++)
					{
						Chicks[i].move(chickmove[i], 5);
						Chicks[i].rotate(4);
						if (Chicks[i].getPosition().x <= 5)
							chickmove[i] *= -1;
						if (Chicks[i].getPosition().x >= 970)
							chickmove[i] *= -1;
					}
					for (int i = 81; i <= 100; i++)
					{
						Chicks[i].move(chickmove[i], 5);
						Chicks[i].rotate(-4);
						if (Chicks[i].getPosition().x <= 5)
							chickmove[i] *= -1;
						if (Chicks[i].getPosition().x >= 970)
							chickmove[i] *= -1;
					}
					Meals[MealRandom1].move(chickmove[101], 5);
					Meals[MealRandom2].move(chickmove[102], 5);
					Meals[MealRandom1].rotate(1);
					Meals[MealRandom2].rotate(1);
					if (Meals[MealRandom1].getPosition().x <= 5)
						chickmove[101] *= -1;
					if (Meals[MealRandom1].getPosition().x >= 970)
						chickmove[101] *= -1;
					if (Meals[MealRandom2].getPosition().x <= 5)
						chickmove[102] *= -1;
					if (Meals[MealRandom2].getPosition().x >= 970)
						chickmove[102] *= -1;
					for (int i = 61; i <= 100; i++)
						window.draw(Chicks[i]);
					window.draw(Meals[MealRandom1]);
					window.draw(Meals[MealRandom2]);

					TextGame();
					if (Player2TextTimer < 4 && !Player2On)
						window.draw(Player2Text);
					if (Player2TextTimer >= 6)
						Player2TextTimer = 0;
					Player2TextTimer += 0.1;

					window.display();


				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
				Escapebool = true;



		}

	}//end of the window

}//main
//Main

void Definition() {

	_Background.loadFromFile("Background.jpg"); //Background
	_Player.loadFromFile("Player.png"); //Player
	_Player2.loadFromFile("Player2.png"); //Player
	_Enemy.loadFromFile("GREENChicken.png"),
		_Enemy2.loadFromFile("REDChicken.png"),
		_REDFireBullet.loadFromFile("REDFireBullet.png");
	_Egg.loadFromFile("Egg.png");
	_Menu.loadFromFile("ChickenInvadersMenu.png");
	_TopBar.loadFromFile("TopBar.png");
	_BottomBar.loadFromFile("BottomBar.png");
	_Smoke.loadFromFile("Smoke.png");
	_PlayerDeath.loadFromFile("PlayerDeath.png");
	_Score.loadFromFile("Gifty Glory.ttf");
	_Lifes.loadFromFile("Gifty Glory.ttf");
	_Sign.loadFromFile("Sign.png");
	_REDGifts.loadFromFile("./RED.png");
	_BLUEGifts.loadFromFile("./BLUE.png");
	_GREENGifts.loadFromFile("./GREEN.png");
	_Shield.loadFromFile("Shield.png");
	_Atom.loadFromFile("Atom.png");
	_Alien.loadFromFile("Alien.png");
	_BLUEFireBullet.loadFromFile("BLUEFire.png");
	_GREENFireBullet.loadFromFile("GREENFire.png");
	_MenuSets.loadFromFile("ovalshape.png");
	_ClickMenuSets.loadFromFile("Click.png");
	_Quit.loadFromFile("ovalshape.png");
	_Fork.loadFromFile("Fork1.png");
	_Fork2.loadFromFile("Fork2.png");
	font.loadFromFile("RobotoCondensed-Bold.ttf");
	font2.loadFromFile("Lobster-Regular.ttf");
	_Stones.loadFromFile("Stones.png");
	font.loadFromFile("Lobster-Regular.ttf");
	font.loadFromFile("Lobster-Regular.ttf");
	_BossEnemy.loadFromFile("Boss.png");
	_AlienBullet.loadFromFile("AlienBullet.png");
	_Chick.loadFromFile("Chick.png");
	_Meal.loadFromFile("Meal.png");
	_CutScene.loadFromFile("CutScene.png");

	if (!_REDFireSound.loadFromFile("REDFire.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_BLUEFireSound.loadFromFile("BLUEFire.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_ChickEat.loadFromFile("ChickEat.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_EggSound.loadFromFile("EggSound.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_EnemyDeadSound.loadFromFile("EnemyDeadSound.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_PlayerDeadSound.loadFromFile("PlayerDeadSound.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_BossDeadSound.loadFromFile("BossDeadSound.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_Flying.loadFromFile("Flying.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_TakenGift.loadFromFile("TakenGift.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_IntroMenu.loadFromFile("IntroMenu.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_Level1.loadFromFile("Level1.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_BossTheme.loadFromFile("BossTheme.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_WinMusic.loadFromFile("WinMusic.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_GameOverMusic.loadFromFile("GameOverMusic.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_SelectMenu.loadFromFile("Select.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_Enter.loadFromFile("Enter.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_Escape.loadFromFile("Escape.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_GREENFireSound.loadFromFile("GreenFire.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_AlienShot.loadFromFile("AlienShot.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!_OneUp.loadFromFile("OneUp.wav")) //sound
	{
		std::cout << "ERROR" << std::endl;
	}

	_MenuSets.loadFromFile("ovalshape.png");
	font2.loadFromFile("Lobster-Regular.ttf");
}
//Paula
void Settings() {
	Player.setPosition(-Out, -Out);
	Player.setScale(0.73, 0.73);
	Player2.setPosition(-Out, -5600 + WavesView_Number);
	Player2.setScale(0.73, 0.73);
	Menu.setPosition(200, 50);
	Menu.setScale(0.8, 0.8);
	Background2.setPosition(0, -1000);
	REDFireBullet.setScale(0.14, 0.14);
	Egg.setPosition(Out, Out);
	BottomBar.setPosition(0, 943);

	TopBar2.setPosition(1000, 0);
	TopBar2.setScale(-1, 1);
	TopBar2.setColor(Color::Red);
	BottomBar2.setPosition(1000, 943);
	BottomBar2.setScale(-1, 1);
	BottomBar2.setColor(Color::Red);


	Lazer.setScale(0.40, 0.83);
	REDGift.setPosition(Out, Out);
	REDGift.setScale(0.6, 0.8);
	//Smoke.setPosition(200, 200);
	Smoke.setScale(0.4, 0.4);
	PlayerDeath.setPosition(-Out, Out);
	PlayerDeath2.setPosition(-Out, Out);
	Score.setFont(_Score);
	Lifes.setFont(_Score);
	Lifes2.setFont(_Score);
	PowerText.setFont(_Score);
	PowerText2.setFont(_Score);
	ChicksText.setFont(_Score);
	ChicksText2.setFont(_Score);

	Enemy.setPosition(Out, Out);
	Score.setPosition(130, 8);
	Lifes.setPosition(43, 970);
	Lifes2.setPosition(940, 970);
	PowerText.setPosition(170, 970);
	PowerText2.setPosition(810, 970);
	ChicksText.setPosition(240, 970);
	ChicksText2.setPosition(750, 970);
	CutSceneMenu.setPosition(-850, -800);
	CutSceneGame.setPosition(-850, -800);
	//Egg.setScale(5, 5);
	Egg.setScale(2, 2.5);
	REDFireBullet.setPosition(Out, -Out);
	BLUEFireBullet.setPosition(Out, -Out);
	GREENFireBullet.setPosition(Out, -Out);
	BLUEFireBullet.setScale(0.05, 0.4);
	GREENFireBullet.setScale(0.4, 0.5);
	AlienBullet.setScale(1, 1.5);
	AlienBullet.setPosition(Out, Out);
	Meal.setPosition(Out, Out);
	Chick.setPosition(Out, Out);
	Chick.setScale(0.08, 0.08);
	Meal.setScale(0.12, 0.12);
	BossBox.setSize(Vector2f(200, 220));
	BossBox2.setSize(Vector2f(100, 100));
	BossBox3.setSize(Vector2f(100, 100));
	AlienBullet.setPosition(Out, Out);
	for (int i = 1; i <= 15; i++) {

		AlienBullets[i] = AlienBullet;
		AlienBullets[i].setPosition(Aliens[i].getPosition().x, Aliens[i].getPosition().y);
	}
	for (int i = 1; i <= 100; i++) {

		REDFireBullets[i] = REDFireBullet;
		REDFireBullets2[i] = REDFireBullet;
		BLUEFireBullets[i] = BLUEFireBullet;
		BLUEFireBullets2[i] = BLUEFireBullet;
		GREENFireBullets[i] = GREENFireBullet;
		GREENFireBullets2[i] = GREENFireBullet;

	}
	for (int i = 1; i <= 67; i++)
		Eggs[i] = Egg;
	for (int i = 1; i <= 64; i++) {
		EnemiesBox[i].setSize(Vector2f(30, 30));
		EnemiesBox[i].setPosition(Out, Out);
	}
	for (int i = 1; i <= 15; i++) {
		AliensBox[i].setSize(Vector2f(60, 30));
		AliensBox[i].setPosition(Out, Out);
		AlienBulletsBox[i].setSize(Vector2f(15, 40));
	}
	for (int i = 1; i <= 64; i++)
		Enemies[i] = Enemy;
	for (int i = 1; i <= 60; i++)
		Stones[i] = Stone;

	Alien.setPosition(Out, Out);
	Alien.setScale(0.6, 0.6);

	for (int i = 1; i <= 100; i++)
		Chicks[i] = Chick;
	for (int i = 1; i <= 32; i++)
		Meals[i] = Meal;
	//BossEnemy.setScale(1, 1.5);

	//

	BossEnemy.setPosition(Out, Out);

	RectangleSound.setSize(Vector2f(100, 100));
	RectangleSound.setFillColor(Color(72, 61, 139, 80));
	RectangleSound.setPosition(900, 200);

	SignSound.setPosition(900, 200);
	SignSound.setScale(.2, .2);
	SignSound.setColor(Color(25, 25, 112, 150));



	RectangleMusic.setSize(Vector2f(100, 100));
	RectangleMusic.setFillColor(Color(72, 61, 139, 80));
	RectangleMusic.setPosition(900, 500);

	SignMusic.setPosition(900, 500);
	SignMusic.setScale(.2, .2);
	SignMusic.setColor(Color(25, 25, 112, 150));



	Sign30.setPosition(300, 800);
	Sign30.setScale(.2, .2);
	Sign30.setColor(Color(25, 25, 112, 150));




	Sign60.setPosition(600, 800);
	Sign60.setScale(.2, .2);
	Sign60.setColor(Color(25, 25, 112, 150));



	Sign120.setPosition(900, 800);
	Sign120.setScale(.2, .2);
	Sign120.setColor(Color(25, 25, 112, 150));




	SoundMenu.setFont(font2);
	SoundMenu.setString("Sound : ");
	SoundMenu.setFillColor(Color::White);
	SoundMenu.setPosition(100, 200);



	MusicMenu.setFont(font2);
	MusicMenu.setString("Music : ");
	MusicMenu.setFillColor(Color::White);
	MusicMenu.setPosition(100, 500);



	BlackScreen.setFillColor(Color::Black);
	BlackScreen2.setFillColor(Color::Black);
	BlackScreen2.setPosition(500, 0);



	Escape.setFillColor(Color(0, 15, 68));




	ResumeBack.setFont(font2);
	ResumeBack.setString("Resume");
	ResumeBack.setCharacterSize(30);
	ResumeBack.setFillColor(Color::White);




	ClickResumeBack.setScale(.8, .9);




	QuitBack.setFont(font2);
	QuitBack.setString("Quit");
	QuitBack.setCharacterSize(30);
	QuitBack.setFillColor(Color::White);


	ClickQuitBack.setScale(.8, .9);

	OvalMute.setScale(0.3, 1);

	ClickMuteBack.setScale(.24, 1);


	MuteBack.setFont(font2);
	MuteBack.setString("Sound");
	MuteBack.setCharacterSize(30);
	MuteBack.setFillColor(Color::White);

	SignMute.setScale(0.15, 0.1);





	REDGift.setPosition(Out, Out);
	BLUEGift.setPosition(Out, Out);
	GREENGift.setPosition(Out, Out);
	REDGift.setScale(.7, .7);
	BLUEGift.setScale(.7, .7);
	GREENGift.setScale(.7, .7);
	Atom.setScale(1.5, 1.5);
	Atom.setPosition(Out, Out);
	for (int i = 1; i <= 48 + 60 + 15; i++) {
		REDGifts[i] = REDGift;

	}
	for (int i = 1; i <= 48 + 60 + 15; i++)
		BLUEGifts[i] = BLUEGift;
	for (int i = 1; i <= 48 + 60 + 15; i++)
		GREENGifts[i] = GREENGift;
	for (int i = 1; i <= 48 + 60 + 15; i++)
		Atoms[i] = Atom;

	Test.setFont(_Score);
	Test2.setFont(_Score);
	Test3.setFont(_Score);
	Test.setPosition(400, 400);
	Test2.setPosition(450, 400);
	Test3.setPosition(500, 400);
	Fork.setPosition(500, 500);
	text.setFont(font);
	text1.setFont(font);
	Player2Text.setFont(font);
	text1.setString("Special Thanks to Dr. Salsabil & Dr. Naglaa\n\n\nThanks to our Supporter: Mohamed waled");
	text1.setCharacterSize(55);
	text1.setPosition(0, TextStop + 70 + MenuView_Number);
	text2.setFont(font);
	text2.setString("By:\n\nPaula Emad\nBeshoy Sedra\nAya Mohamed\nAnas Saad\nAsmaa Salah\nEiad Amr\nAnton Abdallah ");
	text2.setCharacterSize(30);
	text2.setPosition(700, TextStop + 300 + MenuView_Number);
	Player2Text.setPosition(750, 950);
	Player2Text.setFillColor(Color(200, 200, 200, 130));
	Player2Text.setString("Press P for Player 2");
	PlayerName.setCharacterSize(45);
	PlayerName.setPosition(600, 400);
	PlayerName.setFont(font2);
	Name.setScale(2, 2);
	Name.setPosition(500, 200);

	//
	Shield.setScale(0.2, 0.2);
	Shield2.setScale(0.2, 0.2);
	Shield.setPosition(Out, Out);
	Shield2.setPosition(Out, Out);
	Shield2.setColor(Color::Red);
	srand(time(0));
	MealRandom1 = 1 + rand() % 16;
	MealRandom2 = 17 + rand() % 16;
	Wave1Random = 1 + rand() % 32;
	Wave1Random2 = 1 + rand() % 32;
	Wave2Random = 33 + rand() % 16;
	Wave3Random = 1 + rand() % 60;
	Wave4Random = 1 + rand() % 15;
	//for Enemies

	Gifts1Random = 1 + rand() % 4;
	Gifts2Random = 1 + rand() % 4;
	Gifts3Random = 1 + rand() % 4;
	Gifts4Random = 1 + rand() % 4;
	//for Gifts

	//cout << Wave1Random << endl;
	//cout << Gifts1Random << endl;
	//cout << Wave2Random << endl;
	//cout << Gifts2Random << endl;
	//cout << Wave3Random << endl;
	//cout << Gifts3Random << endl;
	//cout << Wave4Random << endl;
	//cout << Gifts4Random << endl;
	//1 ->RED , 2 ->BLUE, 3->GREEN, 4


	//Menu


//click

//before intesect
	_MainMenu[0].setFont(font2);//Menu
	_MainMenu[0].setString("New Game");//Menu
	_MainMenu[0].setOrigin(512, 384);//Menu
	_MainMenu[0].setPosition(980, 820);//Menu
	_MainMenu[0].setCharacterSize(30);//Menu
	_MainMenu[0].setFillColor(Color{ 147, 112, 219 });//Menu

	_MainMenu[1].setFont(font2);//Menu
	_MainMenu[1].setString("Load");//Menu
	_MainMenu[1].setOrigin(512, 384);//Menu
	_MainMenu[1].setPosition(1000, 920);//Menu
	_MainMenu[1].setCharacterSize(30);//Menu
	_MainMenu[1].setFillColor(Color{ 147, 112, 219 });//Menu
	AinShams.setFont(font2);
	AinShams.setOrigin(512, 384);
	AinShams.setPosition(850, 700);
	AinShams.setCharacterSize(75);
	AinShams.setFillColor(Color::White);

	Start.setOrigin(512, 384);//Menu
	Start.setPosition(780, 770);//Menu
	Start.setScale(.9, .9);//Menu
	StartBox.setPosition(450, 440);//Menu
	ClickStart.setOrigin(512, 384);//Menu
	ClickStart.setPosition(718, 632);//Menu
	ClickStart.setScale(.7, .9);//Menu

	Load.setOrigin(512, 384);//Menu
	Load.setPosition(780, 870);//Menu
	Load.setScale(.9, .9);//Menu
	LoadBox.setPosition(450, 540);//Menu
	ClickLoad.setOrigin(512, 384);//Menu
	ClickLoad.setPosition(718, 732);//Menu
	ClickLoad.setScale(.7, .9);//Menu
	Table.setOrigin(512, 384);//Menu
	Table.setPosition(780, 968);//Menu
	Table.setScale(.9, .9);//Menu
	TableBox.setPosition(450, 630);//Menu

	ClickTable.setOrigin(512, 384);//Menu
	ClickTable.setPosition(718, 830);//Menu
	ClickTable.setScale(.7, .9);//Menu

	_MainMenu[2].setFont(font2);//Menu
	_MainMenu[2].setString("Table");//Menu
	_MainMenu[2].setOrigin(512, 384);//Menu
	_MainMenu[2].setPosition(1000, 1015);//Menu
	_MainMenu[2].setCharacterSize(30);//Menu
	_MainMenu[2].setFillColor(Color{ 147, 112, 219 });//Menu

	//options

	Options.setOrigin(512, 384);//Menu
	Options.setPosition(780, 1056);//Menu
	Options.setScale(.9, .9);//Menu

	ClickOptions.setOrigin(512, 384);//Menu
	ClickOptions.setPosition(718, 918);//Menu
	ClickOptions.setScale(.7, .9);//Menu
	OptionsBox.setPosition(450, 730);//Menu


	_MainMenu[3].setFont(font2);//Menu
	_MainMenu[3].setString("Options...");//Menu
	_MainMenu[3].setOrigin(512, 384);//Menu
	_MainMenu[3].setPosition(990, 1105);//Menu
	_MainMenu[3].setCharacterSize(30);//Menu
	_MainMenu[3].setFillColor(Color{ 147, 112, 219 });//Menu

	//cREDits
	CREDits.setOrigin(512, 384);//Menu
	CREDits.setPosition(780, 1144);//Menu
	CREDits.setScale(.9, .9);//Menu


	//click

	ClickCREDits.setOrigin(512, 384);//Menu
	ClickCREDits.setPosition(718, 1006);//Menu
	ClickCREDits.setScale(.7, .9);//Menu

	CREDitsBox.setPosition(450, 820);//Menu

	_MainMenu[4].setFont(font2);//Menu
	_MainMenu[4].setString("CREDits");//Menu
	_MainMenu[4].setOrigin(512, 384);//Menu[]
	_MainMenu[4].setPosition(990, 1190);//Menu
	_MainMenu[4].setCharacterSize(30);//Menu
	_MainMenu[4].setFillColor(Color{ 147, 112, 219 });//Menu

	//Quit//Menu
	Quit.setOrigin(512, 384);//Menu
	Quit.setPosition(300, 1250);//Menu
	Quit.setScale(.55, .9);//Menu

	//click
	ClickQuit.setOrigin(512, 384);//Menu
	ClickQuit.setPosition(265, 1110);//Menu
	ClickQuit.setScale(.45, .89);//Menu
	QuitBox.setPosition(100, 930);//Menu


	_MainMenu[5].setFont(font2);//Menu
	_MainMenu[5].setString("X  Quit");//Menu
	_MainMenu[5].setOrigin(512, 384);//Menu
	_MainMenu[5].setPosition(610, 1300);//Menu
	_MainMenu[5].setCharacterSize(30);//Menu
	_MainMenu[5].setFillColor(Color{ 147, 112, 219 });//Menu
	//Menu


	REDFireSound.setBuffer(_REDFireSound); //Sound
	BLUEFireSound.setBuffer(_BLUEFireSound); //Sound
	REDFireSound2.setBuffer(_REDFireSound); //Sound
	BLUEFireSound2.setBuffer(_BLUEFireSound); //Sound
	ChickEat.setBuffer(_ChickEat); //Sound
	ChickEat2.setBuffer(_ChickEat); //Sound
	EggSound.setBuffer(_EggSound); //Sound
	EnemyDeadSound.setBuffer(_EnemyDeadSound); //Sound
	PlayerDeadSound.setBuffer(_PlayerDeadSound); //Sound
	Player2DeadSound.setBuffer(_PlayerDeadSound); //Sound
	BossDeadSound.setBuffer(_BossDeadSound);
	TakenGift.setBuffer(_TakenGift); //Sound
	TakenGift2.setBuffer(_TakenGift); //Sound
	Flying.setBuffer(_Flying); //Sound
	SelectMenu.setBuffer(_SelectMenu); //Sound
	EnterMenu.setBuffer(_Enter); //Sound
	EscapeMenu.setBuffer(_Escape); //Sound
	GREENFireSound.setBuffer(_GREENFireSound); //Sound
	GREENFireSound2.setBuffer(_GREENFireSound); //Sound
	AlienShot.setBuffer(_AlienShot); //Sound
	for (int i = 1; i <= 15; i++)
		AlienShots[i] = AlienShot;
	OneUp.setBuffer(_OneUp); //Sound

	IntroMenu.setBuffer(_IntroMenu); //Music
	Level1.setBuffer(_Level1); //Music
	BossTheme.setBuffer(_BossTheme); //Music
	WinMusic.setBuffer(_WinMusic);
	GameOverMusic.setBuffer(_GameOverMusic);
	BossHealthBorder.setPosition(210, 60 + WavesView_Number);
	BossHealthBar.setPosition(210, 70 + WavesView_Number);
	BossHealthBorder.setFillColor(Color::Black);
	BossHealthBar.setFillColor(Color(1, 232, 0));
	FireBar.setPosition(Out, Out);//8888
	for (int i = 0; i < 29; i++) {
		FireBars[i] = FireBar;
		FireBars[i].setPosition(160 + (8 * i), 7 + WavesView_Number);
		FireBars2[i] = FireBar2;
		FireBars2[i].setPosition(840 - (8 * i), 7 + WavesView_Number);

	}
	for (int i = 0; i < 10; i++)
		FireBars[i].setFillColor(Color::Blue);
	for (int i = 10; i < 20; i++)
		FireBars[i].setFillColor(Color::Green);
	for (int i = 20; i < 29; i++)
		FireBars[i].setFillColor(Color::Red);

	for (int i = 0; i < 10; i++)
		FireBars2[i].setFillColor(Color::Blue);
	for (int i = 10; i < 20; i++)
		FireBars2[i].setFillColor(Color::Green);
	for (int i = 20; i < 29; i++)
		FireBars2[i].setFillColor(Color::Red);

	Test10.setFont(font);
	Test11.setFont(font);
	Test12.setFont(font);
	Test13.setFont(font);
	nwave1.setFont(font);
	Test10.setPosition(320, 400);
	Test11.setPosition(390, 400);
	Test12.setPosition(500, 400);
	Test13.setPosition(570, 400);
	nwave1.setPosition(440, 450);

	Test8.setFont(font);
	Test9.setFont(font);
	nwave2.setFont(font);
	Test8.setPosition(400, 400);
	Test9.setPosition(480, 400);
	nwave2.setPosition(435, 450);

	Test6.setFont(font);
	Test7.setFont(font);
	nwave3.setFont(font);
	Test6.setPosition(400, 400);
	Test7.setPosition(480, 400);
	nwave3.setPosition(430, 450);



	Test3.setFont(font);
	Test4.setFont(font);
	Test5.setFont(font);
	nwave4.setFont(font);
	Test3.setPosition(370, 400);
	Test4.setPosition(460, 400);
	Test5.setPosition(530, 400);
	nwave4.setPosition(430, 450);
	Test.setFont(font);
	Test1.setFont(font);
	Test2.setFont(font);
	nwave5.setFont(font);
	Test.setPosition(400, 400);
	Test1.setPosition(450, 400);
	Test2.setPosition(500, 400);
	nwave5.setPosition(430, 450);
	GameOver.setFont(font);
	GameOver.setPosition(400, 400);
	GameOver.setScale(2, 2);


	Name.setFont(font2);

	EndGame.setPosition(180, 200 + MenuView_Number);
	EndGame.setFillColor(Color(0, 15, 68));


	OvalName.setPosition(300, 340 + MenuView_Number);



	Name.setString("Enter Your Name");
	Name.setCharacterSize(30);
	Name.setPosition(300, 250 + MenuView_Number);
	Name.setFillColor(Color::White);


	PlayerName.setFont(font2);
	PlayerName.setCharacterSize(30);
	PlayerName.setPosition(280, 350 + MenuView_Number);
	PlayerName.setFillColor(Color::White);

	for (int i = 10; i <= 18; i++) {
		Atoms[i] = Atom;
		Atoms[i].move(0, 2);
		REDGifts[i] = REDGift;
		BLUEGifts[i] = BLUEGift;
		GREENGifts[i] = GREENGift;
	}


	window.setFramerateLimit(60); //FPS

	//Settings
}
// life player system "Anas"

void Life()
{
	if (PlayerDeathbool == 1) {
		LifePlayer1--;
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (PlayerDeathbool2 == 1) {
		LifePlayer2--;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}


}

void Default() {
	timero = 0;
	chickenscore = 0;
	DeathAnimation = false;
	WavesView.setRotation(0);
	PlayerDeathbool = 0;
	PlayerDeath.setPosition(-Out, Out);
	PlayerDeath2.setPosition(-Out, Out);
	DeathAnimation2 = false;
	PlayerDeathbool2 = 0;
	timero5 = 0;
	BLUEScale = 0;
	BLUEScale2 = 0;
	FireNumber = 1;
	FireNumber2 = 1;
	P_Pressed = 0;
	if (Waves == 4) {
		for (int i = 1; i <= 15; i++)
			AlienBullets[i].setPosition(Out, Out);
	}
	if (Waves == 3) {
		for (int i = 1; i <= 30; i++) {
			Stones[i].setPosition((-50 * (1 + rand() % 50)), WavesView_Number - 100 * (1 + rand() % 50) + 300);
		}	for (int i = 31; i <= 60; i++) {
			Stones[i].setPosition((-40 * (1 + rand() % 50)), WavesView_Number - 100 * (1 + rand() % 50) + 800);
		}
	}
	for (int i = 1; i <= 60; i++) {
		Atoms[i].setPosition(-Out, Out);
		REDGifts[i].setPosition(-Out, Out);
		GREENGifts[i].setPosition(-Out, Out);
		BLUEGifts[i].setPosition(-Out, Out);
	}

	for (int i = 0; i < 100; i++) {
		chicken_Health[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		Rock_Health[i] = 0;
	}
	for (int i = 0; i < 50; i++) {
		alien_Health[i] = 0;
	}
	Rotation = 90;
	Rotation2 = -90;
	Rotation_1 = 90;
	Rotation_2 = 90;
	Rotation_3 = -90;
	Rotation_4 = -90;


	DeathExtra[1] = 0;
	DeathExtra[2] = 0;
	DeathExtra[3] = 0;
	DeathExtra[4] = 0;
	TextCounter10 = 0, TextCounter11 = 0, TextCounter12 = 0, TextCounter13 = 0, TextCounter14 = 0, nwavecounter1 = 0;
	TextCounter8 = 0, TextCounter9 = 0, nwavecounter2 = 0;
	TextCounter = 0, TextCounter1 = 0, TextCounter2 = 0, nwavecounter5 = 0;
	TextCounter3 = 0, TextCounter4 = 0, TextCounter5 = 0, nwavecounter4 = 0;
	TextCounter6 = 0, TextCounter7 = 0, nwavecounter3 = 0;

	Winning = 0;
	WaveTimer = 0;
	WinBool = 0;
	FlyingBool = 0;
	endtimer = 0;
	BackgroundSpeed = 2;
	GameOverbool = 0;
	GameOverTimer = 0;
	ChicksCounter1 = 0;
	ChicksCounter2 = 0;
	Waves = 1;//till all enemies dead waves++
	WavePosition = 1;//setPosition and WavePosition++;
	PowerType = RED;
	PowerLevel = 0;
	powerchick = 0;
	powerchick2 = 0;
	PowerType2 = BLUE;
	PowerLevel2 = 0;
	for (int i = 1; i <= 140; i++) {
		Deathbool[i] = 0;
		SmokeStop[i] = 0;
		xSmoke[i] = 0;
		ySmoke[i] = 0;
		Eggs[i].setPosition(Out, Out);
		Meals[i].setPosition(Out, Out);
	}
	WaveTimer = 0;
	Action = 0;
	for (int i = 1; i <= 32; i++) {
		Enemies[i].setPosition((-100 * i) - 1000, WavesView_Number + 970);
		SmokeStop[i] = 0;
		xSmoke[i] = 0;
		ySmoke[i] = 0;
		Eggs[i].setPosition(Out, Out);
		Meals[i].setPosition(Out, Out);

	}
	for (int i = 33; i <= 64; i++) {
		Enemies[i].setPosition(Out, Out);
		Eggs[i].setPosition(Out, Out);
	}
	Actionesta1 = 1,
		Actionesta2 = 1,
		Actionesta3 = 1,
		Actionesta4 = 1,
		Player2On = 0,
		ActScore = 0,
		TotalScore = 0,
		ScoreNumber = 0,
		TargetScore = 100000;

	for (int i = 1; i <= 100; i++)
		Chicks[i].setPosition(Out, Out);

	Player2On = 0;
	Player2.setPosition(-5050, 505050);
	Player.setPosition(450, ViewPort + 600);


	for (int i = 1; i <= 100; i++)
		REDFireBullets[i].setPosition(Out, -Out);

	for (int i = 1; i <= 100; i++)
		BLUEFireBullets[i].setPosition(Out, -Out);

	for (int i = 1; i <= 100; i++)
		GREENFireBullets[i].setPosition(Out, -Out);

	for (int i = 1; i <= 100; i++)
		REDFireBullets2[i].setPosition(Out, -Out);

	for (int i = 1; i <= 100; i++)
		BLUEFireBullets2[i].setPosition(Out, -Out);

	for (int i = 1; i <= 100; i++)
		GREENFireBullets2[i].setPosition(Out, -Out);

	LifePlayer1 = 3;
	LifePlayer2 = 0;

	PowerStop = 0;
	PowerStop2 = 0;

	for (int i = 1; i <= 15; i++) {
		Aliens[i].setPosition((-i * 400), 100 + WavesView_Number + (1 + rand() % 500));
	}

	BossEnemy.setPosition(500, WavesView_Number - 300);
	BossHealth = 100;
	WinTimer = 0;

	Test10.setFont(font);
	Test11.setFont(font);
	Test12.setFont(font);
	Test13.setFont(font);
	nwave1.setFont(font);
	Test10.setPosition(320, 400 + WavesView_Number);
	Test11.setPosition(390, 400 + WavesView_Number);
	Test12.setPosition(500, 400 + WavesView_Number);
	Test13.setPosition(570, 400 + WavesView_Number);
	nwave1.setPosition(440, 450 + WavesView_Number);

	Test8.setFont(font);
	Test9.setFont(font);
	nwave2.setFont(font);
	Test8.setPosition(400, 400 + WavesView_Number);
	Test9.setPosition(480, 400 + WavesView_Number);
	nwave2.setPosition(435, 450 + WavesView_Number);

	Test6.setFont(font);
	Test7.setFont(font);
	nwave3.setFont(font);
	Test6.setPosition(400, 400 + WavesView_Number);
	Test7.setPosition(480, 400 + WavesView_Number);
	nwave3.setPosition(430, 450 + WavesView_Number);



	Test3.setFont(font);
	Test4.setFont(font);
	Test5.setFont(font);
	nwave4.setFont(font);
	Test3.setPosition(370, 400 + WavesView_Number);
	Test4.setPosition(460, 400 + WavesView_Number);
	Test5.setPosition(530, 400 + WavesView_Number);
	nwave4.setPosition(430, 450 + WavesView_Number);
	Test.setFont(font);
	Test1.setFont(font);
	Test2.setFont(font);
	nwave5.setFont(font);
	Test.setPosition(400, 400 + WavesView_Number);
	Test1.setPosition(450, 400 + WavesView_Number);
	Test2.setPosition(500, 400 + WavesView_Number);
	nwave5.setPosition(430, 450 + WavesView_Number);
	GameOver.setFont(font);
	GameOver.setPosition(400, 400 + WavesView_Number);
	GameOver.setScale(2, 2);

}

int System() {

	TotalScore = ScoreNumber;
	if (ScoreNumber >= TotalScore)
		ActScore += 50;
	if (ActScore >= TotalScore + 50)
	{
		ActScore -= 50;


	}
	if (TotalScore >= TargetScore)
	{
		LifePlayer1++;
		OneUp.play();
		TargetScore += 100000;
	}


	return ActScore;

}

//BackGroundGame
void BackgroundGame() {
	WavesView.move(0, -BackgroundSpeed);
	WavesView_Number -= BackgroundSpeed;
	Player.move(0, -BackgroundSpeed);
	Player2.move(0, -BackgroundSpeed);
	//Player.move(0, ViewPort+WavesView_Number-1000);
	for (int i = 1; i <= 64; i++)
		Enemies[i].move(0, -BackgroundSpeed);
	BossEnemy.move(0, -BackgroundSpeed);
	TopBar.move(0, -BackgroundSpeed);
	TopBar2.move(0, -BackgroundSpeed);
	BottomBar.move(0, -BackgroundSpeed);
	BottomBar2.move(0, -BackgroundSpeed);
	Score.move(0, -BackgroundSpeed);
	Lifes.move(0, -BackgroundSpeed);
	Lifes2.move(0, -BackgroundSpeed);
	PowerText.move(0, -BackgroundSpeed);
	PowerText2.move(0, -BackgroundSpeed);
	ChicksText.move(0, -BackgroundSpeed);
	ChicksText2.move(0, -BackgroundSpeed);

	//Test.move(0, -BackgroundSpeed);
	//Test2.move(0, -BackgroundSpeed);
	//Test3.move(0, -BackgroundSpeed);
	Player2Text.move(0, -BackgroundSpeed);
	AlienBullet.move(0, -BackgroundSpeed);
	for (int i = 1; i <= 15; i++)
		Aliens[i].move(0, -BackgroundSpeed);
	CutSceneGame.move(0, -BackgroundSpeed);
	BossHealthBar.move(0, -BackgroundSpeed);
	BossHealthBorder.move(0, -BackgroundSpeed);
	for (int i = 0; i < 29; i++) {
		FireBars[i].move(0, -BackgroundSpeed);
		FireBars2[i].move(0, -BackgroundSpeed);
	}

	Test10.move(0, -BackgroundSpeed);
	Test11.move(0, -BackgroundSpeed);
	Test12.move(0, -BackgroundSpeed);
	Test13.move(0, -BackgroundSpeed);
	nwave1.move(0, -BackgroundSpeed);

	Test8.move(0, -BackgroundSpeed);
	Test9.move(0, -BackgroundSpeed);
	nwave2.move(0, -BackgroundSpeed);

	Test6.move(0, -BackgroundSpeed);
	Test7.move(0, -BackgroundSpeed);
	nwave3.move(0, -BackgroundSpeed);


	Test3.move(0, -BackgroundSpeed);
	Test4.move(0, -BackgroundSpeed);
	Test5.move(0, -BackgroundSpeed);
	nwave4.move(0, -BackgroundSpeed);



	Test.move(0, -BackgroundSpeed);
	Test1.move(0, -BackgroundSpeed);
	Test2.move(0, -BackgroundSpeed);
	nwave5.move(0, -BackgroundSpeed);

	GameOver.move(0, -BackgroundSpeed);
	//Fork.move(0, -BackgroundSpeed);
}
//BackGroundGame


//BackgroundMenu
void BackgroundMenu() {
	MenuView.move(0, -2); //view moving -5000
	MenuView_Number -= 2;//view 0 -5000
	Menu.move(0, -2);//Menu moving with background moving
	AinShams.move(0, -2);//AinShamsText moving with background moving
	Start.move(0, -2);//StartMenu moving with background moving
	Load.move(0, -2);//LoadMenu moving with background moving
	Table.move(0, -2);//TableMenu moving with background moving
	Options.move(0, -2);//OptionsMenu moving with background moving
	CREDits.move(0, -2);//CREDits moving with background moving
	Quit.move(0, -2);//QuitMenu moving with background moving
	StartBox.move(0, -2);//StartBox Collision Menu moving with background moving
	LoadBox.move(0, -2);//LoadBox Collision Menu moving with background moving
	TableBox.move(0, -2);//TableBox Collision Menu moving with background moving
	OptionsBox.move(0, -2);//OptionsBox Collision Menu moving with background moving
	CREDitsBox.move(0, -2);//CREDitsBox Collision Menu moving with background moving
	QuitBox.move(0, -2);//QuitBox Collision Menu moving with background moving

	ClickStart.move(0, -2);//ClickStart  Menu moving with background moving
	ClickLoad.move(0, -2);//ClickLoad  Menu moving with background moving
	ClickOptions.move(0, -2);//ClickOptions  Menu moving with background moving
	ClickTable.move(0, -2);//ClickTable  Menu moving with background moving
	ClickCREDits.move(0, -2);//ClickCREDits  Menu moving with background moving
	ClickQuit.move(0, -2);//ClickQuit  Menu moving with background moving
	PlayerName.move(0, -2);
	CutSceneMenu.move(0, -2);
	for (int i = 0; 10 > i; i++) {
		/*	window.draw(table[i].nameT);
			window.draw(table[i].scoreT);
			window.draw(table[i].levelsT);
			window.draw(Number[i]);*/
		table[i].nameT.move(0, -2);
		table[i].scoreT.move(0, -2);
		table[i].levelsT.move(0, -2);
		Number[i].move(0, -2);
	}

	RectangleSound.move(0, -2);
	RectangleMusic.move(0, -2);
	SignSound.move(0, -2);
	SignMusic.move(0, -2);
	MusicSelection.move(0, -2);

	SoundMenu.move(0, -2);
	MusicMenu.move(0, -2);
	text1.move(0, -2);
	text2.move(0, -2);
	for (int i = 0; i < Max_Menu; i++)
		_MainMenu[i].move(0, -2);//Ovals  Menu moving with background moving
	BlackScreen.move(0, -2);
	BlackScreen2.move(0, -2);
	Name.move(0, -2);
	OvalName.move(0, -2);
	//PlayerName.move(0, -2);
	EndGame.move(0, -2);

}
//BackgroundMenu

bool Eggbool = 0;

//ChickenEgg
void ChickenEgg() {
	for (int i = 1; i <= 67; i++)
		Eggs[i].move(0, +3);
	if (Waves == 1) {
		if (Eggbool) {
			EggNumber = 1 + rand() % 16;
			Eggbool = 0;
		}
		else {
			EggNumber = 17 + rand() % 16;
			Eggbool = 1;
		}


		if (testTimer >= 1)
		{

			testTimer = 0.1;
			/*for(int i=1;i<=32;i++)*/
			if (!Deathbool[EggNumber]) {
				Eggs[EggNumber].setPosition(EnemiesBox[EggNumber].getPosition().x + 40, EnemiesBox[EggNumber].getPosition().y);
				if (SoundOn)
					EggSound.play();

			}
			else

				Eggs[EggNumber].setPosition(Out, -Out);

			testTimer = 0.1;

		}
		testTimer += 0.009;

	}
	if (Waves == 2) {
		if (Eggbool) {
			EggNumber = 33 + rand() % 8; //33 48
			Eggbool = 0;

		}
		else {
			EggNumber = 41 + rand() % 8;
			Eggbool = 1;
		}


		if (testTimer >= 2)
		{

			testTimer = 0.1;
			/*for(int i=1;i<=32;i++)*/
			if (!Deathbool[EggNumber]) {
				Eggs[EggNumber].setPosition(EnemiesBox[EggNumber].getPosition().x + 40, EnemiesBox[EggNumber].getPosition().y);
				if (SoundOn)
					EggSound.play();
			}
			else
				Eggs[EggNumber].setPosition(Out, -Out);

			testTimer = 0.1;

		}
		testTimer += 0.009;

	}
	if (Waves == 5) {
		if (timero5 >= 3) {
			if (Eggs[65].getPosition().y >= WavesView_Number + 2000) {
				Eggs[65].setPosition(BossBox.getPosition().x + (50 * 65) - 3220, BossBox.getPosition().y + 100);
				EggSound.play();
				//egg sound
			}

			if (Eggs[66].getPosition().y >= WavesView_Number + 1500) {
				Eggs[66].setPosition(BossBox.getPosition().x + (50 * 66) - 3220, BossBox.getPosition().y + 100);
				EggSound.play();
			}

			if (Eggs[67].getPosition().y >= WavesView_Number + 1200) {
				Eggs[67].setPosition(BossBox.getPosition().x + (50 * 67) - 3220, BossBox.getPosition().y + 100);
				EggSound.play();
			}
		}
		//cout << Eggs[65].getPosition().x << endl;
		//cout << Eggs[65].getPosition().y << "    BossP  " << BossBox.getPosition().y << endl;
	}
}
//ChickenEgg


//DeadAnimation
void DeadAnimation() {
	if (DeathAnimation) {
		PlayerDeath.setTextureRect(IntRect(xDeath * 100, yDeath * 100, 100, 100));
		if (DeathTimer > 1.6) {
			xDeath++;
			DeathTimer = 0.1;
			PowerStop = 1;

		}
		if (xDeath >= 7) {
			xDeath = 0;
			yDeath++;
		}

		DeathTimer += 0.5;

		if (yDeath > 2)
		{
			yDeath = 0;
			xDeath = 0;
			WavesView.rotate(-ShakeReverse);
			DeathAnimation = 0;
			if (LifePlayer1 > 0) {
				Player.setPosition(450, ViewPort + 200);
				PowerStop = 0;
			}
			ShieldBool = 1;
			WavesView.setRotation(0);

		}

		if (ShakeTimer > 5) { //Shake
			WavesView.rotate(-ShakeReverse);
			ShakeTimer = 1 - ShakeSpeed;

			ShakeReverse *= -1;
		}
		ShakeTimer += 2;
	}
}



void DeadAnimation2() {
	if (DeathAnimation2) {
		PlayerDeath2.setTextureRect(IntRect(xDeath2 * 100, yDeath2 * 100, 100, 100));
		if (DeathTimer2 > 1.6) {
			xDeath2++;
			DeathTimer2 = 0.1;
			PowerStop2 = 1;

		}
		if (xDeath2 >= 7) {
			xDeath2 = 0;
			yDeath2++;
		}

		DeathTimer2 += 0.5;

		if (yDeath2 > 2)
		{
			yDeath2 = 0;
			xDeath2 = 0;
			WavesView.rotate(-ShakeReverse2);
			DeathAnimation2 = 0;
			if (LifePlayer2 > 0) {
				Player2.setPosition(450, ViewPort + 200);
				PowerStop2 = 0;
			}
			ShieldBool2 = 1; //Shield2

		}

		if (ShakeTimer2 > 5) { //Shake
			WavesView.rotate(-ShakeReverse2);
			ShakeTimer2 = 1 - ShakeSpeed2;

			ShakeReverse2 *= -1;
		}
		ShakeTimer2 += 2;
	}
}



void ShieldFunction() {
	if (ShieldBool) {
		ShieldTimer += 0.1;
		PlayerRecovery += 0.15;
		Shield.setPosition(Player.getPosition().x - 20, Player.getPosition().y - 20);
		if (PlayerRecovery > 1) {
			PlayerRecovery = 0.1;
			window.draw(Player);
		}

		if (ShieldTimer > 20) {
			ShieldBool = 0;
			Shield.setPosition(5000, 5000);
			ShieldTimer = 0.1;
		}


	}

	if (ShieldBool2) {
		ShieldTimer2 += 0.1;
		PlayerRecovery2 += 0.15;
		Shield2.setPosition(Player2.getPosition().x - 20, Player2.getPosition().y - 20);
		if (PlayerRecovery2 > 1) {
			PlayerRecovery2 = 0.1;
			window.draw(Player2);
		}

		if (ShieldTimer2 > 20) {
			ShieldBool2 = 0;
			Shield2.setPosition(5000, 5000);
			ShieldTimer2 = 0.1;
		}


	}
}

//DeadAnimation




//EnemyAnimation
void EnemyAnimation() {
	//Enemy
	EnemyAnimationTimer += 0.1;
	if (EnemyAnimationTimer >= 0.3) {
		if (!EnemyLastMove) {
			if (xEnemy == 8)
				EnemyLastMove = 1;
			xEnemy++;
			EnemyAnimationTimer = 0.02;
		}
		else {
			if (xEnemy == 1)
				EnemyLastMove = 0;
			xEnemy--;
			EnemyAnimationTimer = 0.02;

		}
	}
	for (int i = 1; i <= 64; i++)

		Enemies[i].setTextureRect(IntRect(xEnemy * 46.9, 0, 46.9, 38));
	BossEnemy.setTextureRect(IntRect(xEnemy * 3752 / 10, 0, 3752 / 10, 304));
}
//EnemyAnimation


//EnemyMovement
void EnemyMovement() {
	if (Waves == 1)
		for (int i = 1; i <= 32; i++)
			Enemies[i].move(EnemySpeed, 0);

	else if (Waves == 2) {
		for (int i = 33; i <= 40; i++) {
			Enemies[i].move(EnemySpeed, 0);
			Enemies[i + 16].move(EnemySpeed / 4, 0);

		}
		for (int i = 41; i <= 48; i++) {
			Enemies[i].move(EnemySpeed2, 0);
			Enemies[i + 16].move(EnemySpeed2 / 4, 0);
		}


	}

}
//EnemyMovement



//PlayerAnimation
void PlayerAnimation() {

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && xPlayer >= 0) {
		yPlayer = 1;
		if (xPlayer == 0)
			xPlayer++;
		if (xPlayer == 7) {
			xPlayer = 7;
			xaxis = 7;
		}
		else if (xaxis >= xPlayer) {
			xPlayer++;
		}
		else xaxis += 0.5;


	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && xPlayer <= 0) {

		yPlayer = 0;
		if (xPlayer == 0)
			xPlayer--;
		if (abs(xPlayer) == 7) {
			xPlayer = -7;
			xaxis = 7;
		}
		else if (xaxis >= abs(xPlayer)) {
			xPlayer--;
		}
		else xaxis += 0.5;
	}


	else	 if (Keyboard::isKeyPressed(Keyboard::Key::Down)) { //Down xaxis - Down left

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && xPlayer <= 0) {
			yPlayer = 0;
			if (xPlayer == 0)
				xPlayer++;
			if (xPlayer == -7) {
				xPlayer = -7;
				xaxis = 7;
			}
			else if (xaxis >= -xPlayer) {
				xPlayer--;
			}
			else xaxis += 0.5;



		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && xPlayer >= 0) {
			yPlayer = 1;
			if (xPlayer == 0)
				xPlayer++;
			if (xPlayer == 7) {
				xPlayer = 7;
				xaxis = 7;
			}
			else if (xaxis >= xPlayer) {
				xPlayer++;
			}
			else xaxis += 0.5;



		}
		else {

			if (xPlayer <= 0)
			{
				xPlayer = 0;
			}


			else if (xaxis <= xPlayer) {
				xPlayer--;
			}
			else xaxis -= 0.8;

		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {//Up xaxis - Up left

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && xPlayer <= 0) {
			yPlayer = 0;
			if (xPlayer == 0)
				xPlayer++;
			if (xPlayer == 7) {
				xPlayer = 7;
				xaxis = 7;
			}

			else if (xaxis >= xPlayer) {
				xPlayer++;
			}
			else xaxis += 0.5;



		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && xPlayer >= 0) {
			yPlayer = 1;
			if (xPlayer == 0)
				xPlayer++;
			if (xPlayer == 7) {
				xPlayer = 7;
				xaxis = 7;
			}

			else if (xaxis >= xPlayer) {
				xPlayer++;
			}
			else xaxis += 0.5;



		}
		else {

			if (xPlayer <= 0)
			{
				xPlayer = 0;
			}


			else if (xaxis <= xPlayer) {
				xPlayer--;
			}
			else xaxis -= 0.8;

		}

	}
	else {
		if (abs(xPlayer) <= 1)
		{
			xPlayer = 0;
		}


		else if (xaxis <= abs(xPlayer)) {
			if (xPlayer >= 0)
				xPlayer--;
			else xPlayer++;
		}
		else xaxis -= 0.66;


	}
}



void PlayerAnimation2() {

	if (Keyboard::isKeyPressed(Keyboard::Key::D) && xPlayer2 >= 0) {
		yPlayer2 = 1;
		if (xPlayer2 == 0)
			xPlayer2++;
		if (xPlayer2 == 7) {
			xPlayer2 = 7;
			xaxis2 = 7;
		}
		else if (xaxis2 >= xPlayer2) {
			xPlayer2++;
		}
		else xaxis2 += 0.5;


	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A) && xPlayer2 <= 0) {

		yPlayer2 = 0;
		if (xPlayer2 == 0)
			xPlayer2--;
		if (abs(xPlayer2) == 7) {
			xPlayer2 = -7;
			xaxis2 = 7;
		}
		else if (xaxis2 >= abs(xPlayer2)) {
			xPlayer2--;
		}
		else xaxis2 += 0.5;
	}


	else	 if (Keyboard::isKeyPressed(Keyboard::Key::S)) { //Down xaxis - Down left

		if (Keyboard::isKeyPressed(Keyboard::Key::A) && xPlayer2 <= 0) {
			yPlayer2 = 0;
			if (xPlayer2 == 0)
				xPlayer2++;
			if (xPlayer2 == -7) {
				xPlayer2 = -7;
				xaxis2 = 7;
			}
			else if (xaxis2 >= -xPlayer2) {
				xPlayer2--;
			}
			else xaxis2 += 0.5;



		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D) && xPlayer2 >= 0) {
			yPlayer2 = 1;
			if (xPlayer2 == 0)
				xPlayer2++;
			if (xPlayer2 == 7) {
				xPlayer2 = 7;
				xaxis2 = 7;
			}
			else if (xaxis2 >= xPlayer2) {
				xPlayer2++;
			}
			else xaxis2 += 0.5;



		}
		else {

			if (xPlayer2 <= 0)
			{
				xPlayer2 = 0;
			}


			else if (xaxis2 <= xPlayer2) {
				xPlayer2--;
			}
			else xaxis2 -= 0.8;

		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::W)) {//Up xaxis - Up left

		if (Keyboard::isKeyPressed(Keyboard::Key::A) && xPlayer2 <= 0) {
			yPlayer2 = 0;
			if (xPlayer2 == 0)
				xPlayer2++;
			if (xPlayer2 == 7) {
				xPlayer2 = 7;
				xaxis2 = 7;
			}

			else if (xaxis2 >= xPlayer2) {
				xPlayer2++;
			}
			else xaxis2 += 0.5;



		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D) && xPlayer2 >= 0) {
			yPlayer2 = 1;
			if (xPlayer2 == 0)
				xPlayer2++;
			if (xPlayer2 == 7) {
				xPlayer2 = 7;
				xaxis2 = 7;
			}

			else if (xaxis2 >= xPlayer2) {
				xPlayer2++;
			}
			else xaxis2 += 0.5;



		}
		else {

			if (xPlayer2 <= 0)
			{
				xPlayer2 = 0;
			}


			else if (xaxis2 <= xPlayer2) {
				xPlayer2--;
			}
			else xaxis2 -= 0.8;

		}

	}
	else {
		if (abs(xPlayer2) <= 1)
		{
			xPlayer2 = 0;
		}


		else if (xaxis2 <= abs(xPlayer2)) {
			if (xPlayer2 >= 0)
				xPlayer2--;
			else xPlayer2++;
		}
		else xaxis2 -= 0.66;


	}
}



//PlayerAnimation


//PlayerDead
void PlayerDead() {
	if (PlayerDeathbool) {//1
		powerchick /= 2;
		PowerLevel = powerchick;
		FireNumber = 1;
		PlayerDeath.setPosition(Player.getPosition().x, Player.getPosition().y); //SmokeAnimation

		for (int i = 1; i <= 100; i++)
			REDFireBullets[i].setPosition(Out, -Out);

		for (int i = 1; i <= 100; i++)
			BLUEFireBullets[i].setPosition(Out, -Out);

		for (int i = 1; i <= 100; i++)
			GREENFireBullets[i].setPosition(Out, -Out);

		if (SoundOn)
			PlayerDeadSound.play();

		PlayerDeathbool = 0;
	}

}




void PlayerDead2() {

	if (PlayerDeathbool2) {//1
		powerchick2 /= 2;
		PowerLevel2 = powerchick2;
		FireNumber2 = 1;

		for (int i = 1; i <= 100; i++)
			REDFireBullets2[i].setPosition(Out, -Out);

		for (int i = 1; i <= 100; i++)
			BLUEFireBullets2[i].setPosition(Out, -Out);

		for (int i = 1; i <= 100; i++)
			GREENFireBullets2[i].setPosition(Out, -Out);
		PlayerDeath2.setPosition(Player2.getPosition().x, Player2.getPosition().y); //SmokeAnimation
		if (SoundOn)
			Player2DeadSound.play();

		PlayerDeathbool2 = 0;
	}

}


//PlayerDead



//PlayerMovement
void PlayerMovement() {

	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {//Right up- Right down

		if (Speed <= 10)
			Speed += MovementSpeed;
		Player.move(Speed, 0);

		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

			if (Speed <= 10)
				Speed += MovementSpeed;
			Player.move(0, Speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

			if (Speed <= 10)
				Speed += MovementSpeed;

			Player.move(0, -Speed + 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {//Left up - Left down


		if (Speed <= 10)
			Speed += MovementSpeed;
		Player.move(-Speed, 0);
		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

			if (Speed <= 10)
				Speed += MovementSpeed;
			Player.move(0, Speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

			if (Speed <= 10)
				Speed += MovementSpeed;

			Player.move(0, -Speed + 1);
		}


	}

	else	 if (Keyboard::isKeyPressed(Keyboard::Key::Down)) { //Down right - Down left

		if (Speed <= 10)
			Speed += MovementSpeed;
		Player.move(0, Speed);
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {



			if (Speed <= 10)
				Speed += MovementSpeed;
			Player.move(-Speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {


			if (Speed <= 10)

				Speed += MovementSpeed;
			Player.move(Speed, 0);
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {//Up right - Up left

		if (Speed <= 10)
			Speed += MovementSpeed;
		Player.move(0, -Speed);
		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {


			if (Speed <= 10)
				Speed += MovementSpeed;
			Player.move(-Speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

			if (Speed <= 10)
				Speed += MovementSpeed;
			Player.move(Speed, 0);
		}

	}
	else
		Speed = 0;


}



void PlayerMovement2() {

	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {//Right up- Right down

		if (Speed2 <= 10)
			Speed2 += MovementSpeed;
		Player2.move(Speed2, 0);

		if (Keyboard::isKeyPressed(Keyboard::Key::S)) {

			if (Speed2 <= 10)
				Speed2 += MovementSpeed;
			Player2.move(0, Speed2);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {

			if (Speed2 <= 10)
				Speed2 += MovementSpeed;

			Player2.move(0, -Speed2 + 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {//Left up - Left down


		if (Speed2 <= 10)
			Speed2 += MovementSpeed;
		Player2.move(-Speed2, 0);
		if (Keyboard::isKeyPressed(Keyboard::Key::S)) {

			if (Speed2 <= 10)
				Speed2 += MovementSpeed;
			Player2.move(0, Speed2);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {

			if (Speed2 <= 10)
				Speed2 += MovementSpeed;

			Player2.move(0, -Speed2 + 1);
		}


	}

	else	 if (Keyboard::isKeyPressed(Keyboard::Key::S)) { //Down right - Down left

		if (Speed2 <= 10)
			Speed2 += MovementSpeed;
		Player2.move(0, Speed2);
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {



			if (Speed2 <= 10)
				Speed2 += MovementSpeed;
			Player2.move(-Speed2, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D)) {


			if (Speed2 <= 10)

				Speed2 += MovementSpeed;
			Player2.move(Speed2, 0);
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::W)) {//Up right - Up left

		if (Speed2 <= 10)
			Speed2 += MovementSpeed;
		Player2.move(0, -Speed2);
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {


			if (Speed2 <= 10)
				Speed2 += MovementSpeed;
			Player2.move(-Speed2, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D)) {

			if (Speed2 <= 10)
				Speed2 += MovementSpeed;
			Player2.move(Speed2, 0);
		}

	}
	else
		Speed2 = 0;


}

//PlayerMovement
bool PlayerFireReaction = 0;
float PlayerFireReactionTimer = 0;
bool Player2FireReaction = 0;
float Player2FireReactionTimer = 0;
//Power
bool Recharge = 0;
bool Recharge2 = 0;

void Power() {




	if (PowerStop == 0)
	{

		switch (PowerLevel) {
		case 0: {
			FireLoop = 10;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i++)
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 1: {
			FireLoop = 20;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 2) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(0, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 2: {
			FireLoop = 30;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 3) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(0, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 3: {
			FireLoop = 30;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 3) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-20.0f / 4, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++) {
					BLUEFireBullets[i].move(0, -33.0f - BackgroundSpeed);
				}
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 4: {
			FireLoop = 40;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 4) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-20.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(0, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 5: {
			FireLoop = 50;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 5) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-18.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 4].move((-18.0f - BackgroundSpeed) / 2, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 6: {
			FireLoop = 60;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 6) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 4].move((-18.0f - BackgroundSpeed) / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 5].move(0, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 7: {
			FireLoop = 70;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 7) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 4].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 5].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 6].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 8: {
			FireLoop = 80;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 8) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 4].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 5].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 6].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 7].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 9: {
			FireLoop = 100;
			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i += 10) {
					REDFireBullets[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 4].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 5].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 6].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 7].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 8].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets[i + 9].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType == BLUE) {
				for (int i = 1; i <= FireLoop; i++)
					BLUEFireBullets[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType == GREEN) {
				for (int i = 1; i <= FireLoop; i++)
					GREENFireBullets[i].move(0, -8.0f - BackgroundSpeed);
			}
		}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Space) && PowerTimer >= 2 && !PlayerFireReaction && !Recharge) {
			PlayerFireReaction++;
			FireBarsbool[BarCounter] = 1;
			if (BarCounter < 29)
				BarCounter++;
			if (BarCounter == 29)
				Recharge = 1;

		}
		else if (!PlayerFireReaction)
		{

			FireTimer = 0.1;
			if (BarTimer > 2) {
				BarTimer = 0;
				FireBarsbool[BarCounter] = 0;
				if (BarCounter > 0)
					BarCounter--;
				if (BarCounter == 0)
					Recharge = 0;
			}
			BarTimer += 0.5;
			Fire = 0;
		}
		else if (!PlayerFireReaction)
		{

			FireTimer = 0.1;


			Fire = 0;
		}
		/////////////
		if (PlayerFireReaction)
		{


			if (!Fire) {

				if (SoundGame == 1 && SoundOn)
					if (PowerType == RED)
						REDFireSound.play();
				if (PowerType == BLUE && SoundOn)
					BLUEFireSound.play();
				if (PowerType == GREEN && SoundOn)
					GREENFireSound.play();

				Fire++;



				switch (PowerLevel) {
				case 0: {
					BLUEScale %= 40;
					BLUEScale += 20;
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
					}
					else if (PowerType == BLUE) {
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + BLUEScale - 8, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 20);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
					}
					if (FireNumber >= FireLoop)
						FireNumber = 1;
					FireNumber++;

				}
					  break;
				case 1: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 42, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 5, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 14;
						BLUEScale += 7;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 + BLUEScale + 6, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 26 - BLUEScale - 6, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 11, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
				}
					  break;
				case 2: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 42, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 5, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 15);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 10;
						BLUEScale += 5;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 + BLUEScale + 3, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 - BLUEScale - 3, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 25, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 38, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 8, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 38);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
				}
					  break;
				case 3: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30,100);

						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 21 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 28);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 41, Player.getPosition().y - 28);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
				}
					  //REDFireBullets[FireNumber + 2].move(-30,100);
					  break;
				case 4: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 31, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 15, Player.getPosition().y - 10);
						REDFireBullets[FireNumber].setRotation(0);

						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);

						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 22, Player.getPosition().y - 30);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
					}
				}
					  break;
				case 5: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 43);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 37);
						GREENFireBullets[FireNumber].setScale(0.5, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 43);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 19, Player.getPosition().y - 53);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 33);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}

				}
					  break;
				case 6: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 40, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 40, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
					}
				}
					  break;
				case 7: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);//
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 5].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);//
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 92 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 92 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;


					}
				}
					  break;
				case 8: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 6 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 77 - 15, Player.getPosition().y - 73 + 65);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 15 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 60 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 15 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 13, Player.getPosition().y - 73 + 65);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 60 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
					}
				}
					  //REDFireBullets[FireNumber + 7].move(30, 100);
					  break;
				case 9: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 15); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y - 5);
						REDFireBullets[FireNumber].setRotation(15);

						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);

						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);

						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 103, Player.getPosition().y + 30 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);//

						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 8].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);

						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -53, Player.getPosition().y + 35 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);//

						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 9].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);

						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);

						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);

						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
						//REDFireBullets[FireNumber + 7].move(30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 6 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 70, Player.getPosition().y - 63 + 55);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 15, Player.getPosition().y - 63 + 55);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 11;
						FireNumber++;
					}
				}
					  break;
				}


			}//
			if (PowerType == RED)
				Player.move(0, 1.7 - FireTimer);
			if (PowerType == BLUE)
				Player.move(0, 0.2 - FireTimer);
			if (PowerType == GREEN)
				Player.move(0, 2 - FireTimer);


			FireTimer += 0.1;
			if (PowerType == RED)
				PowerSpeed = 3.4;
			if (PowerType == BLUE)
				PowerSpeed = 0.8;
			if (PowerType == GREEN)
				PowerSpeed = 4;
			if (0.01 - FireTimer < -PowerSpeed) { //Timer -3.4
				FireTimer = 0.06; //FireTImer0.06
				if (SoundGame == 1)
					if (PowerType == RED && SoundOn)
						REDFireSound.play();//SoundTimer	
				if (PowerType == BLUE && SoundOn)
					BLUEFireSound.play();//SoundTimer
				if (PowerType == GREEN && SoundOn)
					GREENFireSound.play();//SoundTimer

				switch (PowerLevel) {
				case 0: {
					BLUEScale %= 40;
					BLUEScale += 20;
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
					}
					else if (PowerType == BLUE) {
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + BLUEScale - 8, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 20);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
					}
					if (FireNumber >= FireLoop)
						FireNumber = 1;
					FireNumber++;

				}
					  break;
				case 1: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 42, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 5, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 14;
						BLUEScale += 7;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 + BLUEScale + 6, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 26 - BLUEScale - 6, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 11, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
					}
				}
					  break;
				case 2: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 42, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 5, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 15);
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 10;
						BLUEScale += 5;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 + BLUEScale + 3, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 - BLUEScale - 3, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 25, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 38, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 8, Player.getPosition().y - 26);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 38);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
				}
					  break;
				case 3: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30,100);

						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 21 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 28);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 41, Player.getPosition().y - 28);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
				}
					  //REDFireBullets[FireNumber + 2].move(-30,100);
					  break;
				case 4: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 31, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 15, Player.getPosition().y - 10);
						REDFireBullets[FireNumber].setRotation(0);

						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);

						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 22, Player.getPosition().y - 30);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
					}
				}
					  break;
				case 5: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 43);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 37);
						GREENFireBullets[FireNumber].setScale(0.5, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 35, Player.getPosition().y - 43);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 19, Player.getPosition().y - 53);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 33);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 4, Player.getPosition().y - 45);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}

				}
					  break;
				case 6: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 40, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 40, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x, Player.getPosition().y - 80 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 13, Player.getPosition().y - 110 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
					}
				}
					  break;
				case 7: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 23, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);//
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 5].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);//
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 92 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 92 + 40);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 34, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 108 + 40);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;


					}
				}
					  break;
				case 8: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 6 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 77 - 15, Player.getPosition().y - 73 + 65);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 15 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 60 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 15 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 30 - 15, Player.getPosition().y - 150 + 80);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 13, Player.getPosition().y - 73 + 65);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 60 - 15, Player.getPosition().y - 110 + 70);
						GREENFireBullets[FireNumber].setScale(0.5, 0.6);


						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
					}
				}
					  //REDFireBullets[FireNumber + 7].move(30, 100);
					  break;
				case 9: {
					if (PowerType == RED) {
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 29, Player.getPosition().y - 15); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 53, Player.getPosition().y - 5);
						REDFireBullets[FireNumber].setRotation(15);

						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						//REDFireBullets[FireNumber + 1].move(30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -7, Player.getPosition().y - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);

						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						//REDFireBullets[FireNumber + 2].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 90, Player.getPosition().y + 20 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);

						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						//REDFireBullets[FireNumber + 3].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 103, Player.getPosition().y + 30 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(23);//

						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						//REDFireBullets[FireNumber + 8].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -40, Player.getPosition().y + 25 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);

						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						//REDFireBullets[FireNumber + 4].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -53, Player.getPosition().y + 35 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-23);//

						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						//REDFireBullets[FireNumber + 9].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 17, Player.getPosition().y - 10 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(0);

						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + -18, Player.getPosition().y + 5 - 5); //Bullet with playerPosition
						REDFireBullets[FireNumber].setRotation(-15);

						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						//REDFireBullets[FireNumber + 6].move(-30, 100);
						REDFireBullets[FireNumber].setPosition(Player.getPosition().x + 66, Player.getPosition().y + 5);
						REDFireBullets[FireNumber].setRotation(15);

						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
						//REDFireBullets[FireNumber + 7].move(30, 100);
					}
					else if (PowerType == BLUE) {
						BLUEScale %= 12;
						BLUEScale += 6;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 43 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 7 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 24 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 29 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.05, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 20 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x - 3 - BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 35 + BLUEScale, Player.getPosition().y - 160);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.1, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 6 - BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						BLUEFireBullets[FireNumber].setPosition(Player.getPosition().x + 11 + BLUEScale, Player.getPosition().y - 160 - 35);
						BLUEFireBullets[FireNumber].setRotation(0);
						BLUEFireBullets[FireNumber].setScale(0.14, 0.4);
						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
					}
					else if (PowerType == GREEN) {
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 1;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 2;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 3;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);


						if (FireNumber >= FireLoop)
							FireNumber = 4;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 5;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 6;
						FireNumber++;

						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 70, Player.getPosition().y - 63 + 55);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);
						if (FireNumber >= FireLoop)
							FireNumber = 7;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 15, Player.getPosition().y - 63 + 55);
						GREENFireBullets[FireNumber].setScale(0.4, 0.5);


						if (FireNumber >= FireLoop)
							FireNumber = 8;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 20, Player.getPosition().y - 130 + 65);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 9;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x + 45, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 10;
						FireNumber++;
						GREENFireBullets[FireNumber].setPosition(Player.getPosition().x - 6, Player.getPosition().y - 118 + 70);
						GREENFireBullets[FireNumber].setScale(0.77, 0.7);
						if (FireNumber >= FireLoop)
							FireNumber = 11;
						FireNumber++;
					}
				}
					  break;
				}

			}

			if (PowerType == RED && 1.7 - FireTimer <= -1.6)
				PlayerFireReaction = 0;
			if (PowerType == BLUE && 0.2 - FireTimer <= -0.5)
				PlayerFireReaction = 0;
			if (PowerType == GREEN && 2 + 1.9 <= FireTimer)
				PlayerFireReaction = 0;
		}



		//////////
	}
	else {

		for (int i = 1; i <= 100; i++)
			REDFireBullets[i].setPosition(-50000, -10000);


		for (int i = 1; i <= 100; i++)
			BLUEFireBullets[i].setPosition(-50000, -10000);


		for (int i = 1; i <= 100; i++)
			GREENFireBullets[i].setPosition(-50000, -10000);

	}
}



void Power2() {




	if (PowerStop2 == 0)
	{

		switch (PowerLevel2) {
		case 0: {
			FireLoop2 = 10;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i++)
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 1: {
			FireLoop2 = 20;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 2) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(0, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 2: {
			FireLoop2 = 30;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 3) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(0, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -33.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 3: {
			FireLoop2 = 30;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 3) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-20.0f / 4, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++) {
					BLUEFireBullets2[i].move(0, -33.0f - BackgroundSpeed);
				}
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 4: {
			FireLoop2 = 40;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 4) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-20.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(0, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 5: {
			FireLoop2 = 50;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 5) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-18.0f / 3, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 4].move((-18.0f - BackgroundSpeed) / 2, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 6: {
			FireLoop2 = 60;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 6) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 4].move((-18.0f - BackgroundSpeed) / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 5].move(0, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 7: {
			FireLoop2 = 70;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 7) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 4].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 5].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 6].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 8: {
			FireLoop2 = 80;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 8) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 4].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 5].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 6].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 7].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13

				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}
			  break;
		case 9: {
			FireLoop2 = 100;
			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i += 10) {
					REDFireBullets2[i].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 1].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 2].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 3].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 4].move(13.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 5].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 6].move(-18.0f / 2, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 7].move(0, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 8].move(-18.0f / 4, -18.0f - BackgroundSpeed); //-13
					REDFireBullets2[i + 9].move(13.0f / 4, -18.0f - BackgroundSpeed); //-13
				}
			else if (PowerType2 == BLUE) {
				for (int i = 1; i <= FireLoop2; i++)
					BLUEFireBullets2[i].move(0, -38.0f - BackgroundSpeed);
			}
			else if (PowerType2 == GREEN) {
				for (int i = 1; i <= FireLoop2; i++)
					GREENFireBullets2[i].move(0, -8.0f - BackgroundSpeed);
			}
		}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::LControl) && PowerTimer2 >= 2 &&
			!Player2FireReaction && !Recharge2 && Player2On) {
			Player2FireReaction++;
			FireBarsbool2[BarCounter2] = 1;
			if (BarCounter2 < 29)
				BarCounter2++;
			if (BarCounter2 == 29)
				Recharge2 = 1;

		}
		else if (!Player2FireReaction)
		{

			FireTimer2 = 0.1;
			if (BarTimer2 > 2) {
				FireTimer2 = 0.1;
				if (BarTimer2 > 2) {
					BarTimer2 = 0;
					FireBarsbool2[BarCounter2] = 0;
					if (BarCounter2 > 0)
						BarCounter2--;
					if (BarCounter2 == 0)
						Recharge2 = 0;

				}

				//
			}



			BarTimer2 += 0.5;
			Fire2 = 0;
		}
		else if (!Player2FireReaction)
		{

			FireTimer2 = 0.1;


			Fire2 = 0;
		}
		/////////////
		if (Player2FireReaction)
		{


			if (!Fire2 && Player2On) {

				if (SoundGame == 1 && SoundOn && Player2On)
					if (PowerType2 == RED)
						REDFireSound2.play();
				if (PowerType2 == BLUE && SoundOn && Player2On)
					BLUEFireSound2.play();
				if (PowerType2 == GREEN && SoundOn && Player2On)
					GREENFireSound2.play();

				Fire2++;



				switch (PowerLevel2) {
				case 0: {
					BLUEScale2 %= 40;
					BLUEScale2 += 20;
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
					}
					else if (PowerType2 == BLUE) {
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + BLUEScale2 - 8, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 20);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
					}
					if (FireNumber2 >= FireLoop2)
						FireNumber2 = 1;
					FireNumber2++;

				}
					  break;
				case 1: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 42, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 5, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 14;
						BLUEScale2 += 7;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 + BLUEScale2 + 6, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 26 - BLUEScale2 - 6, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
				}
					  break;
				case 2: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 42, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 5, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 15);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 10;
						BLUEScale2 += 5;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 + BLUEScale2 + 3, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 - BLUEScale2 - 3, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 25, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 38, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 8, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 38);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
				}
					  break;
				case 3: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30,100);

						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 21 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 28);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 41, Player2.getPosition().y - 28);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
				}
					  //REDFireBullets2[FireNumber2 + 2].move(-30,100);
					  break;
				case 4: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 31, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15, Player2.getPosition().y - 10);
						REDFireBullets2[FireNumber2].setRotation(0);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 22, Player2.getPosition().y - 30);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
					}
				}
					  break;
				case 5: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 43);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 37);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 43);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 19, Player2.getPosition().y - 53);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 33);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}

				}
					  break;
				case 6: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 40, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 40, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
					}
				}
					  break;
				case 7: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);//
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 5].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);//
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 92 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 92 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;


					}
				}
					  break;
				case 8: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 6 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 77 - 15, Player2.getPosition().y - 73 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 60 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 13, Player2.getPosition().y - 73 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 60 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
					}
				}
					  //REDFireBullets2[FireNumber2 + 7].move(30, 100);
					  break;
				case 9: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 15); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y - 5);
						REDFireBullets2[FireNumber2].setRotation(15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 103, Player2.getPosition().y + 30 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);//

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 8].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -53, Player2.getPosition().y + 35 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);//

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 9].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 7].move(30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 6 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 70, Player2.getPosition().y - 63 + 55);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 15, Player2.getPosition().y - 63 + 55);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 11;
						FireNumber2++;
					}
				}
					  break;
				}


			}//
			if (PowerType2 == RED)
				Player2.move(0, 1.7 - FireTimer2);
			if (PowerType2 == BLUE)
				Player2.move(0, 0.2 - FireTimer2);
			if (PowerType2 == GREEN)
				Player2.move(0, 2 - FireTimer2);


			FireTimer2 += 0.1;
			if (PowerType2 == RED)
				PowerSpeed = 3.4;
			if (PowerType2 == BLUE)
				PowerSpeed = 0.8;
			if (PowerType2 == GREEN)
				PowerSpeed = 4;
			if (0.01 - FireTimer2 < -PowerSpeed) { //Timer -3.4
				FireTimer2 = 0.06; //FireTimer20.06
				if (SoundGame == 1 && Player2On)
					if (SoundGame == 1 && SoundOn && Player2On)
						if (PowerType2 == RED)
							REDFireSound2.play();
				if (PowerType2 == BLUE && SoundOn && Player2On)
					BLUEFireSound2.play();
				if (PowerType2 == GREEN && SoundOn && Player2On)
					GREENFireSound2.play();


				switch (PowerLevel2) {
				case 0: {
					BLUEScale2 %= 40;
					BLUEScale2 += 20;
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
					}
					else if (PowerType2 == BLUE) {
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + BLUEScale2 - 8, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 20);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
					}
					if (FireNumber2 >= FireLoop2)
						FireNumber2 = 1;
					FireNumber2++;

				}
					  break;
				case 1: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 42, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 5, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 14;
						BLUEScale2 += 7;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 + BLUEScale2 + 6, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 26 - BLUEScale2 - 6, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
					}
				}
					  break;
				case 2: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 42, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 5, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 15);
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 10;
						BLUEScale2 += 5;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 + BLUEScale2 + 3, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 - BLUEScale2 - 3, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 25, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 38, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 8, Player2.getPosition().y - 26);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 38);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
				}
					  break;
				case 3: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30,100);

						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 21 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 28);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 41, Player2.getPosition().y - 28);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
				}
					  //REDFireBullets2[FireNumber2 + 2].move(-30,100);
					  break;
				case 4: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 31, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15, Player2.getPosition().y - 10);
						REDFireBullets2[FireNumber2].setRotation(0);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 22, Player2.getPosition().y - 30);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
					}
				}
					  break;
				case 5: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 43);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 37);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35, Player2.getPosition().y - 43);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 19, Player2.getPosition().y - 53);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 33);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 4, Player2.getPosition().y - 45);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}

				}
					  break;
				case 6: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 40, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x, Player2.getPosition().y - 80
							+ 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 40, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x, Player2.getPosition().y - 80 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 13, Player2.getPosition().y - 110 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
					}
				}
					  break;
				case 7: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 23, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);//
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 5].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);//
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 92 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 92 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 34, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 108 + 40);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;


					}
				}
					  break;
				case 8: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 6 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 77 - 15, Player2.getPosition().y - 73 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 60 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 15 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 30 - 15, Player2.getPosition().y - 150 + 80);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 13, Player2.getPosition().y - 73 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 60 - 15, Player2.getPosition().y - 110 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.5, 0.6);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
					}
				}
					  //REDFireBullets2[FireNumber2 + 7].move(30, 100);
					  break;
				case 9: {
					if (PowerType2 == RED) {
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29, Player2.getPosition().y - 15); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 53, Player2.getPosition().y - 5);
						REDFireBullets2[FireNumber2].setRotation(15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 1].move(30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -7, Player2.getPosition().y - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 2].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 90, Player2.getPosition().y + 20 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 3].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 103, Player2.getPosition().y + 30 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(23);//

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 8].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -40, Player2.getPosition().y + 25 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 4].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -53, Player2.getPosition().y + 35 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-23);//

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 9].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 17, Player2.getPosition().y - 10 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(0);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + -18, Player2.getPosition().y + 5 - 5); //Bullet with Player2Position
						REDFireBullets2[FireNumber2].setRotation(-15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 6].move(-30, 100);
						REDFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 66, Player2.getPosition().y + 5);
						REDFireBullets2[FireNumber2].setRotation(15);

						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
						//REDFireBullets2[FireNumber2 + 7].move(30, 100);
					}
					else if (PowerType2 == BLUE) {
						BLUEScale2 %= 12;
						BLUEScale2 += 6;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 43 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 7 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 24 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 29 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.05, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 3 - BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 35 + BLUEScale2, Player2.getPosition().y - 160);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.1, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 6 - BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						BLUEFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 11 + BLUEScale2, Player2.getPosition().y - 160 - 35);
						BLUEFireBullets2[FireNumber2].setRotation(0);
						BLUEFireBullets2[FireNumber2].setScale(0.14, 0.4);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
					}
					else if (PowerType2 == GREEN) {
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 1;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 2;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 3;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 4;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 5;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 6;
						FireNumber2++;

						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 70, Player2.getPosition().y - 63 + 55);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 7;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 15, Player2.getPosition().y - 63 + 55);
						GREENFireBullets2[FireNumber2].setScale(0.4, 0.5);


						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 8;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 20, Player2.getPosition().y - 130 + 65);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 9;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x + 45, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 10;
						FireNumber2++;
						GREENFireBullets2[FireNumber2].setPosition(Player2.getPosition().x - 6, Player2.getPosition().y - 118 + 70);
						GREENFireBullets2[FireNumber2].setScale(0.77, 0.7);
						if (FireNumber2 >= FireLoop2)
							FireNumber2 = 11;
						FireNumber2++;
					}
				}
					  break;
				}

			}

			if (PowerType2 == RED && 1.7 - FireTimer2 <= -1.6)
				Player2FireReaction = 0;
			if (PowerType2 == BLUE && 0.2 - FireTimer2 <= -0.5)
				Player2FireReaction = 0;
			if (PowerType2 == GREEN && 2 + 1.9 <= FireTimer2)
				Player2FireReaction = 0;
		}



		//////////
	}
	else {

		for (int i = 1; i <= 100; i++)
			REDFireBullets2[i].setPosition(-Out, -Out);


		for (int i = 1; i <= 100; i++)
			BLUEFireBullets2[i].setPosition(-Out, -Out);


		for (int i = 1; i <= 100; i++)
			GREENFireBullets2[i].setPosition(-Out, -Out);

	}
}


//Power

void Action2Extra() {
	if (DeathExtra[1] == 2)
		if (Enemies[36 + 16].getPosition().x >= 0) {
			//
			for (int i = 33 + 16; i <= 36 + 16; i++)
				Enemies[i].setRotation(Rotation_1);
			if (Rotation_1 > 0)
				Rotation_1--;

			if (Rotation_1 < 90 && Rotation_1 != 0)
				for (int i = 33 + 16; i <= 36 + 16; i++)
					Enemies[i].move(3, -2);
			//
			else  EnemyMovement();
		}

		else
			for (int i = 33 + 16; i <= 36 + 16; i++)

				Enemies[i].move(10, 0);
	//
	if (DeathExtra[2] == 2)
		if (Enemies[40 + 16].getPosition().x >= 0) {
			//
			for (int i = 37 + 16; i <= 40 + 16; i++)
				Enemies[i].setRotation(Rotation_2);
			if (Rotation_2 > 0)
				Rotation_2--;

			if (Rotation_2 < 90 && Rotation_2 != 0)
				for (int i = 37 + 16; i <= 40 + 16; i++)
					Enemies[i].move(3, -2);
			//
			else  EnemyMovement();
		}

		else
			for (int i = 37 + 16; i <= 40 + 16; i++)
				Enemies[i].move(10, 0);
	//
	if (DeathExtra[3] == 2)
		if (Enemies[41 + 16].getPosition().x <= 900) {
			//
			for (int i = 41 + 16; i <= 44 + 16; i++)
				Enemies[i].setRotation(Rotation_3);
			if (Rotation_3 < 0)
				Rotation_3++;

			if (Rotation_3 > -90 && Rotation_3 != 0)
				for (int i = 41 + 16; i <= 44 + 16; i++)
					Enemies[i].move(-3, -2);
			//
			else  EnemyMovement();
		}

		else
			for (int i = 41 + 16; i <= 44 + 16; i++)

				Enemies[i].move(-10, 0);
	//
	if (DeathExtra[4] == 2)
		if (Enemies[45 + 16].getPosition().x <= 900) {
			//
			for (int i = 45 + 16; i <= 48 + 16; i++)
				Enemies[i].setRotation(Rotation_4);
			if (Rotation_4 < 0)
				Rotation_4++;

			if (Rotation_4 > -90 && Rotation_4 != 0)
				for (int i = 45 + 16; i <= 48 + 16; i++)
					Enemies[i].move(-3, -2);
			//
			else  EnemyMovement();
		}

		else
			for (int i = 45 + 16; i <= 48 + 16; i++)

				Enemies[i].move(-10, 0);

}




//Waves
void Wave1() {
	for (int i = 1; i <= 8; i++) {
		if (i % 2 == 0)
			Enemies[i] = Enemy2;

		else
			Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * i) - 1000, WavesView_Number + 970);
		//cout << Enemies[1].getPosition().x << endl;

	}for (int i = 9; i <= 16; i++) {
		if (i % 2 == 0)
			Enemies[i] = Enemy2;

		else
			Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * (i - 8)) - 1000, WavesView_Number + 970);
	}
	for (int i = 17; i <= 24; i++) {
		if (i % 2 == 0)
			Enemies[i] = Enemy2;

		else
			Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * (i - 16)) - 1000, WavesView_Number + 970);
	}
	for (int i = 25; i <= 32; i++) {
		if (i % 2 == 0)
			Enemies[i] = Enemy2;

		else
			Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * (i - 24)) - 1000, WavesView_Number + 970);
	}

	for (int i = 1; i <= 300; i++)
		Smokes[i] = Smoke;

}
void Wave2() {
	for (int i = 33; i <= 36; i++) {
		Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * i) + 1000, WavesView_Number + 200);

	}
	for (int i = 37; i <= 40; i++) {
		Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * i) + 1200, WavesView_Number + 400);

	}

	for (int i = 41; i <= 44; i++) {
		Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * i) + 7800, WavesView_Number + 300);

	}
	for (int i = 45; i <= 48; i++) {
		Enemies[i] = Enemy;
		Enemies[i].setScale(2, 2);
		Enemies[i].setPosition((-100 * i) + 8000, WavesView_Number + 500);

	}

	for (int i = 33; i <= 64; i++)
		Smokes[i] = Smoke;
}
void Wave2Extra() {
	if (DeathExtra[1] == 1)
		for (int i = 33 + 16; i <= 36 + 16; i++) {
			Enemies[i] = Enemy2;
			Enemies[i].setScale(2, 2);
			Enemies[i].setPosition((-100 * i) + 4000, WavesView_Number + 200);
			Enemies[i].setRotation(Rotation_1);
			DeathExtra[1] = 2;
		}
	if (DeathExtra[2] == 1)

		for (int i = 37 + 16; i <= 40 + 16; i++) {
			Enemies[i] = Enemy2;
			Enemies[i].setScale(2, 2);
			Enemies[i].setPosition((-100 * i) + 4000, WavesView_Number + 400);
			Enemies[i].setRotation(Rotation_2);

			DeathExtra[2] = 2;

		}
	if (DeathExtra[3] == 1)

		for (int i = 41 + 16; i <= 44 + 16; i++) {
			Enemies[i] = Enemy2;
			Enemies[i].setScale(2, 2);
			Enemies[i].setPosition((-100 * i) + 8000, WavesView_Number + 300);
			Enemies[i].setRotation(Rotation_3);

			DeathExtra[3] = 2;

		}
	if (DeathExtra[4] == 1)

		for (int i = 45 + 16; i <= 48 + 16; i++) {
			Enemies[i] = Enemy2;
			Enemies[i].setScale(2, 2);
			Enemies[i].setPosition((-100 * i) + 8000, WavesView_Number + 500);
			Enemies[i].setRotation(Rotation_4);

			DeathExtra[4] = 2;

		}


}
void Wave3() {
	for (int i = 1; i <= 30; i++) {
		Stones[i].setPosition((-50 * (1 + rand() % 50)), WavesView_Number - 100 * (1 + rand() % 50) + 300);
	}	for (int i = 31; i <= 60; i++) {
		Stones[i].setPosition((-40 * (1 + rand() % 50)), WavesView_Number - 100 * (1 + rand() % 50) + 800);
	}

	for (int i = 65; i <= 124; i++)
		Smokes[i] = Smoke;
}
void Wave4() {
	for (int i = 1; i <= 15; i++) {
		Aliens[i] = Alien;
		//Aliens[i].setPosition((-i * 400), 300 + WavesView_Number);
		Aliens[i].setPosition((-i * 400), 100 + WavesView_Number + (1 + rand() % 500));
	}
	for (int i = 125; i <= 139; i++)
		Smokes[i] = Smoke;
}


void Wave5() {
	BossEnemy.setPosition(500, WavesView_Number - 300);
	Smokes[140] = Smoke;
	Smokes[140].setScale(2, 2);
}

//


void Collision() {



	//Colision with wall
	if (Player.getPosition().x <= 5)
		Player.move(Speed, 0);
	if (Player.getPosition().x >= 910)
		Player.move(-Speed, 0);
	if (Player.getPosition().y <= WavesView_Number)
		Player.move(0, Speed);
	if (Player.getPosition().y >= 900 + WavesView_Number)
		Player.move(0, -Speed);
	////
	if (Player2.getPosition().x <= 5)
		Player2.move(Speed2, 0);
	if (Player2.getPosition().x >= 910)
		Player2.move(-Speed2, 0);
	if (Player2.getPosition().y <= WavesView_Number)
		Player2.move(0, Speed2);
	if (Player2.getPosition().y >= 900 + WavesView_Number)
		Player2.move(0, -Speed2);
	//


	if (Waves == 1) {
		/*for (int i = 1; i <= 32; i++) {*/
		if (Enemies[32].getPosition().x <= -10 || Enemies[8].getPosition().x <= -10 || Enemies[16].getPosition().x <= -10 || Enemies[24].getPosition().x <= -10)
			EnemySpeed = 2;
		if (Enemies[1].getPosition().x >= 910 || Enemies[9].getPosition().x >= 910 || Enemies[17].getPosition().x >= 910 || Enemies[25].getPosition().x >= 910)
			EnemySpeed = -2;
		//}
	}
	//cout << "Number: " << EggNumber << endl;
	if (Waves == 2) {

		for (int i = 33; i <= 40; i++) {
			if (Enemies[i].getPosition().x <= -10)
				EnemySpeed = 2;
			if (Enemies[i].getPosition().x >= 910)
				EnemySpeed = -2;

		}		for (int i = 41; i <= 48; i++) {
			if (Enemies[i].getPosition().x <= -10)
				EnemySpeed2 = 2;
			if (Enemies[i].getPosition().x >= 910)
				EnemySpeed2 = -2;

		}

	}


	//
	for (int k = 1; k <= 32; k++) {
		if (!ShieldBool && WaveTimer >= 2)
			if (Player.getGlobalBounds().intersects(Eggs[k].getGlobalBounds())) {
				Eggs[k].setPosition(500, 3000);
				BLUEScale = 0;
				PlayerDeathbool = 1;
				Life();
				PlayerDead();

				DeathAnimation = 1;

				Player.setPosition(-Out, -Out);


				Fire = 1; //NoFireSound

			}
	}
	//
	for (int k = 1; k <= 32; k++) {

		if (!ShieldBool2 && WaveTimer >= 2 && Player2On)
			if (Player2.getGlobalBounds().intersects(Eggs[k].getGlobalBounds())) {
				BLUEScale2 = 0;
				Eggs[k].setPosition(500, 3000);

				PlayerDeathbool2 = 1;
				Life();
				PlayerDead2();

				DeathAnimation2 = 1;

				Player2.setPosition(-Out, -Out);

				Fire2 = 1; //NoFireSound

			}
	}

	ViewPort = WavesView.getViewport().height + WavesView_Number + 1000; //When Dying

	if (Waves == 1) {
		timero += 0.01;
		for (int i = 2; i <= 32; i += 2) {
			if (Deathbool[i] == 1 && chicken_Health[i] == 0) {
				chick[i] = 1;
				chick[i + 1] = 1;
				chick[i + 2] = 1;
				chick[i + 3] = 1;

			}
			if (chicken_Health[i] < 1)
				Deathbool[i] = 0;

			if (chicken_Health[i - 1] < 2)
				Deathbool[i - 1] = 0;



		}

		if (Deathbool[0] == 1) {
			chick[1] = 1;
			chick[2] = 1;
			chick[3] = 1;
		}


		if (PowerType == RED)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (REDFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						REDFireBullets[i].setPosition(-Out, -Out);

						if (j % 2 == 0) {
							chicken_Health[j] += 1;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;

								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;
								}
								EnemiesBox[j].setPosition(-Out, Out);

								ScoreNumber += 1000;
								chickenscore += 1000;
							}
						}


						else


							chicken_Health[j] += 1; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {

							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);

							ScoreNumber += 1000;
							chickenscore += 1000;
						}
					}


					//



				}



			}//
		if (PowerType == BLUE)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (BLUEFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						BLUEFireBullets[i].setPosition(-Out, -Out);

						if (j % 2 == 0) {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;
								}
								EnemiesBox[j].setPosition(-Out, Out);

								ScoreNumber += 1000;
								chickenscore += 1000;
							}

						}


						else


							chicken_Health[j] += 0.25; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {

							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);

							ScoreNumber += 1000;
							chickenscore += 1000;
						}
					}


					//



				}



			}//
		if (PowerType2 == RED)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (REDFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						REDFireBullets2[i].setPosition(-Out, -Out);

						if (j % 2 == 0) {
							chicken_Health[j] += 1;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;
								}
								EnemiesBox[j].setPosition(-Out, Out);
								chickenscore += 1000;

							}
						}


						else


							chicken_Health[j] += 1; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {

							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);
							chickenscore += 1000;
						}
					}


					//



				}



			}//
		if (PowerType2 == BLUE)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (BLUEFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						BLUEFireBullets2[i].setPosition(-Out, -Out);

						if (j % 2 == 0) {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;
								}
								EnemiesBox[j].setPosition(-Out, Out);
								chickenscore += 1000;

							}
						}


						else


							chicken_Health[j] += 0.25; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {

							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);
							chickenscore += 1000;
						}
					}


					//



				}



			}//////////
		if (PowerType2 == GREEN)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (GREENFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						GREENFireBullets2[i].setPosition(-Out, -Out);
						if (j % 2 == 0) {
							chicken_Health[j] += 1.5;
							if (chicken_Health[j] >= 1) {
								if (!Deathbool[j])
									chickenscore += 1000;
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;

								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;

								}
								EnemiesBox[j].setPosition(-Out, Out);

							}
						}


						else


							chicken_Health[j] += 1.5; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {
							if (!Deathbool[j])
								chickenscore += 1000;
							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);

						}
					}


					//



				}



			}////////
		if (PowerType == GREEN)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 1; j <= 32; j++)//Enemies
				{
					if (GREENFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						GREENFireBullets[i].setPosition(-Out, -Out);

						if (j % 2 == 0) {
							chicken_Health[j] += 1.5;
							if (chicken_Health[j] >= 1) {
								if (!Deathbool[j])
									chickenscore += 1000;
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;

								if (chicken_Health[j] >= 1 && chick[j] == 1)
								{
									Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
									EnemiesBox[j].setPosition(-Out, Out);
									Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
									chick[j] = 0;
								}
								EnemiesBox[j].setPosition(-Out, Out);

								ScoreNumber += 1000;

							}
						}


						else


							chicken_Health[j] += 1.5; //Enemies with double damages 



						if (chicken_Health[j] >= 2) {
							if (!Deathbool[j])
								chickenscore += 1000;
							Deathbool[j] = 1;

							if (chicken_Health[j] >= 1 && chick[j] == 1)
							{
								Deathbool[j] = 1;     //Enemies[j1]=Enemiesdie;
								EnemiesBox[j].setPosition(-Out, Out);
								Enemies[j].setPosition(Enemies[j].getPosition().x, Out);
								chick[j] = 0;
							}
							EnemiesBox[j].setPosition(-Out, Out);
							ScoreNumber += 1000;
						}
					}


					//



				}



			}//



		for (int i = 1; i <= 32; i++) {
			if (!ShieldBool)
				if (Player.getGlobalBounds().intersects(EnemiesBox[i].getGlobalBounds()))
				{
					BLUEScale = 0;
					chicken_Health[i] = 2;//eiad
					Deathbool[i] = 1; //Enemies

					PlayerDeathbool = 1; //Player
					Life();

					PlayerDead();
					DeathAnimation = 1;

					Player.setPosition(-Out, -Out);

					Fire = 1; //NoFireSound

					if (chick[i] == 1)
					{
						Deathbool[i] = 1;     //Enemies[j1]=Enemiesdie;
						EnemiesBox[i].setPosition(Out, Out);
						Enemies[i].setPosition(Enemies[i].getPosition().x, Out);
						chick[i] = 0;
					}
					EnemiesBox[i].setPosition(Out, Out);
					chickenscore += 1000;
				}
		}
		for (int i = 1; i <= 32; i++) {
			if (!ShieldBool2)
				if (Player2.getGlobalBounds().intersects(EnemiesBox[i].getGlobalBounds()))
				{
					BLUEScale2 = 0;
					chicken_Health[i] = 2;//eiad
					Deathbool[i] = 1; //Enemies

					PlayerDeathbool2 = 1; //Player
					Life();

					PlayerDead2();
					DeathAnimation2 = 1;

					Player2.setPosition(-Out, -Out);

					Fire2 = 1; //NoFireSound

					if (chick[i] == 1)
					{
						Deathbool[i] = 1;     //Enemies[j1]=Enemiesdie;
						EnemiesBox[i].setPosition(Out, Out);
						Enemies[i].setPosition(Enemies[i].getPosition().x, Out);
						chick[i] = 0;
					}
					EnemiesBox[i].setPosition(Out, Out);
					chickenscore += 1000;
				}
		}
	}
	if (Waves == 2) {


		if (PowerType == RED)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (REDFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						REDFireBullets[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j]++;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);
								ScoreNumber += 1000;




								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							Deathbool[j] = 1;

							EnemiesBox[j].setPosition(-Out, Out);
							ScoreNumber += 1000;




							EnemiesBox[j].setPosition(-Out, Out);
						}

					}



				}

			}
		if (PowerType == BLUE)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (BLUEFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						BLUEFireBullets[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);
								ScoreNumber += 1000;




								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);
								ScoreNumber += 1000;
								EnemiesBox[j].setPosition(-Out, Out);
							}





						}

					}
					//


				}

			}
		if (PowerType == GREEN)
			for (int i = 1; i <= FireLoop; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (GREENFireBullets[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						GREENFireBullets[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j] += 1.5;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);
								ScoreNumber += 1000;




								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							Deathbool[j] = 1;

							EnemiesBox[j].setPosition(-Out, Out);
							ScoreNumber += 1000;
							EnemiesBox[j].setPosition(-Out, Out);





						}

					}
					//


				}

			}/////////

		if (PowerType2 == RED)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (REDFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						REDFireBullets2[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j]++;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);





								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							Deathbool[j] = 1;

							EnemiesBox[j].setPosition(-Out, Out);





							EnemiesBox[j].setPosition(-Out, Out);
						}

					}



				}

			}
		if (PowerType2 == BLUE)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (BLUEFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						BLUEFireBullets2[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);





								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							chicken_Health[j] += 0.25;
							if (chicken_Health[j] >= 1) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);

								EnemiesBox[j].setPosition(-Out, Out);
							}





						}

					}
					//


				}

			}
		if (PowerType2 == GREEN)
			for (int i = 1; i <= FireLoop2; i++) {   //Bullets  
				for (int j = 33; j <= 64; j++)//Enemies
				{

					if (GREENFireBullets2[i].getGlobalBounds().intersects(EnemiesBox[j].getGlobalBounds())) { //Damaging Enemies

						GREENFireBullets2[i].setPosition(-Out, -Out);
						if (j <= 48) {
							chicken_Health[j] += 1.5;
							if (chicken_Health[j] >= 2) {
								Deathbool[j] = 1;

								EnemiesBox[j].setPosition(-Out, Out);





								EnemiesBox[j].setPosition(-Out, Out);
							}
						}
						else {
							Deathbool[j] = 1;

							EnemiesBox[j].setPosition(-Out, Out);

							EnemiesBox[j].setPosition(-Out, Out);





						}

					}
					//


				}

			}/////////

		for (int k = 33; k <= EggCollision; k++) {
			if (!ShieldBool)
				if (Player.getGlobalBounds().intersects(Eggs[k].getGlobalBounds())) {
					Eggs[k].setPosition(Out, Out);
					BLUEScale = 0;
					PlayerDeathbool = 1;
					Life();
					PlayerDead();

					DeathAnimation = 1;

					Player.setPosition(-Out, -Out);

					Fire = 1; //NoFireSound

				}
		}
		for (int i = 33; i <= EggCollision; i++) {
			if (!ShieldBool)
				if (Player.getGlobalBounds().intersects(EnemiesBox[i].getGlobalBounds()))
				{
					BLUEScale = 0;
					Deathbool[i] = 1; //Enemies

					PlayerDeathbool = 1; //Player
					Life();

					PlayerDead();
					DeathAnimation = 1;

					Player.setPosition(-Out, -Out);

					Fire = 1; //NoFireSound

					EnemiesBox[i].setPosition(Out, Out);
				}
		}


		for (int k = 33; k <= EggCollision; k++) {
			if (!ShieldBool2)
				if (Player2.getGlobalBounds().intersects(Eggs[k].getGlobalBounds())) {
					BLUEScale2 = 0;
					Eggs[k].setPosition(Out, Out);

					PlayerDeathbool2 = 1;
					Life();
					PlayerDead2();

					DeathAnimation2 = 1;

					Player2.setPosition(-Out, -Out);

					Fire2 = 1; //NoFireSound

				}
		}
		for (int i = 33; i <= 64; i++) {
			if (!ShieldBool2)
				if (Player2.getGlobalBounds().intersects(EnemiesBox[i].getGlobalBounds()))
				{
					BLUEScale2 = 0;
					Deathbool[i] = 1; //Enemies

					PlayerDeathbool2 = 1; //Player
					Life();

					PlayerDead2();
					DeathAnimation2 = 1;

					Player2.setPosition(-Out, -Out);

					Fire2 = 1; //NoFireSound

					EnemiesBox[i].setPosition(Out, Out);
				}
		}

	}
	if (Waves == 3) {

		for (int i = 1; i <= 60; i++) {
			if (!ShieldBool)
				if (Player.getGlobalBounds().intersects(Stones[i].getGlobalBounds())) {
					BLUEScale = 0;
					PlayerDeathbool = 1;
					Life();
					PlayerDead();
					DeathAnimation = 1;
					Deathbool[i + 64] = 1;
					Player.setPosition(-Out, -Out);
					Fire = 1; //NoFireSound

				}

		}
		for (int i = 1; i <= 60; i++) {
			if (!ShieldBool2)
				if (Player2.getGlobalBounds().intersects(Stones[i].getGlobalBounds())) {
					BLUEScale2 = 0;
					PlayerDeathbool2 = 1;
					Life();
					PlayerDead2();
					DeathAnimation2 = 1;
					Deathbool[i + 64] = 1;
					Player2.setPosition(-Out, -Out);
					Fire2 = 1; //NoFireSound

				}

		}



		if (PowerType == RED)
			for (int i = 1; i <= FireLoop; i++)
				for (int j = 1; j <= 60; j++) {
					if (REDFireBullets[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j]++;

						REDFireBullets[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;
							ScoreNumber += 1000;

						}

					}//


				}
		if (PowerType == BLUE)
			for (int i = 1; i <= FireLoop; i++)
				for (int j = 1; j <= 60; j++) {
					if (BLUEFireBullets[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j] += 0.25;

						BLUEFireBullets[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;
							ScoreNumber += 1000;

						}
					}//


				}
		if (PowerType == GREEN)
			for (int i = 1; i <= FireLoop; i++)
				for (int j = 1; j <= 60; j++) {
					if (GREENFireBullets[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j] += 1.5;

						GREENFireBullets[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;
							ScoreNumber += 1000;

						}
					}//


				}

		if (PowerType2 == RED)
			for (int i = 1; i <= FireLoop2; i++)
				for (int j = 1; j <= 60; j++) {
					if (REDFireBullets2[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j]++;

						REDFireBullets2[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;


						}

					}//


				}
		if (PowerType2 == BLUE)
			for (int i = 1; i <= FireLoop2; i++)
				for (int j = 1; j <= 60; j++) {
					if (BLUEFireBullets2[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j] += 0.25;

						BLUEFireBullets2[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;


						}
					}//


				}
		if (PowerType2 == GREEN)
			for (int i = 1; i <= FireLoop2; i++)
				for (int j = 1; j <= 60; j++) {
					if (GREENFireBullets2[i].getGlobalBounds().intersects(Stones[j].getGlobalBounds()))
					{
						Rock_Health[j] += 1.5;

						GREENFireBullets2[i].setPosition(-Out, -Out);
						if (Rock_Health[j] >= 3) {
							Deathbool[j + 64] = 1;


						}
					}//


				}

	}
	if (Waves == 4) {
		for (int i = 1; i <= 15; i++) { //HElp
			if (!ShieldBool) {
				if (Player.getGlobalBounds().intersects(AliensBox[i].getGlobalBounds())) {
					BLUEScale = 0;
					PlayerDeathbool = 1;
					Life();
					PlayerDead();
					DeathAnimation = 1;
					Deathbool[i + 124] = 1;
					Player.setPosition(-Out, -Out);
					Fire = 1; //NoFireSound
				}
				for (int i = 1; i <= 15; i++) {
					if (Player.getGlobalBounds().intersects(AlienBulletsBox[i].getGlobalBounds())) {
						BLUEScale = 0;
						PlayerDeathbool = 1; //Player
						Life();

						PlayerDead();
						DeathAnimation = 1;

						Player.setPosition(-Out, -Out);

						Fire = 1; //NoFireSound

						AlienBullets[i].setPosition(-Out, Out);
					}

				}
			}

			if (PowerType == RED)
				for (int i = 1; i <= FireLoop; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)
							if (REDFireBullets[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j]++;

								REDFireBullets[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;
									ScoreNumber += 1000;
								}


							}


					}
			if (PowerType == GREEN)
				for (int i = 1; i <= FireLoop; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)
							if (GREENFireBullets[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j] += 1.5;

								GREENFireBullets[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;
									ScoreNumber += 1000;
								}


							}



					}
			if (PowerType == BLUE)
				for (int i = 1; i <= FireLoop; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)

							if (BLUEFireBullets[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j] += 0.25;

								BLUEFireBullets[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;
									ScoreNumber += 1000;
								}


							}


					}
		}


		for (int i = 1; i <= 15; i++) { //HElp
			if (!ShieldBool2) {
				if (Player2.getGlobalBounds().intersects(AliensBox[i].getGlobalBounds())) {
					BLUEScale2 = 0;
					PlayerDeathbool2 = 1;
					Life();
					PlayerDead2();
					DeathAnimation2 = 1;
					Deathbool[i + 124] = 1;
					Player2.setPosition(-Out, -Out);
					Fire2 = 1; //NoFireSound
				}
				for (int i = 1; i <= 15; i++) {
					if (Player2.getGlobalBounds().intersects(AlienBulletsBox[i].getGlobalBounds())) {
						BLUEScale2 = 0;
						PlayerDeathbool2 = 1; //Player
						Life();

						PlayerDead2();
						DeathAnimation2 = 1;

						Player2.setPosition(-Out, -Out);

						Fire2 = 1; //NoFireSound

						AlienBullets[i].setPosition(-Out, Out);
					}

				}
			}

			if (PowerType2 == RED)
				for (int i = 1; i <= FireLoop2; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)
							if (REDFireBullets2[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j]++;

								REDFireBullets2[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;

								}


							}


					}
			if (PowerType2 == GREEN)
				for (int i = 1; i <= FireLoop2; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)
							if (GREENFireBullets2[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j] += 1.5;

								GREENFireBullets2[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;

								}


							}



					}
			if (PowerType2 == BLUE)
				for (int i = 1; i <= FireLoop2; i++)
					for (int j = 1; j <= 15; j++) {
						if (WaveTimer >= 2)

							if (BLUEFireBullets2[i].getGlobalBounds().intersects(AliensBox[j].getGlobalBounds()))
							{
								alien_Health[j] += 0.25;

								BLUEFireBullets2[i].setPosition(-Out, -Out);
								if (alien_Health[j] >= 2) {
									Deathbool[j + 124] = 1;

								}


							}


					}
		}//////

	}


	if (Waves == 5) {
		timero5 += 0.01;
		if (!ShieldBool) {
			if (Player.getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
				Player.getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
				Player.getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
				BLUEScale = 0;
				PlayerDeathbool = 1;
				Life();
				PlayerDead();
				DeathAnimation = 1;
				Player.setPosition(-Out, -Out);
				Fire = 1; //NoFireSound


			}
			for (int i = 65; i <= 67; i++) {

				if (Player.getGlobalBounds().intersects(Eggs[i].getGlobalBounds())) {
					BLUEScale = 0;
					PlayerDeathbool = 1;
					Life();
					PlayerDead();
					DeathAnimation = 1;
					Player.setPosition(-Out, -Out);
					Eggs[i].setPosition(Out, Out);
					Fire = 1; //NoFireSound
				}

			}



		}

		if (PowerType == RED)
			for (int i = 1; i <= FireLoop; i++) {
				if (WaveTimer >= 2)
					if (REDFireBullets[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						REDFireBullets[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						REDFireBullets[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth--;

						REDFireBullets[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;
							ScoreNumber += 25000;
						}



					}


			}
		if (PowerType == GREEN)
			for (int i = 1; i <= FireLoop; i++) {
				if (WaveTimer >= 2)
					if (GREENFireBullets[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						GREENFireBullets[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						GREENFireBullets[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth -= 1.5;

						GREENFireBullets[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;
							ScoreNumber += 25000;
						}


					}
			}

		if (PowerType == BLUE)
			for (int i = 1; i <= FireLoop; i++) {
				if (WaveTimer >= 2)

					if (BLUEFireBullets[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						BLUEFireBullets[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						BLUEFireBullets[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth -= 0.25;

						BLUEFireBullets[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;
							ScoreNumber += 25000;

						}

					}


			}

		if (!ShieldBool2) {
			if (Player2.getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
				Player2.getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
				Player2.getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
				BLUEScale2 = 0;
				PlayerDeathbool2 = 1;
				Life();
				PlayerDead2();
				DeathAnimation2 = 1;
				Player2.setPosition(-Out, -Out);
				Fire2 = 1; //NoFireSound

			}
			for (int i = 65; i <= 67; i++) {

				if (Player2.getGlobalBounds().intersects(Eggs[i].getGlobalBounds())) {
					BLUEScale2 = 0;
					PlayerDeathbool2 = 1;
					Life();
					PlayerDead2();
					DeathAnimation2 = 1;
					Player2.setPosition(-Out, -Out);
					Eggs[i].setPosition(Out, Out);
					Fire2 = 1; //NoFireSound
				}

			}



		}

		if (PowerType2 == RED)
			for (int i = 1; i <= FireLoop2; i++) {
				if (WaveTimer >= 2)
					if (REDFireBullets2[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						REDFireBullets2[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						REDFireBullets2[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth--;

						REDFireBullets2[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;

						}


					}


			}
		if (PowerType2 == GREEN)
			for (int i = 1; i <= FireLoop2; i++) {
				if (WaveTimer >= 2)
					if (GREENFireBullets2[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						GREENFireBullets2[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						GREENFireBullets2[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth -= 1.5;

						GREENFireBullets2[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;

						}


					}
			}

		if (PowerType2 == BLUE)
			for (int i = 1; i <= FireLoop2; i++) {
				if (WaveTimer >= 2)

					if (BLUEFireBullets2[i].getGlobalBounds().intersects(BossBox.getGlobalBounds()) ||
						BLUEFireBullets2[i].getGlobalBounds().intersects(BossBox2.getGlobalBounds()) ||
						BLUEFireBullets2[i].getGlobalBounds().intersects(BossBox3.getGlobalBounds())) {
						BossHealth -= 0.25;

						BLUEFireBullets2[i].setPosition(-Out, -Out);
						if (BossHealth <= 0)
						{
							Deathbool[140] = 1;


						}

					}


			}///////

	}




	PowerTimer += 0.05;
	PowerTimer2 += 0.05;


	if (REDGifts[Wave1Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		REDGifts[Wave1Random].setPosition(-Out, Out);
		if (PowerType == RED && powerchick < 9)
			powerchick++;
		REDPowerTimerbool = 1;
		ScoreNumber += 1000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (REDGifts[Wave1Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		REDGifts[Wave1Random].setPosition(-Out, Out);
		REDPowerTimerbool2 = 1;
		if (PowerType2 == RED && powerchick2 < 9)
			powerchick2++;
		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (BLUEGifts[Wave1Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		BLUEGifts[Wave1Random].setPosition(-Out, Out);
		if (PowerType == BLUE && powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		BLUEPowerTimerbool = 1;
		ScoreNumber += 2000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (BLUEGifts[Wave1Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		BLUEGifts[Wave1Random].setPosition(-Out, Out);
		BLUEScale2 = 0;
		BLUEPowerTimerbool2 = 1;
		if (PowerType2 == BLUE && powerchick2 < 9)
			powerchick2++;
		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (GREENGifts[Wave1Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		GREENGifts[Wave1Random].setPosition(-Out, Out);
		if (PowerType == GREEN && powerchick < 9)
			powerchick++;
		if (PowerType != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool = 1;
		ScoreNumber += 3000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (GREENGifts[Wave1Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		GREENGifts[Wave1Random].setPosition(-Out, Out);
		if (PowerType2 == GREEN && powerchick2 < 9)
			powerchick2++;
		if (PowerType2 != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets2[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}
	if (REDGifts[Wave2Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		REDGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType == RED && powerchick < 9)
			powerchick++;
		REDPowerTimerbool = 1;
		ScoreNumber += 1000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (REDGifts[Wave2Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		REDGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType2 == RED && powerchick2 < 9)
			powerchick2++;
		REDPowerTimerbool2 = 1;
		if (SoundOn)
			TakenGift.play();
		PowerTimer2 = 0;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (BLUEGifts[Wave2Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		BLUEGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType == BLUE && powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		BLUEPowerTimerbool = 1;
		ScoreNumber += 2000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (BLUEGifts[Wave2Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		BLUEGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType2 == BLUE && powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		BLUEPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (GREENGifts[Wave2Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		GREENGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType == GREEN && powerchick < 9)
			powerchick++;
		if (PowerType != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets[i].setPosition(Out, -Out);
		}

		GREENPowerTimerbool = 1;
		ScoreNumber += 3000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (GREENGifts[Wave2Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		GREENGifts[Wave2Random].setPosition(-Out, Out);
		if (PowerType2 == GREEN && powerchick2 < 9)
			powerchick2++;
		if (PowerType2 != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets2[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (REDGifts[Wave3Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		REDGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType == RED && powerchick < 9)
			powerchick++;
		REDPowerTimerbool = 1;
		ScoreNumber += 1000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;

	}
	if (REDGifts[Wave3Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		REDGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType2 == RED && powerchick2 < 9)
			powerchick2++;
		REDPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (BLUEGifts[Wave3Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		BLUEGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType == BLUE && powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		BLUEPowerTimerbool = 1;
		ScoreNumber += 2000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (BLUEGifts[Wave3Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		BLUEGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType2 == BLUE && powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		BLUEPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}
	if (GREENGifts[Wave3Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		GREENGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType == GREEN && powerchick < 9)
			powerchick++;
		if (PowerType != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool = 1;
		ScoreNumber += 3000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (GREENGifts[Wave3Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		GREENGifts[Wave3Random].setPosition(-Out, Out);
		if (PowerType2 == GREEN && powerchick2 < 9)
			powerchick2++;
		if (PowerType2 != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets2[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}
	if (REDGifts[Wave4Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		REDGifts[Wave4Random].setPosition(-Out, Out);
		if (PowerType == RED && powerchick < 9)
			powerchick++;
		REDPowerTimerbool = 1;
		ScoreNumber += 1000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (REDGifts[Wave4Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		REDGifts[Wave4Random].setPosition(-Out, Out);
		REDPowerTimerbool2 = 1;
		if (PowerType2 == RED && powerchick2 < 9)
			powerchick2++;
		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;

	}
	if (BLUEGifts[Wave4Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		BLUEGifts[Wave4Random].setPosition(-Out, Out);
		if (PowerType == BLUE && powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		BLUEPowerTimerbool = 1;
		ScoreNumber += 2000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (BLUEGifts[Wave4Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		BLUEGifts[Wave4Random].setPosition(-Out, Out);
		BLUEScale2 = 0;
		BLUEPowerTimerbool2 = 1;
		if (PowerType2 == BLUE && powerchick2 < 9)
			powerchick2++;
		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}
	if (GREENGifts[Wave4Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		GREENGifts[Wave4Random].setPosition(-Out, Out);
		if (PowerType == GREEN && powerchick < 9)
			powerchick++;
		if (PowerType != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool = 1;
		ScoreNumber += 3000;
		PowerTimer = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
	}
	if (GREENGifts[Wave4Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		GREENGifts[Wave4Random].setPosition(-Out, Out);
		if (PowerType2 == GREEN && powerchick2 < 9)
			powerchick2++;
		if (PowerType2 != GREEN) {
			for (int i = 1; i <= 100; i++)
				GREENFireBullets2[i].setPosition(Out, -Out);
		}
		GREENPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		if (SoundOn)
			TakenGift.play();
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
	}
	if (REDPowerTimerbool && PowerTimer >= 2) {
		PowerTimer = 0;
		REDPowerTimerbool = 0;
		FireNumber = 1;
		if (PowerType == RED) {
			if (powerchick <= 9)
				PowerLevel = powerchick;
		}
		else {
			PowerType = RED;
			for (int i = 1; i <= 100; i++) {
				BLUEFireBullets[i].setPosition(Out, -Out);
			}
		}
	}
	if (REDPowerTimerbool2 && PowerTimer2 >= 2) {
		PowerTimer2 = 0;
		REDPowerTimerbool2 = 0;
		FireNumber2 = 1;
		if (PowerType2 == RED) {
			if (powerchick2 <= 9)
				PowerLevel2 = powerchick2;

		}
		else {
			PowerType2 = RED;
			for (int i = 1; i <= 100; i++) {
				BLUEFireBullets2[i].setPosition(Out, -Out);
			}
		}
	}
	if (BLUEPowerTimerbool && PowerTimer >= 2) {
		PowerTimer = 0;
		BLUEPowerTimerbool = 0;
		FireNumber = 1;
		if (PowerType == BLUE) {
			if (powerchick <= 9)
				PowerLevel = powerchick;

		}
		else {
			PowerType = BLUE;
			for (int i = 1; i <= 100; i++) {
				REDFireBullets[i].setPosition(Out, -Out);
			}
		}
	}
	if (BLUEPowerTimerbool2 && PowerTimer2 >= 2) {
		PowerTimer2 = 0;
		BLUEPowerTimerbool2 = 0;
		FireNumber2 = 1;
		if (PowerType2 == BLUE) {
			if (powerchick2 <= 9)
				PowerLevel2 = powerchick2;

		}
		else {
			PowerType2 = BLUE;
			for (int i = 1; i <= 100; i++) {
				//GREENFireBullets2[i].setPosition(Out, -Out);
				REDFireBullets2[i].setPosition(Out, -Out);
			}
		}
	}
	if (GREENPowerTimerbool && PowerTimer >= 2) {
		PowerTimer = 0;
		GREENPowerTimerbool = 0;
		FireNumber = 1;
		if (PowerType == GREEN) {
			if (powerchick <= 9)
				PowerLevel = powerchick;

		}
		else {
			PowerType = GREEN;
			for (int i = 1; i <= 100; i++) {
				BLUEFireBullets[i].setPosition(Out, -Out);
				REDFireBullets[i].setPosition(Out, -Out);
			}
		}
	}
	if (GREENPowerTimerbool2 && PowerTimer2 >= 2) {
		PowerTimer2 = 0;
		GREENPowerTimerbool2 = 0;
		FireNumber2 = 1;
		if (PowerType2 == GREEN) {
			if (powerchick2 <= 9)
				PowerLevel2 = powerchick2;

		}
		else {
			PowerType2 = GREEN;
			for (int i = 1; i <= 100; i++) {
				BLUEFireBullets2[i].setPosition(Out, -Out);
				REDFireBullets2[i].setPosition(Out, -Out);
			}
		}
	}

	if (ViewPort - 100 <= Player.getPosition().y) {
		Player.move(0, -4); //moving while player out of view

	}
	if (ViewPort - 100 <= Player2.getPosition().y) {
		Player2.move(0, -4); //moving while player out of view

	}



	if (Atoms[Wave1Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Atoms[Wave1Random].setPosition(-Out, Out);
		if (powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		AtomPowerTimerbool = 1;
		ScoreNumber += 4000;
		PowerTimer = 0;
		BarCounter = 0;
		if (SoundOn)
			TakenGift.play();
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;


	}
	if (Atoms[Wave2Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Atoms[Wave2Random].setPosition(-Out, Out);
		if (powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		AtomPowerTimerbool = 1;
		ScoreNumber += 4000;
		PowerTimer = 0;
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
		if (SoundOn)
			TakenGift.play();

	}
	if (Atoms[Wave3Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Atoms[Wave3Random].setPosition(-Out, Out);
		if (powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		AtomPowerTimerbool = 1;
		ScoreNumber += 4000;
		PowerTimer = 0;
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
		if (SoundOn)
			TakenGift.play();

	}
	if (Atoms[Wave4Random].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Atoms[Wave4Random].setPosition(-Out, Out);
		if (powerchick < 9)
			powerchick++;
		BLUEScale = 0;
		AtomPowerTimerbool = 1;
		ScoreNumber += 4000;
		PowerTimer = 0;
		BarCounter = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool[i] = 0;
		if (SoundOn)
			TakenGift.play();

	}




	if (Atoms[Wave1Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Atoms[Wave1Random].setPosition(-Out, Out);
		if (powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		AtomPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
		if (SoundOn)
			TakenGift.play();

	}
	if (Atoms[Wave2Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Atoms[Wave2Random].setPosition(-Out, Out);
		if (powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		AtomPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
		if (SoundOn)
			TakenGift.play();

	}
	if (Atoms[Wave3Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Atoms[Wave3Random].setPosition(-Out, Out);
		if (powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		AtomPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
		if (SoundOn)
			TakenGift.play();
	}
	if (Atoms[Wave4Random].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Atoms[Wave4Random].setPosition(-Out, Out);
		if (powerchick2 < 9)
			powerchick2++;
		BLUEScale2 = 0;
		AtomPowerTimerbool2 = 1;

		PowerTimer2 = 0;
		BarCounter2 = 0;
		for (int i = 0; i < 29; i++)
			FireBarsbool2[i] = 0;
		if (SoundOn)
			TakenGift.play();
	}

	for (int i = 10; i <= 18; i++) {
		if (Atoms[i].getGlobalBounds().intersects(Player.getGlobalBounds())) {
			Atoms[i].setPosition(-Out, Out);
			if (powerchick < 9)
				powerchick++;
			BLUEScale = 0;
			AtomPowerTimerbool = 1;
			ScoreNumber += 4000;
			PowerTimer = 0;
			BarCounter = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool[i] = 0;
			if (SoundOn)
				TakenGift.play();

		}
		if (Atoms[i].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
			Atoms[i].setPosition(-Out, Out);
			if (powerchick2 < 9)
				powerchick2++;
			BLUEScale2 = 0;
			AtomPowerTimerbool2 = 1;

			PowerTimer2 = 0;
			BarCounter2 = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool2[i] = 0;
			if (SoundOn)
				TakenGift.play();
		}




		//kk

		if (REDGifts[i].getGlobalBounds().intersects(Player.getGlobalBounds())) {
			REDGifts[i].setPosition(-Out, Out);
			if (PowerType == RED && powerchick < 9)
				powerchick++;
			REDPowerTimerbool = 1;
			ScoreNumber += 1000;
			PowerTimer = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool[i] = 0;

		}
		if (REDGifts[i].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
			REDGifts[i].setPosition(-Out, Out);
			REDPowerTimerbool2 = 1;
			if (PowerType2 == RED && powerchick2 < 9)
				powerchick2++;
			PowerTimer2 = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter2 = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool2[i] = 0;

		}
		if (BLUEGifts[i].getGlobalBounds().intersects(Player.getGlobalBounds())) {
			BLUEGifts[i].setPosition(-Out, Out);
			if (PowerType == BLUE && powerchick < 9)
				powerchick++;
			BLUEScale = 0;
			BLUEPowerTimerbool = 1;
			ScoreNumber += 2000;
			PowerTimer = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool[i] = 0;

		}
		if (BLUEGifts[i].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
			BLUEGifts[i].setPosition(-Out, Out);
			BLUEScale2 = 0;
			BLUEPowerTimerbool2 = 1;
			if (PowerType2 == BLUE && powerchick2 < 9)
				powerchick2++;
			PowerTimer2 = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter2 = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool2[i] = 0;

		}
		if (GREENGifts[i].getGlobalBounds().intersects(Player.getGlobalBounds())) {
			GREENGifts[i].setPosition(-Out, Out);
			if (PowerType == GREEN && powerchick < 9)
				powerchick++;
			if (PowerType != GREEN) {
				for (int i = 1; i <= 100; i++)
					GREENFireBullets[i].setPosition(Out, -Out);
			}
			GREENPowerTimerbool = 1;
			ScoreNumber += 3000;
			PowerTimer = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool[i] = 0;

		}
		if (GREENGifts[i].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
			GREENGifts[i].setPosition(-Out, Out);
			if (PowerType2 == GREEN && powerchick2 < 9)
				powerchick2++;
			if (PowerType2 != GREEN) {
				for (int i = 1; i <= 100; i++)
					GREENFireBullets2[i].setPosition(Out, -Out);
			}
			GREENPowerTimerbool2 = 1;

			PowerTimer2 = 0;
			if (SoundOn)
				TakenGift.play();
			BarCounter2 = 0;
			for (int i = 0; i < 29; i++)
				FireBarsbool2[i] = 0;
		}


	}


	if (AtomPowerTimerbool && PowerTimer >= 2) {
		PowerTimer = 0;
		AtomPowerTimerbool = 0;
		FireNumber = 1;

		if (powerchick <= 9)
			PowerLevel = powerchick;



	}
	if (AtomPowerTimerbool2 && PowerTimer2 >= 2) {
		AtomPowerTimerbool2 = 0;
		PowerTimer2 = 0;
		FireNumber2 = 1;

		if (powerchick2 <= 9)
			PowerLevel2 = powerchick2;


	}

	for (int i = 1; i <= 100; i++) {
		if (Chicks[i].getGlobalBounds().intersects(Player.getGlobalBounds())) {
			Chicks[i].setPosition(Out, Out);
			ChicksCounter1++;
			ScoreNumber += 500;
			if (SoundOn)
				ChickEat.play();
		}
	}
	if (Meals[MealRandom1].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Meals[MealRandom1].setPosition(Out, Out);
		ScoreNumber += 5000;
		ChicksCounter1 += 10;
		if (SoundOn)
			ChickEat.play();

	}
	if (Meals[MealRandom2].getGlobalBounds().intersects(Player.getGlobalBounds())) {
		Meals[MealRandom2].setPosition(Out, Out);
		ScoreNumber += 5000;
		ChicksCounter1 += 10;
		if (SoundOn)
			ChickEat.play();

	}

	for (int i = 1; i <= 100; i++) {
		if (Chicks[i].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
			Chicks[i].setPosition(Out, Out);
			ChicksCounter2++;

			if (SoundOn)
				ChickEat2.play();

		}
	}
	if (Meals[MealRandom1].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Meals[MealRandom1].setPosition(Out, Out);

		ChicksCounter2 += 10;

		if (SoundOn)
			ChickEat2.play();

	}
	if (Meals[MealRandom2].getGlobalBounds().intersects(Player2.getGlobalBounds())) {
		Meals[MealRandom2].setPosition(Out, Out);
		ChicksCounter2 += 10;

		if (SoundOn)
			ChickEat2.play();

	}

}//collision


//Waves

//Actions

void Action1() {
	if (!Action) {
		if (Enemies[1].getPosition().x >= 1600 || Enemies[9].getPosition().x >= 1600)
		{

			Action = 1;
		}
		else
			for (int i = 1; i <= 32; i++)
				Enemies[i].move(20, 0);
	}
	else {
		if (Enemies[1].getPosition().y >= 100 + WavesView_Number && (timero < 4.5))
			for (int i = 1; i <= 8; i++) {
				Enemies[i].move(-Actionesta1, -8);
				if (Actionesta1 <= 4)
					Actionesta1 += 0.007;
			}
		if (Enemies[9].getPosition().y >= 250 + WavesView_Number && (timero < 4.5))
			for (int i = 9; i <= 16; i++) {
				Enemies[i].move(-Actionesta2, -8);
				if (Actionesta2 <= 10)
					Actionesta2 += 0.0078;
			}
		if (Enemies[17].getPosition().y >= 400 + WavesView_Number && (timero < 4.5))//187
			for (int i = 17; i <= 24; i++) {

				Enemies[i].move(-Actionesta3, -8);
				if (Actionesta3 <= 16)
					Actionesta3 += 0.0135;
			}
		if (Enemies[25].getPosition().y >= 550 + WavesView_Number && (timero < 4.5))
			for (int i = 25; i <= 32; i++) {

				Enemies[i].move(-Actionesta4, -8);
				if (Actionesta4 <= 22)
					Actionesta4 += 0.0267;

			}
		else 		EnemyMovement();
	}
}
void Action2() {
	if (!Action) {
		if (Enemies[33].getPosition().x >= 400)
		{

			Action = 1;
		}
		else {
			for (int i = 33; i <= 40; i++) {

				Enemies[i].move(10, 0);

				Enemies[i].setRotation(Rotation);

			}




			for (int i = 41; i <= 48; i++)
			{
				Enemies[i].move(-10, 0);
				Enemies[i].setRotation(Rotation2);
			}



		}

	}


	else {
		for (int i = 33; i <= 40; i++)
			Enemies[i].setRotation(Rotation);
		if (Rotation > 0)
			Rotation--;

		if (Rotation < 90 && Rotation != 0)
			for (int i = 33; i <= 40; i++)
				Enemies[i].move(3, -2);
		for (int i = 41; i <= 48; i++)
			Enemies[i].setRotation(Rotation2);
		if (Rotation2 < 0)
			Rotation2++;

		if (Rotation2 > -90 && Rotation2 != 0)
			for (int i = 41; i <= 48; i++)
				Enemies[i].move(-3, -2);
		else 		EnemyMovement();
	}

}
void Action4() {
	if (AliensTimer >= 1) {
		AliensTimer = 0;
		xAliens++;
		if (xAliens == 5)
			xAliens = -4; //4


		AliensTimer = 0;

	}
	AliensTimer += 0.3;
	for (int i = 1; i <= 15; i++) {
		Aliens[i].move(xmovestones[i] + 3, 0);
		Aliens[i].setTextureRect(IntRect(176 * abs(xAliens), 0, 176, 121));
		//if (AliensTimer > 1) {
		//}
	}
}

void Action5() {

	if (BossEnemy.getPosition().y < WavesView_Number + 200)
		BossEnemy.move(0, 2);//top
	else if (BossEnemy.getPosition().y > WavesView_Number + 700)//bot
		BossEnemy.move(0, -2);//top
	else if (BossEnemy.getPosition().x > 700)//r
		BossEnemy.move(-2, 0);
	else if (BossEnemy.getPosition().x < 0)//l
		BossEnemy.move(2, 0);

	else
		BossEnemy.move(BossMoveX, BossMoveY);

	if (BossTimer > 4) {
		//cout << BossTimer << endl;
		BossMoveX = -4 + rand() % 9;
		BossMoveY = -4 + rand() % 9;
		//cout << "X : " << BossMoveX << endl << " Y : " << BossMoveY << endl;

		BossTimer = 0;
	}
	BossTimer += 0.1;

}

//


void ChickMovement() {
	for (int i = ChickBegin; i <= ChickEnd; i++)
	{
		Chicks[i].move(chickmove[i], 5);
		Chicks[i].rotate(4);
		if (Chicks[i].getPosition().x <= 5)
			chickmove[i] *= -1;
		if (Chicks[i].getPosition().x >= 970)
			chickmove[i] *= -1;
	}
	Meals[MealRandom1].move(chickmove[101], 5);
	Meals[MealRandom2].move(chickmove[102], 5);
	Meals[MealRandom1].rotate(1);
	Meals[MealRandom2].rotate(1);
	if (Meals[MealRandom1].getPosition().x <= 5)
		chickmove[101] *= -1;
	if (Meals[MealRandom1].getPosition().x >= 970)
		chickmove[101] *= -1;
	if (Meals[MealRandom2].getPosition().x <= 5)
		chickmove[102] *= -1;
	if (Meals[MealRandom2].getPosition().x >= 970)
		chickmove[102] *= -1;
}

//LeaderBoard

//Bishoy
void save(info& user) {
	if (TotalScore > 0) {
		ofstream file("LeaderBoard.txt", ios::app);
		file << user.name << "\t" << user.level << "\t" << user.score << endl;
	}
}

bool compare(info& a, info& b) {
	return a.score > b.score;
}
//
void TextGame() {
	//Anas
	Score.setString(to_string(ActScore));
	Lifes.setString(to_string(LifePlayer1));
	Lifes2.setString(to_string(LifePlayer2));
	PowerText.setString(to_string(PowerLevel));
	PowerText2.setString(to_string(PowerLevel2));
	ChicksText.setString(to_string(ChicksCounter1));
	ChicksText2.setString(to_string(ChicksCounter2));

	//Asmaa
	if (SelectionMenu == 0)
	{
		AinShams.setString(AinShamsText.substring(0, AinShamsCounter));

		if (AinShamsCounter <= 8) {
			if (AinShamsTimer >= 3) {
				AinShamsTimer = 0.5;              //AinShams Texture and Timer
				AinShamsCounter++;


			}
		}
		AinShamsTimer += 0.1;
	}
	else {
		if (Waves == 1) {
			Test10.setString(HelloTest1.substr(0, TextCounter10)); //lets
			Test11.setString(HelloTest1.substr(5, TextCounter11));//start
			Test12.setString(HelloTest1.substr(10, TextCounter12));//the
			Test13.setString(HelloTest1.substr(15, TextCounter13));//adventure
			nwave1.setString(Hello1.substr(0, nwavecounter1));//wave 1
			if (TextCounter10 <= 4) {
				if (TextTimer >= 3) {
					TextTimer = 2;
					TextCounter10++;
				}
			}
			else if (TextCounter11 <= 5) {
				if (TextTimer >= 3) {
					TextTimer = 2;
					TextCounter11++;
				}
			}
			else if (TextCounter12 <= 3) {
				if (TextTimer >= 3) {
					TextTimer = 2;
					TextCounter12++;
				}
			}
			else if (TextCounter13 <= 9) {
				if (TextTimer >= 3) {
					TextTimer = 2;
					TextCounter13++;
				}
			}
			else if (nwavecounter1 <= 6) {
				if (TextTimer >= 3) {
					TextTimer = 2;
					nwavecounter1++;
				}
			}
			if (TextTimer >= 10) {
				Test10.move(10, 0);
				Test11.move(0, 10);
				Test12.move(0, -10);
				Test13.move(-10, 0);
				nwave1.move(0, -10);
			}
			TextTimer += 0.08;
			window.draw(Test10);
			window.draw(Test11);
			window.draw(Test12);
			window.draw(Test13);
			window.draw(nwave1);
		}
		if (Waves == 2) {
			Test8.setString(HelloTest2.substr(0, TextCounter8)); //well
			Test9.setString(HelloTest2.substr(5, TextCounter9)); //played
			nwave2.setString(Hello2.substr(0, nwavecounter2));//wave2
			if (TextCounter8 <= 4) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter8++;
				}
			}
			else if (TextCounter9 <= 6) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter9++;
				}
			}
			else if (nwavecounter2 < 6) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					nwavecounter2++;
				}
			}
			if (TextTimer >= 10) {
				Test8.move(10, 0);
				Test9.move(-10, 0);
				nwave2.move(0, -10);
			}
			TextTimer += 0.1;

			window.draw(Test8);
			window.draw(Test9);
			window.draw(nwave2);
		}

		if (Waves == 3) {
			Test6.setString(HelloTest3.substr(0, TextCounter6)); //keep
			Test7.setString(HelloTest3.substr(5, TextCounter7)); //going
			nwave3.setString(Hello3.substr(0, nwavecounter3));//wave3
			if (TextCounter6 <= 4) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter6++;
				}
			}
			else if (TextCounter7 <= 6) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter7++;
				}
			}
			else if (nwavecounter3 < 6) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					nwavecounter3++;
				}
			}
			if (TextTimer >= 10) {
				Test6.move(10, 0);
				Test7.move(-10, 0);
				nwave3.move(0, -10);
			}
			TextTimer += 0.1;

			window.draw(Test6);
			window.draw(Test7);
			window.draw(nwave3);
		}

		if (Waves == 4) {

			Test3.setString(HelloTest4.substr(0, TextCounter3)); //never
			Test4.setString(HelloTest4.substr(5, TextCounter4)); //give
			Test5.setString(HelloTest4.substr(10, TextCounter5));//up 
			nwave4.setString(Hello4.substr(0, nwavecounter4));//wave4
			if (TextCounter3 <= 5) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter3++;
				}
			}
			else if (TextCounter4 <= 5) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter4++;
				}
			}
			else if (TextCounter5 <= 5) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter5++;
				}
			}
			else if (nwavecounter4 < 6) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					nwavecounter4++;
				}
			}
			if (TextTimer >= 10) {
				Test3.move(10, 0);
				Test4.move(-10, 0);
				Test5.move(0, -10);
				nwave4.move(0, 10);
			}
			TextTimer += 0.1;

			window.draw(Test3);
			window.draw(Test4);
			window.draw(Test5);
			window.draw(nwave4);
		}

		if (Waves == 5) {
			Test.setString(HelloTest5.substr(0, TextCounter)); //yes 
			Test1.setString(HelloTest5.substr(3, TextCounter1)); //we  
			Test2.setString(HelloTest5.substr(6, TextCounter2));//can 
			nwave5.setString(Hello5.substr(0, nwavecounter5));//wave5
			if (TextCounter <= 10) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter++;
				}
			}
			else if (TextCounter1 <= 10) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter1++;
				}
			}
			else if (TextCounter2 <= 10) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					TextCounter2++;
				}
			}
			else if (nwavecounter5 < 10) {
				if (TextTimer >= 5) {
					TextTimer = 2;
					nwavecounter5++;
				}
			}
			if (TextTimer >= 10) {
				Test.move(10, 0);
				Test1.move(-10, 0);
				Test2.move(0, -10);
				nwave5.move(0, 10);
			}
			TextTimer += 0.8;
			window.draw(Test);
			window.draw(Test1);
			window.draw(Test2);
			window.draw(nwave5);

		}


		//
		if (!LifePlayer1 && !LifePlayer2)
		{




			if (GameOverTimer > 50)
			{

				CutSceneGame.setScale(1 + CutSceneGameMove, 1 + CutSceneGameMove);

				if (CutSceneGameMove > 0) {

					CutSceneGameMove -= 0.01 * 4;
					CutSceneGame.move(6.7 * 8, 6.8 * 8);
				}

				else
					window.clear(Color::Black);


			}



			GameOverTimer += 0.1;

			if (GameOverbool == 0 && GameOverTimer > 4)
				GameOverbool = 1;
			if (GameOverbool == 1)
			{
				Level1.stop();
				BossTheme.stop();
				GameOverMusic.play();
				GameOverbool++;
			}
			if (GameOverTimer > 10) {
				GameOver.setString(GG.substr(0, TextCounter14));//Game Over
				if (TextCounter14 <= 9) {
					if (TextTimer >= 3) {
						TextTimer = 2;
						TextCounter14++;
					}
				}
				TextTimer += 0.08;
			}
			window.draw(GameOver);


			//










			//
			if (GameOverTimer > 150)
			{
				//CutSceneMenu.setScale(1, 1 );
				GameOverTimer = 0;


				user.name = Playerinput;
				user.level = Waves;
				user.score = TotalScore;
				LeaderBoardMenu = 1;
				SelectionMenu = 3;
				if (MusicOn)
					IntroMenu.play();
				Escapebool = 0;
				BossTheme.stop();
				Level1.stop();
				Enter = 0;
				EnterYourNamebool = 0;
				//Default();


			}


		}
	}
}
//Gifts
void Gifts1() {//Gifts[waves]

	//Wave1

	//GiftsRandom=1 >RED , GiftsRandom =2 > BLUE , GiftsRandom = 3 >GREEN
	if (Gifts1Random == 1) //Gifts[Waves]Random
		REDGifts[Wave1Random].setPosition(Enemies[Wave1Random].getPosition().x, Enemies[Wave1Random].getPosition().y);
	if (Gifts1Random == 2)
		BLUEGifts[Wave1Random].setPosition(Enemies[Wave1Random].getPosition().x, Enemies[Wave1Random].getPosition().y);
	if (Gifts1Random == 3)
		GREENGifts[Wave1Random].setPosition(Enemies[Wave1Random].getPosition().x, Enemies[Wave1Random].getPosition().y);
	if (Gifts1Random == 4)
		Atoms[Wave1Random].setPosition(Enemies[Wave1Random].getPosition().x, Enemies[Wave1Random].getPosition().y);



	//GiftsRandom=1 >RED , GiftsRandom =2 > BLUE , GiftsRandom = 3 >GREEN
	if (Gifts1Random == 1) //Gifts[Waves]Random
		REDGifts[Wave1Random2].setPosition(Enemies[Wave1Random2].getPosition().x, Enemies[Wave1Random2].getPosition().y);
	if (Gifts1Random == 2)
		BLUEGifts[Wave1Random2].setPosition(Enemies[Wave1Random2].getPosition().x, Enemies[Wave1Random2].getPosition().y);
	if (Gifts1Random == 3)
		GREENGifts[Wave1Random2].setPosition(Enemies[Wave1Random2].getPosition().x, Enemies[Wave1Random2].getPosition().y);
	if (Gifts1Random == 4)
		Atoms[Wave1Random2].setPosition(Enemies[Wave1Random2].getPosition().x, Enemies[Wave1Random2].getPosition().y);



}
void Gifts2() {


	//Wave2
		//GiftsRandom=1 >RED , GiftsRandom =2 > BLUE , GiftsRandom = 3 >GREEN
	if (Gifts2Random == 1)
		REDGifts[Wave2Random].setPosition(Enemies[Wave2Random].getPosition().x, Enemies[Wave2Random].getPosition().y);
	if (Gifts2Random == 2)
		BLUEGifts[Wave2Random].setPosition(Enemies[Wave2Random].getPosition().x, Enemies[Wave2Random].getPosition().y);
	if (Gifts2Random == 3)
		GREENGifts[Wave2Random].setPosition(Enemies[Wave2Random].getPosition().x, Enemies[Wave2Random].getPosition().y);
	if (Gifts2Random == 4)
		Atoms[Wave2Random].setPosition(Enemies[Wave2Random].getPosition().x, Enemies[Wave2Random].getPosition().y);


}
void Gifts3() {

	//Wave3
		//GiftsRandom=1 >RED , GiftsRandom =2 > BLUE , GiftsRandom = 3 >GREEN

	if (Gifts3Random == 1)
		REDGifts[Wave3Random].setPosition(Stones[Wave3Random].getPosition().x, Stones[Wave3Random].getPosition().y);
	if (Gifts3Random == 2)
		BLUEGifts[Wave3Random].setPosition(Stones[Wave3Random].getPosition().x, Stones[Wave3Random].getPosition().y);
	if (Gifts3Random == 3)
		GREENGifts[Wave3Random].setPosition(Stones[Wave3Random].getPosition().x, Stones[Wave3Random].getPosition().y);
	if (Gifts3Random == 4)
		Atoms[Wave3Random].setPosition(Stones[Wave3Random].getPosition().x, Stones[Wave3Random].getPosition().y);

}
void Gifts4() {

	if (Gifts4Random == 1)
		REDGifts[Wave4Random].setPosition(Aliens[Wave4Random].getPosition().x, Aliens[Wave4Random].getPosition().y);
	if (Gifts4Random == 2)
		BLUEGifts[Wave4Random].setPosition(Aliens[Wave4Random].getPosition().x, Aliens[Wave4Random].getPosition().y);
	if (Gifts4Random == 3)
		GREENGifts[Wave4Random].setPosition(Aliens[Wave4Random].getPosition().x, Aliens[Wave4Random].getPosition().y);
	if (Gifts4Random == 4)
		Atoms[Wave4Random].setPosition(Aliens[Wave4Random].getPosition().x, Aliens[Wave4Random].getPosition().y);
}
void GiftsMovement() {

	for (int i = 10; i <= 18; i++) {
		Atoms[i].move(0, 0.1);
		Atoms[i].setTextureRect(IntRect(44 * xAtoms[i], 0, 44, 37));
		xAtoms[i]++;
		xAtoms[i] %= 25;

		REDGifts[i].move(0, 8);
		REDGifts[i].rotate(1);

		BLUEGifts[i].move(0, 8);
		BLUEGifts[i].rotate(1);

		GREENGifts[i].move(0, 8);
		GREENGifts[i].rotate(1);

	}
	REDGifts[Wave1Random].move(0, 0.1);
	REDGifts[Wave1Random].rotate(1);

	BLUEGifts[Wave1Random].move(0, 0.1);
	BLUEGifts[Wave1Random].rotate(1);

	GREENGifts[Wave1Random].move(0, 0.1);

	GREENGifts[Wave1Random].rotate(1);

	Atoms[Wave1Random].move(0, 0.1);
	Atoms[Wave1Random].setTextureRect(IntRect(44 * xAtoms[Wave1Random], 0, 44, 37));
	xAtoms[Wave1Random]++;
	xAtoms[Wave1Random] %= 25;

	//

	REDGifts[Wave2Random].move(0, 0.1);
	REDGifts[Wave2Random].rotate(1);

	BLUEGifts[Wave2Random].move(0, 0.1);
	BLUEGifts[Wave2Random].rotate(1);

	GREENGifts[Wave2Random].move(0, 0.1);
	GREENGifts[Wave2Random].rotate(1);
	Atoms[Wave2Random].move(0, 0.1);
	Atoms[Wave2Random].setTextureRect(IntRect(44 * xAtoms[Wave2Random], 0, 44, 37));
	xAtoms[Wave2Random]++;
	xAtoms[Wave2Random] %= 25;

	//

	REDGifts[Wave3Random].move(0, 0.1);
	REDGifts[Wave3Random].rotate(1);

	BLUEGifts[Wave3Random].move(0, 0.1);
	BLUEGifts[Wave3Random].rotate(1);

	GREENGifts[Wave3Random].move(0, 0.1);
	GREENGifts[Wave3Random].rotate(1);

	Atoms[Wave3Random].move(0, 0.1);
	Atoms[Wave3Random].setTextureRect(IntRect(44 * xAtoms[Wave3Random], 0, 44, 37));
	xAtoms[Wave3Random]++;
	xAtoms[Wave3Random] %= 25;

	//
	REDGifts[Wave4Random].move(0, 0.1);
	REDGifts[Wave4Random].rotate(1);

	BLUEGifts[Wave4Random].move(0, 0.1);
	BLUEGifts[Wave4Random].rotate(1);

	GREENGifts[Wave4Random].move(0, 0.1);
	GREENGifts[Wave4Random].rotate(1);

	Atoms[Wave4Random].move(0, 0.1);
	Atoms[Wave4Random].setTextureRect(IntRect(44 * xAtoms[Wave4Random], 0, 44, 37));
	xAtoms[Wave4Random]++;
	xAtoms[Wave4Random] %= 25;

}