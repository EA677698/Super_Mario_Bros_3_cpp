class GameTick{
private:
    int tps,fps,tpsCount,fpsCount,frameTimeSplit,tickTimeSplit;

public:
    void muteBGM();
    int getTps();
    int getFps();

};

int GameTick::getTps(){
    return tps;
}

int GameTick::getFps() {
    return fps;
}