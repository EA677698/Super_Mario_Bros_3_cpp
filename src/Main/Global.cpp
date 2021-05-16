//
// Created by Erick on 2/20/2021.
//
#include "Global.h"

void Global::HUDCheck(){
    if(manager->getPlayer()!= nullptr){
        int temp = (int)manager->getPlayer()->getXVelocity();
        for(int i = 1; temp>4; i++){
            active[i] = true;
            temp--;
// FIX SPEED METER VVVVV TEMP SOLUTION!!!!!
            if(active[1]){
                active[0] = true;
            }
        }
    }
    if(money>=100){
        money = 0;
        lives++;
    }
    if(lives>99){
        lives = 99;
    }
}

void Global::addCard(Cards card){
    int totals = 0;
    Cards * selected;
    for(int i = 0; i<3; i++){
        selected = &cards[i];
        if(selected!= nullptr){
            totals++;
        } else {
            selected = &card;
            return;
        }
    }
    if(totals==3){
        lives++;
    }
}

void Global::scaling(){
    if(!(scaleX == (windowSize.width/1980.0)&&scaleY==(windowSize.height/1080.0))){
        scaleX = (windowSize.width/1920.0);
        scaleY = (windowSize.height/1080.0);
    }
}

void Global::playSound(string path) {
    buffer.loadFromFile(path);
    sound.setBuffer(buffer);
    sound.play();
}

Global::Global() {
    manager = new Manager(*this);
}

//void getCards(){
//    Image[] ret = new Image[3];
//    ret[0] = cardToImage(cards[0]);
//    ret[1] = cardToImage(cards[1]);
//    ret[2] = cardToImage(cards[2]);
//    return ret;
//}

//Image cardToImage(Cards card){
//    switch (card){
//        case STAR_CARD:
//            return Main.game.getSpritesLoader().getCards()[3];
//        case FLOWER_CARD:
//            return Main.game.getSpritesLoader().getCards()[2];
//        case MUSHROOM_CARD:
//            return Main.game.getSpritesLoader().getCards()[1];
//        default:
//            return Main.game.getSpritesLoader().getCards()[0];
//    }
//}

//Image[] getTime(){
//    Image[] timer = new Image[3];
//    timer[2] = Renderer.nums.get((time % 10));
//    timer[1] = Renderer.nums.get(time / 10 % 10);
//    timer[0] = Renderer.nums.get(time / 100 % 10);
//    return timer;
//}

//Image[] getLives(){
//    Image[] live = new Image[2];
//    live[0] = Renderer.nums.get(lives / 10);
//    live[1] = Renderer.nums.get(lives % 10);
//    return live;
//}

//Image[] getScores(){
//    Image[] scores = new Image[7];
//    scores[6] = Renderer.nums.get((score % 10));
//    scores[5] = Renderer.nums.get(score / 10 % 10);
//    scores[4] = Renderer.nums.get(score / 100 % 10);
//    scores[3] = Renderer.nums.get(score / 1000 % 10);
//    scores[2] = Renderer.nums.get(score / 10000 % 10);
//    scores[1] = Renderer.nums.get(score / 100000 % 10);
//    scores[0] = Renderer.nums.get(score / 1000000);
//    return scores;
//}

//Image[] getMoney(){
//    Image[] moneys = new Image[2];
//    moneys[1] = Renderer.nums.get(money / 10);
//    moneys[0] = Renderer.nums.get(money % 10);
//    return moneys;
//}