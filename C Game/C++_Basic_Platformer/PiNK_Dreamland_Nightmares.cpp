#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<time.h>
using namespace std;
class TitleScreen{
public:
    sf::Texture bgTxture;
    sf::Sprite bgSprite;
    sf::Texture toGameTxture;
    sf::Sprite toGameSprite;
    sf::Texture tohowToTxture;
    sf::Sprite tohowToSprite;
    sf::Texture titTxture;
    sf::Sprite titSprite;
    sf::Vector2i titsource;
public:
    TitleScreen ();
};

class HowTo{
    public:
        sf::Texture howtoTxture;
        sf::Sprite howtoSprite;
    public:
        HowTo();
};
class Game{
    public:
        Game();
        TitleScreen ts;
        HowTo ht;
        bool isTitle, isHowTo, isGame, isGameOver, isbossbattle, isGameWon;
        void run ();
    private:
        void processEvents();
        void update(sf::Time);
        void render();
        void handlePlayerInput(sf::Keyboard::Key, bool);
        void renderTitle();
        void renderHowTo();
        void renderGame();
    private:
        sf::RenderWindow mWindow;
        sf::View view;
        sf::Texture bTexture;
        sf::Texture mTexture;
        sf::Texture pTexture;
        sf::Texture kTexture;
        sf::Texture eTexture;
        sf::Texture e2Texture;
        sf::Texture e3Texture;
        sf::Texture e4Texture;
        sf::Texture dTexture;
        sf::Texture oTexture;
        sf::Texture maTexture;
        sf::Texture hTexture;
        sf::Texture winTexture;
        sf::Texture blTexture;

        sf::Sprite sky;

        sf::Sprite ground;

        sf::Sprite wall1;
        sf::Sprite wall2;

        sf::Sprite Background;

        sf::Sprite mPlayer;
        sf::Sprite pPower;

        sf::Sprite green1;
        sf::Sprite green2;
        sf::Sprite green3;
        sf::Sprite green4;
        sf::Sprite green5;
        sf::Sprite green6;
        sf::Sprite green7;
        sf::Sprite green8;
        sf::Sprite green9;
        sf::Sprite green10;
        sf::Sprite green11;
        sf::Sprite green12;
        sf::Sprite green13;
        sf::Sprite green14;
        sf::Sprite green15;
        sf::Sprite green16;

        sf::Sprite enemy1;
        sf::Sprite enemy2;
        sf::Sprite enemy3;
        sf::Sprite enemy4;
        sf::Sprite enemy5;
        sf::Sprite enemy6;
        sf::Sprite enemy7;
        sf::Sprite enemy8;
        sf::Sprite enemy9;
        sf::Sprite enemy10;
        sf::Sprite enemy11;
        sf::Sprite enemy12;
        sf::Sprite enemy13;

        sf::Sprite heart1;
        sf::Sprite heart2;
        sf::Sprite heart3;

        sf::Sprite manaready;

        sf::Sprite bheart1;
        sf::Sprite bheart2;
        sf::Sprite bheart3;

        sf::Sprite Gameover;
        sf::Sprite Gamewon;

        sf::Vector2i source;
        sf::Vector2f position;

        sf::Vector2i orb;

        sf::Vector2i en;
        sf::Vector2i ens2;
        sf::Vector2i ens3;
        sf::Vector2i ens4;
        sf::Vector2i ens5;
        sf::Vector2i ens6;
        sf::Vector2i ens7;
        sf::Vector2i ens8;
        sf::Vector2i ens9;
        sf::Vector2i ens10;
        sf::Vector2i ens11;
        sf::Vector2i ens12;
        sf::Vector2i ens13;

        sf::Music gameMusic;
        sf::Music gameOverMusic;
        sf::Music victoryMusic;
        sf::SoundBuffer jumpbuff;
        sf::Sound jumpsfx;
        sf::SoundBuffer attackbuff;
        sf::Sound attacksfx;
        sf::SoundBuffer hurtbuff;
        sf::Sound hurtsfx;


        bool counter, hit, mIsMovingLeft, mIsMovingRight, punch, Space,stance,attack,jump,obstruct,en1,en2,en3,en4,en5,en6, en7,en8, en9, en10, en11, en12, en13, boss, damage,bosscene, bossctr;
        bool deflect;
        int bosslife,jumpctr, movedir, attackctr, initdir, en1dir, en2dir, en3dir, life, recovery, initdir2,en7dir,en8dir,en9dir;
        float PlayerSpeed, stanceSpeed, enemspeed,frameCounter, switchFrame;
        enum directions {UP, RIGHT, DOWN, LEFT};
};
int main(){
    Game game;
    game.run();
}

Game::Game():mWindow(sf::VideoMode(640, 480), "SFML Application"),mTexture(),mPlayer(),source(0,1){
    srand((unsigned int)time(NULL));
    mWindow.setTitle("PiNK: Dreamland Nightmares");
    isTitle = true;
    isHowTo = false;
    isGame = false;
    isGameOver = false;
    isGameWon=false;
    if (!mTexture.loadFromFile("img/kirby.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!pTexture.loadFromFile("img/kirby1.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!bTexture.loadFromFile("img/Background.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!kTexture.loadFromFile("img/attack.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!eTexture.loadFromFile("img/enemy.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!e2Texture.loadFromFile("img/enemy2.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!oTexture.loadFromFile("img/GO.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!hTexture.loadFromFile("img/life.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!maTexture.loadFromFile("img/mana.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!e3Texture.loadFromFile("img/enemy3.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!e4Texture.loadFromFile("img/enemy4.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!dTexture.loadFromFile("img/demon.png")){
        cout<<"Error loading file."<<endl;
    }
    if (!winTexture.loadFromFile("img/Game won.jpg")){
        cout<<"Error loading file."<<endl;
    }
    if (!blTexture.loadFromFile("img/bosslife.png")){
        cout<<"Error loading file."<<endl;
    }
    if(!gameMusic.openFromFile("audio/game2.ogg")){
        cout<<"Error loading game music."<<endl;
    }
    if(!gameMusic.openFromFile("audio/game2.ogg")){
        cout<<"Error loading game music."<<endl;
    }
    if(!gameOverMusic.openFromFile("audio/gameover2.ogg")){
        cout<<"Error loading game over music."<<endl;
    }
    if(!victoryMusic.openFromFile("audio/victory.ogg")){
        cout<<"Error loading victory music."<<endl;
    }
    if (!jumpbuff.loadFromFile("audio/jump2.wav"))
        cout<<"Error loading sfx."<<endl;
    if (!attackbuff.loadFromFile("audio/attack2.wav"))
        cout<<"Error loading sfx."<<endl;
    if (!hurtbuff.loadFromFile("audio/hurt2.wav"))
        cout<<"Error loading sfx."<<endl;
    jumpsfx.setBuffer(jumpbuff);
    attacksfx.setBuffer(attackbuff);
    hurtsfx.setBuffer(hurtbuff);

    Background.setTexture(bTexture);
    Background.setScale(1.0f,0.5f);

    pPower.setTexture(kTexture);
    mPlayer.setPosition(sf::Vector2f(300.f, 385.f));

    ground.setTexture(pTexture);
    ground.setScale(5.25f,0.2f);
    ground.setPosition(1.0f,450.0f);

    sky.setTexture(pTexture);
    sky.setScale(5.25f,0.2f);
    sky.setPosition(1.0f,0.0f);

    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(sf::Vector2f(250.f, 385.f));

    green1.setTexture(pTexture);
    green1.setScale(0.034f,0.05f);
    green1.setPosition(550.0f,390.0f);

    green2.setTexture(pTexture);
    green2.setScale(0.09f,0.09f);
    green2.setPosition(1100.0f,370.0f);

    green3.setTexture(pTexture);
    green3.setScale(0.03f,0.09f);
    green3.setPosition(1650.0f,370.0f);

    green4.setTexture(pTexture);
    green4.setScale(.02,.07f);
    green4.setPosition(1285.0f,385.0f);

    green5.setTexture(pTexture);
    green5.setScale(.02f,.07f);
    green5.setPosition(1405.0f,385.0f);

    green6.setTexture(pTexture);
    green6.setScale(.02f,.07f);
    green6.setPosition(1800.0f,385.0f);

    green7.setTexture(pTexture);
    green7.setScale(.04f,.07f);
    green7.setPosition(2050.0f,385.0f);

    green8.setTexture(pTexture);
    green8.setScale(.07f,.07f);
    green8.setPosition(2300.0f,385.0f);

    green9.setTexture(pTexture);
    green9.setScale(.03f,.07f);
    green9.setPosition(2550.0f,385.0f);

    green10.setTexture(pTexture);
    green10.setScale(.01f,.07f);
    green10.setPosition(2700.0f,385.0f);

    green11.setTexture(pTexture);
    green11.setScale(.03f,.07f);
    green11.setPosition(2800.0f,385.0f);

    green12.setTexture(pTexture);
    green12.setScale(.01f,.07f);
    green12.setPosition(3300.0f,385.0f);

    green13.setTexture(pTexture);
    green13.setScale(.01f,.07f);
    green13.setPosition(3400.0f,385.0f);

    green14.setTexture(pTexture);
    green14.setScale(.01f,.07f);
    green14.setPosition(3850.0f,385.0f);

    green15.setTexture(pTexture);
    green15.setScale(.01f,.07f);
    green15.setPosition(3870.0f,385.0f);

    green16.setTexture(pTexture);
    green16.setScale(.01f,.07f);
    green16.setPosition(3450.0f,385.0f);

    enemy2.setTexture(eTexture);
    enemy2.setPosition(600.0f,385.0f);

    enemy3.setTexture(eTexture);
    enemy3.setPosition(1100.0f,385.0f);

    enemy4.setTexture(e2Texture);
    enemy4.setScale(2.2f,2.2f);
    enemy4.setPosition(681.0f,280.0f);

    enemy5.setTexture(e2Texture);
    enemy5.setScale(2.2f,2.2f);
    enemy5.setPosition(1265.0f,280.0f);

    enemy6.setTexture(e2Texture);
    enemy6.setScale(2.2f,2.2f);
    enemy6.setPosition(1385.0f,280.0f);

    enemy7.setTexture(dTexture);
    enemy7.setScale(1.5f,1.0f);
    enemy7.setPosition(1740.0f,377.0f);

    enemy8.setTexture(e4Texture);
    enemy8.setPosition(2300.0f,385.0f);

    enemy9.setTexture(e4Texture);
    enemy9.setPosition(2850.0f,385.0f);

    enemy10.setTexture(e2Texture);
    enemy10.setScale(2.2f,2.2f);
    enemy10.setPosition(2672.0f,280.0f);

    enemy11.setTexture(e2Texture);
    enemy11.setScale(2.2f,2.2f);
    enemy11.setPosition(3255.0f,280.0f);

    enemy12.setTexture(e2Texture);
    enemy12.setScale(2.2f,2.2f);
    enemy12.setPosition(3375.0f,280.0f);

    enemy13.setTexture(e3Texture);
    enemy13.setPosition(3750.0f,320.0f);

    wall1.setTexture(pTexture);
    wall1.setScale(0.05f,0.75f);
    wall1.setPosition(0.0f,0.0f);

    wall2.setTexture(pTexture);
    wall2.setScale(0.1f,0.75f);
    wall2.setPosition(350.0f,0.0f);

    heart1.setTexture(hTexture);
    heart1.setScale(0.2f,0.2f);
    heart1.setPosition(0.0f,0.0f);

    heart2.setTexture(hTexture);
    heart2.setScale(0.2f,0.2f);
    heart2.setPosition(60.0f,0.0f);

    heart3.setTexture(hTexture);
    heart3.setScale(0.2f,0.2f);
    heart3.setPosition(120.0f,0.0f);

    bheart1.setTexture(blTexture);
    bheart1.setScale(0.2f,0.2f);
    bheart1.setPosition(3900.0f,0.0f);

    bheart2.setTexture(blTexture);
    bheart2.setScale(0.2f,0.2f);
    bheart2.setPosition(3840.0f,0.0f);

    bheart3.setTexture(blTexture);
    bheart3.setScale(0.2f,0.2f);
    bheart3.setPosition(3780.0f,0.0f);

    manaready.setTexture(maTexture);
    manaready.setScale(0.2f,0.2f);
    manaready.setPosition(0.0f,60.0f);

    Gameover.setTexture(oTexture);
    Gameover.setScale(0.5f,0.65f);

    Gamewon.setTexture(winTexture);
    Gamewon.setScale(1.00f,1.00f);

    deflect=bossctr=counter=bosscene=boss=en10=en11=en12=damage=en6=en5=en4=hit=attack=jump= mIsMovingLeft = mIsMovingRight = punch=false;
    en8=en7=en3=en2=stance=en1=true;
    en8dir=en7dir=en2dir=movedir=attackctr=en1dir=0;
    bosslife=life=3;
    PlayerSpeed = 100.0;
    enemspeed=200.0;
    recovery=frameCounter = 0;
    switchFrame = 25;
    stanceSpeed = 300.0;
}
TitleScreen::TitleScreen(){//N
    if (!bgTxture.loadFromFile("img/background1.png")){
        cout<<"Error loading title background."<<endl;
    }
    bgSprite.setTexture(bgTxture);
    bgSprite.setPosition(0.f, 0.f);
    if (!tohowToTxture.loadFromFile("img/howto.png")){
        cout<<"Error loading howto."<<endl;
    }
    tohowToSprite.setTexture(tohowToTxture);
    tohowToSprite.setPosition(241.f, 363.f);

    if (!toGameTxture.loadFromFile("img/togame.png")){
        cout<<"Error loading togame."<<endl;
    }
    toGameSprite.setTexture(toGameTxture);
    toGameSprite.setPosition(225.f, 303.f);

    if (!titTxture.loadFromFile("img/titlecard3.png")){
        cout<<"Error loading file."<<endl;
    }
    titSprite.setTexture(titTxture);
    titSprite.setPosition(130.f, 50.f);
}
HowTo::HowTo(){
    if (!howtoTxture.loadFromFile("img/background2.png")){
        cout<<"Error loading howto background."<<endl;
    }
    howtoSprite.setTexture(howtoTxture);
    howtoSprite.setPosition(0.f, 0.f);
}
void Game::run(){
    sf::Clock clock;
    gameMusic.play();
    while (mWindow.isOpen()){
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}
void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)){
       if  ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)){
            if(isTitle && (event.mouseButton.x >= ts.toGameSprite.getPosition().x && event.mouseButton.x <= ts.toGameSprite.getPosition().x+194) && (event.mouseButton.y >= ts.toGameSprite.getPosition().y && event.mouseButton.y <= ts.toGameSprite.getPosition().y+52)){
                isTitle = false;
                isHowTo = false;
                isGame = true;
                isGameOver = false;
                isGameWon=false;
            }
            else if(isTitle && (event.mouseButton.x >= ts.tohowToSprite.getPosition().x && event.mouseButton.x <= ts.tohowToSprite.getPosition().x+162) && (event.mouseButton.y >= ts.tohowToSprite.getPosition().y && event.mouseButton.y <= ts.tohowToSprite.getPosition().y+37)){
                isTitle = false;
                isHowTo = true;
                isGame = false;
                isGameOver = false;
                isGameWon=false;
            }
            else if(isHowTo && (event.mouseButton.x >= 43 && event.mouseButton.x <= 170) && (event.mouseButton.y >= 395 && event.mouseButton.x <= 444)){
                isTitle = true;
                isHowTo = false;
                isGame = false;
                isGameOver = false;
                isGameWon=false;
            }
        }
        else if(sf::Event::Closed){
            mWindow.close();
        }
        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
   if(!isPressed){
        stance=true;
        if(movedir==1){
            source.x = 0;
            source.y = 11;
        }
        else if(movedir==2){
            source.x = 0;
            source.y = 9;
        }
    }
    if(key == sf::Keyboard::A){
        mIsMovingLeft = isPressed;
        if(isPressed && movedir!=2){
            source.y = 9;
            source.x = 0;
            movedir=2;
        }
    }
    if(key == sf::Keyboard::D){
        mIsMovingRight = isPressed;
        if(isPressed && movedir!=1){
            source.y = 11;
            source.x = 0;
            movedir=1;
        }
    }
    if(key == sf::Keyboard::Space){
        if(jump==false){//So that when it is the first pressed, it will be initialized. And skipped over when it iterates
            jumpsfx.play();
            jumpctr=0;
            if(movedir==1){
                source.y=3;
                source.x=0;
            }
            else{
                source.y=1;
                source.x=0;
            }
        }
        jump = true;
    }
    if(key == sf::Keyboard::P){
        if(isPressed && attack==false){
            stance=false;
            punch = isPressed;
            if(movedir==1){
                source.y = 19;
            }
            else if(movedir==2){
                source.y = 17;
            }
        }
    }
}
void Game::update(sf::Time deltaTime){
    int max,a;
    if(isTitle){
        int max2;
        ts.titSprite.setTextureRect(sf::IntRect(ts.titsource.x*(372),ts.titsource.y*(258),(372),(258)));
        if(frameCounter >= switchFrame){
            frameCounter = 0;
            ts.titsource.x++;
            max2 = 10;
            if(ts.titsource.x>=max2){
                ts.titsource.x = 0;
            }
        }
    }
    else if(isGame==true){
        sf::Vector2f movement(0.f, 0.f);
        sf::Vector2f enemovement(0.f, 0.f);
        sf::Vector2f enemovement2(0.f, 0.f);
        sf::Vector2f enemovement3(0.f, 0.f);
        sf::Vector2f enemovement7(0.f, 0.f);
        sf::Vector2f enemovement8(0.f, 0.f);
        sf::Vector2f enemovement9(0.f, 0.f);
        mPlayer.setTextureRect(sf::IntRect(source.x*64,source.y*64,65,65));
        pPower.setTextureRect(sf::IntRect(orb.x*40,orb.y*33,40,35));
        enemy1.setTextureRect(sf::IntRect(en.x*64,en.y*64,65,65));
        enemy2.setTextureRect(sf::IntRect(ens2.x*64,ens2.y*64,65,65));
        enemy3.setTextureRect(sf::IntRect(ens3.x*64,ens3.y*64,65,65));
        enemy4.setTextureRect(sf::IntRect(ens4.x*38,ens4.y*40,36,40));
        enemy5.setTextureRect(sf::IntRect(ens5.x*38,ens5.y*40,36,40));
        enemy6.setTextureRect(sf::IntRect(ens6.x*38,ens6.y*40,36,40));
        enemy7.setTextureRect(sf::IntRect(ens7.x*80,ens7.y*80,80,80));
        enemy8.setTextureRect(sf::IntRect(ens8.x*64,ens8.y*64,65,65));
        enemy9.setTextureRect(sf::IntRect(ens9.x*64,ens9.y*64,65,65));
        enemy10.setTextureRect(sf::IntRect(ens10.x*38,ens10.y*40,36,40));
        enemy11.setTextureRect(sf::IntRect(ens11.x*38,ens11.y*40,36,40));
        enemy12.setTextureRect(sf::IntRect(ens12.x*38,ens12.y*40,36,40));
        enemy13.setTextureRect(sf::IntRect(ens13.x*192,ens13.y*192,195,195));

        if(en1){
                en.x++;
                en.y=11;
                if((enemy1.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en1=false;
                    hit=false;
                    enemy1.move(sf::Vector2f(0.0f,1000.0f));
                }
                else if(!(enemy1.getGlobalBounds().intersects(green1.getGlobalBounds())) && en1dir==1){
                    enemovement.x+=enemspeed*2;
                }
                else if((enemy1.getGlobalBounds().intersects(green1.getGlobalBounds()))){
                    en1dir=-1;
                    enemovement.x-=enemspeed*5;
                }
                else if(!(enemy1.getGlobalBounds().intersects(green1.getGlobalBounds())) && en1dir==-1){
                    en.y=9;
                    enemovement.x-=enemspeed*2;
                }
                if(enemy1.getGlobalBounds().intersects(wall1.getGlobalBounds())){
                    en1dir=1;
                    enemovement.x+=enemspeed*2;
                }
                if(en.x>=7){
                    en.x=0;
                }
                enemy1.move(enemovement * deltaTime.asSeconds());
        }
        if(en2){
                ens2.x++;
                ens2.y=11;
                if((enemy2.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en2=false;
                    hit=false;
                    enemy2.move(sf::Vector2f(0.0f,1000.0f));
                }
                else if(!(enemy2.getGlobalBounds().intersects(green2.getGlobalBounds())) && en2dir==1){
                    enemovement2.x+=enemspeed*2;
                }
                else if((enemy2.getGlobalBounds().intersects(green2.getGlobalBounds()))){
                    en2dir=-1;
                    enemovement2.x-=enemspeed*5;
                }
                else if(!(enemy2.getGlobalBounds().intersects(green2.getGlobalBounds())) && en2dir==-1){
                    ens2.y=9;
                    enemovement2.x-=enemspeed*2;
                }
                if(enemy2.getGlobalBounds().intersects(green1.getGlobalBounds())){
                    en2dir=1;
                    enemovement2.x+=enemspeed*2;
                }
                if(ens2.x>=7){
                    ens2.x=0;
                }
                enemy2.move(enemovement2 * deltaTime.asSeconds());
        }
        if(en3){
                ens3.x++;
                ens3.y=11;
                if((enemy3.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en3=false;
                    hit=false;
                    enemy3.move(sf::Vector2f(0.0f,1000.0f));

                }
                else if(!(enemy3.getGlobalBounds().intersects(green3.getGlobalBounds())) && en3dir==1){
                    enemovement3.x+=enemspeed*2;
                }
                else if((enemy3.getGlobalBounds().intersects(green3.getGlobalBounds()))){
                    en3dir=-1;
                    enemovement3.x-=enemspeed*5;
                }
                else if(!(enemy3.getGlobalBounds().intersects(green3.getGlobalBounds())) && en3dir==-1){
                    ens3.y=9;
                    enemovement3.x-=enemspeed*2;
                }
                if(enemy3.getGlobalBounds().intersects(green2.getGlobalBounds())){
                    en3dir=1;
                    enemovement3.x+=enemspeed*2;
                }
                if(ens3.x>=7){
                    ens3.x=0;
                }
                enemy3.move(enemovement3 * deltaTime.asSeconds());
        }
        if(en4){
            if(frameCounter >= switchFrame){
                ens4.x++;
                if(ens4.x>=9){
                    ens4.x=0;
                }
            }
            if((enemy4.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en4=false;
                    hit=false;
                    enemy4.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy4.getGlobalBounds())){
                en4=true;
            }
            else if((enemy4.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en4=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
        }
        if(en5){
            if(frameCounter >= switchFrame){
                ens5.x++;
                if(ens5.x>=9){
                    ens5.x=0;
                }
            }
            if((enemy5.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en5=false;
                    hit=false;
                    enemy5.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy5.getGlobalBounds())){
                en5=true;
            }
            else if((enemy5.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en5=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
            if(mPlayer.getGlobalBounds().intersects(green4.getGlobalBounds())){
                    en5=true;
                    enemy5.move(sf::Vector2f(0,100.0f));
            }

        }
        if(en6){
            if(frameCounter >= switchFrame){
                ens6.x++;
                if(ens6.x>=9){
                    ens6.x=0;
                }
            }
            if((enemy6.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en6=false;
                    hit=false;
                    enemy6.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy6.getGlobalBounds())){
                en6=true;
            }
            else if((enemy6.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en6=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
            if(mPlayer.getGlobalBounds().intersects(green5.getGlobalBounds())){
                    en6=true;
                    enemy6.move(sf::Vector2f(0,100.0f));
            }

        }
        if(en7){
                ens7.x++;
                ens7.y=2;
                if((enemy7.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en7=false;
                    hit=false;
                    enemy7.move(sf::Vector2f(0.0f,1000.0f));
                }
                else if(!(enemy7.getGlobalBounds().intersects(green8.getGlobalBounds())) && en7dir==1){
                    enemovement7.x+=enemspeed*2;
                }
                else if((enemy7.getGlobalBounds().intersects(green8.getGlobalBounds()))){
                    en7dir=-1;
                    enemovement7.x-=enemspeed*5;
                }
                else if(!(enemy7.getGlobalBounds().intersects(green8.getGlobalBounds())) && en7dir==-1){
                    ens7.y=1;
                    enemovement7.x-=enemspeed*2;
                }
                if(enemy7.getGlobalBounds().intersects(green6.getGlobalBounds())){
                    en7dir=1;
                    enemovement7.x+=enemspeed*2;
                }
                if(ens7.x>=3){
                    ens7.x=0;
                }
                enemy7.move(enemovement7 * deltaTime.asSeconds());
        }
        if(en8){
                ens8.x++;
                ens8.y=11;
                if((enemy8.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en8=false;
                    hit=false;
                    enemy8.move(sf::Vector2f(0.0f,1000.0f));

                }
                else if(!(enemy8.getGlobalBounds().intersects(green11.getGlobalBounds())) && en8dir==1){
                    enemovement8.x+=enemspeed*2;
                }
                else if((enemy8.getGlobalBounds().intersects(green11.getGlobalBounds()))){
                    en8dir=-1;
                    enemovement8.x-=enemspeed*5;
                }
                else if(!(enemy8.getGlobalBounds().intersects(green11.getGlobalBounds())) && en8dir==-1){
                    ens8.y=9;
                    enemovement8.x-=enemspeed*2;
                }
                if(enemy8.getGlobalBounds().intersects(green8.getGlobalBounds())){
                    en8dir=1;
                    enemovement8.x+=enemspeed*2;
                }
                if(ens8.x>=3){
                    ens8.x=0;
                }
                enemy8.move(enemovement8 * deltaTime.asSeconds());
        }
        if(en9){
                ens9.x++;
                ens9.y=11;
                if((enemy9.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en9=false;
                    hit=false;
                    enemy9.move(sf::Vector2f(0.0f,1000.0f));

                }
                else if(!(enemy9.getGlobalBounds().intersects(green13.getGlobalBounds())) && en9dir==1){
                    enemovement9.x+=enemspeed*2;
                }
                else if((enemy9.getGlobalBounds().intersects(green13.getGlobalBounds()))){
                    en9dir=-1;
                    enemovement9.x-=enemspeed*5;
                }
                else if(!(enemy9.getGlobalBounds().intersects(green13.getGlobalBounds())) && en9dir==-1){
                    ens9.y=9;
                    enemovement9.x-=enemspeed*2;
                }
                if(enemy9.getGlobalBounds().intersects(green11.getGlobalBounds())){
                    en9dir=1;
                    enemovement9.x+=enemspeed*2;
                }
                if(ens9.x>=3){
                    ens9.x=0;
                }
                enemy9.move(enemovement9 * deltaTime.asSeconds());
        }
        if(en11){
            if(frameCounter >= switchFrame){
                ens11.x++;
                if(ens11.x>=9){
                    ens11.x=0;
                }
            }
            if((enemy11.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en11=false;
                    hit=false;
                    enemy11.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy11.getGlobalBounds())){
                en11=true;
            }
            else if((enemy11.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en11=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
            if(mPlayer.getGlobalBounds().intersects(green12.getGlobalBounds())){
                    en11=true;
                    enemy11.move(sf::Vector2f(0,100.0f));
            }

        }
        if(en10){
            if(frameCounter >= switchFrame){
                ens10.x++;
                if(ens10.x>=9){
                    ens10.x=0;
                }
            }
            if((enemy10.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en10=false;
                    hit=false;
                    enemy10.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy10.getGlobalBounds())){
                en10=true;
            }
            else if((enemy10.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en10=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
            if(mPlayer.getGlobalBounds().intersects(green10.getGlobalBounds())){
                    en10=true;
                    enemy10.move(sf::Vector2f(0,100.0f));
            }

        }
        if(en12){
            if(frameCounter >= switchFrame){
                ens12.x++;
                if(ens12.x>=9){
                    ens12.x=0;
                }
            }
            if((enemy12.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en12=false;
                    hit=false;
                    enemy12.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        else{
            if(mPlayer.getGlobalBounds().intersects(enemy12.getGlobalBounds())){
                en12=true;
            }
            else if((enemy12.getGlobalBounds().intersects(pPower.getGlobalBounds()))){
                    en12=true;
                    hit=false;
                    pPower.move(sf::Vector2f(0.0f,500.0f));
            }
            if(mPlayer.getGlobalBounds().intersects(green13.getGlobalBounds())){
                    en12=true;
                    enemy12.move(sf::Vector2f(0,100.0f));
            }

        }
        if(en13){
            ens13.y=8;
            if(counter==true){
                counter=false;
                hit=true;
                pPower.setPosition(green14.getPosition());
                pPower.move(sf::Vector2f(-100,0));
                initdir=2;
                attack=true;
                if(initdir==1){
                    orb.y=1;
                }
                else{
                    orb.y=0;
                }
            }
            else if (pPower.getGlobalBounds().intersects(green14.getGlobalBounds())){
                a=rand()%3;
                if(a==1){
                    bosslife--;
                    pPower.move(sf::Vector2f(0.0f,1000.0f));
                }
                else{
                    hit=true;
                    counter=true;
                    attackctr=0;
                    bossctr=true;
                    deflect=true;
                }
            }
            if((pPower.getGlobalBounds().intersects(mPlayer.getGlobalBounds())) && bossctr==true){
                life--;
                pPower.move(sf::Vector2f(0.0f,1000.0f));
            }
            if(deflect){
                if(frameCounter >= switchFrame){
                    ens13.x++;
                    if(ens13.x>=5){
                        ens13.x=0;
                        deflect=false;
                    }
                }
            }
            if(bosslife==0){
                en13=false;
                enemy13.move(sf::Vector2f(0.0f,1000.0f));
                green14.move(sf::Vector2f(0.0f,1000.0f));
            }
        }
        if((mPlayer.getGlobalBounds().intersects(green16.getGlobalBounds())) &&bosscene==false){
            boss=true;
            position.x+=(350);
            wall1.move(sf::Vector2f(350,0));
            wall2.move(sf::Vector2f(350,0));
            manaready.move(sf::Vector2f(350,0));
            heart1.move(sf::Vector2f(350,0));
            heart2.move(sf::Vector2f(350,0));
            heart3.move(sf::Vector2f(350,0));
            bosscene=true;
        }
        if((mPlayer.getGlobalBounds().intersects(green15.getGlobalBounds()))){
            isGame=false;
            isGameWon=true;
            gameMusic.stop();
            victoryMusic.play();
        }
        if(mIsMovingLeft){
            if(!(mPlayer.getGlobalBounds().intersects(wall1.getGlobalBounds()))){
                movement.x -= PlayerSpeed;
            }
            else if(position.x>0){
                if(boss==false){
                    position.x-=(1);
                    wall1.move(sf::Vector2f(-1,0));
                    wall2.move(sf::Vector2f(-1,0));
                    manaready.move(sf::Vector2f(-1,0));
                    heart1.move(sf::Vector2f(-1,0));
                    heart2.move(sf::Vector2f(-1,0));
                    heart3.move(sf::Vector2f(-1,0));
                }
            }
        }
            else if(mIsMovingRight){
            if(!(mPlayer.getGlobalBounds().intersects(wall2.getGlobalBounds()))){
                movement.x += PlayerSpeed;
            }
            else if(position.x<3400){
                position.x+=(1);
                wall1.move(sf::Vector2f(1,0));
                wall2.move(sf::Vector2f(1,0));
                manaready.move(sf::Vector2f(1,0));
                heart1.move(sf::Vector2f(1,0));
                heart2.move(sf::Vector2f(1,0));
                heart3.move(sf::Vector2f(1,0));
            }
        }
        if(jump){
            if((!(mPlayer.getGlobalBounds().intersects(sky.getGlobalBounds())))&& jumpctr==0){
                movement.y -= PlayerSpeed*4;
            }
            else if((mPlayer.getGlobalBounds().intersects(sky.getGlobalBounds()))&& jumpctr==0){
                movement.y += PlayerSpeed*4;
                jumpctr=-1;
            }
            else {
                movement.y += PlayerSpeed*4;
            }
            if(mPlayer.getGlobalBounds().intersects(ground.getGlobalBounds())){
                movement.y -= PlayerSpeed*6;
                jumpctr=0;
                jump=false;
            }
        }
        if(stance){
            punch=false;
            if(frameCounter >= switchFrame){
                frameCounter = 0;
                source.x++;
                if((mIsMovingRight || mIsMovingLeft)&&!jump)
                    max = 8;
                else if(jump)
                    max = 6;
                else
                    max=0;
                if(source.x>=max){
                    if(mIsMovingRight && movedir==1){
                        source.x = 0;
                        source.y = 11;
                    }
                    else if(mIsMovingLeft && movedir==2){
                        source.x = 0;
                        source.y = 9;
                    }
                    else{
                        source.x=0;
                    }
                }
            }
        }
        else if(punch){//here
            stance=false;
            if(!attack && source.x==8){
                attacksfx.play();
                pPower.setPosition(mPlayer.getPosition());
                pPower.move(sf::Vector2f(0,25));
                initdir=movedir;
                attack=hit=true;
                if(initdir==1){
                    orb.y=0;
                }
                else{
                    orb.y=1;
                }
            }
            else if(frameCounter >= switchFrame){
                frameCounter = 0;
                source.x++;
                if(source.x>=9){
                    source.x=8;
                }
            }

        }
        if(attack){
            attackctr++;
            if(attackctr==1000){
                    bossctr=false;
                    attack=false;
                    attackctr=0;
            }
            else{
                if(hit==true){
                    if(initdir==1){
                        if(deflect){
                            pPower.move(sf::Vector2f(1,0));
                        }
                        else{
                            pPower.move(sf::Vector2f(2,0));
                        }
                    }
                    else if(initdir==2){
                        if(counter){
                            pPower.move(sf::Vector2f(-1,0));
                        }
                        pPower.move(sf::Vector2f(-2,0));
                    }
                }
                else{
                    pPower.move(sf::Vector2f(0,50));
                }
            }
        }
        if(damage){
            recovery++;
            if(recovery<=600){
                if(recovery<250){
                    if(initdir2==1){
                        movement.x -= PlayerSpeed*3;
                    }
                    else{
                       movement.x += PlayerSpeed*3;
                    }
                }
            }
            else{
                damage=false;
                recovery=0;
            }
            if(source.x<=4){
                source.x=3;
            }
        }
        else{
            if((mPlayer.getGlobalBounds().intersects(enemy1.getGlobalBounds())) || (mPlayer.getGlobalBounds().intersects(enemy2.getGlobalBounds())) || (mPlayer.getGlobalBounds().intersects(enemy3.getGlobalBounds())) || (mPlayer.getGlobalBounds().intersects(enemy4.getGlobalBounds())) || (mPlayer.getGlobalBounds().intersects(enemy5.getGlobalBounds())) || (mPlayer.getGlobalBounds().intersects(enemy6.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy7.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy8.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy9.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy10.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy11.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(enemy12.getGlobalBounds()))|| (mPlayer.getGlobalBounds().intersects(green14.getGlobalBounds()))){
                damage=true;
                hurtsfx.play();
                life--;
                initdir2=movedir;
                source.y=20;
                source.x=0;
            }
        }
        mPlayer.move(movement * deltaTime.asSeconds());
        if(life==0){
            isGame=false;
            isGameOver=true;
            gameMusic.stop();
            gameOverMusic.play();
        }
    }
    frameCounter += stanceSpeed * deltaTime.asSeconds();
}
void Game::render(){
    if(isTitle){
        mWindow.clear();
        mWindow.draw(ts.bgSprite);
        mWindow.draw(ts.toGameSprite);
        mWindow.draw(ts.tohowToSprite);
        mWindow.draw(ts.titSprite);
        mWindow.display();
    }
    else if(isHowTo){
        mWindow.clear();
        mWindow.draw(ht.howtoSprite);
        mWindow.display();
    }
    else if(isGame){
        mWindow.clear();
        view.reset(sf::FloatRect(position.x,position.y,640,480));
        mWindow.draw(wall1);
        mWindow.draw(wall2);
        mWindow.setView(view);
        mWindow.draw(sky);
        mWindow.draw(wall1);
        mWindow.draw(wall2);
        mWindow.draw(ground);
        mWindow.draw(green1);
        mWindow.draw(green2);
        mWindow.draw(green3);
        mWindow.draw(green4);
        mWindow.draw(green5);
        mWindow.draw(green6);
        mWindow.draw(green7);
        mWindow.draw(green8);
        mWindow.draw(green9);
        mWindow.draw(green10);
        mWindow.draw(green11);
        mWindow.draw(green12);
        mWindow.draw(green13);
        mWindow.draw(green14);
        mWindow.draw(green15);
        mWindow.draw(green16);
        mWindow.draw(Background);

        if(!attack){
            mWindow.draw(manaready);
        }
        if(life>=1){
            mWindow.draw(heart1);
            if(life>=2){
            mWindow.draw(heart2);
                if(life>=3){
                    mWindow.draw(heart3);
                }
            }
        }
        if(bosslife>=1){
            mWindow.draw(bheart1);
            if(bosslife>=2){
                mWindow.draw(bheart2);
                if(bosslife>=3){
                    mWindow.draw(bheart3);
                }
            }
        }
        if(en1){
            mWindow.draw(enemy1);
        }
        if(en2){
            mWindow.draw(enemy2);
        }
        if(en3){
            mWindow.draw(enemy3);
        }
        if(en4){
            mWindow.draw(enemy4);
        }
        if(en5){
            mWindow.draw(enemy5);
        }
        if(en6){
            mWindow.draw(enemy6);
        }
        if(en7){
            mWindow.draw(enemy7);
        }
        if(en8){
            mWindow.draw(enemy8);
        }
        if(en9){
            mWindow.draw(enemy9);
        }
        if(en10){
            mWindow.draw(enemy10);
        }
        if(en11){
            mWindow.draw(enemy11);
        }
        if(en12){
            mWindow.draw(enemy12);
        }
        mWindow.draw(enemy13);
        mWindow.draw(mPlayer);
        if(attack){
            mWindow.draw(pPower);
        }

        mWindow.display();
    }
    else if (isGameOver){
        mWindow.clear();
        mWindow.setView(mWindow.getDefaultView());
        mWindow.draw(Gameover);
        mWindow.display();
    }
    else  if(isGameWon){
        mWindow.clear();
        mWindow.setView(mWindow.getDefaultView());
        mWindow.draw(Gamewon);
        mWindow.display();
    }
}
