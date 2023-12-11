import pygame as pg
import os
from pygame.locals import *
from entity import Entity as Entity
from melee import Melee as Melee
from ranged import Ranged as Ranged
from projectile import Projectile as Projectile

def onEntityClick(entities, entity, delta):
    if entity.team == 'player' and entity.unitType != 'projectile':
        if entity.selected == False:
            entity.selected = True
        else:
            entity.selected = False
    elif entity.team == 'enemy':
        for entityIt in entities:
            if entityIt.team == 'player':
                if entityIt.selected == True:
                    entityIt.attack(entity, delta)

def onGameFieldClick(entities, x, y):
    for entity in entities:
        if entity.team == 'player':
            if entity.selected == True:
                entity.moveTo(x, y)
                    
def main():
    # Startup pygame
    pg.init()
    
    # Get a screen object
    screen = pg.display.set_mode([825, 825]) # class dimensions

    # Background
    background = pg.image.load('./assets/tile_sheet_960px_by_960px.png')
    
    entities = pg.sprite.Group()

    # player
    melee = Melee((275, 200), 'player')
    entities.add(melee)
    melee = Melee((250, 150), 'player')
    entities.add(melee)
    melee = Melee((200, 125), 'player')
    entities.add(melee)
    melee = Melee((200, 200), 'player')
    entities.add(melee)
    melee = Melee((200, 275), 'player')
    entities.add(melee)
    melee = Melee((250, 250), 'player')
    entities.add(melee)
    ranged = Ranged((150, 250), 'player')
    entities.add(ranged)
    ranged = Ranged((150, 175), 'player')
    entities.add(ranged)
    # enemy
    melee = Melee((625, 550), 'enemy')
    entities.add(melee)
    melee = Melee((700, 525), 'enemy')
    entities.add(melee)
    melee = Melee((700, 600), 'enemy')
    entities.add(melee)
    melee = Melee((700, 675), 'enemy')
    entities.add(melee)
    melee = Melee((625, 650), 'enemy')
    entities.add(melee)
    ranged = Ranged((750, 650), 'enemy')
    entities.add(ranged)
    ranged = Ranged((750, 575), 'enemy')
    entities.add(ranged)
    
    
    # Start sound
    pg.mixer.music.load("./assets/04 - Human 1.mp3", "mp3")
    pg.mixer.music.play(-1)
    
    # Get font setup
    pg.freetype.init()
    font_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "./assets/", "Retro Gaming.ttf")
    font_size = 64
    font = pg.freetype.Font(font_path, font_size)
    WHITE = (254, 254, 254)
    
    # Startup the main game loop
    running = True
    delta = 0
    shotDelta = 500
    animationDelta = 500
    combatDelta = 500
    attackSpeedDelta = 500
    fps = 60
    clock = pg.time.Clock()
    clock.tick(fps)
    score = 0
    gameover = False
    while running:
        # First thing we need to clear the events
        for event in pg.event.get():
            if event.type == pg.QUIT:
                running = False
            if event.type == pg.MOUSEBUTTONUP:
                pos = pg.mouse.get_pos()
                entityClicked = False
                for entity in entities:
                    if entity.rect.collidepoint(pos):
                        onEntityClick(entities, entity, delta)
                        entityClicked = True
                if entityClicked == False:
                    onGameFieldClick(entities, pos[0], pos[1])
        
        if score >= 700:
            print("You win!")
            gameover = True
        noUnits = True
        for entity in entities:
            if entity.team == 'player' and entity.unitType != 'projectile':
                if entity.dead == False:
                    noUnits = False
        if noUnits == True:
            print("You lose!")
            gameover = True
        
        # Ok, events are handled, let's draw!
        # background instantiation 
        screen.blit(background, (0, 0))
        pg.display.update
        
        if gameover == True:
            break
        
        for entity in entities:
            entity.update(entities,  delta)
        
         # update combat
        if attackSpeedDelta >= .50:
            for entity in entities:
                if entity.inCombatWith != None and entity.unitType != 'projectile':
                    if entity.unitType == 'ranged':
                        projectile = Projectile(entity.rect.center, entity.inCombatWith)
                        entities.add(projectile)
                    entity.attack(entity.inCombatWith, delta)
            attackSpeedDelta = 0
            
        # update entities animation
        if animationDelta >= .10:
            for entity in entities:
                score += entity.updateAnimation()
            animationDelta = 0
            
        entities.draw(screen)
        
        font.render_to(screen, (10, 10), "Score: " + str(score), WHITE, None, size=64)
    
        # When drawing is done, flip the buffer.
        pg.display.flip()
        
        delta = clock.tick(fps) / 1000.0
        shotDelta += delta
        animationDelta += delta
        attackSpeedDelta += delta
    
    # game is over
    while running:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                running = False
       
        screen.blit(background, (0, 0))
        pg.display.update
     
        entities.draw(screen)
        
        font.render_to(screen, (10, 10), "Score: " + str(score), WHITE, None, size=64)
        
        if score >= 700:
            font.render_to(screen, (250, 350), "You win!", WHITE, None, size=64)
        else:
            font.render_to(screen, (250, 350), "You lose!", WHITE, None, size=64)
    
        pg.display.flip()
        
# Startup the main method to get things going.
if __name__ == "__main__":
    main()
    pg.quit()