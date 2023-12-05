

import pygame as pg
import os
#from projectile import Projectile
from pygame.locals import *
#from Python.Project.entity import Entity as Entity
from entity import Entity as Entity

#change to private vars later
def onEntityClick(entities, entity):
    if entity.team == 'player':
        if entity.selected == False:
            entity.selected = True
        else:
            entity.selected = False
    elif entity.team == 'enemy':
        for entityIt in entities:
            if entityIt.team == 'player':
                if entityIt.selected == True:
                    # entityIt.attack(entity)
                    pass
                    
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
    screen = pg.display.set_mode([960, 960]) # class dimensions

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

    # place 1 enemy in middle for testing
    entity = Entity((500, 500))
    entities.add(entity)
    
    
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
    fps = 60
    clock = pg.time.Clock()
    clock.tick(fps)
    score = 0
    while running:
        # First thing we need to clear the events
        for event in pg.event.get():
            if event.type == pg.QUIT:
                running = False
            if event.type == pg.USEREVENT + 1:
                score += 100
            if event.type == pg.MOUSEBUTTONUP:
                pos = pg.mouse.get_pos()
                for entity in entities:
                    if entity.rect.collidepoint(pos):
                        onEntityClick(entities, entity)
                    else:
                        onGameFieldClick(entities, pos[0], pos[1])
                # for resource in resources:
                #     if resource.rect.collidepoint(pos):
                #         onResourceClick(entities, resource)
        keys = pg.key.get_pressed()
        # if keys[K_w]:
        #     #player.up(delta)
        #     pass
        # if keys[K_a]:
        #     #player.left(delta)
        #     pass
        # if keys[K_s]:
        #     #player.down(delta)
        #     pass
        # if keys[K_d]:
        #     #player.right(delta)
        #     pass
        # # Attacking input
        # if keys[K_SPACE]:
        #     if shotDelta >= .25:
        #         projectile = Projectile(player.rect, enemies)
        #         projectiles.add(projectile)
        #         shotDelta = 0
        #         pass
        # # Win condition    
        # if len(enemies) == 0:
        #     print("You win!")
        #     return
        
        # Ok, events are handled, let's draw!

        # background instantiation 
        screen.blit(background, (0, 0))
        pg.display.update
        
        # player.update(delta)
        for entity in entities:
            entity.update(delta)
        # for projectile in projectiles:
        #     projectile.update(delta)
        
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

# Startup the main method to get things going.
if __name__ == "__main__":
    main()
    pg.quit()