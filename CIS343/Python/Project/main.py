

import pygame as pg
import os
#from projectile import Projectile
from pygame.locals import *
#from Python.Project.entity import Entity as Entity
from entity import Entity as Entity

#change to private vars later
def onEntityClick(entities, entity, delta):
    if entity.team == 'player':
        if entity.selected == False:
            entity.selected = True
        else:
            entity.selected = False
    elif entity.team == 'enemy':
        for entityIt in entities:
            if entityIt.team == 'player':
                if entityIt.selected == True:
                    entityIt.attack(entity, delta)
                    
                    
# def onResourceClick(entities, resource):
#     for entity in entities:
#         if entity.team == 'player':
#             if entity.selected == True:
#                 if entity.type == 'gatherer':
#                     entity.gather(resource)

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
    
    #player = Player()
    
    entities = pg.sprite.Group()
    #projectiles = pg.sprite.Group()
    
    # placing in class enemies at spawns
    # for i in range(500, 1000, 75):
    #     for j in range(100, 600, 50):
    #         entity = Entity((i, j))
    #         entities.add(entity)

    # place 2 entities in middle for testing
    entity = Entity((100, 800), 'player')
    entities.add(entity)
    entity = Entity((150, 750), 'player')
    entities.add(entity)
    entity = Entity((200, 800), 'player')
    entities.add(entity)
    entity = Entity((250, 750), 'player')
    entities.add(entity)
    entity = Entity((300, 800), 'player')
    entities.add(entity)
    entity = Entity((600, 100), 'enemy')
    entities.add(entity)
    entity = Entity((650, 150), 'enemy')
    entities.add(entity)
    entity = Entity((700, 100), 'enemy')
    entities.add(entity)
    entity = Entity((750, 150), 'enemy')
    entities.add(entity)
    entity = Entity((800, 100), 'enemy')
    entities.add(entity)
    #MORE!!!
    
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
    while running:
        # First thing we need to clear the events
        for event in pg.event.get():
            if event.type == pg.QUIT:
                running = False
            #if event.type == pg.USEREVENT + 1:
            #    score += 100
            if event.type == pg.MOUSEBUTTONUP:
                pos = pg.mouse.get_pos()
                entityClicked = False
                for entity in entities:
                    if entity.rect.collidepoint(pos):
                        onEntityClick(entities, entity, delta)
                        entityClicked = True
                        #if entity.team == 'enemy':
                            # hacky way to force collision for combat
                            
                        #    entityClicked = False
                if entityClicked == False:
                    onGameFieldClick(entities, pos[0], pos[1])
                # for resource in resources:
                #     if resource.rect.collidepoint(pos):
                #         onResourceClick(entities, resource)
        
        # Win condition 
        #enemyExists = False
        #playerExists = False   
        #for entity in entities:
        #    if entity.team == 'enemy':
        #        enemyExists = True
        #    if entity.team == 'player':
        #        playerExists = True
        #    #if enemyExists == False and playerExists == True:
        #    #    print("You win!")
        #    #    return
        #    if playerExists == False:
        #        print("You lose!")
        #        return
        
        # Ok, events are handled, let's draw!

        # background instantiation 
        screen.blit(background, (0, 0))
        pg.display.update
        
        # player.update(delta)
        for entity in entities:
            entity.update(entities,  delta)
        # for projectile in projectiles:
        #     projectile.update(delta)
        
         # update combat
        if attackSpeedDelta >= .50:
            for entity in entities:
                if entity.inCombatWith != None:
                    entity.attack(entity.inCombatWith, delta)
            attackSpeedDelta = 0
            
        #if combatDelta > 3:
        #    for entity in entities:
        for entity in entities:
            if entity.inCombatWith != None:
                if entity.timeSinceAttack >= 3:
                    entity.inCombatWith = None
                    entity.timeSinceAttack = 0
                    # TODO:
                    # work with entity class to check for hit
        
        # update entities animation
        if animationDelta >= .10:
            for entity in entities:
                entity.updateAnimation()
            animationDelta = 0
            
        
            
       
        
        entities.draw(screen)
        
        
        # projectiles.draw(screen)
        # projectiles.draw(screen)
        font.render_to(screen, (10, 10), "Score: " + str(score), WHITE, None, size=64)
    
        # When drawing is done, flip the buffer.
        pg.display.flip()
        
        delta = clock.tick(fps) / 1000.0
        shotDelta += delta
        animationDelta += delta
        attackSpeedDelta += delta
        # needs to be in entity class
        combatDelta += delta
        
        # Check for deaths
        # for entity in entities:
        #     if entity.dead == True:
        #         if entity.team == 'enemy':
        #             score += 100
        #         if entity.team == 'player':
        #             score -= 100
        #         entities.remove(entity)

# Startup the main method to get things going.
if __name__ == "__main__":
    main()
    pg.quit()