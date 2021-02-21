//
// Created by Erick on 2/21/2021.
//

#include "Manager.h"

Manager::Manager() {

}

bool Manager::commandInput(String input) {
    if(input.contains(" ")) {
        String end = input.substring(input.find(" ") + 1);
        switch (input.substring(0, input.find(" ")-1)) {
            case "spawn":
                return spawnElement(end);
            case "remove":
                return removeElement(end);
            case "add":
                return addStats(end);
            case "freeze":
                return freezeElements(end);
            case "background":
                try {
                    level.setBackground(Background.valueOf(end.toUpperCase()));
                } catch (Exception e) {
                    e.printStackTrace();
                }
                return true;
            case "save":
                Saver.world = Integer.parseInt(end.substring(0,end.indexOf(" ")));
                Saver.level = Integer.parseInt(end.substring(end.indexOf(" ")+1));
                Saver.createLevel();
                return true;
            case "load":
                //Loader.loadLevel(end);
                Loader.loadLevel(end);
                return true;
            case "bgm":
                level.changeMusic(BGM.valueOf(end.toUpperCase()));
                return true;
        }
    } else {
        switch (input){
            case "debug":
                Settings.debug = !Settings.debug;
                return true;
            case "fps":
                Settings.fps = !Settings.fps;
                return true;
            case "hitbox":
                Settings.hitBoxes = !Settings.hitBoxes;
                return true;
            case "crt":
                Settings.crt = !Settings.crt;
                return true;
            case "quit":
                System.exit(0);
                return true;
            case "unload":
                ents.clear();
                tiles.clear();
                level = new Level(Background.AQUA_BACKGROUND, BGM.GRASS_LAND);
                return true;
            case "mute":
                Settings.muted = !Settings.muted;
        }
    }
    return false;
}

bool Manager::addStats(string stat) {
    int end = Integer.parseInt(stat.substring(stat.indexOf(" ")+1));
    switch (stat.substring(0,stat.indexOf(" "))){
        case "score":
            Global.score += end;
            return true;
        case "money":
            Global.money += end;
            return true;
        case "lives":
            Global.lives += end;
            return true;
    }
    return false;
}

bool Manager::freezeElements(string element) {
    switch (element){
        case "all":
            for(Entity entity: ents){
                entity.setAllowedMoving(!entity.isAllowedMoving());
            }
            return true;
        case "goomba":
            for(Entity entity: ents){
                if(entity instanceof Goomba){
                    entity.setAllowedMoving(!entity.isAllowedMoving());
                }
            }
            return true;
        case "enemies":
            for(Entity entity: ents){
                if(entity instanceof Enemy){
                    entity.setAllowedMoving(!entity.isAllowedMoving());
                }
            }
            return true;
        case "koopatroopa":
            for(Entity entity: ents){
                if(entity instanceof KoopaTroopa){
                    entity.setAllowedMoving(!entity.isAllowedMoving());
                }
            }
            return true;
        case "fireball":
            for(Entity entity: ents){
                if(entity instanceof Fireball){
                    entity.setAllowedMoving(!entity.isAllowedMoving());
                }
            }
            return true;
        case "hammerbro":
            for(Entity entity: ents){
                if(entity instanceof HammerBro){
                    entity.setAllowedMoving(!entity.isAllowedMoving());
                }
            }
            return true;
    }
    return false;
}

void Manager::resetEntities() {
    for(Entity ent: ents){
        ent.removeFromLayer();
        ents.remove(ent);
    }
}

void Manager::resetTiles() {
    for(Tile tile: tiles){
        tile.removeFromLayer();
        tiles.remove(tile);
    }
}

void Manager::select() {
    for(Entity ent: ents){
        if(ent.getHitBox().intersects(Controls.mouseHitBox)){
            if(selectedEntity!=null){
                selectedEntity.setDirection(previousDirection);
                selectedEntity.setSelected(false);
            }
            selectedEntity = ent;
            selectedEntity.setSelected(true);
            selectedTile = null;
            previousDirection = selectedEntity.getDirection();
            selectedEntity.setDirection(0);
            return;
        }
    }
    for(Tile tile: tiles){
        if(tile.getHitBox().intersects(Controls.mouseHitBox)){
            selectedTile = tile;
            if(selectedEntity!=null){
                selectedEntity.setDirection(previousDirection);
                selectedEntity.setSelected(false);
                return;
            }
        }
    }
}

void Manager::freeEntity() {
    if(selectedEntity!=NULL){
        if(System.nanoTime()-timer1>100000000){
            if(Controls.six&&selectedEntity.getDirection()==0){
                selectedEntity.setDirection(previousDirection);
            } else{
                if(Controls.six&&selectedEntity.getDirection()!=0){
                    selectedEntity.setDirection(0);
                }
            }
            timer1 = System.nanoTime();
        }
    }
}

void Manager::culling() {
    //Checks to see if the element is within the screen's boundaries otherwise it unloads it
    for(Entity entity: ents){
        //entity.setUnloaded(!screen.intersects(entity.getHitBox()) && !screen.contains(entity.getHitBox()));
        entity.setUnloaded((entity.getHitBox().getMinX()<0&&entity.getHitBox().getMaxX()<0)||
                           (entity.getHitBox().getMinX()>1920&&entity.getHitBox().getMaxX()>1920)||(entity.getHitBox().getMinY()>840&&entity.getHitBox().getMaxY()>840)||
                           (entity.getHitBox().getMinY()<0&&entity.getHitBox().getMaxY()<0));
    }
    for(Tile tile: tiles){
        tile.setUnloaded((tile.getHitBox().getMinX()<0&&tile.getHitBox().getMaxX()<0)||
                         (tile.getHitBox().getMinX()>1920&&tile.getHitBox().getMaxX()>1920)||(tile.getHitBox().getMinY()>840&&tile.getHitBox().getMaxY()>840)||
                         (tile.getHitBox().getMinY()<0&&tile.getHitBox().getMaxY()<0));
        //tile.setUnloaded(!screen.intersects(tile.getHitBox()) && !screen.contains(tile.getHitBox()));
    }
}

void Manager::tick() {
    if(Settings.debug){
        freeEntity();
    }
    sideScroll();
    collision();
    culling();
    if(Settings.debug&&!Controls.console){
        deleteSelected();
    }
}

void Manager::marioCheck() {
    if(player!=null){
        player.removeFromLayer();
        ents.remove(player);
        player = null;
    }
}

bool Manager::removeElement(string element) {
    if(element.equals("entities")){
        resetEntities();
        return true;
    } else if(element.equals("tiles")){
        resetTiles();
        return true;
    }
    return false;
}

bool Manager::spawnElement(string element) {
    String temp;
    if(element.contains(" ")){
        temp = element.substring(0, element.indexOf(" "));
    } else {
        temp = element;
    }
    switch (temp){
        case "mario":
            marioCheck();
            ents.add(new Player(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,60, true));
            return true;
        case "goomba":
            ents.add(new Goomba(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,60,1, true));
            return true;
        case "koopatroopa":
            ents.add(new KoopaTroopa(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,98,1, true));
            return true;
        case "redmushroom":
            ents.add(new RedMushroom(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,60,1,true));
            return true;
        case "greenmushroom":
            ents.add(new GreenMushroom(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,60,1,true));
            return true;
        case "coin":
            ents.add(new Coin(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,60,0,true));
            return true;
        case "floor":
            tiles.add(new Floor(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,8,1));
            return true;
        case "woodenblock":
            tiles.add(new WoodenBlock(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true));
            return true;
        case "luckyblock":
            tiles.add(new LuckyBlock(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,new Coin(Layer.NONE, new Point(0,0),70,80,0,true)));
            return true;
        case "hill1":
            tiles.add(new Hill(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),false,2,8));
            return true;
        case "hill2":
            tiles.add(new Hill(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),false,1,8));
            return true;
        case "brick":
            tiles.add(new Bricks(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,true));
            return true;
        case "firehammerbro":
            ents.add(new HammerBro(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),60,98,-1,true,3));
            return true;
        case "pipe":
            tiles.add(new Pipes(Layer.MIDDLE_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,4));
            return true;
        case "cloud1":
            tiles.add(new Clouds(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2), false ,1));
            return true;
        case "bg":
            tiles.add(new BigBlocks(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,0,0,0));
            return true;
        case  "bp":
            tiles.add(new BigBlocks(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,2,0,0));
            return true;
        case  "bb":
            tiles.add(new BigBlocks(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,1,0,0));
            return true;
        case  "bw":
            tiles.add(new BigBlocks(Layer.BACK_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),true,3,0,0));
            return true;
        case  "shrub":
            tiles.add(new Shrub(Layer.BACK_LAYER,new Point(Window.screenWidth/2,Window.screenHeight/2),false));
            return true;
        case "clip":
            tiles.add(new Clip(Layer.FRONT_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2),0,1));
            return true;
        case "trigger":
            String command = element.substring(element.indexOf(" ")+1, element.lastIndexOf(" "));
            int activations = Integer.parseInt(element.substring(element.lastIndexOf(" ")+1));
            tiles.add(new Trigger(Layer.FRONT_LAYER, new Point(Window.screenWidth/2,Window.screenHeight/2), 0,1, command, activations));
            return true;
    }
    return false;
}

void Manager::deleteSelected() {
    if(selectedEntity!=null){
        if(Controls.delete){
            if(selectedEntity==player){
                marioCheck();
            }
            selectedEntity.removeFromLayer();
            ents.remove(selectedEntity);
            selectedEntity = null;
        }
    }
    if(selectedTile!=null){
        if(Controls.delete){
            selectedTile.removeFromLayer();
            tiles.remove(selectedTile);
            selectedTile = null;
        }
    }
}

void Manager::sideScroll() {
    if(Settings.debug&&!Controls.shift){
        if(System.nanoTime()-debugScroll>70000000){
            if(Controls.right){
                for(Entity ent: ents){
                    if(ent!=player){
                        ent.addX(-60);
                    }
                }
                for(Tile tile : tiles){
                    tile.addX(-60);
                }
            } else if(Controls.left){
                for(Entity ent: ents){
                    if(ent!=player){
                        ent.addX(60);
                    }
                }
                for(Tile tile : tiles){
                    tile.addX(60);
                }
            }
            debugScroll = System.nanoTime();
        }
        return;
    }
    if(player == null){
        for(Entity ent: ents){
            if(ent instanceof Player){
                player = (Player) ent;
            }
        }
    }
    if(player == null){
        return;
    }
    if(!player.isDead()){
        if(player.isMiddleH()&&Controls.jump){
            for(Entity ent: ents){
                if(ent!=player){
                    ent.addY(5);
                }
            }
            for(Tile tile : tiles){
                tile.addY(5);
            }
        } else {
            if(player.isStartH()){
                for(Entity ent: ents){
                    if(ent!=player){
                        ent.addY(-5);
                    }
                }
                for(Tile tile : tiles){
                    tile.addY(-5);
                }
            }
        }
        if(player.isMiddle()){
            for(Entity ent: ents){
                if(ent!=player){
                    ent.addX((int)(-1*player.getXVelocity()));
                }
            }
            for(Tile tile : tiles){
                tile.addX((int)(-1*player.getXVelocity()));
            }
        } else {
            if(player.isStart()){
                for(Entity ent: ents){
                    if(ent!=player){
                        ent.addX((int)player.getXVelocity());
                    }
                }
                for(Tile tile : tiles){
                    tile.addX((int)player.getXVelocity());
                }
            }
        }
    }
}

void Manager::collision() {
    for(Entity ent : ents){
        if(ent.isCollision()&&!ent.isUnloaded()){
            if(player!=null){
                if(ent instanceof Enemy){
                    if(System.nanoTime()-hitTimer>2000000000){
                        // If an enemy hits mario from his sides
                        int side = ent.getHitBox().outcode(player.getHitBox().getCenterX(),player.getHitBox().getCenterY());
                        if(player.getHitBox().intersects(ent.getHitBox())){
                            if(side==1||side==4){
                                switch (player.getPower()){
                                    case SMALL: player.setDead(true);
                                        Main.game.getBgmPlayer().getMusic().stop();
                                        SFX.down1.setFramePosition(0);
                                        SFX.down1.start();
                                        break;
                                    case BIG: player.setPower(Powers.SMALL);
                                        SFX.pipe.setFramePosition(0);
                                        SFX.pipe.start();
                                        break;
                                    default: player.setPower(Powers.BIG);
                                }
                                hitTimer = System.nanoTime();
                            } else {
                                if(side==2){
                                    ent.death();
                                }
                            }
                        }
                    }
                    //Activates Non Living Entity Special Action towards Mario
                } else if(ent instanceof NotLiving){
                    if(ent.getHitBox().intersects(player.getHitBox())){
                        ((NotLiving) ent).executeUponTouch(player);
                    }
                }
            }
            //If two entities collide
            for(Entity ent2: ents){
                if(ent!=ent2) {
                    if (ent2.isCollision() && !ent2.isUnloaded()) {
                        if (ent instanceof Enemy && ent2 instanceof Enemy) {
                            if (ent.getHitBox().intersects(ent2.getHitBox())) {
                                ent.setDirection(ent.getDirection() * -1);
                                ent2.setDirection(ent2.getDirection() * -1);
                            }
                        }
                    }
                }
            }
            for(Tile tile : tiles){
                if(tile.isCollision()&&!tile.isUnloaded()){
                    if(tile.getHitBox().intersects(ent.getHitBox())){
                        //If an entity hits something from his sides while moving
                        int side = tile.getHitBox().outcode(ent.getHitBox().getCenterX(),ent.getHitBox().getCenterY());
                        if(!(tile instanceof BigBlocks)&&(side==1||side==4||side==9||side==12)){
                            if(ent.isFacingTile(tile)){
                                if(ent instanceof Player){
                                    if(ent.getDirection()==1){
                                        player.setXVelocity(0);
                                        Controls.right = false;
                                    } else {
                                        player.setXVelocity(0);
                                        Controls.left = false;
                                    }
                                } else {
                                    ent.setDirection(ent.getDirection()*-1);
                                }
                            } //If Mario Hits something above him while jumping
                        } else if(side==8||side==9||side==12){
                            if(ent instanceof Player){
                                ent.setYVelocity(0);
                                ent.setHasGravity(true);
                            }
                        }
                    }
                }
            }
        }
    }
}

Entity *Manager::getSelectedEntity() const {
    return selectedEntity;
}

void Manager::setSelectedEntity(Entity *selectedEntity) {
    Manager::selectedEntity = selectedEntity;
}

Tile *Manager::getSelectedTile() const {
    return selectedTile;
}

void Manager::setSelectedTile(Tile *selectedTile) {
    Manager::selectedTile = selectedTile;
}

Player *Manager::getMario() const {
    return mario;
}

void Manager::setMario(Player *mario) {
    Manager::mario = mario;
}

Level *Manager::getLevel() const {
    return level;
}

void Manager::setLevel(Level *level) {
    Manager::level = level;
}

const vector<Tile *> &Manager::getTiles() const {
    return tiles;
}

const HitBox &Manager::getScreen() const {
    return screen;
}

int Manager::getPreviousDirection() const {
    return previousDirection;
}

const vector<Entity *> &Manager::getEnts() const {
    return ents;
}

void Manager::setPreviousDirection(int previousDirection) {
    Manager::previousDirection = previousDirection;
}
